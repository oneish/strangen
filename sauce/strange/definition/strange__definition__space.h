#pragma once
#include "strange__definition__abstraction.h"
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

template<>
struct std::hash<strange::definition::space>
{
    inline auto operator()(strange::definition::space const & spc) const -> size_t
    {
        std::size_t h = std::hash<std::string>{}(spc.name);
        for (auto const & abs : spc.abstractions)
        {
            h ^= std::hash<strange::definition::abstraction>{}(abs);
        }
        return h;
    }
};
