#pragma once
#include <functional>

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
