#pragma once
#include <string>
#include <vector>
#include <functional>
#include "strange__definition__parameter.h"

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

    auto operator==(operation const & other) const -> bool
    {
        return name == other.name
            && parameters == other.parameters
            && constness == other.constness
            && result == other.result
            && data == other.data;
    }
};
}
}

template<>
struct std::hash<strange::definition::operation>
{
    auto operator()(strange::definition::operation const & op) const -> size_t
    {
        std::size_t h = std::hash<std::string>{}(op.name);
        for (auto const & param : op.parameters)
        {
            h ^= std::hash<strange::definition::parameter>{}(param);
        }
        return h ^ std::hash<bool>{}(op.constness)
            ^ std::hash<std::string>{}(op.result)
            ^ std::hash<bool>{}(op.data);
    }
};