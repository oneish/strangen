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

struct space_a
{
    virtual auto name() const -> std::string const & = 0;
    virtual auto name() -> std::string & = 0;

    virtual auto abstractions() const -> std::vector<abstraction_a> const & = 0;
    virtual auto abstractions() -> std::vector<abstraction_a> & = 0;
}
}
*/

namespace strange
{
namespace meta
{
auto definition() -> strange::space_a
{
    return strange::make_space
    ({
        .name = "strange",
        .abstractions =
        {
            strange::make_abstraction
            ({
                .parameters =
                {
                    strange::make_parameter
                    ({
                        .type = "typename",
                        .name = "T",
                    }),
                },
                .name = "vector_a",
                .operations =
                {
                    strange::make_operation
                    ({
                        .name = "operator=",
                        .parameters =
                        {
                            strange::make_parameter
                            ({
                                .type = "std::vector<T> const &",
                                .name = "other",
                            }),
                        },
                        .result = "*this",
                    }),
                    strange::make_operation
                    ({
                        .name = "operator=",
                        .parameters =
                        {
                            strange::make_parameter
                            ({
                                .type = "std::vector<T> &&",
                                .name = "other",
                            }),
                        },
                        .result = "*this",
                    }),
                    strange::make_operation
                    ({
                        .name = "operator=",
                        .parameters =
                        {
                            strange::make_parameter
                            ({
                                .type = "std::initializer_list<T>",
                                .name = "ilist",
                            }),
                        },
                        .result = "*this",
                    }),
                    strange::make_operation
                    ({
                        .name = "assign",
                        .parameters =
                        {
                            strange::make_parameter
                            ({
                                .type = "size_t",
                                .name = "count",
                            }),
                            strange::make_parameter
                            ({
                                .type = "T const &",
                                .name = "value",
                            }),
                        },
                        .result = "void",
                    }),
                    strange::make_operation
                    ({
                        .name = "assign",
                        .parameters =
                        {
                            strange::make_parameter
                            ({
                                .type = "std::initializer_list<T>",
                                .name = "ilist",
                            }),
                        },
                        .result = "void",
                    }),
                    strange::make_operation
                    ({
                        .name = "at",
                        .parameters =
                        {
                            strange::make_parameter
                            ({
                                .type = "size_t",
                                .name = "pos",
                            }),
                        },
                        .result = "T &",
                    }),
                    strange::make_operation
                    ({
                        .name = "at",
                        .parameters =
                        {
                            strange::make_parameter
                            ({
                                .type = "size_t",
                                .name = "pos",
                            }),
                        },
                        .constness = true,
                        .result = "T const &",
                    }),
                    strange::make_operation
                    ({
                        .name = "operator[]",
                        .parameters =
                        {
                            strange::make_parameter
                            ({
                                .type = "size_t",
                                .name = "pos",
                            }),
                        },
                        .result = "T &",
                    }),
                    strange::make_operation
                    ({
                        .name = "operator[]",
                        .parameters =
                        {
                            strange::make_parameter
                            ({
                                .type = "size_t",
                                .name = "pos",
                            }),
                        },
                        .constness = true,
                        .result = "T const &",
                    }),
                },
            }),
            strange::make_abstraction
            ({
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
            }),
            strange::make_abstraction
            ({
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
            }),
            strange::make_abstraction
            ({
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
            }),
            strange::make_abstraction
            ({
                .name = "space_a",
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
                        .name = "abstractions",
                        .constness = true,
                        .result = "std::vector<abstraction_a> const &",
                        .data = true,
                    }),
                    strange::make_operation
                    ({
                        .name = "abstractions",
                        .result = "std::vector<abstraction_a> &",
                        .data = true,
                    }),
                },
            }),
        },
    });
}
}
}