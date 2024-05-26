#pragma once
#include "../definition/strange__definition__parameter.h"
#include "../definition/strange__definition__operation.h"
#include "../definition/strange__definition__abstraction.h"
#include "../definition/strange__definition__space.h"

namespace strange
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
        .name = "strange",
        .abstractions = abstractions
        ({
            abstraction
            ({
                .name = "any",
            }),
            abstraction
            ({
                .parameters = parameters
                ({
                    parameter
                    ({
                        .type = "typename",
                        .name = "T",
                    }),
                }),
                .name = "forward_const_iterator",
                .parents = parents
                ({
                    "any",
                }),
                .types = parameters
                ({
                    parameter
                    ({
                        .type = "using",
                        .name = "value_type",
                        .argument = "T",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "difference_type",
                        .argument = "std::ptrdiff_t",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "reference",
                        .argument = "value_type &",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "pointer",
                        .argument = "value_type *",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "iterator_category",
                        .argument = "std::forward_iterator_tag",
                    }),
                }),
                .operations = operations
                ({
                    operation
                    ({
                        .name = "operator*",
                        .constness = true,
                        .result = "T const &",
                    }),
                    operation
                    ({
                        .name = "operator->",
                        .constness = true,
                        .result = "T const *",
                    }),
                    operation
                    ({
                        .name = "operator++",
                        .result = "*this",
                    }),
                    operation
                    ({
                        .name = "operator++",
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
                    operation
                    ({
                        .name = "operator==",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "forward_const_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing == other.template _static<forward_const_iterator_<T, _Thing, _Copy> const>()._thing()",
                    }),
                    operation
                    ({
                        .name = "operator!=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "forward_const_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return !operator==(other)",
                    }),
                }),
            }),
            abstraction
            ({
                .parameters = parameters
                ({
                    parameter
                    ({
                        .type = "typename",
                        .name = "T",
                    }),
                }),
                .name = "forward_iterator",
                .parents = parents
                ({
                    "forward_const_iterator<T>",
                }),
                .types = parameters
                ({
                    parameter
                    ({
                        .type = "using",
                        .name = "value_type",
                        .argument = "T",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "difference_type",
                        .argument = "std::ptrdiff_t",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "reference",
                        .argument = "value_type &",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "pointer",
                        .argument = "value_type *",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "iterator_category",
                        .argument = "std::forward_iterator_tag",
                    }),
                }),
                .operations = operations
                ({
                    operation
                    ({
                        .name = "operator*",
// hack                        .constness = true,
                        .result = "T &",
                    }),
                    operation
                    ({
                        .name = "operator->",
// hack                        .constness = true,
                        .result = "T *",
                    }),
                    operation
                    ({
                        .name = "operator==",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "forward_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing == other.template _static<forward_iterator_<T, _Thing, _Copy> const>()._thing()",
                    }),
                    operation
                    ({
                        .name = "operator!=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "forward_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return !operator==(other)",
                    }),
                }),
            }),
            abstraction
            ({
                .parameters = parameters
                ({
                    parameter
                    ({
                        .type = "typename",
                        .name = "T",
                    }),
                }),
                .name = "bidirectional_const_iterator",
                .parents = parents
                ({
                    "forward_const_iterator<T>",
                }),
                .types = parameters
                ({
                    parameter
                    ({
                        .type = "using",
                        .name = "iterator_category",
                        .argument = "std::bidirectional_iterator_tag",
                    }),
                }),
                .operations = operations
                ({
                    operation
                    ({
                        .name = "operator==",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "bidirectional_const_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing == other.template _static<bidirectional_const_iterator_<T, _Thing, _Copy> const>()._thing()",
                    }),
                    operation
                    ({
                        .name = "operator!=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "bidirectional_const_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return !operator==(other)",
                    }),
                    operation
                    ({
                        .name = "operator--",
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
                .parameters = parameters
                ({
                    parameter
                    ({
                        .type = "typename",
                        .name = "T",
                    }),
                }),
                .name = "bidirectional_iterator",
                .parents = parents
                ({
                    "forward_iterator<T>",
                    "bidirectional_const_iterator<T>",
                }),
                .types = parameters
                ({
                    parameter
                    ({
                        .type = "using",
                        .name = "value_type",
                        .argument = "T",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "difference_type",
                        .argument = "std::ptrdiff_t",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "reference",
                        .argument = "value_type &",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "pointer",
                        .argument = "value_type *",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "iterator_category",
                        .argument = "std::bidirectional_iterator_tag",
                    }),
                }),
                .operations = operations
                ({
                    operation
                    ({
                        .name = "operator==",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "bidirectional_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing == other.template _static<bidirectional_iterator_<T, _Thing, _Copy> const>()._thing()",
                    }),
                    operation
                    ({
                        .name = "operator!=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "bidirectional_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return !operator==(other)",
                    }),
                }),
            }),
            abstraction
            ({
                .parameters = parameters
                ({
                    parameter
                    ({
                        .type = "typename",
                        .name = "T",
                    }),
                }),
                .name = "random_access_const_iterator",
                .parents = parents
                ({
                    "bidirectional_const_iterator<T>",
                }),
                .types = parameters
                ({
                    parameter
                    ({
                        .type = "using",
                        .name = "value_type",
                        .argument = "T",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "difference_type",
                        .argument = "std::ptrdiff_t",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "reference",
                        .argument = "value_type &",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "pointer",
                        .argument = "value_type *",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "iterator_category",
                        .argument = "std::random_access_iterator_tag",
                    }),
                }),
                .operations = operations
                ({
                    operation
                    ({
                        .name = "operator==",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "random_access_const_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing == other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing()",
                    }),
                    operation
                    ({
                        .name = "operator!=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "random_access_const_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return !operator==(other)",
                    }),
                    operation
                    ({
                        .name = "operator<",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "random_access_const_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing < other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing()",
                    }),
                    operation
                    ({
                        .name = "operator>",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "random_access_const_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing > other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing()",
                    }),
                    operation
                    ({
                        .name = "operator<=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "random_access_const_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing <= other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing()",
                    }),
                    operation
                    ({
                        .name = "operator>=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "random_access_const_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing >= other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing()",
                    }),
                    operation
                    ({
                        .name = "operator+=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "std::ptrdiff_t",
                                .name = "n",
                            }),
                        }),
                        .result = "*this",
                    }),
                    operation
                    ({
                        .name = "operator-=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "std::ptrdiff_t",
                                .name = "n",
                            }),
                        }),
                        .result = "*this",
                    }),
                    operation
                    ({
                        .name = "operator+",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "std::ptrdiff_t",
                                .name = "n",
                            }),
                        }),
                        .constness = true,
                        .result = "random_access_const_iterator<T>",
                        .customisation = "return random_access_const_iterator<T>::template _make<_Thing, _Copy>(_thing + n)",
                    }),
                    operation
                    ({
                        .name = "operator-",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "std::ptrdiff_t",
                                .name = "n",
                            }),
                        }),
                        .constness = true,
                        .result = "random_access_const_iterator<T>",
                        .customisation = "return random_access_const_iterator<T>::template _make<_Thing, _Copy>(_thing - n)",
                    }),
                    operation
                    ({
                        .name = "operator-",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "random_access_const_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "std::ptrdiff_t",
                        .customisation = "return _thing - other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing()",
                    }),
                    operation
                    ({
                        .name = "operator[]",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "std::ptrdiff_t",
                                .name = "n",
                            }),
                        }),
                        .constness = true,
                        .result = "T const &",
                    }),
                }),
            }),
            abstraction
            ({
                .parameters = parameters
                ({
                    parameter
                    ({
                        .type = "typename",
                        .name = "T",
                    }),
                }),
                .name = "random_access_iterator",
                .parents = parents
                ({
                    "bidirectional_iterator<T>",
                    "random_access_const_iterator<T>",
                }),
                .types = parameters
                ({
                    parameter
                    ({
                        .type = "using",
                        .name = "value_type",
                        .argument = "T",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "difference_type",
                        .argument = "std::ptrdiff_t",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "reference",
                        .argument = "value_type &",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "pointer",
                        .argument = "value_type *",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "iterator_category",
                        .argument = "std::random_access_iterator_tag",
                    }),
                }),
                .operations = operations
                ({
                    operation
                    ({
                        .name = "operator==",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "random_access_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing == other.template _static<random_access_iterator_<T, _Thing, _Copy> const>()._thing()",
                    }),
                    operation
                    ({
                        .name = "operator!=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "random_access_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return !operator==(other)",
                    }),
                    operation
                    ({
                        .name = "operator<",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "random_access_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing < other.template _static<random_access_iterator_<T, _Thing, _Copy> const>()._thing()",
                    }),
                    operation
                    ({
                        .name = "operator>",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "random_access_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing > other.template _static<random_access_iterator_<T, _Thing, _Copy> const>()._thing()",
                    }),
                    operation
                    ({
                        .name = "operator<=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "random_access_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing <= other.template _static<random_access_iterator_<T, _Thing, _Copy> const>()._thing()",
                    }),
                    operation
                    ({
                        .name = "operator>=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "random_access_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing >= other.template _static<random_access_iterator_<T, _Thing, _Copy> const>()._thing()",
                    }),
                    operation
                    ({
                        .name = "operator+",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "std::ptrdiff_t",
                                .name = "n",
                            }),
                        }),
// hack                        .constness = true,
                        .result = "random_access_iterator<T>",
                        .customisation = "return random_access_iterator<T>::template _make<_Thing, _Copy>(_thing + n)",
                    }),
                    operation
                    ({
                        .name = "operator-",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "std::ptrdiff_t",
                                .name = "n",
                            }),
                        }),
