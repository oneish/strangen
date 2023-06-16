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
                            .name = "modify",
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
            },
        };
    }
}