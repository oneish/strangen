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

    inline auto pack(bag & dest) const -> void;

    inline auto unpack(bag const & src) -> void;
};
}
}
