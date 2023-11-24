#pragma once
#include "../strange.h"
#include <ostream>
#include <algorithm>
#include <unordered_set>

namespace strange
{
struct transformation
{
protected:
    space_a _space;
    std::ostream & _out;

public:
    transformation(space_a space, std::ostream & out)
    :_space(space)
    ,_out(out)
    {
    }

    auto transform() -> void
    {
        _out << R"#(
#include <memory>
#include <type_traits>
)#";
        _namespace();
    }

protected:
    auto _namespace() -> void
    {
        _out << R"#(
namespace )#" << _space.name() << R"#(
{

)#";
        _forward_declarations();
        _declarations();
        _definitions();
        _out << R"#(}
)#";
    }

    auto _forward_declarations() -> void
    {
        for (auto const & abstraction : _space.abstractions())
        {
            _abstraction_parameters(abstraction, true, true, false);
            _out << R"#(struct )#" << abstraction.name() << R"#(;

)#";
            _abstraction_parameters(abstraction, true, true, true);
            _out << R"#(struct )#" << abstraction.name() << R"#(_;

)#";
        }
    }

    auto _declarations() -> void
    {
        for (auto const & abstraction : _space.abstractions())
        {
            _abstraction_parameters(abstraction, true, false, false);
            _out << R"#(struct )#" << abstraction.name() << R"#( : )#";
            _abstraction_parents(abstraction, false);
            _out << R"#(
{
    inline )#" << abstraction.name() << R"#(() = default;

    inline )#" << abstraction.name() << R"#(()#" << abstraction.name() << R"#( const & other)
    :strange::_common{other}
)#";
            _abstraction_default_construct_bases(abstraction);
            _out << R"#(    {
    }

    inline )#" << abstraction.name() << R"#(()#" << abstraction.name() << R"#( && other)
    :strange::_common{std::move(other)}
)#";
            _abstraction_default_construct_bases(abstraction);
            _out << R"#(    {
    }

    inline auto operator=()#" << abstraction.name() << R"#( const & other) -> )#" << abstraction.name() << R"#( &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=()#" << abstraction.name() << R"#( && other) -> )#" << abstraction.name() << R"#( &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline )#" << abstraction.name() << R"#((std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
)#";
            _abstraction_default_construct_bases(abstraction);
            _out << R"#(    {
    }

    explicit inline )#" << abstraction.name() << R"#((std::shared_ptr<strange::_common::_base> && shared)
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
        static inline auto _static_shared_to_base(std::shared_ptr<)#" << abstraction.name()
                << R"#(::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
)#";
            if (abstraction.parents().empty())
            {
                _out << R"#(            return derived;
)#";
            }
            else
            {
                _out << R"#(            return )#" << abstraction.parents()[0]
                    << R"#(::_derived::_static_shared_to_base(derived);
)#";
            }
            _out << R"#(        }
)#";
            {
                std::unordered_set<operation_a> unique;
                _abstraction_operations(abstraction, abstraction, true, true, false, unique);
            }
            _out << R"#(    };

//private:
    template<typename _Thing, bool _Copy>
    struct _instance final : )#" << abstraction.name() << R"#(::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :)#" << abstraction.name() << R"#(::_derived{}
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
            _out << R"#(                return )#" << abstraction.name() << R"#(::_derived::_static_shared_to_base(std::make_shared<)#"
                << abstraction.name() << R"#(::_instance<_Thing, _Copy>>(_thing));
            }
            else
            {
                throw true;
            }
        }
)#";
            {
                std::unordered_set<operation_a> unique;
                _abstraction_operations(abstraction, abstraction, true, false, false, unique);
            }
            _out << R"#(
    //private:
        _Thing _thing;
    };

