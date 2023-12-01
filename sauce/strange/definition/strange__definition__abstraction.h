#pragma once
#include "../strange.h"
#include <string>
#include <vector>

namespace strange
{
namespace definition
{
struct abstraction
{
    std::vector<parameter_a> parameters;
    std::string name;
    std::vector<std::string> parents;
    std::vector<operation_a> operations;
    std::string thing;
};

inline auto operator==(abstraction const & lhs, abstraction const & rhs) -> bool
{
    return lhs.parameters == rhs.parameters
        && lhs.name == rhs.name
        && lhs.parents == rhs.parents
        && lhs.operations == rhs.operations
        && lhs.thing == rhs.thing;
}

}

template<>
struct reflection<strange::definition::abstraction>
{
    inline static auto name() -> std::string
    {
        return "strange::definition::abstraction";
    }
};

}

template<>
struct std::hash<strange::definition::abstraction>
{
    inline auto operator()(strange::definition::abstraction const & abs) const -> size_t
    {
        std::size_t h = 0;
        for (auto const & param : abs.parameters)
        {
            h ^= std::hash<strange::parameter_a>{}(param);
        }
        h ^= std::hash<std::string>{}(abs.name);
        for (auto const & parent : abs.parents)
        {
            h ^= std::hash<std::string>{}(parent);
        }
        for (auto const & oper : abs.operations)
        {
            h ^= std::hash<strange::operation_a>{}(oper);
        }
        h ^= std::hash<std::string>{}(abs.thing);
        return h;
    }
};
