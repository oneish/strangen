#pragma once
#include <string>

namespace strange
{
namespace definition
{
struct parameter
{
    std::string type;
    std::string name;
    std::string argument;

    auto operator==(parameter const & other) const -> bool
    {
        return type == other.type
            && name == other.name
            && argument == other.argument;
    }
};
}
}

template<>
struct std::hash<strange::definition::parameter>
{
    auto operator()(strange::definition::parameter const & param) const -> size_t
    {
        return std::hash<std::string>{}(param.type)
            ^ std::hash<std::string>{}(param.name)
            ^ std::hash<std::string>{}(param.argument);
    }
};