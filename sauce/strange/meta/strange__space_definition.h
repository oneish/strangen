#pragma once
#include "../definition/strange__definition__space.h"

namespace strange
{
namespace meta
{
auto definition() -> strange::definition::space
{
    return strange::definition::space
    {
        .name = "strange",
        .abstractions =
        {
            strange::definition::abstraction
            {
                .name = "any_a",
            },
             strange::definition::abstraction
            {
                .parameters =
                {
                    strange::definition::parameter
                    {
                        .type = "typename",
                        .name = "T",
                    },
                },
                .name = "vector_a",
                .parents =
                {
                    "any_a",
                },
                .operations =
                {
                    strange::definition::operation
                    {
                        .name = "operator=",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "std::vector<T> const &",
                                .name = "other",
                            },
                        },
                        .result = "*this",
                    },
                    strange::definition::operation
                    {
                        .name = "operator=",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "std::vector<T> &&",
                                .name = "other",
                            },
                        },
                        .result = "*this",
                    },
                    strange::definition::operation
                    {
                        .name = "operator=",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "std::initializer_list<T>",
                                .name = "ilist",
                            },
                        },
                        .result = "*this",
                    },
                    strange::definition::operation
                    {
                        .name = "assign",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "size_t",
                                .name = "count",
                            },
                            strange::definition::parameter
                            {
                                .type = "T const &",
                                .name = "value",
                            },
                        },
                        .result = "void",
                    },
                    strange::definition::operation
                    {
                        .name = "assign",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "std::initializer_list<T>",
                                .name = "ilist",
                            },
                        },
                        .result = "void",
                    },
                    strange::definition::operation
                    {
                        .name = "at",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "size_t",
                                .name = "pos",
                            },
                        },
                        .result = "T &",
                    },
                    strange::definition::operation
                    {
                        .name = "at",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "size_t",
                                .name = "pos",
                            },
                        },
                        .constness = true,
                        .result = "T const &",
                    },
                    strange::definition::operation
                    {
                        .name = "operator[]",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "size_t",
                                .name = "pos",
                            },
                        },
                        .result = "T &",
                    },
                    strange::definition::operation
                    {
                        .name = "operator[]",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "size_t",
                                .name = "pos",
                            },
                        },
                        .constness = true,
                        .result = "T const &",
                    },
                    strange::definition::operation
                    {
                        .name = "front",
                        .result = "T &",
                    },
                    strange::definition::operation
                    {
                        .name = "front",
                        .constness = true,
                        .result = "T const &",
                    },
                    strange::definition::operation
                    {
                        .name = "back",
                        .result = "T &",
                    },
                    strange::definition::operation
                    {
                        .name = "back",
                        .constness = true,
                        .result = "T const &",
                    },
                    strange::definition::operation
                    {
                        .name = "data",
                        .result = "T *",
                    },
                    strange::definition::operation
                    {
                        .name = "data",
                        .constness = true,
                        .result = "T const *",
                    },
                    strange::definition::operation
                    {
                        .name = "begin",
                        .result = "typename std::vector<T>::iterator",
                    },
                    strange::definition::operation
                    {
                        .name = "begin",
                        .constness = true,
                        .result = "typename std::vector<T>::const_iterator",
                    },
                    strange::definition::operation
                    {
                        .name = "cbegin",
                        .constness = true,
                        .result = "typename std::vector<T>::const_iterator",
                    },
                    strange::definition::operation
                    {
                        .name = "end",
                        .result = "typename std::vector<T>::iterator",
                    },
                    strange::definition::operation
                    {
                        .name = "end",
                        .constness = true,
                        .result = "typename std::vector<T>::const_iterator",
                    },
                    strange::definition::operation
                    {
                        .name = "cend",
                        .constness = true,
                        .result = "typename std::vector<T>::const_iterator",
                    },
                    strange::definition::operation
                    {
                        .name = "rbegin",
                        .result = "typename std::vector<T>::reverse_iterator",
                    },
                    strange::definition::operation
                    {
                        .name = "rbegin",
                        .constness = true,
                        .result = "typename std::vector<T>::const_reverse_iterator",
                    },
                    strange::definition::operation
                    {
                        .name = "crbegin",
                        .constness = true,
                        .result = "typename std::vector<T>::const_reverse_iterator",
                    },
                    strange::definition::operation
                    {
                        .name = "rend",
                        .result = "typename std::vector<T>::reverse_iterator",
                    },
                    strange::definition::operation
                    {
                        .name = "rend",
                        .constness = true,
                        .result = "typename std::vector<T>::const_reverse_iterator",
                    },
                    strange::definition::operation
                    {
                        .name = "crend",
                        .constness = true,
                        .result = "typename std::vector<T>::const_reverse_iterator",
                    },
                    strange::definition::operation
                    {
                        .name = "empty",
                        .constness = true,
                        .result = "bool",
                    },
                    strange::definition::operation
                    {
                        .name = "size",
                        .constness = true,
                        .result = "size_t",
                    },
                    strange::definition::operation
                    {
                        .name = "max_size",
                        .constness = true,
                        .result = "size_t",
                    },
                    strange::definition::operation
                    {
                        .name = "reserve",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "size_t",
                                .name = "new_cap",
                            },
                        },
                        .result = "void",
                    },
                    strange::definition::operation
                    {
                        .name = "capacity",
                        .constness = true,
                        .result = "size_t",
                    },
                    strange::definition::operation
                    {
                        .name = "shrink_to_fit",
                        .result = "void",
                    },
                    strange::definition::operation
                    {
                        .name = "clear",
                        .result = "void",
                    },
                    strange::definition::operation
                    {
                        .name = "insert",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "typename std::vector<T>::const_iterator",
                                .name = "pos",
                            },
                            strange::definition::parameter
                            {
                                .type = "T const &",
                                .name = "value",
                            },
                        },
                        .result = "typename std::vector<T>::iterator",
                    },
                    strange::definition::operation
                    {
                        .name = "insert",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "typename std::vector<T>::const_iterator",
                                .name = "pos",
                            },
                            strange::definition::parameter
                            {
                                .type = "T &&",
                                .name = "value",
                            },
                        },
                        .result = "typename std::vector<T>::iterator",
                    },
                    strange::definition::operation
                    {
                        .name = "insert",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "typename std::vector<T>::const_iterator",
                                .name = "pos",
                            },
                            strange::definition::parameter
                            {
                                .type = "size_t",
                                .name = "count",
                            },
                            strange::definition::parameter
                            {
                                .type = "T const &",
                                .name = "value",
                            },
                        },
                        .result = "typename std::vector<T>::iterator",
                    },
                    strange::definition::operation
                    {
                        .name = "insert",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "typename std::vector<T>::const_iterator",
                                .name = "pos",
                            },
                            strange::definition::parameter
                            {
                                .type = "std::initializer_list<T>",
                                .name = "ilist",
                            },
                        },
                        .result = "typename std::vector<T>::iterator",
                    },
                    strange::definition::operation
                    {
                        .name = "erase",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "typename std::vector<T>::const_iterator",
                                .name = "pos",
                            },
                        },
                        .result = "typename std::vector<T>::iterator",
                    },
                    strange::definition::operation
                    {
                        .name = "erase",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "typename std::vector<T>::const_iterator",
                                .name = "first",
                            },
                            strange::definition::parameter
                            {
                                .type = "typename std::vector<T>::const_iterator",
                                .name = "last",
                            },
                        },
                        .result = "typename std::vector<T>::iterator",
                    },
                    strange::definition::operation
                    {
                        .name = "push_back",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "T const &",
                                .name = "value",
                            },
                        },
                        .result = "void",
                    },
                    strange::definition::operation
                    {
                        .name = "push_back",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "T &&",
                                .name = "value",
                            },
                        },
                        .result = "void",
                    },
                    strange::definition::operation
                    {
                        .name = "pop_back",
                        .result = "void",
                    },
                    strange::definition::operation
                    {
                        .name = "resize",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "size_t",
                                .name = "count",
                            },
                        },
                        .result = "void",
                    },
                    strange::definition::operation
                    {
                        .name = "resize",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "size_t",
                                .name = "count",
                            },
                            strange::definition::parameter
                            {
                                .type = "T const &",
                                .name = "value",
                            },
                        },
                        .result = "void",
                    },
                    strange::definition::operation
                    {
                        .name = "swap",
                        .parameters =
                        {
                            strange::definition::parameter
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