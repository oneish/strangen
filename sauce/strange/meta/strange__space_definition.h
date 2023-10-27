#pragma once
#include "../definition/strange__definition__space.h"

/*
namespace strange
{

struct parameter
{
    virtual auto type() const -> std::string const & = 0;
    virtual auto type() -> std::string & = 0;

    virtual auto name() const -> std::string const & = 0;
    virtual auto name() -> std::string & = 0;

    virtual auto argument() const -> std::string const & = 0;
    virtual auto argument() -> std::string & = 0;
};

}
*/

namespace strange
{
namespace meta
{
    definition::space definition()
    {
        return
        {
            // space
            .name = "strange",
            .abstractions =
            {
                {
                    // abstraction
                    .name = "parameter_a",
                    .operations =
                    {
                        {
                            .name = "type",
                            .constness = true,
                            .result = "std::string const &",
                            .data = true,
                        },
                        {
                            .name = "type",
                            .result = "std::string &",
                            .data = true,
                        },
                        {
                            .name = "name",
                            .constness = true,
                            .result = "std::string const &",
                            .data = true,
                        },
                        {
                            .name = "name",
                            .result = "std::string &",
                            .data = true,
                        },
                        {
                            .name = "argument",
                            .constness = true,
                            .result = "std::string const &",
                            .data = true,
                        },
                        {
                            .name = "argument",
                            .result = "std::string &",
                            .data = true,
                        },
                    },
                },
            },
        };
    }
}
}