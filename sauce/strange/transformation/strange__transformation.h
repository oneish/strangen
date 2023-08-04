#pragma once
#include <ostream>
#include "../definition/strange__space.h"

namespace strange
{

struct transformation
{
protected:
    strange::space _space;
    std::ostream & _out;

public:
    transformation(strange::space space, std::ostream & out)
    :_space(space)
    ,_out(out)
    {
    }

    auto transform() -> void
    {
        _out << R"#(
#include <memory>
#include <type_traits>
#include "../common/strange__common.h"
)#";
        _namespace();
    }

protected:
    auto _namespace() -> void
    {
        _out << R"#(
namespace )#" << _space.name << R"#(
{

)#";
        _forward_declarations();
        _declarations();
        _out << R"#(}
)#";
    }

protected:
    auto _forward_declarations() -> void
    {
        for (auto const & abstraction : _space.abstractions)
        {
            if (!abstraction.parameters.empty())
            {
                _out << R"#(template<)#";
                bool first = true;
                for (auto const & parameter : abstraction.parameters)
                {
                    if (first)
                    {
                        first = false;
                    }
                    else
                    {
                        _out << parameter.type << R"#(, )#";
                    }
                    _out << parameter.type << R"#( )#" << parameter.name;
                    if (!parameter.argument.empty())
                    {
                        _out << R"#( = )#" << parameter.argument;
                    }
                }
                _out << R"#(> )#";
            }
            _out << R"#(struct )#" << abstraction.name << R"#(;
)#";
        }
        _out << R"#(
)#";
    }

    auto _declarations() -> void
    {
        for (auto const & abstraction : _space.abstractions)
        {
            if (!abstraction.parameters.empty())
            {
                _out << R"#(template<)#";
                bool first = true;
                for (auto const & parameter : abstraction.parameters)
                {
                    if (first)
                    {
                        first = false;
                    }
                    else
                    {
                        _out << parameter.type << R"#(, )#";
                    }
                    _out << parameter.type << R"#( )#" << parameter.name;
                }
                _out << R"#(>
)#";
            }
            _out << R"#(struct )#" << abstraction.name << R"#( : )#";
            if (abstraction.parents.empty())
            {
                _out << R"#(virtual strange::_common)#";
            }
            else
            {
                bool first = true;
                for (auto const & parent : abstraction.parents)
                {
                    if (first)
                    {
                        first = false;
                    }
                    else
                    {
                        _out << R"#(, )#";
                    }
                    _out << parent;
                }
            }
            _out << R"#(
{
)#";

            _out << R"#(};

)#";
        }
    }

};

}