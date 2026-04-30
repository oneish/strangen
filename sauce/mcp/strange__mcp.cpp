// MCP (Model Context Protocol) server for strangen.
// Uses strange::baggage for all JSON handling.
// Communicates via JSON-RPC 2.0 over stdio.
//
// Build: cmake --build bake-gcc --target strange_mcp
// Register: claude mcp add --transport stdio strange -- ./bake-gcc/sauce/mcp/strange_mcp

#include <iostream>
#include <sstream>
#include "strange/strange.h"
#include "strange/implementation/baggage/strange__implementation__baggage.h"
#include "strange/comprehension/strange__comprehension__parser.h"
#include "strange/meta/strange__transformation.h"

auto make() -> strange::baggage
{
    return strange::baggage::_make();
}

auto handle_initialize() -> strange::baggage
{
    auto result = make();
    result.from_object();
    result.insert_object("protocolVersion", result.make_string("2025-11-25"));

    auto capabilities = make();
    capabilities.from_object();
    auto tools = make();
    tools.from_object();
    capabilities.insert_object("tools", tools);
    result.insert_object("capabilities", capabilities);

    auto server_info = make();
    server_info.from_object();
    server_info.insert_object("name", server_info.make_string("strange"));
    server_info.insert_object("version", server_info.make_string("1.0.0"));
    result.insert_object("serverInfo", server_info);

    return result;
}

auto handle_tools_list() -> strange::baggage
{
    auto result = make();
    result.from_object();

    auto tools = make();
    tools.from_array();

    auto tool = make();
    tool.from_object();
    tool.insert_object("name", tool.make_string("enstrange"));
    tool.insert_object("description", tool.make_string("Transform a strangen prototype into a generated C++ header"));

    auto schema = make();
    schema.from_object();
    schema.insert_object("type", schema.make_string("object"));

    auto properties = make();
    properties.from_object();
    auto prototype_prop = make();
    prototype_prop.from_object();
    prototype_prop.insert_object("type", prototype_prop.make_string("string"));
    prototype_prop.insert_object("description", prototype_prop.make_string("The prototype definition (C++ source)"));
    properties.insert_object("prototype", prototype_prop);
    schema.insert_object("properties", properties);

    auto required = make();
    required.from_array();
    required.push_back_array(required.make_string("prototype"));
    schema.insert_object("required", required);

    tool.insert_object("inputSchema", schema);
    tools.push_back_array(tool);

    result.insert_object("tools", tools);
    return result;
}

auto handle_tool_call(std::string const & name, strange::baggage const & args) -> strange::baggage
{
    auto result = make();
    result.from_object();

    if (name == "enstrange")
    {
        auto prototype = args.get_object("prototype").to_string();

        std::istringstream iss{prototype};
        std::istreambuf_iterator<char> it{iss};
        strange::comprehension::toker toker{it, "prototype"};
        strange::comprehension::parser parser{toker};
        auto space = parser.parse();

        std::string output;
        if (space._valid())
        {
            std::ostringstream oss;
            strange::transformation(space, oss).transform();
            output = oss.str();
        }
        else
        {
            output = "error: " + space._error();
        }

        auto content = make();
        content.from_array();
        auto item = make();
        item.from_object();
        item.insert_object("type", item.make_string("text"));
        item.insert_object("text", item.make_string(output));
        content.push_back_array(item);
        result.insert_object("content", content);
    }
    else
    {
        auto content = make();
        content.from_array();
        auto item = make();
        item.from_object();
        item.insert_object("type", item.make_string("text"));
        item.insert_object("text", item.make_string("unknown tool: " + name));
        content.push_back_array(item);
        result.insert_object("content", content);
        result.insert_object("isError", result.make_bool(true));
    }

    return result;
}

auto handle_request(strange::baggage const & req) -> strange::baggage
{
    if (!req.contains_object("method"))
    {
        return strange::baggage{};
    }

    auto method = req.get_object("method").to_string();

    if (method.rfind("notifications/", 0) == 0)
    {
        return strange::baggage{};
    }

    auto resp = make();
    resp.from_object();
    resp.insert_object("jsonrpc", resp.make_string("2.0"));
    if (req.contains_object("id"))
    {
        resp.insert_object("id", req.get_object("id"));
    }

    if (method == "initialize")
    {
        resp.insert_object("result", handle_initialize());
    }
    else if (method == "tools/list")
    {
        resp.insert_object("result", handle_tools_list());
    }
    else if (method == "tools/call")
    {
        auto params = req.get_object("params");
        auto name = params.get_object("name").to_string();
        auto arguments = params.get_object("arguments");
        resp.insert_object("result", handle_tool_call(name, arguments._static<strange::baggage>()));
    }
    else
    {
        auto error = make();
        error.from_object();
        error.insert_object("code", error.make_int64(-32601));
        error.insert_object("message", error.make_string("Method not found"));
        resp.insert_object("error", error);
    }

    return resp;
}

int main()
{
    std::string line;
    while (std::getline(std::cin, line))
    {
        if (line.empty())
        {
            continue;
        }

        try
        {
            auto req = make();
            req.from_json(line);
            req.unseal();

            auto resp = handle_request(req);
            if (resp._something())
            {
                std::cout << resp.to_json() << "\n" << std::flush;
            }
        }
        catch (std::exception const & e)
        {
            std::cout << R"({"jsonrpc":"2.0","id":null,"error":{"code":-32700,"message":"Parse error"}})" << "\n" << std::flush;
        }
        catch (...)
        {
            std::cout << R"({"jsonrpc":"2.0","id":null,"error":{"code":-32700,"message":"Parse error"}})" << "\n" << std::flush;
        }
    }

    return 0;
}
