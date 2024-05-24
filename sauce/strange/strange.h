#pragma once
#include "space/strange__space.h"

namespace strange
{
inline auto operator==(parameter const & lhs, parameter const & rhs) -> bool
{
    return lhs.type() == rhs.type()
        && lhs.name() == rhs.name()
        && lhs.argument() == rhs.argument();
}

// deduction guide
template<class InputIt>
vector(InputIt, InputIt)
    -> vector<typename std::iterator_traits<InputIt>::value_type>;
}

template<>
struct std::hash<strange::parameter>
{
    inline auto operator()(strange::parameter const & param) const -> size_t
    {
        return std::hash<std::string>{}(param.type())
            ^ std::hash<std::string>{}(param.name())
            ^ std::hash<std::string>{}(param.argument());
    }
};
