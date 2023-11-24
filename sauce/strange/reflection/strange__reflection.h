#pragma once
#include <string>
#include <vector>

namespace strange
{

template<typename>
struct reflection;

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