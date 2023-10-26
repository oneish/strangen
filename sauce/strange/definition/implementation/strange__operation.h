#pragma once
#include <string>
#include <vector>
#include <functional>
#include "strange__parameter.h"

namespace strange
{

struct operation
{
    std::string name;
    std::vector<strange::parameter> parameters;
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

template<>
struct std::hash<strange::operation>
{
    auto operator()(strange::operation const & op) const -> size_t
    {
        std::size_t h = std::hash<std::string>{}(op.name);
        for (auto const & param : op.parameters)
        {
            h ^= std::hash<strange::parameter>{}(param);
        }
        return h ^ std::hash<bool>{}(op.constness)
            ^ std::hash<std::string>{}(op.result)
            ^ std::hash<bool>{}(op.data);
    }
};