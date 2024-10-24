#pragma once
#include <string>
#include <cstdint>
#include <vector>

namespace strange
{

template<typename>
struct reflection
{
    static inline auto name() -> std::string
    {
        return "???";
    }
};

template<>
struct reflection<bool>
{
    static inline auto name() -> std::string
    {
        return "bool";
    }
};

template<>
struct reflection<int32_t>
{
    static inline auto name() -> std::string
    {
        return "int32_t";
    }
};

template<>
struct reflection<int64_t>
{
    static inline auto name() -> std::string
    {
        return "int64_t";
    }
};

template<typename T>
struct reflection<std::vector<T>>
{
    static inline auto name() -> std::string
    {
        return "std::vector<" + reflection<T>::name() + ">";
    }

    static inline auto operations() -> std::vector<std::string>
    {
        return
        {
            "auto operator=(" + name() + " const &) -> " + name() + " &",
            "auto operator=(" + name() + " &&) -> " + name() + " &",
        };
    }
};

}
