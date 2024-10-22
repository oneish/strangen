#pragma once
#include "../../sauce/strange/common/strange__common.h"
#include "../../sauce/strange/reflection/strange__reflection.h"
#include <memory>
#include <string>
#include <type_traits>
#include <unordered_set>

namespace example
{

struct widget;

template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct widget_;

struct button;

template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct button_;

struct number;

template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct number_;

struct widget_number;

template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct widget_number_;

template<typename Data = int>
struct numeric;

template<typename Data, typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct numeric_;

}

namespace strange
{

template<>
struct reflection<example::widget>
{
    inline static auto name() -> std::string
    {
        return "example::widget";
    }
};

template<typename _Thing, bool _Copy>
struct reflection<example::widget_<_Thing, _Copy>>
{
    inline static auto name() -> std::string
    {
        return "example::widget_<" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<>
struct reflection<example::button>
{
    inline static auto name() -> std::string
    {
        return "example::button";
    }
};

template<typename _Thing, bool _Copy>
struct reflection<example::button_<_Thing, _Copy>>
{
    inline static auto name() -> std::string
    {
        return "example::button_<" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<>
struct reflection<example::number>
{
    inline static auto name() -> std::string
    {
        return "example::number";
    }
};

template<typename _Thing, bool _Copy>
struct reflection<example::number_<_Thing, _Copy>>
{
    inline static auto name() -> std::string
    {
        return "example::number_<" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<>
struct reflection<example::widget_number>
{
    inline static auto name() -> std::string
    {
        return "example::widget_number";
    }
};

template<typename _Thing, bool _Copy>
struct reflection<example::widget_number_<_Thing, _Copy>>
{
    inline static auto name() -> std::string
    {
        return "example::widget_number_<" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<typename Data>
struct reflection<example::numeric<Data>>
{
    inline static auto name() -> std::string
    {
        return "example::numeric<" + reflection<Data>::name() + ">";
    }
};

template<typename Data, typename _Thing, bool _Copy>
struct reflection<example::numeric_<Data, _Thing, _Copy>>
{
    inline static auto name() -> std::string
    {
        return "example::numeric_<" + reflection<Data>::name() + ", " + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

}

namespace example
{

struct widget : virtual strange::_common
{
    inline widget() = default;

    inline widget(widget const & other)
    :strange::_common{other}
    {
    }

    inline widget(widget && other)
    :strange::_common{std::move(other)}
    {
    }

    inline auto operator=(widget const & other) -> widget &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(widget && other) -> widget &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline widget(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    {
    }

    explicit inline widget(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    {
    }

protected:
    struct _derived : strange::_common::_base
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename widget::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return derived;
        }

        virtual auto display(button b) const -> void = 0;

        virtual auto inc() -> void = 0;

        virtual auto operator++() -> void = 0;

        virtual auto operator--(int i) -> void = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename widget::_derived const>(strange::_common::_shared).operator bool();
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> widget
    {
        return widget{widget::_derived::_static_shared_to_base(std::make_shared<typename widget_<_Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    using _Abstraction_ = widget;

    inline static std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    inline static std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(_cat_);
        return cats;
    }();

    inline auto display(button b) const -> void;

    inline auto inc() -> void;

    inline auto operator++() -> widget &;

    inline auto operator--(int i) -> widget;
};

template<typename _Thing, bool _Copy>
struct widget_ : widget
{
    inline widget_() = default;

    inline widget_(widget_ const & other)
    :strange::_common{other}
    ,widget{}
    {
    }

    inline widget_(widget_ && other)
    :strange::_common{std::move(other)}
    ,widget{}
    {
    }

    inline auto operator=(widget_ const & other) -> widget_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(widget_ && other) -> widget_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline widget_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,widget{}
    {
    }

    explicit inline widget_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,widget{}
    {
    }

private:
    friend struct widget;

    struct _instance final : widget::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :widget_::_derived{}
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
                return widget_::_derived::_static_shared_to_base(std::make_shared<widget_::_instance>(_thing));
            }
            else
            {
                throw strange::_no_copy_constructor{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return widget::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return widget::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return widget_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return widget_::_name_;
        }

        inline auto display(button b) const -> void final;

        inline auto inc() -> void final;

        inline auto operator++() -> void final;

        inline auto operator--(int i) -> void final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    inline static auto _make_(_Args && ... _args) -> widget_
    {
        return widget_{widget_::_derived::_static_shared_to_base(std::make_shared<widget_::_instance>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<widget_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<widget_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<widget_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = widget_;
    using _Thing_ = _Thing;

    inline static bool const _copy_ = _Copy;

    inline static std::string const _name_ = strange::reflection<_Kind_>::name();
};

struct button : widget
{
    inline button() = default;

    inline button(button const & other)
    :strange::_common{other}
    ,widget{}
    {
    }

    inline button(button && other)
    :strange::_common{std::move(other)}
    ,widget{}
    {
    }

    inline auto operator=(button const & other) -> button &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(button && other) -> button &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline button(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,widget{}
    {
    }

    explicit inline button(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,widget{}
    {
    }

protected:
    struct _derived : widget::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename button::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return widget::_derived::_static_shared_to_base(derived);
        }

        virtual auto push() -> void = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename button::_derived const>(strange::_common::_shared).operator bool();
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> button
    {
        return button{button::_derived::_static_shared_to_base(std::make_shared<typename button_<_Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    using _Abstraction_ = button;

    inline static std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    inline static std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(widget::_cats_.cbegin(), widget::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();

    inline auto display(button b) const -> void;

    inline auto inc() -> void;

    inline auto operator++() -> button &;

    inline auto operator--(int i) -> button;

    inline auto push() -> void;
};

template<typename _Thing, bool _Copy>
struct button_ : button
{
    inline button_() = default;

    inline button_(button_ const & other)
    :strange::_common{other}
    ,button{}
    {
    }

    inline button_(button_ && other)
    :strange::_common{std::move(other)}
    ,button{}
    {
    }

    inline auto operator=(button_ const & other) -> button_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(button_ && other) -> button_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline button_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,button{}
    {
    }

    explicit inline button_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,button{}
    {
    }

private:
    friend struct button;

    struct _instance final : button::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :button_::_derived{}
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
                return button_::_derived::_static_shared_to_base(std::make_shared<button_::_instance>(_thing));
            }
            else
            {
                throw strange::_no_copy_constructor{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return button::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return button::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return button_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return button_::_name_;
        }

        inline auto display(button b) const -> void final;

        inline auto inc() -> void final;

        inline auto operator++() -> void final;

        inline auto operator--(int i) -> void final;

        inline auto push() -> void final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    inline static auto _make_(_Args && ... _args) -> button_
    {
        return button_{button_::_derived::_static_shared_to_base(std::make_shared<button_::_instance>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<button_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<button_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<button_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = button_;
    using _Thing_ = _Thing;

    inline static bool const _copy_ = _Copy;

    inline static std::string const _name_ = strange::reflection<_Kind_>::name();
};

struct number : virtual strange::_common
{
    inline number() = default;

    inline number(number const & other)
    :strange::_common{other}
    {
    }

    inline number(number && other)
    :strange::_common{std::move(other)}
    {
    }

    inline auto operator=(number const & other) -> number &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(number && other) -> number &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline number(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    {
    }

    explicit inline number(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    {
    }

protected:
    struct _derived : strange::_common::_base
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename number::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return derived;
        }

        virtual auto inc() -> void = 0;

        virtual auto dec() -> void = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename number::_derived const>(strange::_common::_shared).operator bool();
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> number
    {
        return number{number::_derived::_static_shared_to_base(std::make_shared<typename number_<_Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    using _Abstraction_ = number;

    inline static std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    inline static std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(_cat_);
        return cats;
    }();

    inline auto inc() -> void;

    inline auto dec() -> void;
};

template<typename _Thing, bool _Copy>
struct number_ : number
{
    inline number_() = default;

    inline number_(number_ const & other)
    :strange::_common{other}
    ,number{}
    {
    }

    inline number_(number_ && other)
    :strange::_common{std::move(other)}
    ,number{}
    {
    }

    inline auto operator=(number_ const & other) -> number_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(number_ && other) -> number_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline number_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,number{}
    {
    }

    explicit inline number_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,number{}
    {
    }

private:
    friend struct number;

    struct _instance final : number::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :number_::_derived{}
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
                return number_::_derived::_static_shared_to_base(std::make_shared<number_::_instance>(_thing));
            }
            else
            {
                throw strange::_no_copy_constructor{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return number::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return number::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return number_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return number_::_name_;
        }

        inline auto inc() -> void final;

        inline auto dec() -> void final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    inline static auto _make_(_Args && ... _args) -> number_
    {
        return number_{number_::_derived::_static_shared_to_base(std::make_shared<number_::_instance>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<number_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<number_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<number_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = number_;
    using _Thing_ = _Thing;

    inline static bool const _copy_ = _Copy;

    inline static std::string const _name_ = strange::reflection<_Kind_>::name();
};

struct widget_number : widget, number
{
    inline widget_number() = default;

    inline widget_number(widget_number const & other)
    :strange::_common{other}
    ,widget{}
    ,number{}
    {
    }

    inline widget_number(widget_number && other)
    :strange::_common{std::move(other)}
    ,widget{}
    ,number{}
    {
    }

    inline auto operator=(widget_number const & other) -> widget_number &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(widget_number && other) -> widget_number &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline widget_number(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,widget{}
    ,number{}
    {
    }

    explicit inline widget_number(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,widget{}
    ,number{}
    {
    }

protected:
    struct _derived : widget::_derived, number::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename widget_number::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return widget::_derived::_static_shared_to_base(derived);
        }
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename widget_number::_derived const>(strange::_common::_shared).operator bool();
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> widget_number
    {
        return widget_number{widget_number::_derived::_static_shared_to_base(std::make_shared<typename widget_number_<_Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    using _Abstraction_ = widget_number;

    inline static std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    inline static std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(widget::_cats_.cbegin(), widget::_cats_.cend());
        cats.insert(number::_cats_.cbegin(), number::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();

    inline auto display(button b) const -> void;

    inline auto inc() -> void;

    inline auto operator++() -> widget_number &;

    inline auto operator--(int i) -> widget_number;

    inline auto dec() -> void;
};

template<typename _Thing, bool _Copy>
struct widget_number_ : widget_number
{
    inline widget_number_() = default;

    inline widget_number_(widget_number_ const & other)
    :strange::_common{other}
    ,widget_number{}
    {
    }

    inline widget_number_(widget_number_ && other)
    :strange::_common{std::move(other)}
    ,widget_number{}
    {
    }

    inline auto operator=(widget_number_ const & other) -> widget_number_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(widget_number_ && other) -> widget_number_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline widget_number_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,widget_number{}
    {
    }

    explicit inline widget_number_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,widget_number{}
    {
    }

private:
    friend struct widget_number;

    struct _instance final : widget_number::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :widget_number_::_derived{}
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
                return widget_number_::_derived::_static_shared_to_base(std::make_shared<widget_number_::_instance>(_thing));
            }
            else
            {
                throw strange::_no_copy_constructor{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return widget_number::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return widget_number::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return widget_number_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return widget_number_::_name_;
        }

        inline auto display(button b) const -> void final;

        inline auto inc() -> void final;

        inline auto operator++() -> void final;

        inline auto operator--(int i) -> void final;

        inline auto dec() -> void final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    inline static auto _make_(_Args && ... _args) -> widget_number_
    {
        return widget_number_{widget_number_::_derived::_static_shared_to_base(std::make_shared<widget_number_::_instance>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<widget_number_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<widget_number_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<widget_number_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = widget_number_;
    using _Thing_ = _Thing;

    inline static bool const _copy_ = _Copy;

    inline static std::string const _name_ = strange::reflection<_Kind_>::name();
};

template<typename Data>
struct numeric : number
{
    inline numeric() = default;

    inline numeric(numeric const & other)
    :strange::_common{other}
    ,number{}
    {
    }

    inline numeric(numeric && other)
    :strange::_common{std::move(other)}
    ,number{}
    {
    }

    inline auto operator=(numeric const & other) -> numeric &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(numeric && other) -> numeric &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline numeric(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,number{}
    {
    }

    explicit inline numeric(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,number{}
    {
    }

protected:
    struct _derived : number::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename numeric::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return number::_derived::_static_shared_to_base(derived);
        }

        virtual auto get() const -> Data = 0;

        virtual auto x() const -> Data const & = 0;

        virtual auto x() -> Data & = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename numeric::_derived const>(strange::_common::_shared).operator bool();
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> numeric
    {
        return numeric{numeric::_derived::_static_shared_to_base(std::make_shared<typename numeric_<Data, _Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    using _Abstraction_ = numeric;

    inline static std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    inline static std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(number::_cats_.cbegin(), number::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();

    inline auto inc() -> void;

    inline auto dec() -> void;

    inline auto get() const -> Data;

    inline auto x() const -> Data const &;

    inline auto x() -> Data &;
};

template<typename Data, typename _Thing, bool _Copy>
struct numeric_ : numeric<Data>
{
    inline numeric_() = default;

    inline numeric_(numeric_ const & other)
    :strange::_common{other}
    ,numeric<Data>{}
    {
    }

    inline numeric_(numeric_ && other)
    :strange::_common{std::move(other)}
    ,numeric<Data>{}
    {
    }

    inline auto operator=(numeric_ const & other) -> numeric_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(numeric_ && other) -> numeric_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline numeric_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,numeric<Data>{}
    {
    }

    explicit inline numeric_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,numeric<Data>{}
    {
    }

private:
    friend struct numeric<Data>;

    struct _instance final : numeric<Data>::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :numeric_::_derived{}
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
                return numeric_::_derived::_static_shared_to_base(std::make_shared<numeric_::_instance>(_thing));
            }
            else
            {
                throw strange::_no_copy_constructor{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return numeric<Data>::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return numeric<Data>::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return numeric_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return numeric_::_name_;
        }

        inline auto inc() -> void final;

        inline auto dec() -> void final;

        inline auto get() const -> Data final;

        inline auto x() const -> Data const & final;

        inline auto x() -> Data & final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    inline static auto _make_(_Args && ... _args) -> numeric_
    {
        return numeric_{numeric_::_derived::_static_shared_to_base(std::make_shared<numeric_::_instance>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<numeric_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<numeric_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<numeric_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = numeric_;
    using _Thing_ = _Thing;

    inline static bool const _copy_ = _Copy;

    inline static std::string const _name_ = strange::reflection<_Kind_>::name();
};

inline auto widget::display(button b = button()) const -> void
{
    std::dynamic_pointer_cast<typename widget::_derived const>(strange::_common::_shared)->display(b);
}

inline auto widget::inc() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename widget::_derived>(strange::_common::_shared)->inc();
}

inline auto widget::operator++() -> widget &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename widget::_derived>(strange::_common::_shared)->operator++();
    return *this;
}

inline auto widget::operator--(int i) -> widget
{
    auto _result = *this;
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename widget::_derived>(strange::_common::_shared)->operator--(i);
    return _result;
}

template<typename _Thing, bool _Copy>
inline auto widget_<_Thing, _Copy>::_instance::display(button b) const -> void
{
    _thing.display(b);
}

template<typename _Thing, bool _Copy>
inline auto widget_<_Thing, _Copy>::_instance::inc() -> void
{
    _thing.inc();
}

template<typename _Thing, bool _Copy>
inline auto widget_<_Thing, _Copy>::_instance::operator++() -> void
{
    _thing.operator++();
}

template<typename _Thing, bool _Copy>
inline auto widget_<_Thing, _Copy>::_instance::operator--(int i) -> void
{
    _thing.operator--(i);
}

inline auto button::display(button b = button()) const -> void
{
    std::dynamic_pointer_cast<typename widget::_derived const>(strange::_common::_shared)->display(b);
}

inline auto button::inc() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename widget::_derived>(strange::_common::_shared)->inc();
}

inline auto button::operator++() -> button &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename widget::_derived>(strange::_common::_shared)->operator++();
    return *this;
}

inline auto button::operator--(int i) -> button
{
    auto _result = *this;
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename widget::_derived>(strange::_common::_shared)->operator--(i);
    return _result;
}

inline auto button::push() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename button::_derived>(strange::_common::_shared)->push();
}

template<typename _Thing, bool _Copy>
inline auto button_<_Thing, _Copy>::_instance::display(button b) const -> void
{
    _thing.display(b);
}

template<typename _Thing, bool _Copy>
inline auto button_<_Thing, _Copy>::_instance::inc() -> void
{
    _thing.inc();
}

template<typename _Thing, bool _Copy>
inline auto button_<_Thing, _Copy>::_instance::operator++() -> void
{
    _thing.operator++();
}

template<typename _Thing, bool _Copy>
inline auto button_<_Thing, _Copy>::_instance::operator--(int i) -> void
{
    _thing.operator--(i);
}

template<typename _Thing, bool _Copy>
inline auto button_<_Thing, _Copy>::_instance::push() -> void
{
    _thing.push();
}

inline auto number::inc() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename number::_derived>(strange::_common::_shared)->inc();
}

inline auto number::dec() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename number::_derived>(strange::_common::_shared)->dec();
}

template<typename _Thing, bool _Copy>
inline auto number_<_Thing, _Copy>::_instance::inc() -> void
{
    _thing.inc();
}

template<typename _Thing, bool _Copy>
inline auto number_<_Thing, _Copy>::_instance::dec() -> void
{
    _thing.dec();
}

inline auto widget_number::display(button b = button()) const -> void
{
    std::dynamic_pointer_cast<typename widget::_derived const>(strange::_common::_shared)->display(b);
}

inline auto widget_number::inc() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename widget::_derived>(strange::_common::_shared)->inc();
}

inline auto widget_number::operator++() -> widget_number &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename widget::_derived>(strange::_common::_shared)->operator++();
    return *this;
}

inline auto widget_number::operator--(int i) -> widget_number
{
    auto _result = *this;
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename widget::_derived>(strange::_common::_shared)->operator--(i);
    return _result;
}

inline auto widget_number::dec() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename number::_derived>(strange::_common::_shared)->dec();
}

template<typename _Thing, bool _Copy>
inline auto widget_number_<_Thing, _Copy>::_instance::display(button b) const -> void
{
    _thing.display(b);
}

template<typename _Thing, bool _Copy>
inline auto widget_number_<_Thing, _Copy>::_instance::inc() -> void
{
    _thing.inc();
}

template<typename _Thing, bool _Copy>
inline auto widget_number_<_Thing, _Copy>::_instance::operator++() -> void
{
    _thing.operator++();
}

template<typename _Thing, bool _Copy>
inline auto widget_number_<_Thing, _Copy>::_instance::operator--(int i) -> void
{
    _thing.operator--(i);
}

template<typename _Thing, bool _Copy>
inline auto widget_number_<_Thing, _Copy>::_instance::dec() -> void
{
    _thing.dec();
}

template<typename Data>
inline auto numeric<Data>::inc() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename number::_derived>(strange::_common::_shared)->inc();
}

template<typename Data>
inline auto numeric<Data>::dec() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename number::_derived>(strange::_common::_shared)->dec();
}

template<typename Data>
inline auto numeric<Data>::get() const -> Data
{
    return std::dynamic_pointer_cast<typename numeric<Data>::_derived const>(strange::_common::_shared)->get();
}

template<typename Data>
inline auto numeric<Data>::x() const -> Data const &
{
    return std::dynamic_pointer_cast<typename numeric<Data>::_derived const>(strange::_common::_shared)->x();
}

template<typename Data>
inline auto numeric<Data>::x() -> Data &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename numeric<Data>::_derived>(strange::_common::_shared)->x();
}

template<typename Data, typename _Thing, bool _Copy>
inline auto numeric_<Data, _Thing, _Copy>::_instance::inc() -> void
{
    _thing.inc();
}

template<typename Data, typename _Thing, bool _Copy>
inline auto numeric_<Data, _Thing, _Copy>::_instance::dec() -> void
{
    _thing.dec();
}

template<typename Data, typename _Thing, bool _Copy>
inline auto numeric_<Data, _Thing, _Copy>::_instance::get() const -> Data
{
    return _thing.get();
}

template<typename Data, typename _Thing, bool _Copy>
inline auto numeric_<Data, _Thing, _Copy>::_instance::x() const -> Data const &
{
    return _thing.x_;
}

template<typename Data, typename _Thing, bool _Copy>
inline auto numeric_<Data, _Thing, _Copy>::_instance::x() -> Data &
{
    return _thing.x_;
}

}
