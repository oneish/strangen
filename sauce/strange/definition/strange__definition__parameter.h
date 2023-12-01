#pragma once
#include "../reflection/strange__reflection.h"
#include <string>
#include <functional>

namespace strange
{
namespace definition
{
struct parameter
{
    std::string type;
    std::string name;
    std::string argument;
};

inline auto operator==(parameter const & lhs, parameter const & rhs) -> bool
{
    return lhs.type == rhs.type
        && lhs.name == rhs.name
        && lhs.argument == rhs.argument;
}

}

template<>
struct reflection<strange::definition::parameter>
{
    inline static auto name() -> std::string
    {
        return "strange::definition::parameter";
    }
};

}

template<>
struct std::hash<strange::definition::parameter>
{
    inline auto operator()(strange::definition::parameter const & param) const -> size_t
    {
        return std::hash<std::string>{}(param.type)
            ^ std::hash<std::string>{}(param.name)
            ^ std::hash<std::string>{}(param.argument);
    }
};
