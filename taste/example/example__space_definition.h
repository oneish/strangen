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
inline auto parents(strange::implementation::vector<std::string> pars) -> strange::vector<std::string>
{
    return strange::vector<std::string>::_make(pars);
}

inline auto parameter(strange::implementation::parameter param) -> strange::parameter
{
    return strange::parameter::_make(param);
}

inline auto parameters(strange::implementation::vector<strange::parameter> params) -> strange::vector<strange::parameter>
{
    return strange::vector<strange::parameter>::_make(params);
}

inline auto operation(strange::implementation::operation oper) -> strange::operation
{
    return strange::operation::_make(oper);
}

inline auto operations(strange::implementation::vector<strange::operation> opers) -> strange::vector<strange::operation>
{
    return strange::vector<strange::operation>::_make(opers);
}

inline auto abstraction(strange::implementation::abstraction abstract) -> strange::abstraction
{
    return strange::abstraction::_make(abstract);
}

inline auto abstractions(strange::implementation::vector<strange::abstraction> abstracts) -> strange::vector<strange::abstraction>
{
    return strange::vector<strange::abstraction>::_make(abstracts);
}

inline auto space(strange::implementation::space spc) -> strange::space
{
    return strange::space::_make(spc);
}

auto definition() -> strange::space
{
    return meta::space
    ({
        .name_ = "example",
        .abstractions_ = abstractions
        ({
            abstraction
            ({
                .name_ = "widget",
                .operations_ = operations
                ({
                    operation
                    ({
                        .name_ = "display",
                        .parameters_ = parameters
                        ({
                            parameter
                            ({
                                .type_ = "button",
                                .name_ = "b",
                                .argument_ = "button()",
                            }),
                        }),
                        .constness_ = true,
                        .result_ = "void",
                    }),
                    operation
                    ({
                        .name_ = "inc",
                        .result_ = "void",
                    }),
                    operation
                    ({
                        .name_ = "operator++",
                        .result_ = "*this",
                    }),
                    operation
                    ({
                        .name_ = "operator--",
                        .parameters_ = parameters
                        ({
                            parameter
                            ({
                                .type_ = "int",
                                .name_ = "i",
                            }),
                        }),
                        .result_ = "*that",
                    }),
                }),
            }),
            abstraction
            ({
                .name_ = "button",
                .parents_ = parents
                ({
                    "widget",
                }),
                .operations_ = operations
                ({
                    operation
                    ({
                        .name_ = "push",
                        .result_ = "void",
                    }),
                }),
            }),
            abstraction
            ({
                .name_ = "number",
                .operations_ = operations
                ({
                    operation
                    ({
                        .name_ = "inc",
                        .result_ = "void",
                    }),
                    operation
                    ({
                        .name_ = "dec",
                        .result_ = "void",
                    }),
                }),
            }),
            abstraction
            ({
                .name_ = "widget_number",
                .parents_ = parents
                ({
                    "widget",
                    "number",
                }),
            }),
            abstraction
            ({
                .parameters_ = parameters
                ({
                    parameter
                    ({
                        .type_ = "typename",
                        .name_ = "Data",
                        .argument_ = "int",
                    }),
                }),
                .name_ = "numeric",
                .parents_ = parents
                ({
                    "number",
                }),
                .operations_ = operations
                ({
                    operation
                    ({
                        .name_ = "get",
                        .constness_ = true,
                        .result_ = "Data",
                    }),
                    operation
                    ({
                        .name_ = "x",
                        .constness_ = true,
                        .result_ = "Data const &",
                        .data_ = true,
                    }),
                    operation
                    ({
                        .name_ = "x",
                        .result_ = "Data &",
                        .data_ = true,
                    }),
                }),
            }),
        }),
    });
}
}
}
