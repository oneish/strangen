# MCP Server

The strangen MCP server (`sauce/mcp/strange__mcp.cpp`) implements the [Model Context Protocol](https://modelcontextprotocol.io/specification/latest) using `strange::baggage` for all JSON handling. It communicates via JSON-RPC 2.0 over stdio.

## Build & Register

```bash
cmake --build bake-gcc --target strange_mcp
claude mcp add --transport stdio strange -- ./bake-gcc/sauce/mcp/strange_mcp
```

## JSON with strange::baggage

The server uses `strange::baggage` instead of a third-party JSON library. Key patterns:

```cpp
// Factory
auto make() -> strange::baggage
{
    return strange::baggage::_make();
}

// Parse JSON from stdin
auto req = make();
req.from_json(line);
req.unseal(); // from_json produces a finalized buffer; unseal() before accessing fields

// Read fields
auto method = req.get_object("method").to_string();
auto id = req.get_object("id");
if (req.contains_object("id")) { ... }

// Build JSON objects
auto resp = make();
resp.from_object();
resp.insert_object("jsonrpc", resp.make_string("2.0"));
resp.insert_object("id", id);
resp.insert_object("result", result);

// Build JSON arrays
auto content = make();
content.from_array();
content.push_back_array(item);

// Write JSON to stdout
std::cout << resp.to_json() << "\n" << std::flush;
```

## Protocol

The server handles four JSON-RPC methods:

| Method | Purpose | Response? |
|--------|---------|-----------|
| `initialize` | Handshake, declare capabilities | Yes |
| `notifications/initialized` | Client says ready | No |
| `tools/list` | Return available tools | Yes |
| `tools/call` | Execute a tool | Yes |

Notifications (methods starting with `notifications/`) get no response. Requests with missing `method` fields are silently ignored.

## Key Rules

1. **Never write debug output to stdout** -- it corrupts the protocol. Use `std::cerr` instead.
2. Tool results must be `{"content": [{"type": "text", "text": "..."}]}`, not bare strings.
3. Use `resp._something()` to check whether a response should be sent (empty baggage = no response).
4. **Always call `unseal()` after `from_json()`** -- `dart::packet::from_json` produces a finalized (read-only) buffer by default. Calling `contains_object`/`get_object` on it returns false/null for all fields. Call `unseal()` first to convert it to a mutable heap.
5. **Always echo the request `"id"` in responses** -- Claude Code matches responses to pending requests by id. A missing or null id causes a 30-second connection timeout.

## Available Tools

### enstrange

Transforms a strangen prototype into a generated C++ header. Takes a `prototype` string parameter and returns the generated code as text.

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "method": "tools/call",
    "params": {
        "name": "enstrange",
        "arguments": {
            "prototype": "namespace test { struct widget : strange::any { auto display() const -> void; }; }"
        }
    }
}
```

## Dependencies

The MCP server links against `strange`, `dart`, `gsl`, `rapidjson`, and `sajson` for the baggage JSON implementation.
