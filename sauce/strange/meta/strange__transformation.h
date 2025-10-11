#pragma once
#include "../strange.h"
#include <sstream>
#include <ostream>
#include <iostream>
#include <algorithm>
#include <unordered_set>

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
        _out << R"#(#include <memory>
#include <string>
#include <type_traits>
#include <unordered_set>
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
        _reflections();
        _declarations();
        _definitions();
    }

    auto _forward_declarations() -> void
    {
        for (auto const & abstraction : _space.abstractions())
        {
            _out << R"#(
)#";
            _abstraction_parameters(abstraction, true, true, false, false);
            _out << R"#(struct )#" << abstraction.name() << R"#(;

)#";
            _abstraction_implementation(abstraction, true);
            _abstraction_parameters(abstraction, true, true, true, false);
            _out << R"#(struct )#" << abstraction.name() << R"#(_;
)#";
        }
        _out << R"#(
)#";
    }

    auto _reflections() -> void
    {
        _out << R"#(}

namespace strange
{
)#";
        for (auto const & abstraction : _space.abstractions())
        {
            _out << R"#(
)#";
            _abstraction_parameters(abstraction, true, false, false, true);
            _out << R"#(struct reflection<)#" << _space.name() << R"#(::)#";
            _abstraction_name_and_parameters(abstraction);
            _out << R"#(>
{
    static inline auto name() -> std::string
    {
        return ")#" << _space.name() << R"#(::)#" << abstraction.name();
            _abstraction_parameters(abstraction, false, false, false, true);
            _out << R"#(";
    }
};

)#";
            _abstraction_parameters(abstraction, true, false, true, false);
            _out << R"#(struct reflection<)#" << _space.name() << R"#(::)#" << abstraction.name() << R"#(_)#";
            _abstraction_parameters(abstraction, false, false, true, false);
            _out << R"#(>
{
    static inline auto name() -> std::string
    {
        return ")#" << _space.name() << R"#(::)#" << abstraction.name() << R"#(_)#";
            _abstraction_parameters(abstraction, false, false, true, true);
            _out << R"#(";
    }
};
)#";
            if (!abstraction.implementation().empty())
            {
                _out << R"#(
)#";
                _abstraction_parameters(abstraction, true, false, false, true);
                _out << R"#(struct reflection<)#" << abstraction.implementation();
                _abstraction_parameters(abstraction, false, false, false, true);
                _out << R"#(>
{
    static inline auto name() -> std::string
    {
        return ")#" << abstraction.implementation();
                _abstraction_parameters(abstraction, false, false, false, true);
                _out << R"#(";
    }
};
)#";
            }
        }
        _out << R"#(
}

