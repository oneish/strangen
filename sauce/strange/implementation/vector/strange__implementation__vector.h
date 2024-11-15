#pragma once

#include <string>
#include <type_traits>
#include <vector>

namespace strange
{
struct bag;

namespace implementation
{
template<typename T>
struct vector : std::vector<T>
{
    vector() = default;

    explicit vector(std::size_t count)
    :std::vector<T>(count)
    {
    }

    explicit vector(std::size_t count, T const & value)
    :std::vector<T>(count, value)
    {
    }

    template<typename InputIt>
    vector(InputIt first, InputIt last)
    :std::vector<T>(first, last)
    {
    }

    vector(const vector& other) = default;

    vector(vector && other) = default;

    vector(std::initializer_list<T> ilist)
    :std::vector<T>(ilist)
    {
    }

    vector& operator=(const vector& other)
    {
        std::vector<T>::operator=(other);
        return *this;
    }

    vector& operator=(vector&& other)
    {
        std::vector<T>::operator=(std::move(other));
        return *this;
    }

    vector& operator=(std::initializer_list<T> ilist)
    {
        std::vector<T>::operator=(ilist);
        return *this;
    }

    inline auto pack(bag & dest) const -> void
    {
        dest.from_array();
        for (auto const & item : *this)
        {
            if constexpr (std::is_same_v<bool, T>)
            {
                dest.push_back_array(dest.make_bool(item));
            }
            else if constexpr (std::is_integral_v<T>)
            {
                dest.push_back_array(dest.make_int64(item));
            }
            else if constexpr (std::is_floating_point_v<T>)
            {
                dest.push_back_array(dest.make_double(item));
            }
            else if constexpr (std::is_same_v<std::string, T>)
            {
                dest.push_back_array(dest.make_string(item));
            }
            else if constexpr (std::is_base_of_v<strange::any, T>)
            {
                dest.push_back_array(dest.make_any(item));
            }
        }
    }

    inline auto unpack(bag const & src) -> void
    {
        std::vector<T>::clear();
        auto source = src.to_array();
        for (auto const & item : source)
        {
            if constexpr (std::is_same_v<bool, T>)
            {
                std::vector<T>::push_back(item.to_bool());
            }
            else if constexpr (std::is_integral_v<T>)
            {
                std::vector<T>::push_back(item.to_int64());
            }
            else if constexpr (std::is_floating_point_v<T>)
            {
                std::vector<T>::push_back(item.to_double());
            }
            else if constexpr (std::is_same_v<std::string, T>)
            {
                std::vector<T>::push_back(item.to_string());
            }
            else if constexpr (std::is_base_of_v<strange::any, T>)
            {
                std::vector<T>::push_back(item.to_any());
            }
        }
    }
};
}
}
