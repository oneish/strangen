#pragma once
#include "space/strange__space.h"

namespace std
{
inline auto operator==(strange::parameter_a const & lhs, strange::parameter_a const & rhs) -> bool
{
    return lhs.type() == rhs.type()
        && lhs.name() == rhs.name()
        && lhs.argument() == rhs.argument();
}
}

template<>
struct std::hash<strange::parameter_a>
{
    inline auto operator()(strange::parameter_a const & param) const -> size_t
    {
        return std::hash<std::string>{}(param.type())
            ^ std::hash<std::string>{}(param.name())
            ^ std::hash<std::string>{}(param.argument());
    }
};

#include "definition/strange__definition__parameter.h"

namespace strange
{
inline auto make_parameter(definition::parameter param) -> parameter_a
{
    return parameter_a::_make<definition::parameter>(param);
}
}

#include "definition/strange__definition__operation.h"
#include "definition/strange__definition__abstraction.h"
#include "definition/strange__definition__space.h"