// Code generation engine that transforms a parsed strange::space definition into
// C++ code. Generates forward declarations, reflection specializations, type-erased
// wrapper structs, implementation templates, pack/unpack serialization, closures,
// and factory registration.

#pragma once
#include "../strange.h"
#include "../comprehension/strange__comprehension__parser.h"
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
        for (auto const & include : _space.includes())
        {
            _out << R"#(#include <)#" << include << R"#(>
)#";
        }
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
        _hashes();
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
{)#";
            _generate_constructors(abstraction.name(), [&]() {
                _abstraction_default_construct_bases(abstraction);
            });
            _abstraction_types(abstraction);
            _generate_derived_struct(abstraction);
            _out << R"#(public:
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
    _out << R"#(, bool _Copy = std::is_copy_constructible_v<_Thing>, typename... _Args>
    static inline auto _make(_Args && ..._args) -> )#" << abstraction.name() << R"#(
    {
        return )#" << abstraction.name() << R"#({)#" << abstraction.name() << R"#(::_derived::_static_shared_to_base(std::make_shared<typename )#"
            << abstraction.name() << R"#(_)#";
            _abstraction_parameters(abstraction, false, false, true, false);
            _out << R"#(::_instance>(std::forward<_Args>(_args)...))};
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
                _abstraction_operations(abstraction, abstraction, _gen_mode::type_erased_decl, unique);
            }
            _out << R"#(};

)#";
            // type-unerased version
            _abstraction_parameters(abstraction, true, false, true, false);
            _out << R"#(struct )#" << abstraction.name() << R"#(_ : )#";
            _abstraction_name_and_parameters(abstraction);
            _out << R"#(
{)#";
            _generate_constructors(abstraction.name() + "_", [&]() {
                _out << R"#(    ,)#";
                _abstraction_name_and_parameters(abstraction);
                _out << R"#({}
)#";
            });
            _out << R"#(private:
    friend struct )#";
            _abstraction_name_and_parameters(abstraction);
            _out << R"#(;

)#";
            _generate_instance_struct(abstraction);
            _out << R"#(public:
    template<typename... _Args>
    static inline auto _make_(_Args && ..._args) -> )#" << abstraction.name() << R"#(_
    {
        return )#" << abstraction.name() << R"#(_{)#" << abstraction.name() << R"#(_::_derived::_static_shared_to_base(std::make_shared<)#" << abstraction.name() << R"#(_::_instance>(std::forward<_Args>(_args)...))};
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
                _abstraction_operations(abstraction, abstraction, _gen_mode::type_erased_def, unique);
            }
            {
                std::unordered_set<strange::operation> unique;
                _abstraction_operations(abstraction, abstraction, _gen_mode::inner_def, unique);
            }
        }
        _out << R"#(}
)#";
        for (auto const & abstraction : _space.abstractions())
        {
            std::unordered_set<strange::operation> unique;
            _abstraction_operations(abstraction, abstraction, _gen_mode::impl_def, unique);
        }
    }

    auto _hashes() -> void
    {
        for (auto const & abstraction : _space.abstractions())
        {
            if (!abstraction.hash() || !abstraction.parameters().empty())
            {
                continue;
            }
            _out << R"#(
template<>
struct std::hash<)#" << _space.name() << R"#(::)#" << abstraction.name() << R"#(>
{
    inline auto operator()()#" << _space.name() << R"#(::)#" << abstraction.name() << R"#( const & _obj) const -> size_t
    {
)#";
            bool first = true;
            for (auto const & operation : abstraction.operations())
            {
                if (!operation.data() || operation.constness())
                {
                    continue;
                }
                auto result = operation.result();
                if (result.length() >= 2 && result.substr(result.length() - 2) == " &")
                {
                    result = result.substr(0, result.length() - 2);
                }
                bool const is_vector = (result.length() >= 12 && result.substr(0, 12) == "std::vector<");
                if (first)
                {
                    first = false;
                    if (is_vector)
                    {
                        _out << R"#(        auto _h = strange::hash_range(_obj.)#" << operation.name() << R"#(());
)#";
                    }
                    else
                    {
                        _out << R"#(        auto _h = strange::hash_init(_obj.)#" << operation.name() << R"#(());
)#";
                    }
                }
                else
                {
                    if (is_vector)
                    {
                        _out << R"#(        strange::hash_combine(_h, strange::hash_range(_obj.)#" << operation.name() << R"#(()));
)#";
                    }
                    else
                    {
                        _out << R"#(        strange::hash_combine(_h, _obj.)#" << operation.name() << R"#(());
)#";
                    }
                }
            }
            _out << R"#(        return _h;
    }
};
)#";
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
                    bool can_default = true;
                    for (auto const & parameter : abstraction.parameters())
                    {
                        if (parameter.argument().empty())
                        {
                            can_default = false;
                            break;
                        }
                    }
                    _out << R"#(typename _Thing)#";
                    if (can_default && !abstraction.thing().empty())
                    {
                        _out << R"#( = )#" << abstraction.thing();
                    }
                    _out << R"#(, bool _Copy)#";
                    if (can_default)
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
                    _out << R"#(" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + )#";
                    if (abstraction.parameters().empty())
                    {
                        _out << R"#(")#";
                    }
                }
                else
                {
                    _out << R"#(_Thing, _Copy)#";
                }
            }
            if (reflection && (!types) && !abstraction.parameters().empty())
            {
                if (!thing)
                {
                    _out << R"#(" + )#";
                }
                _out << R"#(concatename<)#" << (thing ? R"#(true, )#" : R"#(false, )#");
                first = true;
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
                    _out << parameter.type();
                    if (parameter.variadic())
                    {
                        _out << R"#(...)#";
                    }
                    _out << R"#( )#";
                }
                _out << parameter.name();
                if (parameter.variadic() && !types)
                {
                    _out << R"#(...)#";
                }
                else if (arguments && !parameter.argument().empty())
                {
                    _out << R"#( = )#" << parameter.argument();
                }
            }
            if (types)
            {
                _out << R"#(>
)#";
            }
            else if (reflection && !abstraction.parameters().empty())
            {
                _out << R"#(>() + ">)#";
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

    auto _generate_constructors(std::string const & name, std::function<void()> const & base_init) -> void
    {
        _out << R"#(
    inline )#" << name << R"#(() = default;

    inline )#" << name << R"#(()#" << name << R"#( const & other)
    :strange::_common{other}
)#";
        base_init();
        _out << R"#(    {
    }

    inline )#" << name << R"#(()#" << name << R"#( && other)
    :strange::_common{std::move(other)}
)#";
        base_init();
        _out << R"#(    {
    }

    inline auto operator=()#" << name << R"#( const & other) -> )#" << name << R"#( &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=()#" << name << R"#( && other) -> )#" << name << R"#( &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline )#" << name << R"#((std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
)#";
        base_init();
        _out << R"#(    {
    }

    explicit inline )#" << name << R"#((std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
)#";
        base_init();
        _out << R"#(    {
    }

)#";
    }

    auto _abstraction_default_construct_bases(strange::abstraction const & abstraction) -> void
    {
        for (auto const & parent : abstraction.parents())
        {
            _out << R"#(    ,)#" << parent << R"#({}
)#";
        }
    }

    // Splits a qualified name (e.g., "strange::implementation::baggage") into
    // namespace parts, opens namespace braces, and returns the final name and depth.
    auto _open_namespaces(std::string const & qualified) -> std::pair<std::string, int64_t>
    {
        std::istringstream imp{qualified};
        std::string part;
        std::string last;
        int64_t depth = 0;
        while (std::getline(imp, part, ':'))
        {
            if (part.empty())
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
            last = part;
        }
        return {last, depth};
    }

    auto _generate_derived_struct(strange::abstraction const & abstraction) -> void
    {
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
            _abstraction_operations(abstraction, abstraction, _gen_mode::pure_virtual_decl, unique);
        }
        _out << R"#(    };

)#";
    }

    auto _generate_instance_struct(strange::abstraction const & abstraction) -> void
    {
        _out << R"#(    struct _instance final : )#";
        _abstraction_name_and_parameters(abstraction);
        _out << R"#(::_derived
    {
        template<typename... _Args>
        inline _instance(_Args && ..._args)
        :)#" << abstraction.name() << R"#(_::_derived{}
        ,_thing{std::forward<_Args>(_args)...}
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
            _abstraction_operations(abstraction, abstraction, _gen_mode::inner_decl, unique);
        }
        _out << R"#(
        _Thing _thing;
    };

)#";
    }

    struct _pack_entry { std::string result_type; std::string pack_method; std::string unpack_method; };

    static inline std::vector<_pack_entry> const & _pack_table()
    {
        static std::vector<_pack_entry> const table = {
            {"bool &",                                  "make_bool",        "as_bool"},
            {"int64_t &",                               "make_int64",       "as_int64"},
            {"uint64_t &",                              "make_uint64",      "as_uint64"},
            {"double &",                                "make_double",      "as_double"},
            {"std::string &",                           "make_string",      "as_string"},
            {"std::vector<strange::bag> &",             "make_array",       "as_array"},
            {"std::vector<bool> &",                     "make_array_bool",  "as_array_bool"},
            {"std::vector<int64_t> &",                  "make_array_int64", "as_array_int64"},
            {"std::vector<uint64_t> &",                 "make_array_uint64","as_array_uint64"},
            {"std::vector<double> &",                   "make_array_double","as_array_double"},
            {"std::vector<std::string> &",              "make_array_string","as_array_string"},
            {"std::unordered_map<std::string, bag> &",  "make_object",      "as_object"},
        };
        return table;
    }

    auto _generate_pack_field(strange::operation const & operation) -> void
    {
        for (auto const & entry : _pack_table())
        {
            if (operation.result() == entry.result_type)
            {
                _out << R"#(        dest.insert_object(")#" << operation.name() << R"#(", dest.)#" << entry.pack_method << R"#(()#" << operation.name() << R"#(()));
)#";
                return;
            }
        }
        if (operation.result().length() >= 12 && operation.result().substr(0, 12) == "std::vector<")
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
        else
        {
            _out << R"#(        dest.insert_object(")#" << operation.name() << R"#(", dest.make_any()#" << operation.name() << R"#(()));
)#";
        }
    }

    auto _generate_unpack_field(strange::operation const & operation) -> void
    {
        for (auto const & entry : _pack_table())
        {
            if (operation.result() == entry.result_type)
            {
                _out << R"#(        src.get_object(")#" << operation.name() << R"#(").)#" << entry.unpack_method << R"#(()#" << operation.name() << R"#(());
)#";
                return;
            }
        }
        if (operation.result().length() >= 12 && operation.result().substr(0, 12) == "std::vector<")
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
        else
        {
            _out << R"#(        src.get_object(")#" << operation.name() << R"#(").as_any()#" << operation.name() << R"#(());
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
        auto [last, depth] = _open_namespaces(abstraction.implementation());
        _abstraction_parameters(abstraction, true, true, false, false);
        _out << R"#(struct )#" << last;
        if (!forward)
        {
            _out << R"#(
{
)#";
            {
                std::unordered_set<strange::operation> unique;
                _abstraction_operations(abstraction, abstraction, _gen_mode::impl_decl, unique);
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
                            _generate_pack_field(operation);
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
                            _generate_unpack_field(operation);
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
        while (depth > 1)
        {
            --depth;
            _out << R"#(}
)#";
        }
        if (depth > 0)
        {
            _out << R"#(})#";
        }
        _out << R"#(

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
            // Mutate name to include namespace prefix; the match lambda
            // captures name by reference and will use this new value.
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

    enum class _gen_mode
    {
        pure_virtual_decl,
        inner_decl,
        type_erased_decl,
        type_erased_def,
        inner_def,
        impl_decl,
        impl_def,
    };

    auto _abstraction_operations(strange::abstraction const & abstraction, strange::abstraction const & derived, _gen_mode const mode, std::unordered_set<strange::operation> & unique, std::string const & name = std::string{}) -> void
    {
        bool const inner = (mode == _gen_mode::pure_virtual_decl || mode == _gen_mode::inner_decl || mode == _gen_mode::inner_def);
        bool const pure = (mode == _gen_mode::pure_virtual_decl);
        bool const definition = (mode == _gen_mode::type_erased_def || mode == _gen_mode::inner_def || mode == _gen_mode::impl_def);
        bool const implementation = (mode == _gen_mode::impl_decl || mode == _gen_mode::impl_def);

        if ((!inner) || !pure)
        {
            // override base class operations as well
            std::string space;
            auto abs_name = abstraction.name();
            auto pos = abs_name.find("::");
            if (pos != std::string::npos)
            {
                space = abs_name.substr(0, pos + 2);
            }
            for (auto const & parent : abstraction.parents())
            {
                auto recurse = _find_parent(parent, space);
                if (recurse._something())
                {
                    _abstraction_operations(recurse, derived, mode, unique, parent);
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
                        // Strip "const &" suffix (7 chars) from result type, keeping
                        // the leading space as separator before the member name.
                        constexpr size_t const_ref_suffix = 7; // length of "const &"
                        _out << R"#(    )#" << (operation.result().length() >= const_ref_suffix ? operation.result().substr(0, operation.result().length() - const_ref_suffix) : operation.result())
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
                    auto [last, depth] = _open_namespaces(abstraction.implementation());
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
            _generate_operation_method(operation, abstraction, derived, inner, pure, definition, name);
            if (!operation.closure().empty())
            {
                _generate_closure_method(operation, abstraction, derived, inner, pure, definition, name);
            }
        }
    }

    // Shared prefix: emits leading keywords and class qualification for operation/closure signatures
    auto _generate_method_prefix(strange::abstraction const & derived, bool const inner, bool const pure, bool const definition) -> void
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
    }

    // Emits the qualified method name (for definitions) or just the name (for declarations)
    auto _generate_method_name(std::string const & method_name, strange::abstraction const & derived, bool const inner, bool const definition) -> void
    {
        if (!definition)
        {
            _out << R"#(auto )#" << method_name;
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
            _out << method_name;
        }
    }

    struct _result_flags
    {
        bool that;
        bool this_or_that;
        bool this_or_that_or_void;
    };

    // Emits the result type, handling *this/*that/void/normal, returns flags for body generation
    auto _generate_result_type(strange::operation const & operation, strange::abstraction const & derived, bool const inner, bool const pure) -> _result_flags
    {
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
        return {that, this_or_that, this_or_that_or_void};
    }

    // Emits the declaration terminator (= 0, final, or ;)
    auto _generate_decl_suffix(bool const inner, bool const pure) -> void
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

    auto _generate_operation_method(strange::operation const & operation, strange::abstraction const & abstraction, strange::abstraction const & derived, bool const inner, bool const pure, bool const definition, std::string const & name) -> void
    {
        _generate_method_prefix(derived, inner, pure, definition);
        _generate_method_name(operation.name(), derived, inner, definition);
        _operation_parameters(operation, true, (!definition) && (!pure) && !inner);
        auto [that, this_or_that, this_or_that_or_void] = _generate_result_type(operation, derived, inner, pure);
        if (!definition)
        {
            _generate_decl_suffix(inner, pure);
            return;
        }
        _out << R"#(
{
    )#";
        if (inner)
        {
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
            _out << R"#(>(strange::_common::_shared)->)#" << operation.name();
        }
        if ((operation.modification().empty() && !inner) || operation.customisation().empty())
        {
            _operation_parameters(operation, false, false);
        }
        if ((!inner) && !operation.modification().empty())
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

    auto _generate_closure_method(strange::operation const & operation, strange::abstraction const & abstraction, strange::abstraction const & derived, bool const inner, bool const pure, bool const definition, std::string const & name) -> void
    {
        _generate_method_prefix(derived, inner, pure, definition);
        _generate_method_name(operation.closure(), derived, inner, definition);
        _out << R"#(())#";
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
        // return type: std::function<auto (params) -> result>
        _out << R"#(std::function<auto )#";
        _operation_parameters(operation, true, false);
        _out << R"#( -> )#";
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
        _out << R"#(>)#";
        if (!definition)
        {
            _generate_decl_suffix(inner, pure);
            return;
        }
        _out << R"#(
{
    )#";
        if (inner)
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
            _operation_parameters(operation, false, false);
            _out << R"#(;
    };
}

)#";
            return;
        }
        else if (operation.modification().empty())
        {
            if (!operation.constness())
            {
                _out << R"#(strange::_common::_mutate();
    )#";
            }
            _out << R"#(return std::dynamic_pointer_cast<typename )#";
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
            _out << R"#(>(strange::_common::_shared)->)#" << operation.closure();
        }
        if ((operation.modification().empty() && !inner) || operation.customisation().empty())
        {
            if (!inner)
            {
                _out << R"#(())#";
            }
        }
        _out << R"#(;
}

)#";
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
                _out << parameter.type() << R"#( )#";
                if (parameter.variadic())
                {
                    _out << R"#(...)#";
                }
                _out << parameter.name();
                if (arguments && !parameter.argument().empty())
                {
                    _out << R"#( = )#" << parameter.argument();
                }
            }
            else if ((parameter.type().length() >= 2) && (parameter.type().substr(parameter.type().length() - 2) == "&&"))
            {
                if (parameter.variadic())
                {
                    auto param = parameter.type().substr(0, parameter.type().length() - 2);
                    strange::comprehension::parser::rtrim(param);
                    _out << R"#(std::forward<)#" << param << R"#(>()#" << parameter.name() << R"#()...)#";
                }
                else
                {
                    _out << R"#(std::move()#" << parameter.name() << R"#())#";
                }
            }
            else if (parameter.variadic())
            {
                _out << parameter.name() << R"#(...)#";
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
