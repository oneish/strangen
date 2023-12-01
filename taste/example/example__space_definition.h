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
auto definition() -> strange::definition::space
{
    return strange::definition::space
    {
        .name = "example",
        .abstractions =
        {
            strange::definition::abstraction
            {
                .name = "widget",
                .operations =
                {
                    strange::definition::operation
                    {
                        .name = "display",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "button",
                                .name = "b",
                                .argument = "button()",
                            },
                        },
                        .constness = true,
                        .result = "void",
                    },
                    strange::definition::operation
                    {
                        .name = "inc",
                        .result = "void",
                    },
                    strange::definition::operation
                    {
                        .name = "operator++",
                        .result = "*this",
                    },
                    strange::definition::operation
                    {
                        .name = "operator--",
                        .parameters =
                        {
                            strange::definition::parameter
                            {
                                .type = "int",
                                .name = "i",
                            },
                        },
                        .result = "*that",
                    },
                },
            },
            strange::definition::abstraction
            {
                .name = "button",
                .parents =
                {
                    "widget",
                },
                .operations =
                {
                    strange::definition::operation
                    {
                        .name = "push",
                        .result = "void",
                    },
                },
            },
            strange::definition::abstraction
            {
                .name = "number",
                .operations =
                {
                    strange::definition::operation
                    {
                        .name = "inc",
                        .result = "void",
                    },
                    strange::definition::operation
                    {
                        .name = "dec",
                        .result = "void",
                    },
                },
            },
            strange::definition::abstraction
            {
                .name = "widget_number",
                .parents =
                {
                    "widget",
                    "number",
                },
            },
            strange::definition::abstraction
            {
                .parameters =
                {
                    strange::definition::parameter
                    {
                        .type = "typename",
                        .name = "Data",
                        .argument = "int",
                    },
                },
                .name = "numeric",
                .parents =
                {
                    "number",
                },
                .operations =
                {
                    strange::definition::operation
                    {
                        .name = "get",
                        .constness = true,
                        .result = "Data",
                    },
                    strange::definition::operation
                    {
                        .name = "x",
                        .constness = true,
                        .result = "Data const &",
                        .data = true,
                    },
                    strange::definition::operation
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