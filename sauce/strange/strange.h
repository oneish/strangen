#pragma once
#include "space/strange__space.h"

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

template<typename T>
inline auto hash_init(T const & v) -> std::size_t
{
    std::hash<T> hasher;
    return hasher(v);
}

template<typename T>
inline auto hash_combine(std::size_t & seed, T const & v) -> void
{
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

template<typename T>
inline auto hash_range(T const & v) -> std::size_t
{
    auto h = hash_init(v.size());
    for (auto const & elem : v)
    {
        hash_combine(h, elem);
    }
    return h;
}

template<>
struct std::hash<strange::parameter>
{
    inline auto operator()(strange::parameter const & param) const -> size_t
    {
        auto h = hash_init(param.type());
        hash_combine(h, param.name());
        hash_combine(h, param.argument());
        return h;
    }
};

template<>
struct std::hash<strange::operation>
{
    inline auto operator()(strange::operation const & oper) const -> size_t
    {
        auto h = hash_init(oper.name());
        hash_combine(h, hash_range(oper.parameters()));
        hash_combine(h, oper.constness());
        hash_combine(h, oper.result());
        hash_combine(h, oper.data());
        hash_combine(h, oper.modification());
        hash_combine(h, oper.customisation());
        hash_combine(h, oper.implementation());
        return h;
    }
};

template<>
struct std::hash<strange::abstraction>
{
    inline auto operator()(strange::abstraction const & abstract) const -> size_t
    {
        auto h = hash_range(abstract.parameters());
        hash_combine(h, abstract.name());
        hash_combine(h, hash_range(abstract.parents()));
        hash_combine(h, hash_range(abstract.types()));
        hash_combine(h, hash_range(abstract.operations()));
        hash_combine(h, abstract.thing());
        hash_combine(h, abstract.implementation());
        return h;
    }
};

template<>
struct std::hash<strange::space>
{
    inline auto operator()(strange::space const & spc) const -> size_t
    {
        auto h = hash_init(spc.name());
        hash_combine(h, hash_range(spc.abstractions()));
        return h;
    }
};

template<>
struct std::hash<strange::token>
{
    inline auto operator()(strange::token const & tok) const -> size_t
    {
        auto h = hash_init(tok.filename());
        hash_combine(h, tok.line());
        hash_combine(h, tok.position());
        hash_combine(h, tok.classification());
        hash_combine(h, tok.text());
        return h;
    }
};
