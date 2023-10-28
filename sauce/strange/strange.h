#pragma once
#include "space/strange__space.h"
#include <functional>

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

namespace std
{
inline auto operator==(strange::operation_a const & lhs, strange::operation_a const & rhs) -> bool
{
    return lhs.name() == rhs.name()
        && lhs.parameters() == rhs.parameters()
        && lhs.constness() == rhs.constness()
        && lhs.result() == rhs.result()
        && lhs.data() == rhs.data();
}
}

template<>
struct std::hash<strange::operation_a>
{
    inline auto operator()(strange::operation_a const & op) const -> size_t
    {
        std::size_t h = std::hash<std::string>{}(op.name());
        for (auto const & param : op.parameters())
        {
            h ^= std::hash<strange::parameter_a>{}(param);
        }
        return h ^ std::hash<bool>{}(op.constness())
            ^ std::hash<std::string>{}(op.result())
            ^ std::hash<bool>{}(op.data());
    }
};

namespace std
{
inline auto operator==(strange::abstraction_a const & lhs, strange::abstraction_a const & rhs) -> bool
{
    return lhs.parameters() == rhs.parameters()
        && lhs.name() == rhs.name()
        && lhs.parents() == rhs.parents()
        && lhs.operations() == rhs.operations();
}
}

template<>
struct std::hash<strange::abstraction_a>
{
    inline auto operator()(strange::abstraction_a const & op) const -> size_t
    {
        std::size_t h = 0;
        for (auto const & param : op.parameters())
        {
            h ^= std::hash<strange::parameter_a>{}(param);
        }
        h ^= std::hash<std::string>{}(op.name());
        for (auto const & paren : op.parents())
        {
            h ^= std::hash<std::string>{}(paren);
        }
        for (auto const & oper : op.operations())
        {
            h ^= std::hash<strange::operation_a>{}(oper);
        }
        return h;
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

namespace strange
{
inline auto make_operation(definition::operation oper) -> operation_a
{
    return operation_a::_make<definition::operation>(oper);
}
}

#include "definition/strange__definition__abstraction.h"

namespace strange
{
inline auto make_abstraction(definition::abstraction abs) -> abstraction_a
{
    return abstraction_a::_make<definition::abstraction>(abs);
}
}

#include "definition/strange__definition__space.h"