// Compile-time type name registry using template specialization. The primary
// template returns "???" for unknown types. Explicit specializations provide
// names for built-in types, std::string, std::vector<T>, and strange types
// (generated in strange__space.h). The concatename helper builds comma-separated
// lists of type names for template parameter packs.

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

template<bool _Comma>
inline auto concatename() -> std::string
{
    return std::string {};
}

template<bool _Comma, typename _First, typename... _Rest>
inline auto concatename() -> std::string
{
    std::string result;
    if constexpr (_Comma)
    {
        result = ", ";
    }
    result += reflection<_First>::name();
    ((result += ", " + reflection<_Rest>::name()), ...);
    return result;
}

template<>
struct reflection<void>
{
    static inline auto name() -> std::string
    {
        return "void";
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
struct reflection<char>
{
    static inline auto name() -> std::string
    {
        return "char";
    }
};

template<>
struct reflection<int8_t>
{
    static inline auto name() -> std::string
    {
        return "int8_t";
    }
};

template<>
struct reflection<int16_t>
{
    static inline auto name() -> std::string
    {
        return "int16_t";
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

template<>
struct reflection<uint8_t>
{
    static inline auto name() -> std::string
    {
        return "uint8_t";
    }
};

template<>
struct reflection<uint16_t>
{
    static inline auto name() -> std::string
    {
        return "uint16_t";
    }
};

template<>
struct reflection<uint32_t>
{
    static inline auto name() -> std::string
    {
        return "uint32_t";
    }
};

template<>
struct reflection<uint64_t>
{
    static inline auto name() -> std::string
    {
        return "uint64_t";
    }
};

template<>
struct reflection<float>
{
    static inline auto name() -> std::string
    {
        return "float";
    }
};

template<>
struct reflection<double>
{
    static inline auto name() -> std::string
    {
        return "double";
    }
};

template<>
struct reflection<std::string>
{
    static inline auto name() -> std::string
    {
        return "std::string";
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
