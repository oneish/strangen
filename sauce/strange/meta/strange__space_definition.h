#pragma once
#include "../definition/strange__definition__space.h"

namespace strange
{
namespace meta
{
using strange::definition::space;
using strange::definition::abstraction;
using strange::definition::operation;
using strange::definition::parameter;

auto definition() -> space
{
    return space
    {
        .name = "strange",
        .abstractions =
        {
            abstraction
            {
                .name = "any",
            },
            abstraction
            {
                .parameters =
                {
                    parameter
                    {
                        .type = "typename",
                        .name = "T",
                    },
                },
                .name = "forward_const_iterator",
                .parents =
                {
                    "any",
                },
                .types =
                {
                    parameter
                    {
                        .type = "using",
                        .name = "value_type",
                        .argument = "T",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "difference_type",
                        .argument = "std::ptrdiff_t",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "reference",
                        .argument = "value_type &",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "pointer",
                        .argument = "value_type *",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "iterator_category",
                        .argument = "std::forward_iterator_tag",
                    },
                },
                .operations =
                {
                    operation
                    {
                        .name = "operator*",
                        .constness = true,
                        .result = "T const &",
                    },
                    operation
                    {
                        .name = "operator->",
                        .constness = true,
                        .result = "T const *",
                    },
                    operation
                    {
                        .name = "operator++",
                        .result = "*this",
                    },
                    operation
                    {
                        .name = "operator++",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "int",
                                .name = "i",
                            },
                        },
                        .result = "*that",
                    },
                    operation
                    {
                        .name = "operator==",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "forward_const_iterator<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing == other.template _static<forward_const_iterator_<T, _Thing, _Copy>>()._thing()",
                    },
                    operation
                    {
                        .name = "operator!=",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "forward_const_iterator<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return !operator==(other)",
                    },
                },
            },
            abstraction
            {
                .parameters =
                {
                    parameter
                    {
                        .type = "typename",
                        .name = "T",
                    },
                },
                .name = "forward_iterator",
                .parents =
                {
                    "forward_const_iterator<T>",
                },
                .types =
                {
                    parameter
                    {
                        .type = "using",
                        .name = "value_type",
                        .argument = "T",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "difference_type",
                        .argument = "std::ptrdiff_t",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "reference",
                        .argument = "value_type &",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "pointer",
                        .argument = "value_type *",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "iterator_category",
                        .argument = "std::forward_iterator_tag",
                    },
                },
                .operations =
                {
                    operation
                    {
                        .name = "operator*",
// hack                        .constness = true,
                        .result = "T &",
                    },
                    operation
                    {
                        .name = "operator->",
// hack                        .constness = true,
                        .result = "T *",
                    },
                    operation
                    {
                        .name = "operator==",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "forward_iterator<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing == other.template _static<forward_iterator_<T, _Thing, _Copy>>()._thing()",
                    },
                    operation
                    {
                        .name = "operator!=",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "forward_iterator<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return !operator==(other)",
                    },
                },
            },
            abstraction
            {
                .parameters =
                {
                    parameter
                    {
                        .type = "typename",
                        .name = "T",
                    },
                },
                .name = "bidirectional_const_iterator",
                .parents =
                {
                    "forward_const_iterator<T>",
                },
                .types =
                {
                    parameter
                    {
                        .type = "using",
                        .name = "iterator_category",
                        .argument = "std::bidirectional_iterator_tag",
                    },
                },
                .operations =
                {
                    operation
                    {
                        .name = "operator==",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "bidirectional_const_iterator<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing == other.template _static<bidirectional_const_iterator_<T, _Thing, _Copy>>()._thing()",
                    },
                    operation
                    {
                        .name = "operator!=",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "bidirectional_const_iterator<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return !operator==(other)",
                    },
                    operation
                    {
                        .name = "operator--",
                        .result = "*this",
                    },
                    operation
                    {
                        .name = "operator--",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "int",
                                .name = "i",
                            },
                        },
                        .result = "*that",
                    },
                },
            },
            abstraction
            {
                .parameters =
                {
                    parameter
                    {
                        .type = "typename",
                        .name = "T",
                    },
                },
                .name = "bidirectional_iterator",
                .parents =
                {
                    "forward_iterator<T>",
                    "bidirectional_const_iterator<T>",
                },
                .types =
                {
                    parameter
                    {
                        .type = "using",
                        .name = "value_type",
                        .argument = "T",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "difference_type",
                        .argument = "std::ptrdiff_t",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "reference",
                        .argument = "value_type &",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "pointer",
                        .argument = "value_type *",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "iterator_category",
                        .argument = "std::bidirectional_iterator_tag",
                    },
                },
                .operations =
                {
                    operation
                    {
                        .name = "operator==",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "bidirectional_iterator<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing == other.template _static<bidirectional_iterator_<T, _Thing, _Copy>>()._thing()",
                    },
                    operation
                    {
                        .name = "operator!=",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "bidirectional_iterator<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return !operator==(other)",
                    },
                },
            },
            abstraction
            {
                .parameters =
                {
                    parameter
                    {
                        .type = "typename",
                        .name = "T",
                    },
                },
                .name = "random_access_const_iterator",
                .parents =
                {
                    "bidirectional_const_iterator<T>",
                },
                .types =
                {
                    parameter
                    {
                        .type = "using",
                        .name = "value_type",
                        .argument = "T",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "difference_type",
                        .argument = "std::ptrdiff_t",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "reference",
                        .argument = "value_type &",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "pointer",
                        .argument = "value_type *",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "iterator_category",
                        .argument = "std::random_access_iterator_tag",
                    },
                },
                .operations =
                {
                    operation
                    {
                        .name = "operator==",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "random_access_const_iterator<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing == other.template _static<random_access_const_iterator_<T, _Thing, _Copy>>()._thing()",
                    },
                    operation
                    {
                        .name = "operator!=",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "random_access_const_iterator<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return !operator==(other)",
                    },
                    operation
                    {
                        .name = "operator<",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "random_access_const_iterator<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing < other.template _static<random_access_const_iterator_<T, _Thing, _Copy>>()._thing()",
                    },
                    operation
                    {
                        .name = "operator>",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "random_access_const_iterator<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing > other.template _static<random_access_const_iterator_<T, _Thing, _Copy>>()._thing()",
                    },
                    operation
                    {
                        .name = "operator<=",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "random_access_const_iterator<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing <= other.template _static<random_access_const_iterator_<T, _Thing, _Copy>>()._thing()",
                    },
                    operation
                    {
                        .name = "operator>=",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "random_access_const_iterator<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing >= other.template _static<random_access_const_iterator_<T, _Thing, _Copy>>()._thing()",
                    },
                    operation
                    {
                        .name = "operator+=",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "std::ptrdiff_t",
                                .name = "n",
                            },
                        },
                        .result = "*this",
                    },
                    operation
                    {
                        .name = "operator-=",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "std::ptrdiff_t",
                                .name = "n",
                            },
                        },
                        .result = "*this",
                    },
                    operation
                    {
                        .name = "operator+",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "std::ptrdiff_t",
                                .name = "n",
                            },
                        },
                        .constness = true,
                        .result = "random_access_const_iterator<T>",
                        .customisation = "return random_access_const_iterator<T>::template _make<_Thing, _Copy>(_thing + n)",
                    },
                    operation
                    {
                        .name = "operator-",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "std::ptrdiff_t",
                                .name = "n",
                            },
                        },
                        .constness = true,
                        .result = "random_access_const_iterator<T>",
                        .customisation = "return random_access_const_iterator<T>::template _make<_Thing, _Copy>(_thing - n)",
                    },
                    operation
                    {
                        .name = "operator-",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "random_access_const_iterator<T>",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "std::ptrdiff_t",
                        .customisation = "return _thing - other.template _static<random_access_const_iterator_<T, _Thing, _Copy>>()._thing()",
                    },
                    operation
                    {
                        .name = "operator[]",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "std::ptrdiff_t",
                                .name = "n",
                            },
                        },
                        .constness = true,
                        .result = "T const &",
                    },
                },
            },
            abstraction
            {
                .parameters =
                {
                    parameter
                    {
                        .type = "typename",
                        .name = "T",
                    },
                },
                .name = "random_access_iterator",
                .parents =
                {
                    "bidirectional_iterator<T>",
                    "random_access_const_iterator<T>",
                },
                .types =
                {
                    parameter
                    {
                        .type = "using",
                        .name = "value_type",
                        .argument = "T",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "difference_type",
                        .argument = "std::ptrdiff_t",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "reference",
                        .argument = "value_type &",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "pointer",
                        .argument = "value_type *",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "iterator_category",
                        .argument = "std::random_access_iterator_tag",
                    },
                },
                .operations =
                {
                    operation
                    {
                        .name = "operator==",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "random_access_iterator<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing == other.template _static<random_access_iterator_<T, _Thing, _Copy>>()._thing()",
                    },
                    operation
                    {
                        .name = "operator!=",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "random_access_iterator<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return !operator==(other)",
                    },
                    operation
                    {
                        .name = "operator<",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "random_access_iterator<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing < other.template _static<random_access_iterator_<T, _Thing, _Copy>>()._thing()",
                    },
                    operation
                    {
                        .name = "operator>",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "random_access_iterator<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing > other.template _static<random_access_iterator_<T, _Thing, _Copy>>()._thing()",
                    },
                    operation
                    {
                        .name = "operator<=",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "random_access_iterator<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing <= other.template _static<random_access_iterator_<T, _Thing, _Copy>>()._thing()",
                    },
                    operation
                    {
                        .name = "operator>=",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "random_access_iterator<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing >= other.template _static<random_access_iterator_<T, _Thing, _Copy>>()._thing()",
                    },
                    operation
                    {
                        .name = "operator+",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "std::ptrdiff_t",
                                .name = "n",
                            },
                        },
// hack                        .constness = true,
                        .result = "random_access_iterator<T>",
                        .customisation = "return random_access_iterator<T>::template _make<_Thing, _Copy>(_thing + n)",
                    },
                    operation
                    {
                        .name = "operator-",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "std::ptrdiff_t",
                                .name = "n",
                            },
                        },
