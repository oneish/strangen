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
                    strange::make_operation
                    ({
                        .name = "front",
                        .result = "T &",
                    }),
                    strange::make_operation
                    ({
                        .name = "front",
                        .constness = true,
                        .result = "T const &",
                    }),
                    strange::make_operation
                    ({
                        .name = "back",
                        .result = "T &",
                    }),
                    strange::make_operation
                    ({
                        .name = "back",
                        .constness = true,
                        .result = "T const &",
                    }),
                    strange::make_operation
                    ({
                        .name = "data",
                        .result = "T *",
                    }),
                    strange::make_operation
                    ({
                        .name = "data",
                        .constness = true,
                        .result = "T const *",
                    }),
                    strange::make_operation
                    ({
                        .name = "begin",
                        .result = "typename std::vector<T>::iterator",
                    }),
                    strange::make_operation
                    ({
                        .name = "begin",
                        .constness = true,
                        .result = "typename std::vector<T>::const_iterator",
                    }),
                    strange::make_operation
                    ({
                        .name = "cbegin",
                        .constness = true,
                        .result = "typename std::vector<T>::const_iterator",
                    }),
                    strange::make_operation
                    ({
                        .name = "end",
                        .result = "typename std::vector<T>::iterator",
                    }),
                    strange::make_operation
                    ({
                        .name = "end",
                        .constness = true,
                        .result = "typename std::vector<T>::const_iterator",
                    }),
                    strange::make_operation
                    ({
                        .name = "cend",
                        .constness = true,
                        .result = "typename std::vector<T>::const_iterator",
                    }),
                    strange::make_operation
                    ({
                        .name = "rbegin",
                        .result = "typename std::vector<T>::reverse_iterator",
                    }),
                    strange::make_operation
                    ({
                        .name = "rbegin",
                        .constness = true,
                        .result = "typename std::vector<T>::const_reverse_iterator",
                    }),
                    strange::make_operation
                    ({
                        .name = "crbegin",
                        .constness = true,
                        .result = "typename std::vector<T>::const_reverse_iterator",
                    }),
                    strange::make_operation
                    ({
                        .name = "rend",
                        .result = "typename std::vector<T>::reverse_iterator",
                    }),
                    strange::make_operation
                    ({
                        .name = "rend",
                        .constness = true,
                        .result = "typename std::vector<T>::const_reverse_iterator",
                    }),
                    strange::make_operation
                    ({
                        .name = "crend",
                        .constness = true,
                        .result = "typename std::vector<T>::const_reverse_iterator",
                    }),
                    strange::make_operation
                    ({
                        .name = "empty",
                        .constness = true,
                        .result = "bool",
                    }),
                    strange::make_operation
                    ({
                        .name = "size",
                        .constness = true,
                        .result = "size_t",
                    }),
                    strange::make_operation
                    ({
                        .name = "max_size",
                        .constness = true,
                        .result = "size_t",
                    }),
                    strange::make_operation
                    ({
                        .name = "reserve",
                        .parameters =
                        {
                            strange::make_parameter
                            ({
                                .type = "size_t",
                                .name = "new_cap",
                            }),
                        },
                        .result = "void",
                    }),
                    strange::make_operation
                    ({
                        .name = "capacity",
                        .constness = true,
                        .result = "size_t",
                    }),
                    strange::make_operation
                    ({
                        .name = "shrink_to_fit",
                        .result = "void",
                    }),
                    strange::make_operation
                    ({
                        .name = "clear",
                        .result = "void",
                    }),
                    strange::make_operation
                    ({
                        .name = "insert",
                        .parameters =
                        {
                            strange::make_parameter
                            ({
                                .type = "typename std::vector<T>::const_iterator",
                                .name = "pos",
                            }),
                            strange::make_parameter
                            ({
                                .type = "T const &",
                                .name = "value",
                            }),
                        },
                        .result = "typename std::vector<T>::iterator",
                    }),
                    strange::make_operation
                    ({
                        .name = "insert",
                        .parameters =
                        {
                            strange::make_parameter
                            ({
                                .type = "typename std::vector<T>::const_iterator",
                                .name = "pos",
                            }),
                            strange::make_parameter
                            ({
                                .type = "T &&",
                                .name = "value",
                            }),
                        },
                        .result = "typename std::vector<T>::iterator",
                    }),
                    strange::make_operation
                    ({
                        .name = "insert",
                        .parameters =
                        {
                            strange::make_parameter
                            ({
                                .type = "typename std::vector<T>::const_iterator",
                                .name = "pos",
                            }),
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
                        .result = "typename std::vector<T>::iterator",
                    }),
                    strange::make_operation
                    ({
                        .name = "insert",
                        .parameters =
                        {
                            strange::make_parameter
                            ({
                                .type = "typename std::vector<T>::const_iterator",
                                .name = "pos",
                            }),
                            strange::make_parameter
                            ({
                                .type = "std::initializer_list<T>",
                                .name = "ilist",
                            }),
                        },
                        .result = "typename std::vector<T>::iterator",
                    }),
                    strange::make_operation
                    ({
                        .name = "erase",
                        .parameters =
                        {
                            strange::make_parameter
                            ({
                                .type = "typename std::vector<T>::const_iterator",
                                .name = "pos",
                            }),
                        },
                        .result = "typename std::vector<T>::iterator",
                    }),
                    strange::make_operation
                    ({
                        .name = "erase",
                        .parameters =
                        {
                            strange::make_parameter
                            ({
                                .type = "typename std::vector<T>::const_iterator",
                                .name = "first",
                            }),
                            strange::make_parameter
                            ({
                                .type = "typename std::vector<T>::const_iterator",
                                .name = "last",
                            }),
                        },
                        .result = "typename std::vector<T>::iterator",
                    }),
                    strange::make_operation
                    ({
                        .name = "push_back",
                        .parameters =
                        {
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
                        .name = "push_back",
                        .parameters =
                        {
                            strange::make_parameter
                            ({
                                .type = "T &&",
                                .name = "value",
                            }),
                        },
                        .result = "void",
                    }),
                    strange::make_operation
                    ({
                        .name = "pop_back",
                        .result = "void",
                    }),
                    strange::make_operation
                    ({
                        .name = "resize",
                        .parameters =
                        {
                            strange::make_parameter
                            ({
                                .type = "size_t",
                                .name = "count",
                            }),
                        },
                        .result = "void",
                    }),
                    strange::make_operation
                    ({
                        .name = "resize",
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
                        .name = "swap",
                        .parameters =
                        {
                            strange::make_parameter
                            ({
                                .type = "std::vector<T> &",
                                .name = "other",
                            }),
                        },
                        .result = "void",
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