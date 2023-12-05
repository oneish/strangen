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
                .name = "vector",
                .parents =
                {
                    "any",
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
                                .type = "std::vector<T> const &",
                                .name = "other",
                            },
                        },
                        .result = "*this",
                    },
                    operation
                    {
                        .name = "operator=",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "std::vector<T> &&",
                                .name = "other",
                            },
                        },
                        .result = "*this",
                    },
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
                        .result = "typename std::vector<T>::iterator",
                    },
                    operation
                    {
                        .name = "begin",
                        .constness = true,
                        .result = "typename std::vector<T>::const_iterator",
                    },
                    operation
                    {
                        .name = "cbegin",
                        .constness = true,
                        .result = "typename std::vector<T>::const_iterator",
                    },
                    operation
                    {
                        .name = "end",
                        .result = "typename std::vector<T>::iterator",
                    },
                    operation
                    {
                        .name = "end",
                        .constness = true,
                        .result = "typename std::vector<T>::const_iterator",
                    },
                    operation
                    {
                        .name = "cend",
                        .constness = true,
                        .result = "typename std::vector<T>::const_iterator",
                    },
                    operation
                    {
                        .name = "rbegin",
                        .result = "typename std::vector<T>::reverse_iterator",
                    },
                    operation
                    {
                        .name = "rbegin",
                        .constness = true,
                        .result = "typename std::vector<T>::const_reverse_iterator",
                    },
                    operation
                    {
                        .name = "crbegin",
                        .constness = true,
                        .result = "typename std::vector<T>::const_reverse_iterator",
                    },
                    operation
                    {
                        .name = "rend",
                        .result = "typename std::vector<T>::reverse_iterator",
                    },
                    operation
                    {
                        .name = "rend",
                        .constness = true,
                        .result = "typename std::vector<T>::const_reverse_iterator",
                    },
                    operation
                    {
                        .name = "crend",
                        .constness = true,
                        .result = "typename std::vector<T>::const_reverse_iterator",
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
                                .type = "typename std::vector<T>::const_iterator",
                                .name = "pos",
                            },
                            parameter
                            {
                                .type = "T const &",
                                .name = "value",
                            },
                        },
                        .result = "typename std::vector<T>::iterator",
                    },
                    operation
                    {
                        .name = "insert",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "typename std::vector<T>::const_iterator",
                                .name = "pos",
                            },
                            parameter
                            {
                                .type = "T &&",
                                .name = "value",
                            },
                        },
                        .result = "typename std::vector<T>::iterator",
                    },
                    operation
                    {
                        .name = "insert",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "typename std::vector<T>::const_iterator",
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
                        .result = "typename std::vector<T>::iterator",
                    },
                    operation
                    {
                        .name = "insert",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "typename std::vector<T>::const_iterator",
                                .name = "pos",
                            },
                            parameter
                            {
                                .type = "std::initializer_list<T>",
                                .name = "ilist",
                            },
                        },
                        .result = "typename std::vector<T>::iterator",
                    },
                    operation
                    {
                        .name = "erase",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "typename std::vector<T>::const_iterator",
                                .name = "pos",
                            },
                        },
                        .result = "typename std::vector<T>::iterator",
                    },
                    operation
                    {
                        .name = "erase",
                        .parameters =
                        {
                            parameter
                            {
                                .type = "typename std::vector<T>::const_iterator",
                                .name = "first",
                            },
                            parameter
                            {
                                .type = "typename std::vector<T>::const_iterator",
                                .name = "last",
                            },
                        },
                        .result = "typename std::vector<T>::iterator",
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
                                .type = "std::vector<T> &",
                                .name = "other",
                            },
                        },
                        .result = "void",
                    },
                },
                .thing = "std::vector<T>",
            },
        },
    };
}
}
}