// hack                        .constness = true,
                        .result = "random_access_iterator<T>",
                        .customisation = "return random_access_iterator<T>::template _make<_Thing, _Copy>(_thing - n)",
                    },
                    operation
                    {
                        .name = "operator-",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "random_access_iterator<T>",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "std::ptrdiff_t",
                        .customisation = "return _thing - other.template _static<random_access_iterator_<T, _Thing, _Copy>>()._thing()",
                    },
                    operation
                    {
                        .name = "operator[]",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "std::ptrdiff_t",
                                .name = "n",
                            },
                        },
// hack                        .constness = true,
                        .result = "T &",
                    },
                },
            },
            abstraction
            {
                .parameters =
                {
                    parameter
                    {
                        .type = "typename",
                        .name = "T",
                    },
                },
                .name = "vector",
                .parents =
                {
                    "any",
                },
                .types =
                {
                    parameter
                    {
                        .type = "using",
                        .name = "value_type",
                        .argument = "T",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "size_type",
                        .argument = "std::size_t",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "difference_type",
                        .argument = "std::ptrdiff_t",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "reference",
                        .argument = "value_type &",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "const_reference",
                        .argument = "value_type const &",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "pointer",
                        .argument = "value_type *",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "const_pointer",
                        .argument = "value_type const *",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "iterator",
                        .argument = "typename strange::random_access_iterator<T>",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "const_iterator",
                        .argument = "typename strange::random_access_const_iterator<T>",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "reverse_iterator",
                        .argument = "typename std::reverse_iterator<iterator>",
                    },
                    parameter
                    {
                        .type = "using",
                        .name = "const_reverse_iterator",
                        .argument = "typename std::reverse_iterator<const_iterator>",
                    },
                },
                .operations =
                {
                    operation
                    {
                        .name = "operator=",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "std::initializer_list<T>",
                                .name = "ilist",
                            },
                        },
                        .result = "*this",
                    },
                    operation
                    {
                        .name = "assign",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "size_t",
                                .name = "count",
                            },
                            parameter
                            {
                                .type = "T const &",
                                .name = "value",
                            },
                        },
                        .result = "void",
                    },
                    operation
                    {
                        .name = "assign",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "forward_const_iterator<T>",
                                .name = "first",
                            },
                            parameter
                            {
                                .type = "forward_const_iterator<T>",
                                .name = "last",
                            },
                        },
                        .result = "void",
                    },
                    operation
                    {
                        .name = "assign",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "std::initializer_list<T>",
                                .name = "ilist",
                            },
                        },
                        .result = "void",
                    },
                    operation
                    {
                        .name = "at",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "size_t",
                                .name = "pos",
                            },
                        },
                        .result = "T &",
                    },
                    operation
                    {
                        .name = "at",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "size_t",
                                .name = "pos",
                            },
                        },
                        .constness = true,
                        .result = "T const &",
                    },
                    operation
                    {
                        .name = "operator[]",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "size_t",
                                .name = "pos",
                            },
                        },
                        .result = "T &",
                    },
                    operation
                    {
                        .name = "operator[]",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "size_t",
                                .name = "pos",
                            },
                        },
                        .constness = true,
                        .result = "T const &",
                    },
                    operation
                    {
                        .name = "front",
                        .result = "T &",
                    },
                    operation
                    {
                        .name = "front",
                        .constness = true,
                        .result = "T const &",
                    },
                    operation
                    {
                        .name = "back",
                        .result = "T &",
                    },
                    operation
                    {
                        .name = "back",
                        .constness = true,
                        .result = "T const &",
                    },
                    operation
                    {
                        .name = "data",
                        .result = "T *",
                    },
                    operation
                    {
                        .name = "data",
                        .constness = true,
                        .result = "T const *",
                    },
                    operation
                    {
                        .name = "begin",
                        .result = "typename strange::random_access_iterator<T>",
                        .customisation = "return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.begin())",
                    },
                    operation
                    {
                        .name = "begin",
                        .constness = true,
                        .result = "typename strange::random_access_const_iterator<T>",
                        .customisation = "return random_access_const_iterator<T>::template _make<decltype(_thing.cbegin())>(_thing.cbegin())",
                    },
                    operation
                    {
                        .name = "cbegin",
                        .constness = true,
                        .result = "typename strange::random_access_const_iterator<T>",
                        .customisation = "return random_access_const_iterator<T>::template _make<decltype(_thing.cbegin())>(_thing.cbegin())",
                    },
                    operation
                    {
                        .name = "end",
                        .result = "typename strange::random_access_iterator<T>",
                        .customisation = "return random_access_iterator<T>::template _make<decltype(_thing.end())>(_thing.end())",
                    },
                    operation
                    {
                        .name = "end",
                        .constness = true,
                        .result = "typename strange::random_access_const_iterator<T>",
                        .customisation = "return random_access_const_iterator<T>::template _make<decltype(_thing.cend())>(_thing.cend())",
                    },
                    operation
                    {
                        .name = "cend",
                        .constness = true,
                        .result = "typename strange::random_access_const_iterator<T>",
                        .customisation = "return random_access_const_iterator<T>::template _make<decltype(_thing.cend())>(_thing.cend())",
                    },
                    operation
                    {
                        .name = "rbegin",
                        .result = "typename std::reverse_iterator<strange::random_access_iterator<T>>",
                        .customisation = "return typename std::reverse_iterator<strange::random_access_iterator<T>>{random_access_iterator<T>::template _make<decltype(_thing.end())>(_thing.end())}",
                    },
                    operation
                    {
                        .name = "rbegin",
                        .constness = true,
                        .result = "typename std::reverse_iterator<strange::random_access_const_iterator<T>>",
                        .customisation = "return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{random_access_const_iterator<T>::template _make<decltype(_thing.cend())>(_thing.cend())}",
                    },
                    operation
                    {
                        .name = "crbegin",
                        .constness = true,
                        .result = "typename std::reverse_iterator<strange::random_access_const_iterator<T>>",
                        .customisation = "return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{random_access_const_iterator<T>::template _make<decltype(_thing.cend())>(_thing.cend())}",
                    },
                    operation
                    {
                        .name = "rend",
                        .result = "typename std::reverse_iterator<strange::random_access_iterator<T>>",
                        .customisation = "return typename std::reverse_iterator<strange::random_access_iterator<T>>{random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.begin())}",
                    },
                    operation
                    {
                        .name = "rend",
                        .constness = true,
                        .result = "typename std::reverse_iterator<strange::random_access_const_iterator<T>>",
                        .customisation = "return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{random_access_const_iterator<T>::template _make<decltype(_thing.cbegin())>(_thing.cbegin())}",
                    },
                    operation
                    {
                        .name = "crend",
                        .constness = true,
                        .result = "typename std::reverse_iterator<strange::random_access_const_iterator<T>>",
                        .customisation = "return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{random_access_const_iterator<T>::template _make<decltype(_thing.cbegin())>(_thing.cbegin())}",
                    },
                    operation
                    {
                        .name = "empty",
                        .constness = true,
                        .result = "bool",
                    },
                    operation
                    {
                        .name = "size",
                        .constness = true,
                        .result = "size_t",
                    },
                    operation
                    {
                        .name = "max_size",
                        .constness = true,
                        .result = "size_t",
                    },
                    operation
                    {
                        .name = "reserve",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "size_t",
                                .name = "new_cap",
                            },
                        },
                        .result = "void",
                    },
                    operation
                    {
                        .name = "capacity",
                        .constness = true,
                        .result = "size_t",
                    },
                    operation
                    {
                        .name = "shrink_to_fit",
                        .result = "void",
                    },
                    operation
                    {
                        .name = "clear",
                        .result = "void",
                    },
                    operation
                    {
                        .name = "insert",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "typename strange::random_access_const_iterator<T>",
                                .name = "pos",
                            },
                            parameter
                            {
                                .type = "T const &",
                                .name = "value",
                            },
                        },
                        .result = "typename strange::random_access_iterator<T>",
                        .modification = R"#(auto const index = pos - cbegin();
    strange::_common::_mutate(); // could invalidate iterators
    pos = cbegin() + index;
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, value);)#",
                        .customisation = "return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), value))",
                    },
                    operation
                    {
                        .name = "insert",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "typename strange::random_access_const_iterator<T>",
                                .name = "pos",
                            },
                            parameter
                            {
                                .type = "T &&",
                                .name = "value",
                            },
                        },
                        .result = "typename strange::random_access_iterator<T>",
                        .modification = R"#(auto const index = pos - cbegin();
    strange::_common::_mutate(); // could invalidate iterators
    pos = cbegin() + index;
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, std::move(value));)#",
                        .customisation = "return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), std::move(value)))",
                    },
                    operation
                    {
                        .name = "insert",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "typename strange::random_access_const_iterator<T>",
                                .name = "pos",
                            },
                            parameter
                            {
                                .type = "size_t",
                                .name = "count",
                            },
                            parameter
                            {
                                .type = "T const &",
                                .name = "value",
                            },
                        },
                        .result = "typename strange::random_access_iterator<T>",
                        .modification = R"#(auto const index = pos - cbegin();
    strange::_common::_mutate(); // could invalidate iterators
    pos = cbegin() + index;
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, count, value);)#",
                        .customisation = "return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), count, value))",
                    },
                    operation
                    {
                        .name = "insert",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "typename strange::random_access_const_iterator<T>",
                                .name = "pos",
                            },
                            parameter
                            {
                                .type = "forward_const_iterator<T>",
                                .name = "first",
                            },
                            parameter
                            {
                                .type = "forward_const_iterator<T>",
                                .name = "last",
                            },
                        },
                        .result = "typename strange::random_access_iterator<T>",
                        .modification = R"#(auto const index = pos - cbegin();
    strange::_common::_mutate(); // could invalidate iterators
    pos = cbegin() + index;
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, first, last);)#",
                        .customisation = "return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), first, last))",
                    },
                    operation
                    {
                        .name = "insert",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "typename strange::random_access_const_iterator<T>",
                                .name = "pos",
                            },
                            parameter
                            {
                                .type = "std::initializer_list<T>",
                                .name = "ilist",
                            },
                        },
                        .result = "typename strange::random_access_iterator<T>",
                        .modification = R"#(auto const index = pos - cbegin();
    strange::_common::_mutate(); // could invalidate iterators
    pos = cbegin() + index;
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, ilist);)#",
                        .customisation = "return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), ilist))",
                    },
                    operation
                    {
                        .name = "erase",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "typename strange::random_access_const_iterator<T>",
                                .name = "pos",
                            },
                        },
                        .result = "typename strange::random_access_iterator<T>",
                        .modification = R"#(auto const index = pos - cbegin();
    strange::_common::_mutate(); // could invalidate iterators
    pos = cbegin() + index;
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->erase(pos);)#",
                        .customisation = "return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.erase(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing()))",
                    },
                    operation
                    {
                        .name = "erase",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "typename strange::random_access_const_iterator<T>",
                                .name = "first",
                            },
                            parameter
                            {
                                .type = "typename strange::random_access_const_iterator<T>",
                                .name = "last",
                            },
                        },
                        .result = "typename strange::random_access_iterator<T>",
                        .modification = R"#(auto const first_index = first - cbegin();
    auto const last_index = last - cbegin();
    strange::_common::_mutate(); // could invalidate iterators
    first = cbegin() + first_index;
    last = cbegin() + last_index;
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->erase(first, last);)#",
                        .customisation = "return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.erase(first.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), last.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing()))",
                    },
                    operation
                    {
                        .name = "push_back",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "T const &",
                                .name = "value",
                            },
                        },
                        .result = "void",
                    },
                    operation
                    {
                        .name = "push_back",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "T &&",
                                .name = "value",
                            },
                        },
                        .result = "void",
                    },
                    operation
                    {
                        .name = "pop_back",
                        .result = "void",
                    },
                    operation
                    {
                        .name = "resize",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "size_t",
                                .name = "count",
                            },
                        },
                        .result = "void",
                    },
                    operation
                    {
                        .name = "resize",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "size_t",
                                .name = "count",
                            },
                            parameter
                            {
                                .type = "T const &",
                                .name = "value",
                            },
                        },
                        .result = "void",
                    },
                    operation
                    {
                        .name = "swap",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "vector<T> &",
                                .name = "other",
                            },
                        },
                        .result = "void",
                        .customisation = "_thing.swap(other.template _static<vector_<T, _Thing, _Copy>>()._thing())"
                    },
                    operation
                    {
                        .name = "operator==",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "vector<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing == other.template _static<vector_<T, _Thing, _Copy>>()._thing()",
                    },
                    operation
                    {
                        .name = "operator!=",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "vector<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing != other.template _static<vector_<T, _Thing, _Copy>>()._thing()",
                    },
                    operation
                    {
                        .name = "operator<",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "vector<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing < other.template _static<vector_<T, _Thing, _Copy>>()._thing()",
                    },
                    operation
                    {
                        .name = "operator>",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "vector<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing > other.template _static<vector_<T, _Thing, _Copy>>()._thing()",
                    },
                    operation
                    {
                        .name = "operator<=",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "vector<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing <= other.template _static<vector_<T, _Thing, _Copy>>()._thing()",
                    },
                    operation
                    {
                        .name = "operator>=",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "vector<T> const &",
                                .name = "other",
                            },
                        },
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing >= other.template _static<vector_<T, _Thing, _Copy>>()._thing()",
                    },
                },
                .thing = "std::vector<T>",
            },
        },
    };
}
}
}