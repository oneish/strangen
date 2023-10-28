#pragma once
#include "../strange.h"
#include <string>
#include <vector>
#include <functional>

namespace strange
{
namespace definition
{
struct operation
{
    std::string name;
    std::vector<parameter_a> parameters;
    bool constness = false;
    std::string result;
    bool data = false;
};
}
}

namespace std
{
inline auto operator==(strange::definition::operation const & lhs, strange::definition::operation const & rhs) -> bool
{
    return lhs.name == rhs.name
        && lhs.parameters == rhs.parameters
        && lhs.constness == rhs.constness
        && lhs.result == rhs.result
        && lhs.data == rhs.data;
}
}

template<>
struct std::hash<strange::definition::operation>
{
    inline auto operator()(strange::definition::operation const & op) const -> size_t
    {
        std::size_t h = std::hash<std::string>{}(op.name);
        for (auto const & param : op.parameters)
        {
            h ^= std::hash<strange::parameter_a>{}(param);
        }
        return h ^ std::hash<bool>{}(op.constness)
            ^ std::hash<std::string>{}(op.result)
            ^ std::hash<bool>{}(op.data);
    }
};