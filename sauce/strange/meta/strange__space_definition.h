#pragma once
#include "../strange.h"

/*
namespace strange
{
struct parameter_a
{
    virtual auto type() const -> std::string const & = 0;
    virtual auto type() -> std::string & = 0;

    virtual auto name() const -> std::string const & = 0;
    virtual auto name() -> std::string & = 0;

    virtual auto argument() const -> std::string const & = 0;
    virtual auto argument() -> std::string & = 0;
};

struct operation_a
{
    virtual auto name() const -> std::string const & = 0;
    virtual auto name() -> std::string & = 0;

    virtual auto parameters() const -> std::vector<parameter_a> const & = 0;
    virtual auto parameters() -> std::vector<parameter_a> & = 0;

    virtual auto constness() const -> bool const & = 0;
    virtual auto constness() -> bool & = 0;

    virtual auto result() const -> std::string const & = 0;
    virtual auto result() -> std::string & = 0;

    virtual auto data() const -> bool const & = 0;
    virtual auto data() -> bool & = 0;
};

struct abstraction_a
{
    virtual auto parameters() const -> std::vector<parameter_a> const & = 0;
    virtual auto parameters() -> std::vector<parameter_a> & = 0;

    virtual auto name() const -> std::string const & = 0;
    virtual auto name() -> std::string & = 0;

    virtual auto parents() const -> std::vector<std::string> const & = 0;
    virtual auto parents() -> std::vector<std::string> & = 0;

    virtual auto operations() const -> std::vector<operation_a> const & = 0;
    virtual auto operations() -> std::vector<operation_a> & = 0;
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
                    strange::make_operation
                    ({
                        .name = "type",
                        .constness = true,
                        .result = "std::string const &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "type",
                        .result = "std::string &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "name",
                        .constness = true,
                        .result = "std::string const &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "name",
                        .result = "std::string &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "argument",
                        .constness = true,
                        .result = "std::string const &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "argument",
                        .result = "std::string &",
                        .data = true,
                    }),
                },
            },
            {
                // abstraction
                .name = "operation_a",
                .operations =
                {
                    strange::make_operation
                    ({
                        .name = "name",
                        .constness = true,
                        .result = "std::string const &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "name",
                        .result = "std::string &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "parameters",
                        .constness = true,
                        .result = "std::vector<parameter_a> const &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "parameters",
                        .result = "std::vector<parameter_a> &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "constness",
                        .constness = true,
                        .result = "bool const &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "constness",
                        .result = "bool &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "result",
                        .constness = true,
                        .result = "std::string const &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "result",
                        .result = "std::string &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "data",
                        .constness = true,
                        .result = "bool const &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "data",
                        .result = "bool &",
                        .data = true,
                    }),
                },
            },
            {
                // abstraction
                .name = "abstraction_a",
                .operations =
                {
                    strange::make_operation
                    ({
                        .name = "parameters",
                        .constness = true,
                        .result = "std::vector<parameter_a> const &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "parameters",
                        .result = "std::vector<parameter_a> &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "name",
                        .constness = true,
                        .result = "std::string const &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "name",
                        .result = "std::string &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "parents",
                        .constness = true,
                        .result = "std::vector<std::string> const &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "parents",
                        .result = "std::vector<std::string> &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "operations",
                        .constness = true,
                        .result = "std::vector<operation_a> const &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "operations",
                        .result = "std::vector<operation_a> &",
                        .data = true,
                    }),
                },
            },
        },
    };
}
}
}