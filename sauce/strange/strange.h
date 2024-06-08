#pragma once
#include "space/strange__space.h"
#include "definition/strange__definition__parameter.h"
#include "definition/strange__definition__operation.h"
#include "definition/strange__definition__abstraction.h"
#include "definition/strange__definition__space.h"
#include "comprehension/strange__comprehension__toker.h"

namespace strange
{
// deduction guide
template<class InputIt>
vector(InputIt, InputIt)
    -> vector<typename std::iterator_traits<InputIt>::value_type>;

template<typename _Abstraction, typename Message>
auto error(Message && message) -> _Abstraction
{
    _Abstraction abs;
    abs._error(message);
    return abs;
}
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

template<>
struct std::hash<strange::operation>
{
    inline auto operator()(strange::operation const & oper) const -> size_t
    {
        std::size_t h = std::hash<std::string>{}(oper.name());
        for (auto const & param : oper.parameters())
        {
            h ^= std::hash<strange::parameter>{}(param);
        }
        return h ^ std::hash<bool>{}(oper.constness())
            ^ std::hash<std::string>{}(oper.result())
            ^ std::hash<bool>{}(oper.data())
            ^ std::hash<std::string>{}(oper.modification())
            ^ std::hash<std::string>{}(oper.customisation())
            ^ std::hash<std::string>{}(oper.implementation());
    }
};

template<>
struct std::hash<strange::abstraction>
{
    inline auto operator()(strange::abstraction const & abstract) const -> size_t
    {
        std::size_t h = 0;
        for (auto const & param : abstract.parameters())
        {
            h ^= std::hash<strange::parameter>{}(param);
        }
        h ^= std::hash<std::string>{}(abstract.name());
        for (auto const & parent : abstract.parents())
        {
            h ^= std::hash<std::string>{}(parent);
        }
        for (auto const & type : abstract.types())
        {
            h ^= std::hash<strange::parameter>{}(type);
        }
        for (auto const & oper : abstract.operations())
        {
            h ^= std::hash<strange::operation>{}(oper);
        }
        h ^= std::hash<std::string>{}(abstract.thing());
        return h;
    }
};

template<>
struct std::hash<strange::space>
{
    inline auto operator()(strange::space const & spc) const -> size_t
    {
        std::size_t h = std::hash<std::string>{}(spc.name());
        for (auto const & abstract : spc.abstractions())
        {
            h ^= std::hash<strange::abstraction>{}(abstract);
        }
        return h;
    }
};
/*
template<>
struct std::hash<strange::token>
{
    inline auto operator()(strange::token const & tok) const -> size_t
    {
        return std::hash<std::string>{}(tok.filename())
            ^ std::hash<int64_t>{}(tok.line())
            ^ std::hash<int64_t>{}(tok.position())
            ^ std::hash<std::underlying_type_t<strange::comprehension::cls>>{}(static_cast<std::underlying_type_t<strange::comprehension::cls>>(tok.classification()))
            ^ std::hash<std::string>{}(tok.text());
    }
};
*/
