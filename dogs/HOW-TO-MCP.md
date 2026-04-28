There's **no official C++ MCP SDK**. The official SDKs are TypeScript, Python, C#, and Go. But MCP is just **JSON-RPC 2.0 over stdio**, so it's straightforward to implement yourself.

### What You Need

- A JSON library — **nlohmann/json** (header-only) is the standard choice
- A stdin/stdout read loop
- Handlers for a few methods

### Minimal C++ MCP Server

```cpp
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

json handleInitialize() {
    return {
        {"protocolVersion", "2025-06-18"},
        {"capabilities", {{"tools", json::object()}}},
        {"serverInfo", {{"name", "my-cpp-server"}, {"version", "1.0.0"}}}
    };
}

json handleToolsList() {
    return {{"tools", {{
        {"name", "greet"},
        {"description", "Greet a user by name"},
        {"inputSchema", {
            {"type", "object"},
            {"properties", {{"name", {{"type", "string"}}}}},
            {"required", {"name"}}
        }}
    }}}};
}

json handleToolCall(const std::string& name, const json& args) {
    if (name == "greet") {
        std::string msg = "Hello, " + args["name"].get<std::string>() + "!";
        return {{"content", {{{"type", "text"}, {"text", msg}}}}};
    }
    return {{"error", "Unknown tool"}};
}

json handleRequest(const json& req) {
    std::string method = req["method"];
    json result;

    if (method == "initialize")       result = handleInitialize();
    else if (method == "tools/list")  result = handleToolsList();
    else if (method == "tools/call")  result = handleToolCall(
        req["params"]["name"], req["params"]["arguments"]);
    else if (method == "notifications/initialized") return {};  // no response
    else return {{"jsonrpc", "2.0"}, {"id", req["id"]},
                 {"error", {{"code", -32601}, {"message", "Method not found"}}}};

    return {{"jsonrpc", "2.0"}, {"id", req["id"]}, {"result", result}};
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        auto req = json::parse(line);
        if (req.contains("method") && req["method"].get<std::string>().rfind("notifications/", 0) == 0)
            continue;  // notifications don't get responses
        auto resp = handleRequest(req);
        if (!resp.empty()) {
            std::cout << resp.dump() << "\n" << std::flush;
        }
    }
}
```

### Key Rules

1. **Never write debug output to stdout** — it corrupts the protocol. Use `std::cerr` instead.
2. Tool results must be `{"content": [{"type": "text", "text": "..."}]}`, not bare strings.
3. Notifications (methods starting with `notifications/`) get **no response**.

### Build & Register

```bash
g++ -std=c++17 -o my-server server.cpp -I/path/to/nlohmann
claude mcp add --transport stdio my-cpp-server -- ./my-server
```

### Methods You Need to Handle

| Method | Purpose | Response? |
|--------|---------|-----------|
| `initialize` | Handshake, declare capabilities | Yes |
| `notifications/initialized` | Client says ready | No |
| `tools/list` | Return available tools | Yes |
| `tools/call` | Execute a tool | Yes |

That covers a working server. The full spec is at https://modelcontextprotocol.io/specification/latest if you want to add resources or prompts later.
