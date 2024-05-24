#pragma once
#include "space/strange__space.h"

namespace strange
{
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

#include "definition/strange__definition__operation.h"
template<>
struct std::hash<strange::definition::operation>
{
    inline auto operator()(strange::definition::operation const & op) const -> size_t
    {
        std::size_t h = std::hash<std::string>{}(op.name);
        for (auto const & param : op.parameters)
        {
            h ^= std::hash<strange::parameter>{}(param);
        }
        return h ^ std::hash<bool>{}(op.constness)
            ^ std::hash<std::string>{}(op.result)
            ^ std::hash<bool>{}(op.data)
            ^ std::hash<std::string>{}(op.modification)
            ^ std::hash<std::string>{}(op.customisation)
            ^ std::hash<std::string>{}(op.implementation);
    }
};

#include "definition/strange__definition__abstraction.h"
template<>
struct std::hash<strange::definition::abstraction>
{
    inline auto operator()(strange::definition::abstraction const & abs) const -> size_t
    {
        std::size_t h = 0;
        for (auto const & param : abs.parameters)
        {
            h ^= std::hash<strange::parameter>{}(param);
        }
        h ^= std::hash<std::string>{}(abs.name);
        for (auto const & parent : abs.parents)
        {
            h ^= std::hash<std::string>{}(parent);
        }
        for (auto const & type : abs.types)
        {
            h ^= std::hash<strange::parameter>{}(type);
        }
        for (auto const & oper : abs.operations)
        {
            h ^= std::hash<strange::definition::operation>{}(oper);
        }
        h ^= std::hash<std::string>{}(abs.thing);
        return h;
    }
};

#include "definition/strange__definition__space.h"
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