namespace )#" << _space.name() << R"#(
{

)#";
    }

    auto _declarations() -> void
    {
        for (auto const & abstraction : _space.abstractions())
        {
            // type-erased version
            _abstraction_parameters(abstraction, true, false, false, false);
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

)#";
            _abstraction_types(abstraction);
            _out << R"#(protected:
    struct _derived : )#";
            _abstraction_parents(abstraction, true);
            _out << R"#(
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename )#" << abstraction.name()
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
                std::unordered_set<strange::operation> unique;
                _abstraction_operations(abstraction, abstraction, true, true, false, false, unique);
            }
            _out << R"#(    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename )#" << abstraction.name() << R"#(::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> )#" << abstraction.name() << R"#(
    {
        try
        {
            return )#" << abstraction.name() << R"#({strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return )#" << abstraction.name() << R"#({};
        }
    }

    inline auto _reproduce() const -> )#" << abstraction.name() << R"#(
    {
        try
        {
            return )#" << abstraction.name() << R"#({strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return )#" << abstraction.name() << R"#({};
        }
    }

    inline auto _weak() const -> )#" << abstraction.name() << R"#(
    {
        return )#" << abstraction.name() << R"#({strange::_common::_weak_base()};
    }

    inline auto _strong() const -> )#" << abstraction.name() << R"#(
    {
        return )#" << abstraction.name() << R"#({strange::_common::_shared->_strong()};
    }

    template<typename _Thing)#";
    if (!abstraction.thing().empty())
    {
        _out << R"#( = )#" << abstraction.thing();
    }
    _out << R"#(, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> )#" << abstraction.name() << R"#(
    {
        return )#" << abstraction.name() << R"#({)#" << abstraction.name() << R"#(::_derived::_static_shared_to_base(std::make_shared<typename )#"
            << abstraction.name() << R"#(_)#";
            _abstraction_parameters(abstraction, false, false, true, false);
            _out << R"#(::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> )#" << abstraction.name() << R"#(
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return )#" << abstraction.name() << R"#({};
        }
        return )#" << abstraction.name() << R"#({it->second()};
    }

    using _Abstraction_ = )#" << abstraction.name() << R"#(;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
)#";
            for (auto const & parent : abstraction.parents())
            {
                _out << R"#(        cats.insert()#" << parent << R"#(::_cats_.cbegin(), )#" << parent << R"#(::_cats_.cend());
)#";
            }
            _out << R"#(        cats.insert(_cat_);
        return cats;
    }();
)#";
            {
                std::unordered_set<strange::operation> unique;
                _abstraction_operations(abstraction, abstraction, false, false, false, false, unique);
            }
            _out << R"#(};

)#";
            // type-unerased version
            _abstraction_parameters(abstraction, true, false, true, false);
            _out << R"#(struct )#" << abstraction.name() << R"#(_ : )#";
            _abstraction_name_and_parameters(abstraction);
            _out << R"#(
{
    inline )#" << abstraction.name() << R"#(_() = default;

    inline )#" << abstraction.name() << R"#(_()#" << abstraction.name() << R"#(_ const & other)
    :strange::_common{other}
    ,)#";
            _abstraction_name_and_parameters(abstraction);
            _out << R"#({}
    {
    }

    inline )#" << abstraction.name() << R"#(_()#" << abstraction.name() << R"#(_ && other)
    :strange::_common{std::move(other)}
    ,)#";
            _abstraction_name_and_parameters(abstraction);
            _out << R"#({}
    {
    }

    inline auto operator=()#" << abstraction.name() << R"#(_ const & other) -> )#" << abstraction.name() << R"#(_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=()#" << abstraction.name() << R"#(_ && other) -> )#" << abstraction.name() << R"#(_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline )#" << abstraction.name() << R"#(_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,)#";
            _abstraction_name_and_parameters(abstraction);
            _out << R"#({}
    {
    }

    explicit inline )#" << abstraction.name() << R"#(_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,)#";
            _abstraction_name_and_parameters(abstraction);
            _out << R"#({}
    {
    }

private:
    friend struct )#";
            _abstraction_name_and_parameters(abstraction);
            _out << R"#(;

    struct _instance final : )#";
            _abstraction_name_and_parameters(abstraction);
            _out << R"#(::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :)#" << abstraction.name() << R"#(_::_derived{}
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
            _out << R"#(                return )#" << abstraction.name() << R"#(_::_derived::_static_shared_to_base(std::make_shared<)#"
                << abstraction.name() << R"#(_::_instance>(_thing));
            }
            else
            {
                throw strange::_common::_no_copy{};
            }
        }

        inline auto _reproduce() const -> std::shared_ptr<strange::_common::_base> final
        {
            if constexpr (std::is_default_constructible_v<_Thing>)
            {
)#";
            _out << R"#(                return )#" << abstraction.name() << R"#(_::_derived::_static_shared_to_base(std::make_shared<)#"
                << abstraction.name() << R"#(_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return )#";
            _abstraction_name_and_parameters(abstraction);
            _out << R"#(::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return )#";
            _abstraction_name_and_parameters(abstraction);
            _out << R"#(::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return )#" << abstraction.name() << R"#(_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return )#" << abstraction.name() << R"#(_::_name_;
        }
)#";
            {
                std::unordered_set<strange::operation> unique;
                _abstraction_operations(abstraction, abstraction, true, false, false, false, unique);
            }
            _out << R"#(
        _Thing _thing;
    };

