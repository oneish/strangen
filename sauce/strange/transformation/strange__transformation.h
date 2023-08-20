#pragma once
#include <ostream>
#include <algorithm>
#include <unordered_set>
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
        static inline auto _static_shared_to_base(std::shared_ptr<)#" << abstraction.name << R"#(::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
)#";
            if (abstraction.parents.empty())
            {
                _out << R"#(            return derived;
)#";
            }
            else
            {
                _out << R"#(            return )#" << abstraction.parents[0] << R"#(::_derived::_static_shared_to_base(derived);
)#";
            }
            _out << R"#(        }
)#";
            {
                std::unordered_set<strange::operation> unique;
                _abstraction_operations(abstraction, true, true, unique);
            }
            _out << R"#(    };

private:
    template<typename _Thing, bool _Copy>
    struct _instance final : )#" << abstraction.name << R"#(::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :)#" << abstraction.name << R"#(::_derived{}
        ,_thing{std::forward<_Args>(_args) ...}
        {
        }

        inline auto _address() const -> void const * final
        {
            return &_thing;
        }

        inline auto _sizeof() const -> size_t final
        {
            return sizeof(_thing);
        }

        inline auto _clone() const -> std::shared_ptr<strange::_common::_base> final
        {
            if constexpr (_Copy)
            {
)#";
            _out << R"#(                return )#" << abstraction.name << R"#(::_derived::_static_shared_to_base(std::make_shared<)#" << abstraction.name << R"#(::_instance<_Thing, _Copy>>(_thing));
            }
            else
            {
                throw true;
            }
        }
)#";
            {
                std::unordered_set<strange::operation> unique;
                _abstraction_operations(abstraction, true, false, unique);
            }
            _out << R"#(
    private:
        _Thing _thing;
    };
)#";
            _out << R"#(};

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

    auto _abstraction_operations(strange::abstraction const & abstraction, bool const inner, bool const pure, std::unordered_set<strange::operation> & unique) -> void
    {
        if ((!inner) || (!pure))
        {
            // need to override base class operations as well
            for (auto const & parent : abstraction.parents)
            {
                auto it = std::find_if(_space.abstractions.cbegin(), _space.abstractions.cend(),
                    [& parent](strange::abstraction const & candidate){return candidate.name == parent;});
                if (it != _space.abstractions.cend())
                {
                    _abstraction_operations(*it, inner, pure, unique);
                }
            }
        }
        if (!abstraction.operations.empty())
        {
            for (auto const & operation : abstraction.operations)
            {
                if (unique.count(operation))
                {
                    continue;
                }
                unique.insert(operation);
                if (pure)
                {
                    _out << R"#(
        virtual )#";
                }
                else
                {
                    _out << R"#(
        inline )#";
                }
                _out << R"#(auto )#" << operation.name;
                _operation_parameters(operation, false);
                _out << (operation.constness ? R"#( const)#" : R"#()#") << R"#( -> )#" << operation.result;
                if (pure)
                {
                    _out << R"#( = 0;
)#";
                }
                else
                {
                    _out << R"#( final;
)#";
                }
            }
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