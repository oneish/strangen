#pragma once
#include "../space/strange__space.h"
#include "../reflection/strange__reflection.h"
#include <string>

namespace strange
{
namespace definition
{
struct operation
{
    std::string name;
    strange::vector<strange::parameter> parameters = strange::vector<strange::parameter>::_make();
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