public:
    template<typename ... _Args>
    static inline auto _make_(_Args && ... _args) -> )#" << abstraction.name() << R"#(_
    {
        return )#" << abstraction.name() << R"#(_{)#" << abstraction.name() << R"#(_::_derived::_static_shared_to_base(std::make_shared<)#" << abstraction.name() << R"#(_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> )#" << abstraction.name() << R"#(_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return )#" << abstraction.name() << R"#(_{};
        }
        return )#" << abstraction.name() << R"#(_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<)#" << abstraction.name() << R"#(_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> )#" << abstraction.name() << R"#(_
    {
        try
        {
            return )#" << abstraction.name() << R"#(_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return )#" << abstraction.name() << R"#(_{};
        }
    }

    inline auto _reproduce_() const -> )#" << abstraction.name() << R"#(_
    {
        try
        {
            return )#" << abstraction.name() << R"#(_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return )#" << abstraction.name() << R"#(_{};
        }
    }

    inline auto _weak_() const -> )#" << abstraction.name() << R"#(_
    {
        return )#" << abstraction.name() << R"#(_{strange::_common::_weak_base()};
    }

    inline auto _strong_() const -> )#" << abstraction.name() << R"#(_
    {
        return )#" << abstraction.name() << R"#(_{strange::_common::_shared->_strong()};
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<)#" << abstraction.name() << R"#(_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<)#" << abstraction.name() << R"#(_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = )#" << abstraction.name() << R"#(_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return )#" << abstraction.name() << R"#(_::_derived::_static_shared_to_base(std::make_shared<)#" << abstraction.name() << R"#(_::_instance>());
            });
        }
        return name;
    }();
};

)#";
            _abstraction_implementation(abstraction, false);
        }
    }

    auto _definitions() -> void
    {
        for (auto const & abstraction : _space.abstractions())
        {
            {
                std::unordered_set<strange::operation> unique;
                _abstraction_operations(abstraction, abstraction, false, false, true, false, unique);
            }
            {
                std::unordered_set<strange::operation> unique;
                _abstraction_operations(abstraction, abstraction, true, false, true, false, unique);
            }
        }
        _out << R"#(}
)#";
        for (auto const & abstraction : _space.abstractions())
        {
            std::unordered_set<strange::operation> unique;
            _abstraction_operations(abstraction, abstraction, false, false, true, true, unique);
        }
    }

    auto _abstraction_name_and_parameters(strange::abstraction const & abstraction) -> void
    {
        _out << abstraction.name();
        _abstraction_parameters(abstraction, false, false, false, false);
    }

    auto _abstraction_parameters(strange::abstraction const & abstraction, bool const types, bool const arguments, bool const thing, bool const reflection) -> void
    {
        if (thing || (types && reflection) || !abstraction.parameters().empty())
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
                if (arguments)
                {
                    _out << R"#(typename _Thing)#";
                    if (abstraction.parameters().empty() && !abstraction.thing().empty())
                    {
                        _out << R"#( = )#" << abstraction.thing();
                    }
                    _out << R"#(, bool _Copy)#";
                    if (abstraction.parameters().empty())
                    {
                        _out << R"#( = std::is_copy_constructible_v<_Thing>)#";
                    }
                }
                else if (types)
                {
                    _out << R"#(typename _Thing, bool _Copy)#";
                }
                else if (reflection)
                {
                    _out << R"#(" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ")#";
                }
                else
                {
                    _out << R"#(_Thing, _Copy)#";
                }
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
                else if (reflection)
                {
                    _out << R"#(" + reflection<)#";
                }
                _out << parameter.name();
                if (reflection && !types)
                {
                    _out << R"#(>::name() + ")#";
                }
                else if (arguments && ((!thing) || !abstraction.thing().empty()) && !parameter.argument().empty())
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

    auto _abstraction_parents(strange::abstraction const & abstraction, bool const inner) -> void
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

    auto _abstraction_default_construct_bases(strange::abstraction const & abstraction) -> void
    {
        for (auto const & parent : abstraction.parents())
        {
            _out << R"#(    ,)#" << parent << R"#({}
)#";
        }
    }

    auto _abstraction_implementation(strange::abstraction const & abstraction, bool const forward) -> void
    {
        if (abstraction.implementation().empty())
        {
            return;
        }
        _out << R"#(}

)#";
        std::istringstream imp{abstraction.implementation()};
        std::string name;
        std::string last;
        int64_t depth = 0;
        while (std::getline(imp, name, ':'))
        {
            if (name.empty())
            {
                continue;
            }
            if (!last.empty())
            {
                _out << R"#(namespace )#" << last << R"#(
{
)#";
                ++depth;
            }
            last = name;
        }
        _abstraction_parameters(abstraction, true, true, false, false);
        _out << R"#(struct )#" << last;
        if (!forward)
        {
            _out << R"#(
{
)#";
            {
                std::unordered_set<strange::operation> unique;
                _abstraction_operations(abstraction, abstraction, false, false, false, true, unique);
            }
            for (auto const & parent : abstraction.parents())
            {
                if ((_space.name() == "strange" && parent == "stuff")
                    || parent == "strange::stuff")
                {
                    _out << R"#(
    inline auto pack(strange::bag & dest) const -> void
    {
        dest.from_object();
)#";
                    {
                        std::unordered_set<strange::operation> unique;
                        for (auto const & operation : abstraction.operations())
                        {
                            if (operation.implementation().empty() || (!operation.data()) || operation.constness() || unique.count(operation))
                            {
                                continue;
                            }
                            unique.insert(operation);
                            if (operation.result() == "bool &")
                            {
                                _out << R"#(        dest.insert_object(")#" << operation.name() << R"#(", dest.make_bool()#" << operation.name() << R"#(()));
)#";
                            }
                            else if (operation.result() == "int64_t &")
                            {
                                _out << R"#(        dest.insert_object(")#" << operation.name() << R"#(", dest.make_int64()#" << operation.name() << R"#(()));
)#";
                            }
                            else if (operation.result() == "uint64_t &")
                            {
                                _out << R"#(        dest.insert_object(")#" << operation.name() << R"#(", dest.make_uint64()#" << operation.name() << R"#(()));
)#";
                            }
                            else if (operation.result() == "double &")
                            {
                                _out << R"#(        dest.insert_object(")#" << operation.name() << R"#(", dest.make_double()#" << operation.name() << R"#(()));
)#";
                            }
                            else if (operation.result() == "std::string &")
                            {
                                _out << R"#(        dest.insert_object(")#" << operation.name() << R"#(", dest.make_string()#" << operation.name() << R"#(()));
)#";
                            }
                            else if (operation.result() == "std::vector<strange::bag> &")
                            {
                                _out << R"#(        dest.insert_object(")#" << operation.name() << R"#(", dest.make_array()#" << operation.name() << R"#(()));
)#";
                            }
                            else if (operation.result() == "std::vector<bool> &")
                            {
                                _out << R"#(        dest.insert_object(")#" << operation.name() << R"#(", dest.make_array_bool()#" << operation.name() << R"#(()));
)#";
                            }
                            else if (operation.result() == "std::vector<int64_t> &")
                            {
                                _out << R"#(        dest.insert_object(")#" << operation.name() << R"#(", dest.make_array_int64()#" << operation.name() << R"#(()));
)#";
                            }
                            else if (operation.result() == "std::vector<uint64_t> &")
                            {
                                _out << R"#(        dest.insert_object(")#" << operation.name() << R"#(", dest.make_array_uint64()#" << operation.name() << R"#(()));
)#";
                            }
                            else if (operation.result() == "std::vector<double> &")
                            {
                                _out << R"#(        dest.insert_object(")#" << operation.name() << R"#(", dest.make_array_double()#" << operation.name() << R"#(()));
)#";
                            }
                            else if (operation.result() == "std::vector<std::string> &")
                            {
                                _out << R"#(        dest.insert_object(")#" << operation.name() << R"#(", dest.make_array_string()#" << operation.name() << R"#(()));
)#";
                            }
                            else if (operation.result().substr(0, 12) == "std::vector<")
                            {
                                _out << R"#(        {
            auto _array = dest.make_array();
            for (auto const & _item : )#" << operation.name() << R"#(())
            {
                _array.push_back_array(dest.make_any(_item));
            }
            dest.insert_object(")#" << operation.name() << R"#(", _array);
        }
)#";
                            }
                            else if (operation.result() == "std::unordered_map<std::string, bag> &")
                            {
                                _out << R"#(        dest.insert_object(")#" << operation.name() << R"#(", dest.make_object()#" << operation.name() << R"#(()));
)#";
                            }
                            else
                            {
                                _out << R"#(        dest.insert_object(")#" << operation.name() << R"#(", dest.make_any()#" << operation.name() << R"#(()));
)#";
                            }
                        }
                    }
                    _out << R"#(    }

    inline auto unpack(strange::bag const & src) -> void
    {
)#";
                    {
                        std::unordered_set<strange::operation> unique;
                        for (auto const & operation : abstraction.operations())
                        {
                            if (operation.implementation().empty() || (!operation.data()) || operation.constness() || unique.count(operation))
                            {
                                continue;
                            }
                            unique.insert(operation);
                            if (operation.result() == "bool &")
                            {
                                _out << R"#(        src.get_object(")#" << operation.name() << R"#(").as_bool()#" << operation.name() << R"#(());
)#";
                            }
                            else if (operation.result() == "int64_t &")
                            {
                                _out << R"#(        src.get_object(")#" << operation.name() << R"#(").as_int64()#" << operation.name() << R"#(());
)#";
                            }
                            else if (operation.result() == "uint64_t &")
                            {
                                _out << R"#(        src.get_object(")#" << operation.name() << R"#(").as_uint64()#" << operation.name() << R"#(());
)#";
                            }
                            else if (operation.result() == "double &")
                            {
                                _out << R"#(        src.get_object(")#" << operation.name() << R"#(").as_double()#" << operation.name() << R"#(());
)#";
                            }
                            else if (operation.result() == "std::string &")
                            {
                                _out << R"#(        src.get_object(")#" << operation.name() << R"#(").as_string()#" << operation.name() << R"#(());
)#";
                            }
                            else if (operation.result() == "std::vector<strange::bag> &")
                            {
                                _out << R"#(        src.get_object(")#" << operation.name() << R"#(").as_array()#" << operation.name() << R"#(());
)#";
                            }
                            else if (operation.result() == "std::vector<bool> &")
                            {
                                _out << R"#(        src.get_object(")#" << operation.name() << R"#(").as_array_bool()#" << operation.name() << R"#(());
)#";
                            }
                            else if (operation.result() == "std::vector<int64_t> &")
                            {
                                _out << R"#(        src.get_object(")#" << operation.name() << R"#(").as_array_int64()#" << operation.name() << R"#(());
)#";
                            }
                            else if (operation.result() == "std::vector<uint64_t> &")
                            {
                                _out << R"#(        src.get_object(")#" << operation.name() << R"#(").as_array_uint64()#" << operation.name() << R"#(());
)#";
                            }
                            else if (operation.result() == "std::vector<double> &")
                            {
                                _out << R"#(        src.get_object(")#" << operation.name() << R"#(").as_array_double()#" << operation.name() << R"#(());
)#";
                            }
                            else if (operation.result() == "std::vector<std::string> &")
                            {
                                _out << R"#(        src.get_object(")#" << operation.name() << R"#(").as_array_string()#" << operation.name() << R"#(());
)#";
                            }
                            else if (operation.result().substr(0, 12) == "std::vector<")
                            {
                                _out << R"#(        {
            auto _array = src.get_object(")#" << operation.name() << R"#(").to_array();
            auto _size = _array.size();
            )#" << operation.name() << R"#(().clear();
            )#" << operation.name() << R"#(().resize(_size);
            for (std::size_t _index = 0; _index < _size; ++_index)
            {
                _array[_index].as_any()#" << operation.name() << R"#(()[_index]);
            }
        }
)#";
                            }
                            else if (operation.result() == "std::unordered_map<std::string, bag> &")
                            {
                                _out << R"#(        src.get_object(")#" << operation.name() << R"#(").as_object()#" << operation.name() << R"#(());
)#";
                            }
                            else
                            {
                                _out << R"#(        src.get_object(")#" << operation.name() << R"#(").as_any()#" << operation.name() << R"#(());
)#";
                            }
                        }
                    }
                    _out << R"#(    }
)#";
                    break;
                }
            }
            _out << R"#(})#";
        }
        _out << R"#(;
)#";
        while (--depth)
        {
            _out << R"#(}
)#";
        }
        _out << R"#(}

