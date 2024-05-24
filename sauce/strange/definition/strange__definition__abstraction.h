#pragma once
#include "../space/strange__space.h"
#include "strange__definition__operation.h"
#include "../reflection/strange__reflection.h"
#include <string>
#include <vector>

namespace strange
{
namespace definition
{
struct abstraction
{
    std::vector<strange::parameter> parameters;
    std::string name;
    std::vector<std::string> parents;
    std::vector<strange::parameter> types;
    std::vector<operation> operations;
    std::string thing;
};

inline auto operator==(abstraction const & lhs, abstraction const & rhs) -> bool
{
    return lhs.parameters == rhs.parameters
        && lhs.name == rhs.name
        && lhs.parents == rhs.parents
        && lhs.types == rhs.types
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
