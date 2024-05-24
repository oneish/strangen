#pragma once
#include "strange__definition__abstraction.h"
#include "../reflection/strange__reflection.h"
#include <string>
#include <vector>

namespace strange
{
namespace definition
{
struct space
{
    std::string name;
    std::vector<abstraction> abstractions;
};

inline auto operator==(space const & lhs, space const & rhs) -> bool
{
    return lhs.name == rhs.name
        && lhs.abstractions == rhs.abstractions;
}

}

template<>
struct reflection<strange::definition::space>
{
    inline static auto name() -> std::string
    {
        return "strange::definition::space";
    }
};

}