public:
    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> )#" << abstraction.name() << R"#(
    {
        return )#" << abstraction.name() << R"#({)#" << abstraction.name()
            << R"#(::_derived::_static_shared_to_base(std::make_shared<)#" << abstraction.name()
            << R"#(::_instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<)#" << abstraction.name() << R"#(::_derived>(strange::_common::_shared).operator bool();
    }
)#";
            {
                std::unordered_set<operation_a> unique;
                _abstraction_operations(abstraction, abstraction, false, false, false, unique);
            }
            _out << R"#(};

)#";
        }
    }

    auto _definitions() -> void
    {
        for (auto const & abstraction : _space.abstractions())
        {
            {
                std::unordered_set<operation_a> unique;
                _abstraction_operations(abstraction, abstraction, true, false, true, unique);
            }
            {
                std::unordered_set<operation_a> unique;
                _abstraction_operations(abstraction, abstraction, false, false, true, unique);
            }
        }
    }

    auto _abstraction_parameters(abstraction_a const & abstraction, bool const types, bool const arguments, bool const thing) -> void
    {
        if (thing || !abstraction.parameters().empty())
        {
            if (types)
            {
                _out << R"#(template<)#";

            }
            else
            {
                _out << R"#(<)#";
            }
            bool first = true;
            if (thing)
            {
                first = false;
                _out << R"#(typename _Thing)#";
            }
            for (auto const & parameter : abstraction.parameters())
            {
                if (first)
                {
                    first = false;
                }
                else
                {
                    _out << R"#(, )#";
                }
                if (types)
                {
                    _out << parameter.type() << R"#( )#";
                }
                _out << parameter.name();
                if (arguments && !parameter.argument().empty())
                {
                    _out << R"#( = )#" << parameter.argument();
                }
            }
            if (types)
            {
                _out << R"#(>
)#";
            }
            else
            {
                _out << R"#(>)#";
            }
        }
    }

    auto _abstraction_parents(abstraction_a const & abstraction, bool const inner) -> void
    {
        if (abstraction.parents().empty())
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
            for (auto const & parent : abstraction.parents())
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

    auto _abstraction_default_construct_bases(abstraction_a const & abstraction) -> void
    {
        for (auto const & parent : abstraction.parents())
        {
            _out << R"#(    ,)#" << parent << R"#({}
)#";
        }
    }

    auto _abstraction_operations(abstraction_a const & abstraction, abstraction_a const & derived, bool const inner, bool const pure, bool const definition, std::unordered_set<operation_a> & unique) -> void
    {
        if ((!inner) || (!pure))
        {
            // override base class operations as well
            for (auto const & parent : abstraction.parents())
            {
                auto it = std::find_if(_space.abstractions().cbegin(), _space.abstractions().cend(),
                    [& parent](abstraction_a const & candidate){return candidate.name() == parent;});
                if (it != _space.abstractions().cend())
                {
                    _abstraction_operations(*it, derived, inner, pure, definition, unique);
                }
            }
        }
        if (!abstraction.operations().empty())
        {
            for (auto const & operation : abstraction.operations())
            {
                if (unique.count(operation))
                {
                    continue;
                }
                unique.insert(operation);
                if (!definition)
                {
                    if (pure)
                    {
                        _out << R"#(
        virtual )#";
                    }
                    else if (inner)
                    {
                        _out << R"#(
        inline )#";
                    }
                    else
                    {
                        _out << R"#(
    inline )#";
                    }
                }
                else
                {
                    _abstraction_parameters(derived, true, false, false);
                    if (inner)
                    {
                        _out << R"#(template<typename _Thing, bool _Copy>
inline )#";
                    }
                    else
                    {
                        _out << R"#(inline )#";
                    }
                }
                if (!definition)
                {
                    _out << R"#(auto )#" << operation.name();
                }
                else
                {
                    _out << R"#(auto )#" << derived.name();
                    _abstraction_parameters(derived, false, false, false);
                    if (inner)
                    {
                        _out << R"#(::_instance<_Thing, _Copy>::)#";
                    }
                    else
                    {
                        _out << R"#(::)#";
                    }
                    _out << operation.name();
                }
                _operation_parameters(operation, true, definition && !inner);
                if (operation.constness())
                {
                    _out << R"#( const -> )#";
                }
                else
                {
                    _out << R"#( -> )#";
                }
                bool const that = (operation.result() == "*that");
                bool const this_or_that = (that || operation.result() == "*this");
                bool const this_or_that_or_void = (this_or_that || operation.result() == "void");
                if (this_or_that)
                {
                    if (inner || pure)
                    {
                        _out << "void";
                    }
                    else
                    {
                        _out << derived.name();
                        if (!that)
                        {
                            _out << R"#( &)#";
                        }
                    }
                }
                else
                {
                    _out << operation.result();
                }
                if (!definition)
                {
                    if (pure)
                    {
                        _out << R"#( = 0;
)#";
                    }
                    else if (inner)
                    {
                        _out << R"#( final;
)#";
                    }
                    else
                    {
                        _out << R"#(;
)#";
                    }
                }
                else
                {
                    _out << R"#(
{
    )#";
                    if (inner)
                    {
                        if (this_or_that_or_void)
                        {
                            _out << R"#(_thing.)#" << operation.name();
                        }
                        else
                        {
                            _out << R"#(return _thing.)#" << operation.name();
                        }
                    }
                    else
                    {
                        if (that)
                        {
                            _out << R"#(auto _result = *this;
    )#";
                        }
                        if (!operation.constness())
                        {
                            _out << R"#(strange::_common::_mutate();
    )#";
                        }
                        if (this_or_that_or_void)
                        {
                            _out << R"#(std::dynamic_pointer_cast<)#" << abstraction.name();
                        }
                        else
                        {
                            _out << R"#(return std::dynamic_pointer_cast<)#" << abstraction.name();
                        }
                        _abstraction_parameters(abstraction, false, false, false);
                        _out << R"#(::_derived>(strange::_common::_shared)->)#" << operation.name();
                    }
                    if ((!inner) || (!operation.data()))
                    {
                        _operation_parameters(operation, false, false);
                    }
                    if ((!inner) && this_or_that)
                    {
                        if (that)
                        {
                            _out << R"#(;
    return _result;)#";

                        }
                        else
                        {
                            _out << R"#(;
    return *this;)#";
                        }
                    }
                    else
                    {
                        _out << R"#(;)#";
                    }
                    _out << R"#(
}

)#";
                }
            }
        }
    }

    auto _operation_parameters(operation_a const & operation, bool const types, bool const arguments) -> void
    {
        _out << R"#(()#";
        bool first = true;
        for (auto const & parameter : operation.parameters())
        {
            if (first)
            {
                first = false;
            }
            else
            {
                _out << R"#(, )#";
            }
            if (types)
            {
                _out << parameter.type() << R"#( )#";
            }
            _out << parameter.name();
            if (arguments && !parameter.argument().empty())
            {
                _out << R"#( = )#" << parameter.argument();
            }
        }
        _out << R"#())#";
    }

};
}