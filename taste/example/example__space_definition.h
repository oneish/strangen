#pragma once
#include "../../sauce/strange/strange.h"

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
strange::definition::space definition()
{
    return
    {
        // space
        .name = "example",
        .abstractions =
        {
            {
                // abstraction
                .name = "widget",
                .operations =
                {
                    strange::make_operation
                    ({
                        .name = "display",
                        .parameters =
                        {
                            strange::make_parameter
                            ({
                                .type = "button",
                                .name = "b",
                                .argument = "button()",
                            }),
                        },
                        .constness = true,
                        .result = "void",
                    }),
                    strange::make_operation
                    ({
                        .name = "inc",
                        .result = "void",
                    }),
                    strange::make_operation
                    ({
                        .name = "operator++",
                        .result = "*this",
                    }),
                    strange::make_operation
                    ({
                        .name = "operator--",
                        .parameters =
                        {
                            strange::make_parameter
                            ({
                                .type = "int",
                                .name = "i",
                            }),
                        },
                        .result = "*that",
                    }),
                },
            },
            {
                // abstraction
                .name = "button",
                .parents =
                {
                    "widget",
                },
                .operations =
                {
                    strange::make_operation
                    ({
                        .name = "push",
                        .result = "void",
                    }),
                },
            },
            {
                // abstraction
                .name = "number",
                .operations =
                {
                    strange::make_operation
                    ({
                        .name = "inc",
                        .result = "void",
                    }),
                    strange::make_operation
                    ({
                        .name = "dec",
                        .result = "void",
                    }),
                },
            },
            {
                // abstraction
                .name = "widget_number",
                .parents =
                {
                    "widget",
                    "number",
                },
            },
            {
                // abstraction
                .parameters =
                {
                    strange::make_parameter
                    ({
                        .type = "typename",
                        .name = "Data",
                        .argument = "int",
                    }),
                },
                .name = "numeric",
                .parents =
                {
                    "number",
                },
                .operations =
                {
                    strange::make_operation
                    ({
                        .name = "get",
                        .constness = true,
                        .result = "Data",
                    }),
                    strange::make_operation
                    ({
                        .name = "x",
                        .constness = true,
                        .result = "Data const &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "x",
                        .result = "Data &",
                        .data = true,
                    }),
                },
            },
        },
    };
}
}