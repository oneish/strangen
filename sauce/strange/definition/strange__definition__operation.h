#pragma once
#include "strange__definition__parameter.h"
#include "../reflection/strange__reflection.h"
#include <string>
#include <vector>

namespace strange
{
namespace definition
{
struct operation
{
    std::string name;
    std::vector<parameter> parameters;
    bool constness = false;
    std::string result;
    bool data = false;
    std::string modification;
    std::string customisation;
    std::string implementation;
};

inline auto operator==(operation const & lhs, operation const & rhs) -> bool
{
    return lhs.name == rhs.name
        && lhs.parameters == rhs.parameters
        && lhs.constness == rhs.constness
        && lhs.result == rhs.result
        && lhs.data == rhs.data
        && lhs.modification == rhs.modification
        && lhs.customisation == rhs.customisation
        && lhs.implementation == rhs.implementation;
}

}

template<>
struct reflection<strange::definition::operation>
{
    inline static auto name() -> std::string
    {
        return "strange::definition::operation";
    }
};

}

template<>
struct std::hash<strange::definition::operation>
{
    inline auto operator()(strange::definition::operation const & op) const -> size_t
    {
        std::size_t h = std::hash<std::string>{}(op.name);
        for (auto const & param : op.parameters)
        {
            h ^= std::hash<strange::definition::parameter>{}(param);
        }
        return h ^ std::hash<bool>{}(op.constness)
            ^ std::hash<std::string>{}(op.result)
            ^ std::hash<bool>{}(op.data)
            ^ std::hash<std::string>{}(op.modification)
            ^ std::hash<std::string>{}(op.customisation)
            ^ std::hash<std::string>{}(op.implementation);
    }
};