namespace )#" << _space.name() << R"#(
{

)#";
    }

    auto _find_parent(std::string const & parent, std::string const & space) -> strange::abstraction
    {
        auto name = parent.substr(0, parent.find('<'));
        auto match = [& name](strange::abstraction const & candidate)
            {
                return candidate.name() == name;
            };
        auto it = std::find_if(_space.abstractions().cbegin(), _space.abstractions().cend(), match);
        if (it != _space.abstractions().cend())
        {
            return *it;
        }
        it = std::find_if(_space.inclusions().cbegin(), _space.inclusions().cend(), match);
        if (it != _space.inclusions().cend())
        {
            return *it;
        }
        if (!space.empty())
        {
            name = space + name;
            it = std::find_if(_space.inclusions().cbegin(), _space.inclusions().cend(), match);
            if (it != _space.inclusions().cend())
            {
                return *it;
            }
        }
        _out << R"#(static_assert(false, "strange abstraction parent not recognised: )#" << parent << R"#(");
)#";
        return strange::abstraction{};
    }

    auto _abstraction_operations(strange::abstraction const & abstraction, strange::abstraction const & derived, bool const inner, bool const pure, bool const definition, bool const implementation, std::unordered_set<strange::operation> & unique, std::string const & name = std::string{}) -> void
    {
        if ((!inner) || !pure)
        {
            // override base class operations as well
            std::string space;
            auto name = abstraction.name();
            auto pos = name.find("::");
            if (pos != std::string::npos)
            {
                space = name.substr(0, pos + 2);
            }
            for (auto const & parent : abstraction.parents())
            {
                auto recurse = _find_parent(parent, space);
                if (recurse._something())
                {
                    _abstraction_operations(recurse, derived, inner, pure, definition, implementation, unique, parent);
                }
            }
        }
        for (auto const & operation : abstraction.operations())
        {
            if (unique.count(operation))
            {
                continue;
            }
            unique.insert(operation);
            if (implementation)
            {
                if (operation.implementation().empty())
                {
                    continue;
                }
                else if (operation.data())
                {
                    if (operation.constness() && !definition)
                    {
                        _out << R"#(    )#" << operation.result().substr(0, operation.result().length() - 7)
                            << operation.name() << R"#(_ )#" << operation.implementation() << R"#(;
)#";
                    }
                }
                if (!definition)
                {
                    _out << R"#(    inline auto )#" << operation.name();
                    _operation_parameters(operation, true, true);
                    if (operation.constness())
                    {
                        _out << R"#( const -> )#";
                    }
                    else
                    {
                        _out << R"#( -> )#";
                    }
                    _out << operation.result();
                    if (operation.data())
                    {
                        _out << R"#( { return )#" << operation.name() << R"#(_; })#";
                    }
                    _out << R"#(;
)#";
                }
                else if (!operation.data())
                {
                    _out << R"#(
)#";
                    std::istringstream imp{abstraction.implementation()};
                    std::string name;
                    std::string last;
                    int64_t depth = 0;
                    while (std::getline(imp, name, ':'))
                    {
                        if (name.empty())
                        {
                            continue;
                        }
                        if (!last.empty())
                        {
                            _out << R"#(namespace )#" << last << R"#(
{
)#";
                            ++depth;
                        }
                        last = name;
                    }
                    _abstraction_parameters(derived, true, false, inner, false);
                    _out << R"#(inline auto )#" << last << R"#(::)#" << operation.name();
                    _operation_parameters(operation, true, false);
                    if (operation.constness())
                    {
                        _out << R"#( const -> )#";
                    }
                    else
                    {
                        _out << R"#( -> )#";
                    }
                    _out << operation.result() << R"#(
)#" << operation.implementation() << R"#(
)#";
                    while (depth--)
                    {
                        _out << R"#(}
)#";
                    }
                }
                continue;
            }
            for (int64_t fun = 0; fun < 2; ++fun)
            {
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
                    _abstraction_parameters(derived, true, false, inner, false);
                    _out << R"#(inline )#";
                }
                if (!definition)
                {
                    _out << R"#(auto )#" << (fun ? operation.closure() : operation.name());
                }
                else
                {
                    _out << R"#(auto )#" << derived.name();
                    if (inner)
                    {
                        _out << R"#(_)#";
                    }
                    _abstraction_parameters(derived, false, false, inner, false);
                    if (inner)
                    {
                        _out << R"#(::_instance::)#";
                    }
                    else
                    {
                        _out << R"#(::)#";
                    }
                    _out << (fun ? operation.closure() : operation.name());
                }
                if (fun)
                {
                    _out << R"#(())#";
                }
                else
                {
                    _operation_parameters(operation, true, (!definition) && (!pure) && !inner);
                }
                if (operation.constness())
                {
                    _out << R"#( const -> )#";
                }
                else
                {
                    _out << R"#( -> )#";
                }
                bool const that = (operation.result() == "*that");
                bool const this_or_that = (that || (operation.result() == "*this"));
                bool const this_or_that_or_void = (this_or_that || (operation.result() == "void"));
                if (fun)
                {
                    _out << R"#(std::function<auto )#";
                    _operation_parameters(operation, true, false);
                    _out << R"#( -> )#";
                }
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
                if (fun)
                {
                    _out << R"#(>)#";
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
                        if (fun)
                        {
                            _out << R"#(return [this])#";
                            _operation_parameters(operation, true, false);
                            _out << R"#( -> )#";
                            if (this_or_that)
                            {
                                _out << "void";
                            }
                            else
                            {
                                _out << operation.result();
                            }
                            _out << R"#(
    {
        )#";
                        }
                        if (!operation.customisation().empty())
                        {
                            _out << operation.customisation();
                        }
                        else if (this_or_that_or_void)
                        {
                            _out << R"#(_thing.)#" << operation.name();
                        }
                        else
                        {
                            _out << R"#(return _thing.)#" << operation.name();
                        }
                    }
                    else if (operation.modification().empty())
                    {
                        if (that && !fun)
                        {
                            _out << R"#(auto _result = *this;
    )#";
                        }
                        if (!operation.constness())
                        {
                            _out << R"#(strange::_common::_mutate();
    )#";
                        }
                        if (this_or_that_or_void && !fun)
                        {
                            _out << R"#(std::dynamic_pointer_cast<typename )#";
                        }
                        else
                        {
                            _out << R"#(return std::dynamic_pointer_cast<typename )#";
                        }
                        if (name.empty())
                        {
                            _out << abstraction.name();
                            _abstraction_parameters(abstraction, false, false, false, false);
                        }
                        else
                        {
                            _out << name;
                        }
                        _out << R"#(::_derived)#";
                        if (operation.constness())
                        {
                            _out << R"#( const)#";
                        }
                        _out << R"#(>(strange::_common::_shared)->)#" << (fun ? operation.closure() : operation.name());
                    }
                    if ((operation.modification().empty() && !inner) || operation.customisation().empty())
                    {
                        if (fun && !inner)
                        {
                            _out << R"#(())#";
                        }
                        else
                        {
                            _operation_parameters(operation, false, false);
                        }
                    }
                    if (fun)
                    {
                        _out << R"#(;)#";
                        if (inner)
                        {
                            _out << R"#(
    };)#";
                        }
                    }
                    else if ((!inner) && !operation.modification().empty())
                    {
                        _out << operation.modification();
                    }
                    else if (this_or_that && (!inner))
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
                if (operation.closure().empty())
                {
                    break;
                }
            }
        }
    }

    auto _operation_parameters(strange::operation const & operation, bool const types, bool const arguments) -> void
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
                _out << parameter.type() << R"#( )#" << parameter.name();
                if (arguments && !parameter.argument().empty())
                {
                    _out << R"#( = )#" << parameter.argument();
                }
            }
            else if ((parameter.type().length() >= 2) && (parameter.type().substr(parameter.type().length() - 2) == "&&"))
            {
                _out << R"#(std::move()#" << parameter.name() << R"#())#";
            }
            else
            {
                _out << parameter.name();
            }
        }
        _out << R"#())#";
    }

    auto _abstraction_types(strange::abstraction const & abstraction) -> void
    {
        for (auto const & type : abstraction.types())
        {
            _out << R"#(    )#" << type.type() << R"#( )#" << type.name() << R"#( = )#" << type.argument() << R"#(;

)#";
        }
    }
};
}
