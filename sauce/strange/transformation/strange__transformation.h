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
            _abstraction_parameters(abstraction, true);
            _out << R"#(struct )#" << abstraction.name << R"#(;

)#";
        }
    }

    auto _declarations() -> void
    {
        for (auto const & abstraction : _space.abstractions)
        {
            _abstraction_parameters(abstraction, false);
            _out << R"#(struct )#" << abstraction.name << R"#( : )#";
            _abstraction_parents(abstraction, false);
            _out << R"#(
{
    inline )#" << abstraction.name << R"#(() = default;

    inline )#" << abstraction.name << R"#(()#" << abstraction.name << R"#( const & other)
    :strange::_common{other}
)#";
            _abstraction_default_construct_bases(abstraction);
            _out << R"#(    {
    }

    inline )#" << abstraction.name << R"#(()#" << abstraction.name << R"#( && other)
    :strange::_common{std::move(other)}
)#";
            _abstraction_default_construct_bases(abstraction);
            _out << R"#(    {
    }

    inline auto operator=()#" << abstraction.name << R"#( const & other) -> )#" << abstraction.name << R"#( &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=()#" << abstraction.name << R"#( && other) -> )#" << abstraction.name << R"#( &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline )#" << abstraction.name << R"#((std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
)#";
            _abstraction_default_construct_bases(abstraction);
            _out << R"#(    {
    }

    explicit inline )#" << abstraction.name << R"#((std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
)#";
            _abstraction_default_construct_bases(abstraction);
            _out << R"#(    {
    }

protected:
    struct _derived : )#";
            _abstraction_parents(abstraction, true);
            _out << R"#(
    {
)#";
            for (auto const & operation : abstraction.operations)
            {
                _out << R"#(        virtual auto )#" << operation.name;
                _operation_parameters(operation, false);
                _out << (operation.constness ? R"#( const)#" : R"#()#") << R"#( -> )#" << operation.result << R"#( = 0;
)#";
            }
            _out << R"#(    };

private:
)#";
            _out << R"#(};

)#";
        }
    }

    auto _abstraction_parents(strange::abstraction const & abstraction, bool const inner) -> void
    {
        if (abstraction.parents.empty())
        {
            if (inner)
            {
                _out << R"#(strange::_common::_base)#";
            }
            else
            {
                _out << R"#(virtual strange::_common)#";
            }
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
                if (inner)
                {
                    _out << R"#(::_derived)#";
                }
            }
        }
    }

    auto _abstraction_default_construct_bases(strange::abstraction const & abstraction) -> void
    {
        for (auto const & parent : abstraction.parents)
        {
            _out << R"#(    ,)#" << parent << R"#({}
)#";
        }
    }

    auto _abstraction_parameters(strange::abstraction const & abstraction, bool const arguments) -> void
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
                    _out << R"#(, )#";
                }
                _out << parameter.type << R"#( )#" << parameter.name;
                if (arguments && !parameter.argument.empty())
                {
                    _out << R"#( = )#" << parameter.argument;
                }
            }
            _out << R"#(>
)#";
        }
    }

    auto _operation_parameters(strange::operation const & operation, bool const arguments) -> void
    {
        _out << R"#(()#";
        bool first = true;
        for (auto const & parameter : operation.parameters)
        {
            if (first)
            {
                first = false;
            }
            else
            {
                _out << R"#(, )#";
            }
            _out << parameter.type << R"#( )#" << parameter.name;
            if (arguments && !parameter.argument.empty())
            {
                _out << R"#( = )#" << parameter.argument;
            }
        }
        _out << R"#())#";
    }

};

}