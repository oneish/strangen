#pragma once
#include "../strange/definition/strange__space.h"

namespace example
{
    strange::space definition()
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
                        {
                            // operation
                            .name = "display",
                            .parameters =
                            {
                                {
                                    // parameter
                                    .type = "button",
                                    .name = "b",
                                    .argument = "button()",
                                },
                            },
                            .constness = true,
                            .result = "void",
                        },
                        {
                            // operation
                            .name = "inc",
                            .result = "void",
                        },
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
                        {
                            // operation
                            .name = "push",
                            .result = "void",
                        },
                    },
                },
                {
                    // abstraction
                    .name = "number",
                    .operations =
                    {
                        {
                            // operation
                            .name = "inc",
                            .result = "void",
                        },
                        {
                            // operation
                            .name = "dec",
                            .result = "void",
                        },
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
                        {
                            // parameter
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
                        {
                            .name = "get",
                            .constness = true,
                            .result = "Data",
                        },
                    },
                },
            },
        };
    }
}