// hack                        .constness = true,
                        .result = "random_access_iterator<T>",
                        .customisation = "return random_access_iterator<T>::template _make<_Thing, _Copy>(_thing - n)",
                    }),
                    operation
                    ({
                        .name = "operator-",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "random_access_iterator<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "std::ptrdiff_t",
                        .customisation = "return _thing - other.template _static<random_access_iterator_<T, _Thing, _Copy> const>()._thing()",
                    }),
                    operation
                    ({
                        .name = "operator[]",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "std::ptrdiff_t",
                                .name = "n",
                            }),
                        }),
// hack                        .constness = true,
                        .result = "T &",
                    }),
                }),
            }),
            abstraction
            ({
                .parameters = parameters
                ({
                    parameter
                    ({
                        .type = "typename",
                        .name = "T",
                    }),
                }),
                .name = "vector",
                .parents = parents
                ({
                    "any",
                }),
                .types = parameters
                ({
                    parameter
                    ({
                        .type = "using",
                        .name = "value_type",
                        .argument = "T",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "size_type",
                        .argument = "std::size_t",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "difference_type",
                        .argument = "std::ptrdiff_t",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "reference",
                        .argument = "value_type &",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "const_reference",
                        .argument = "value_type const &",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "pointer",
                        .argument = "value_type *",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "const_pointer",
                        .argument = "value_type const *",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "iterator",
                        .argument = "typename strange::random_access_iterator<T>",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "const_iterator",
                        .argument = "typename strange::random_access_const_iterator<T>",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "reverse_iterator",
                        .argument = "typename std::reverse_iterator<iterator>",
                    }),
                    parameter
                    ({
                        .type = "using",
                        .name = "const_reverse_iterator",
                        .argument = "typename std::reverse_iterator<const_iterator>",
                    }),
                }),
                .operations = operations
                ({
                    operation
                    ({
                        .name = "operator=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "std::initializer_list<T>",
                                .name = "ilist",
                            }),
                        }),
                        .result = "*this",
                    }),
                    operation
                    ({
                        .name = "assign",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "size_t",
                                .name = "count",
                            }),
                            parameter
                            ({
                                .type = "T const &",
                                .name = "value",
                            }),
                        }),
                        .result = "void",
                    }),
                    operation
                    ({
                        .name = "assign",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "forward_const_iterator<T>",
                                .name = "first",
                            }),
                            parameter
                            ({
                                .type = "forward_const_iterator<T>",
                                .name = "last",
                            }),
                        }),
                        .result = "void",
                    }),
                    operation
                    ({
                        .name = "assign",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "std::initializer_list<T>",
                                .name = "ilist",
                            }),
                        }),
                        .result = "void",
                    }),
                    operation
                    ({
                        .name = "at",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "size_t",
                                .name = "pos",
                            }),
                        }),
                        .result = "T &",
                    }),
                    operation
                    ({
                        .name = "at",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "size_t",
                                .name = "pos",
                            }),
                        }),
                        .constness = true,
                        .result = "T const &",
                    }),
                    operation
                    ({
                        .name = "operator[]",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "size_t",
                                .name = "pos",
                            }),
                        }),
                        .result = "T &",
                    }),
                    operation
                    ({
                        .name = "operator[]",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "size_t",
                                .name = "pos",
                            }),
                        }),
                        .constness = true,
                        .result = "T const &",
                    }),
                    operation
                    ({
                        .name = "front",
                        .result = "T &",
                    }),
                    operation
                    ({
                        .name = "front",
                        .constness = true,
                        .result = "T const &",
                    }),
                    operation
                    ({
                        .name = "back",
                        .result = "T &",
                    }),
                    operation
                    ({
                        .name = "back",
                        .constness = true,
                        .result = "T const &",
                    }),
                    operation
                    ({
                        .name = "data",
                        .result = "T *",
                    }),
                    operation
                    ({
                        .name = "data",
                        .constness = true,
                        .result = "T const *",
                    }),
                    operation
                    ({
                        .name = "begin",
                        .result = "typename strange::random_access_iterator<T>",
                        .customisation = "return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.begin())",
                    }),
                    operation
                    ({
                        .name = "begin",
                        .constness = true,
                        .result = "typename strange::random_access_const_iterator<T>",
                        .customisation = "return random_access_const_iterator<T>::template _make<decltype(_thing.begin())>(_thing.begin())",
                    }),
                    operation
                    ({
                        .name = "cbegin",
                        .constness = true,
                        .result = "typename strange::random_access_const_iterator<T>",
                        .customisation = "return random_access_const_iterator<T>::template _make<decltype(_thing.cbegin())>(_thing.cbegin())",
                    }),
                    operation
                    ({
                        .name = "end",
                        .result = "typename strange::random_access_iterator<T>",
                        .customisation = "return random_access_iterator<T>::template _make<decltype(_thing.end())>(_thing.end())",
                    }),
                    operation
                    ({
                        .name = "end",
                        .constness = true,
                        .result = "typename strange::random_access_const_iterator<T>",
                        .customisation = "return random_access_const_iterator<T>::template _make<decltype(_thing.end())>(_thing.end())",
                    }),
                    operation
                    ({
                        .name = "cend",
                        .constness = true,
                        .result = "typename strange::random_access_const_iterator<T>",
                        .customisation = "return random_access_const_iterator<T>::template _make<decltype(_thing.cend())>(_thing.cend())",
                    }),
                    operation
                    ({
                        .name = "rbegin",
                        .result = "typename std::reverse_iterator<strange::random_access_iterator<T>>",
                        .customisation = "return typename std::reverse_iterator<strange::random_access_iterator<T>>{random_access_iterator<T>::template _make<decltype(_thing.end())>(_thing.end())}",
                    }),
                    operation
                    ({
                        .name = "rbegin",
                        .constness = true,
                        .result = "typename std::reverse_iterator<strange::random_access_const_iterator<T>>",
                        .customisation = "return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{random_access_const_iterator<T>::template _make<decltype(_thing.end())>(_thing.end())}",
                    }),
                    operation
                    ({
                        .name = "crbegin",
                        .constness = true,
                        .result = "typename std::reverse_iterator<strange::random_access_const_iterator<T>>",
                        .customisation = "return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{random_access_const_iterator<T>::template _make<decltype(_thing.cend())>(_thing.cend())}",
                    }),
                    operation
                    ({
                        .name = "rend",
                        .result = "typename std::reverse_iterator<strange::random_access_iterator<T>>",
                        .customisation = "return typename std::reverse_iterator<strange::random_access_iterator<T>>{random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.begin())}",
                    }),
                    operation
                    ({
                        .name = "rend",
                        .constness = true,
                        .result = "typename std::reverse_iterator<strange::random_access_const_iterator<T>>",
                        .customisation = "return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{random_access_const_iterator<T>::template _make<decltype(_thing.begin())>(_thing.begin())}",
                    }),
                    operation
                    ({
                        .name = "crend",
                        .constness = true,
                        .result = "typename std::reverse_iterator<strange::random_access_const_iterator<T>>",
                        .customisation = "return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{random_access_const_iterator<T>::template _make<decltype(_thing.cbegin())>(_thing.cbegin())}",
                    }),
                    operation
                    ({
                        .name = "empty",
                        .constness = true,
                        .result = "bool",
                    }),
                    operation
                    ({
                        .name = "size",
                        .constness = true,
                        .result = "size_t",
                    }),
                    operation
                    ({
                        .name = "max_size",
                        .constness = true,
                        .result = "size_t",
                    }),
                    operation
                    ({
                        .name = "reserve",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "size_t",
                                .name = "new_cap",
                            }),
                        }),
                        .result = "void",
                    }),
                    operation
                    ({
                        .name = "capacity",
                        .constness = true,
                        .result = "size_t",
                    }),
                    operation
                    ({
                        .name = "shrink_to_fit",
                        .result = "void",
                    }),
                    operation
                    ({
                        .name = "clear",
                        .result = "void",
                    }),
                    operation
                    ({
                        .name = "insert",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "typename strange::random_access_const_iterator<T>",
                                .name = "pos",
                            }),
                            parameter
                            ({
                                .type = "T const &",
                                .name = "value",
                            }),
                        }),
                        .result = "typename strange::random_access_iterator<T>",
                        .modification = R"#(auto const index = pos - cbegin();
    strange::_common::_mutate(); // could invalidate iterators
    pos = cbegin() + index;
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, value);)#",
                        .customisation = "return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), value))",
                    }),
                    operation
                    ({
                        .name = "insert",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "typename strange::random_access_const_iterator<T>",
                                .name = "pos",
                            }),
                            parameter
                            ({
                                .type = "T &&",
                                .name = "value",
                            }),
                        }),
                        .result = "typename strange::random_access_iterator<T>",
                        .modification = R"#(auto const index = pos - cbegin();
    strange::_common::_mutate(); // could invalidate iterators
    pos = cbegin() + index;
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, std::move(value));)#",
                        .customisation = "return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), std::move(value)))",
                    }),
                    operation
                    ({
                        .name = "insert",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "typename strange::random_access_const_iterator<T>",
                                .name = "pos",
                            }),
                            parameter
                            ({
                                .type = "size_t",
                                .name = "count",
                            }),
                            parameter
                            ({
                                .type = "T const &",
                                .name = "value",
                            }),
                        }),
                        .result = "typename strange::random_access_iterator<T>",
                        .modification = R"#(auto const index = pos - cbegin();
    strange::_common::_mutate(); // could invalidate iterators
    pos = cbegin() + index;
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, count, value);)#",
                        .customisation = "return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), count, value))",
                    }),
                    operation
                    ({
                        .name = "insert",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "typename strange::random_access_const_iterator<T>",
                                .name = "pos",
                            }),
                            parameter
                            ({
                                .type = "forward_const_iterator<T>",
                                .name = "first",
                            }),
                            parameter
                            ({
                                .type = "forward_const_iterator<T>",
                                .name = "last",
                            }),
                        }),
                        .result = "typename strange::random_access_iterator<T>",
                        .modification = R"#(auto const index = pos - cbegin();
    strange::_common::_mutate(); // could invalidate iterators
    pos = cbegin() + index;
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, first, last);)#",
                        .customisation = "return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), first, last))",
                    }),
                    operation
                    ({
                        .name = "insert",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "typename strange::random_access_const_iterator<T>",
                                .name = "pos",
                            }),
                            parameter
                            ({
                                .type = "std::initializer_list<T>",
                                .name = "ilist",
                            }),
                        }),
                        .result = "typename strange::random_access_iterator<T>",
                        .modification = R"#(auto const index = pos - cbegin();
    strange::_common::_mutate(); // could invalidate iterators
    pos = cbegin() + index;
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, ilist);)#",
                        .customisation = "return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), ilist))",
                    }),
                    operation
                    ({
                        .name = "erase",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "typename strange::random_access_const_iterator<T>",
                                .name = "pos",
                            }),
                        }),
                        .result = "typename strange::random_access_iterator<T>",
                        .modification = R"#(auto const index = pos - cbegin();
    strange::_common::_mutate(); // could invalidate iterators
    pos = cbegin() + index;
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->erase(pos);)#",
                        .customisation = "return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.erase(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing()))",
                    }),
                    operation
                    ({
                        .name = "erase",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "typename strange::random_access_const_iterator<T>",
                                .name = "first",
                            }),
                            parameter
                            ({
                                .type = "typename strange::random_access_const_iterator<T>",
                                .name = "last",
                            }),
                        }),
                        .result = "typename strange::random_access_iterator<T>",
                        .modification = R"#(auto const first_index = first - cbegin();
    auto const last_index = last - cbegin();
    strange::_common::_mutate(); // could invalidate iterators
    first = cbegin() + first_index;
    last = cbegin() + last_index;
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->erase(first, last);)#",
                        .customisation = "return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.erase(first.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), last.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing()))",
                    }),
                    operation
                    ({
                        .name = "push_back",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "T const &",
                                .name = "value",
                            }),
                        }),
                        .result = "void",
                    }),
                    operation
                    ({
                        .name = "push_back",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "T &&",
                                .name = "value",
                            }),
                        }),
                        .result = "void",
                    }),
                    operation
                    ({
                        .name = "pop_back",
                        .result = "void",
                    }),
                    operation
                    ({
                        .name = "resize",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "size_t",
                                .name = "count",
                            }),
                        }),
                        .result = "void",
                    }),
                    operation
                    ({
                        .name = "resize",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "size_t",
                                .name = "count",
                            }),
                            parameter
                            ({
                                .type = "T const &",
                                .name = "value",
                            }),
                        }),
                        .result = "void",
                    }),
                    operation
                    ({
                        .name = "swap",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "vector<T> &",
                                .name = "other",
                            }),
                        }),
                        .result = "void",
                        .customisation = "_thing.swap(other.template _static<vector_<T, _Thing, _Copy>>()._thing())"
                    }),
                    operation
                    ({
                        .name = "operator==",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "vector<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing == other.template _static<vector_<T, _Thing, _Copy> const>()._thing()",
                    }),
                    operation
                    ({
                        .name = "operator!=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "vector<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing != other.template _static<vector_<T, _Thing, _Copy> const>()._thing()",
                    }),
                    operation
                    ({
                        .name = "operator<",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "vector<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing < other.template _static<vector_<T, _Thing, _Copy> const>()._thing()",
                    }),
                    operation
                    ({
                        .name = "operator>",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "vector<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing > other.template _static<vector_<T, _Thing, _Copy> const>()._thing()",
                    }),
                    operation
                    ({
                        .name = "operator<=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "vector<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing <= other.template _static<vector_<T, _Thing, _Copy> const>()._thing()",
                    }),
                    operation
                    ({
                        .name = "operator>=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "vector<T> const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return _thing >= other.template _static<vector_<T, _Thing, _Copy> const>()._thing()",
                    }),
                }),
                .thing = "std::vector<T>",
            }),
            abstraction
            ({
                .name = "parameter",
                .parents = parents
                ({
                    "any",
                }),
                .operations = operations
                ({
                    operation
                    ({
                        .name = "type",
                        .constness = true,
                        .result = "std::string const &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "type",
                        .result = "std::string &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "name",
                        .constness = true,
                        .result = "std::string const &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "name",
                        .result = "std::string &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "argument",
                        .constness = true,
                        .result = "std::string const &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "argument",
                        .result = "std::string &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "operator==",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "parameter const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = R"#(return type() == other.type()
        && name() == other.name()
        && argument() == other.argument())#",
                    }),
                    operation
                    ({
                        .name = "operator!=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "parameter const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return !operator==(other)",
                    }),
                    operation
                    ({
                        .name = "operator<",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "parameter const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = R"#(return type() < other.type()
        || (type() == other.type() && (name() < other.name()
        || (name() == other.name() && argument() < other.argument()))))#",
                    }),
                    operation
                    ({
                        .name = "operator<=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "parameter const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = R"#(return operator<(other) || operator==(other))#",
                    }),
                    operation
                    ({
                        .name = "operator>",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "parameter const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = R"#(return !operator<=(other))#",
                    }),
                    operation
                    ({
                        .name = "operator>=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "parameter const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = R"#(return !operator<(other))#",
                    }),
                }),
                .thing = "strange::definition::parameter",
            }),
            abstraction
            ({
                .name = "operation",
                .parents = parents
                ({
                    "any",
                }),
                .operations = operations
                ({
                    operation
                    ({
                        .name = "name",
                        .constness = true,
                        .result = "std::string const &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "name",
                        .result = "std::string &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "parameters",
                        .constness = true,
                        .result = "strange::vector<strange::parameter> const &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "parameters",
                        .result = "strange::vector<strange::parameter> &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "constness",
                        .constness = true,
                        .result = "bool const &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "constness",
                        .result = "bool &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "result",
                        .constness = true,
                        .result = "std::string const &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "result",
                        .result = "std::string &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "data",
                        .constness = true,
                        .result = "bool const &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "data",
                        .result = "bool &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "modification",
                        .constness = true,
                        .result = "std::string const &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "modification",
                        .result = "std::string &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "customisation",
                        .constness = true,
                        .result = "std::string const &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "customisation",
                        .result = "std::string &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "implementation",
                        .constness = true,
                        .result = "std::string const &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "implementation",
                        .result = "std::string &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "operator==",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "operation const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = R"#(return name() == other.name()
        && parameters() == other.parameters()
        && constness() == other.constness()
        && result() == other.result()
        && data() == other.data()
        && modification() == other.modification()
        && customisation() == other.customisation()
        && implementation() == other.implementation())#",
                    }),
                    operation
                    ({
                        .name = "operator!=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "operation const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return !operator==(other)",
                    }),
                    operation
                    ({
                        .name = "operator<",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "operation const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = R"#(return name() < other.name()
        || (name() == other.name() && (parameters() < other.parameters()
        || (parameters() == other.parameters() && (constness() < other.constness()
        || (constness() == other.constness() && (result() < other.result()
        || (result() == other.result() && (data() < other.data()
        || (data() == other.data() && (modification() < other.modification()
        || (modification() == other.modification() && (customisation() < other.customisation()
        || (customisation() == other.customisation() && implementation() < other.implementation()))))))))))))))#",
                    }),
                    operation
                    ({
                        .name = "operator<=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "operation const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = R"#(return operator<(other) || operator==(other))#",
                    }),
                    operation
                    ({
                        .name = "operator>",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "operation const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = R"#(return !operator<=(other))#",
                    }),
                    operation
                    ({
                        .name = "operator>=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "operation const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = R"#(return !operator<(other))#",
                    }),
                }),
                .thing = "strange::definition::operation",
            }),
            abstraction
            ({
                .name = "abstraction",
                .parents = parents
                ({
                    "any",
                }),
                .operations = operations
                ({
                    operation
                    ({
                        .name = "parameters",
                        .constness = true,
                        .result = "strange::vector<strange::parameter> const &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "parameters",
                        .result = "strange::vector<strange::parameter> &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "name",
                        .constness = true,
                        .result = "std::string const &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "name",
                        .result = "std::string &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "parents",
                        .constness = true,
                        .result = "strange::vector<std::string> const &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "parents",
                        .result = "strange::vector<std::string> &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "types",
                        .constness = true,
                        .result = "strange::vector<strange::parameter> const &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "types",
                        .result = "strange::vector<strange::parameter> &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "operations",
                        .constness = true,
                        .result = "strange::vector<strange::operation> const &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "operations",
                        .result = "strange::vector<strange::operation> &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "thing",
                        .constness = true,
                        .result = "std::string const &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "thing",
                        .result = "std::string &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "operator==",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "abstraction const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = R"#(return parameters() == other.parameters()
        && name() == other.name()
        && parents() == other.parents()
        && types() == other.types()
        && operations() == other.operations()
        && thing() == other.thing())#",
                    }),
                    operation
                    ({
                        .name = "operator!=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "abstraction const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return !operator==(other)",
                    }),
                    operation
                    ({
                        .name = "operator<",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "abstraction const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = R"#(return parameters() < other.parameters()
        || (parameters() == other.parameters() && (name() < other.name()
        || (name() == other.name() && (parents() < other.parents()
        || (parents() == other.parents() && (types() < other.types()
        || (types() == other.types() && (operations() < other.operations()
        || (operations() == other.operations() && thing() < other.thing()))))))))))#",
                    }),
                    operation
                    ({
                        .name = "operator<=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "abstraction const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = R"#(return operator<(other) || operator==(other))#",
                    }),
                    operation
                    ({
                        .name = "operator>",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "abstraction const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = R"#(return !operator<=(other))#",
                    }),
                    operation
                    ({
                        .name = "operator>=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "abstraction const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = R"#(return !operator<(other))#",
                    }),
                }),
                .thing = "strange::definition::abstraction",
            }),
            abstraction
            ({
                .name = "space",
                .parents = parents
                ({
                    "any",
                }),
                .operations = operations
                ({
                    operation
                    ({
                        .name = "name",
                        .constness = true,
                        .result = "std::string const &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "name",
                        .result = "std::string &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "abstractions",
                        .constness = true,
                        .result = "strange::vector<strange::abstraction> const &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "abstractions",
                        .result = "strange::vector<strange::abstraction> &",
                        .data = true,
                    }),
                    operation
                    ({
                        .name = "operator==",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "space const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = R"#(return name() == other.name()
        && abstractions() == other.abstractions())#",
                    }),
                    operation
                    ({
                        .name = "operator!=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "space const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = "return !operator==(other)",
                    }),
                    operation
                    ({
                        .name = "operator<",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "space const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = R"#(return name() < other.name()
        || (name() == other.name() && abstractions() < other.abstractions()))#",
                    }),
                    operation
                    ({
                        .name = "operator<=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "space const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = R"#(return operator<(other) || operator==(other))#",
                    }),
                    operation
                    ({
                        .name = "operator>",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "space const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = R"#(return !operator<=(other))#",
                    }),
                    operation
                    ({
                        .name = "operator>=",
                        .parameters = parameters
                        ({
                            parameter
                            ({
                                .type = "space const &",
                                .name = "other",
                            }),
                        }),
                        .constness = true,
                        .result = "bool",
                        .customisation = R"#(return !operator<(other))#",
                    }),
                }),
                .thing = "strange::definition::space",
            }),
        }),
    });
}
}
}
