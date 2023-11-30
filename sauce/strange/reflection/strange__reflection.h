#pragma once
#include <string>
#include <vector>

namespace strange
{

template<typename>
struct reflection
{
    inline static auto name() -> std::string
    {
        return "???";
    }
};

template<>
struct reflection<bool>
{
    inline static auto name() -> std::string
    {
        return "bool";
    }
};

template<>
struct reflection<int>
{
    inline static auto name() -> std::string
    {
        return "int";
    }
};

template<typename T>
struct reflection<std::vector<T>>
{
    inline static auto name() -> std::string
    {
        return "std::vector<" + reflection<T>::name() + ">";
    }
};

}