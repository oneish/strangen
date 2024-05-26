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
namespace meta
{
inline auto parents(std::vector<std::string> pars) -> strange::vector<std::string>
{
    return strange::vector<std::string>::_make(pars);
}

inline auto parameter(strange::definition::parameter param) -> strange::parameter
{
    return strange::parameter::_make(param);
}

inline auto parameters(std::vector<strange::parameter> params) -> strange::vector<strange::parameter>
{
    return strange::vector<strange::parameter>::_make(params);
}

inline auto operation(strange::definition::operation oper) -> strange::operation
{
    return strange::operation::_make(oper);
}

inline auto operations(std::vector<strange::operation> opers) -> strange::vector<strange::operation>
{
    return strange::vector<strange::operation>::_make(opers);
}

inline auto abstraction(strange::definition::abstraction abstract) -> strange::abstraction
{
    return strange::abstraction::_make(abstract);
}

inline auto abstractions(std::vector<strange::abstraction> abstracts) -> strange::vector<strange::abstraction>
{
    return strange::vector<strange::abstraction>::_make(abstracts);
}

inline auto space(strange::definition::space spc) -> strange::space
{
    return strange::space::_make(spc);
}

auto definition() -> strange::space
{
    return meta::space
    ({
        .name = "example",
        .abstractions = abstractions
        ({
            abstraction
            ({
                .name = "widget",
                .operations = operations
                ({
                    operation
                    ({
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
                    }),
                    operation
                    ({
                        .name = "inc",
                        .result = "void",
                    }),
                    operation
                    ({
                        .name = "operator++",
                        .result = "*this",
                    }),
                    operation
                    ({
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
                    }),
                }),
            }),
            abstraction
            ({
                .name = "button",
                .parents = parents
                ({
                    "widget",
                }),
                .operations = operations
                ({
                    operation
                    ({
                        .name = "push",
                        .result = "void",
                    }),
                }),
            }),
            abstraction
            ({
                .name = "number",
                .operations = operations
                ({
                    operation
                    ({
                        .name = "inc",
                        .result = "void",
                    }),
                    operation
                    ({
                        .name = "dec",
                        .result = "void",
                    }),
                }),
            }),
            abstraction
            ({
                .name = "widget_number",
                .parents = parents
                ({
                    "widget",
                    "number",
                }),
            }),
            abstraction
            ({
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
                .parents = parents
                ({
                    "number",
                }),
                .operations = operations
                ({
                    operation
                    ({
                        .name = "get",
                        .constness = true,
                        .result = "Data",
                    }),
                    operation
                    ({
                        .name = "x",
                        .constness = true,
                        .result = "Data const &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "x",
                        .result = "Data &",
                        .data = true,
                    }),
                }),
            }),
        }),
    });
}
}
}
