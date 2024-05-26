#pragma once
#include "../../sauce/strange/definition/strange__definition__space.h"

/*
namespace example
{
struct widget
{
    virtual auto display(button b = button()) const -> void = 0;
    virtual auto inc() -> void = 0;
    virtual auto operator++() -> widget & = 0;
    virtual auto operator--(int) -> widget = 0;
};

struct button : widget
{
    virtual auto push() -> void = 0;
};

struct number
{
    virtual auto inc() -> void = 0;
    virtual auto dec() -> void = 0;
};

struct widget_number : widget, number
{
};

template<typename Data = int>
struct numeric
{
    virtual auto get() const -> Data = 0;
    virtual auto x() const -> Data const & = 0;
    virtual auto x() -> Data & = 0;
};
}
*/

namespace example
{
namespace meta
{
using strange::definition::space;
using strange::definition::abstraction;
using strange::definition::operation;

inline auto parameter(strange::definition::parameter param) -> strange::parameter
{
    return strange::parameter::_make(param);
}

inline auto parameters(std::vector<strange::parameter> params) -> strange::vector<strange::parameter>
{
    return strange::vector<strange::parameter>::_make(params);
}

auto definition() -> space
{
    return space
    {
        .name = "example",
        .abstractions =
        {
            abstraction
            {
                .name = "widget",
                .operations =
                {
                    operation
                    {
                        .name = "display",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "button",
                                .name = "b",
                                .argument = "button()",
                            }),
                        }),
                        .constness = true,
                        .result = "void",
                    },
                    operation
                    {
                        .name = "inc",
                        .result = "void",
                    },
                    operation
                    {
                        .name = "operator++",
                        .result = "*this",
                    },
                    operation
                    {
                        .name = "operator--",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "int",
                                .name = "i",
                            }),
                        }),
                        .result = "*that",
                    },
                },
            },
            abstraction
            {
                .name = "button",
                .parents =
                {
                    "widget",
                },
                .operations =
                {
                    operation
                    {
                        .name = "push",
                        .result = "void",
                    },
                },
            },
            abstraction
            {
                .name = "number",
                .operations =
                {
                    operation
                    {
                        .name = "inc",
                        .result = "void",
                    },
                    operation
                    {
                        .name = "dec",
                        .result = "void",
                    },
                },
            },
            abstraction
            {
                .name = "widget_number",
                .parents =
                {
                    "widget",
                    "number",
                },
            },
            abstraction
            {
                .parameters = parameters
                ({
                    parameter
                    ({
                        .type = "typename",
                        .name = "Data",
                        .argument = "int",
                    }),
                }),
                .name = "numeric",
                .parents =
                {
                    "number",
                },
                .operations =
                {
                    operation
                    {
                        .name = "get",
                        .constness = true,
                        .result = "Data",
                    },
                    operation
                    {
                        .name = "x",
                        .constness = true,
                        .result = "Data const &",
                        .data = true,
                    },
                    operation
                    {
                        .name = "x",
                        .result = "Data &",
                        .data = true,
                    },
                },
            },
        },
    };
}
}
}
