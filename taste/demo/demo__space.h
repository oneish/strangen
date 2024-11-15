#pragma once
#include "../../sauce/strange/common/strange__common.h"
#include "../../sauce/strange/reflection/strange__reflection.h"
#include <memory>
#include <string>
#include <type_traits>
#include <unordered_set>

namespace demo
{

struct food;

template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct food_;

struct fruit;

template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct fruit_;

template<typename Item>
struct bunch;

template<typename Item, typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct bunch_;

struct bunch_of_fruit;

template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct bunch_of_fruit_;

struct function;

template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct function_;

}

namespace strange
{

template<>
struct reflection<demo::food>
{
    static inline auto name() -> std::string
    {
        return "demo::food";
    }
};

template<typename _Thing, bool _Copy>
struct reflection<demo::food_<_Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "demo::food_<" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<>
struct reflection<demo::fruit>
{
    static inline auto name() -> std::string
    {
        return "demo::fruit";
    }
};

template<typename _Thing, bool _Copy>
struct reflection<demo::fruit_<_Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "demo::fruit_<" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<typename Item>
struct reflection<demo::bunch<Item>>
{
    static inline auto name() -> std::string
    {
        return "demo::bunch<" + reflection<Item>::name() + ">";
    }
};

template<typename Item, typename _Thing, bool _Copy>
struct reflection<demo::bunch_<Item, _Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "demo::bunch_<" + reflection<Item>::name() + ", " + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<>
struct reflection<demo::bunch_of_fruit>
{
    static inline auto name() -> std::string
    {
        return "demo::bunch_of_fruit";
    }
};

template<typename _Thing, bool _Copy>
struct reflection<demo::bunch_of_fruit_<_Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "demo::bunch_of_fruit_<" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<>
struct reflection<demo::function>
{
    static inline auto name() -> std::string
    {
        return "demo::function";
    }
};

template<typename _Thing, bool _Copy>
struct reflection<demo::function_<_Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "demo::function_<" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

}

namespace demo
{

struct food : strange::any
{
    inline food() = default;

    inline food(food const & other)
    :strange::_common{other}
    ,strange::any{}
    {
    }

    inline food(food && other)
    :strange::_common{std::move(other)}
    ,strange::any{}
    {
    }

    inline auto operator=(food const & other) -> food &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(food && other) -> food &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline food(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,strange::any{}
    {
    }

    explicit inline food(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,strange::any{}
    {
    }

protected:
    struct _derived : strange::any::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename food::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return strange::any::_derived::_static_shared_to_base(derived);
        }

        virtual auto eat() -> void = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename food::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> food
    {
        try
        {
            return food{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return food{};
        }
    }

    inline auto _reproduce() const -> food
    {
        try
        {
            return food{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return food{};
        }
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> food
    {
        return food{food::_derived::_static_shared_to_base(std::make_shared<typename food_<_Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> food
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return food{};
        }
        return food{it->second()};
    }

    using _Abstraction_ = food;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(strange::any::_cats_.cbegin(), strange::any::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();

    inline auto eat() -> void;
};

template<typename _Thing, bool _Copy>
struct food_ : food
{
    inline food_() = default;

    inline food_(food_ const & other)
    :strange::_common{other}
    ,food{}
    {
    }

    inline food_(food_ && other)
    :strange::_common{std::move(other)}
    ,food{}
    {
    }

    inline auto operator=(food_ const & other) -> food_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(food_ && other) -> food_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline food_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,food{}
    {
    }

    explicit inline food_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,food{}
    {
    }

private:
    friend struct food;

    struct _instance final : food::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :food_::_derived{}
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
                return food_::_derived::_static_shared_to_base(std::make_shared<food_::_instance>(_thing));
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
                return food_::_derived::_static_shared_to_base(std::make_shared<food_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return food::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return food::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return food_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return food_::_name_;
        }

        inline auto eat() -> void final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    static inline auto _make_(_Args && ... _args) -> food_
    {
        return food_{food_::_derived::_static_shared_to_base(std::make_shared<food_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> food_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return food_{};
        }
        return food_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<food_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> food_
    {
        try
        {
            return food_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return food_{};
        }
    }

    inline auto _reproduce_() const -> food_
    {
        try
        {
            return food_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return food_{};
        }
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<food_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<food_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = food_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return food_::_derived::_static_shared_to_base(std::make_shared<food_::_instance>());
            });
        }
        return name;
    }();
};

struct fruit : food
{
    inline fruit() = default;

    inline fruit(fruit const & other)
    :strange::_common{other}
    ,food{}
    {
    }

    inline fruit(fruit && other)
    :strange::_common{std::move(other)}
    ,food{}
    {
    }

    inline auto operator=(fruit const & other) -> fruit &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(fruit && other) -> fruit &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline fruit(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,food{}
    {
    }

    explicit inline fruit(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,food{}
    {
    }

protected:
    struct _derived : food::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename fruit::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return food::_derived::_static_shared_to_base(derived);
        }

        virtual auto ripen() -> void = 0;

        virtual auto ripe() const -> bool = 0;

        virtual auto peel() -> void = 0;

        virtual auto peeled() const -> bool = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename fruit::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> fruit
    {
        try
        {
            return fruit{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return fruit{};
        }
    }

    inline auto _reproduce() const -> fruit
    {
        try
        {
            return fruit{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return fruit{};
        }
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> fruit
    {
        return fruit{fruit::_derived::_static_shared_to_base(std::make_shared<typename fruit_<_Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> fruit
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return fruit{};
        }
        return fruit{it->second()};
    }

    using _Abstraction_ = fruit;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(food::_cats_.cbegin(), food::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();

    inline auto eat() -> void;

    inline auto ripen() -> void;

    inline auto ripe() const -> bool;

    inline auto peel() -> void;

    inline auto peeled() const -> bool;
};

template<typename _Thing, bool _Copy>
struct fruit_ : fruit
{
    inline fruit_() = default;

    inline fruit_(fruit_ const & other)
    :strange::_common{other}
    ,fruit{}
    {
    }

    inline fruit_(fruit_ && other)
    :strange::_common{std::move(other)}
    ,fruit{}
    {
    }

    inline auto operator=(fruit_ const & other) -> fruit_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(fruit_ && other) -> fruit_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline fruit_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,fruit{}
    {
    }

    explicit inline fruit_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,fruit{}
    {
    }

private:
    friend struct fruit;

    struct _instance final : fruit::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :fruit_::_derived{}
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
                return fruit_::_derived::_static_shared_to_base(std::make_shared<fruit_::_instance>(_thing));
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
                return fruit_::_derived::_static_shared_to_base(std::make_shared<fruit_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return fruit::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return fruit::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return fruit_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return fruit_::_name_;
        }

        inline auto eat() -> void final;

        inline auto ripen() -> void final;

        inline auto ripe() const -> bool final;

        inline auto peel() -> void final;

        inline auto peeled() const -> bool final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    static inline auto _make_(_Args && ... _args) -> fruit_
    {
        return fruit_{fruit_::_derived::_static_shared_to_base(std::make_shared<fruit_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> fruit_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return fruit_{};
        }
        return fruit_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<fruit_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> fruit_
    {
        try
        {
            return fruit_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return fruit_{};
        }
    }

    inline auto _reproduce_() const -> fruit_
    {
        try
        {
            return fruit_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return fruit_{};
        }
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<fruit_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<fruit_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = fruit_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return fruit_::_derived::_static_shared_to_base(std::make_shared<fruit_::_instance>());
            });
        }
        return name;
    }();
};

template<typename Item>
struct bunch : strange::any
{
    inline bunch() = default;

    inline bunch(bunch const & other)
    :strange::_common{other}
    ,strange::any{}
    {
    }

    inline bunch(bunch && other)
    :strange::_common{std::move(other)}
    ,strange::any{}
    {
    }

    inline auto operator=(bunch const & other) -> bunch &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(bunch && other) -> bunch &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline bunch(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,strange::any{}
    {
    }

    explicit inline bunch(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,strange::any{}
    {
    }

protected:
    struct _derived : strange::any::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename bunch::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return strange::any::_derived::_static_shared_to_base(derived);
        }

        virtual auto push_back(Item const & item) -> void = 0;

        virtual auto push_back(Item && item) -> void = 0;

        virtual auto size() const -> std::size_t = 0;

        virtual auto operator[](std::size_t pos) const -> Item const & = 0;

        virtual auto operator[](std::size_t pos) -> Item & = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename bunch::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> bunch
    {
        try
        {
            return bunch{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return bunch{};
        }
    }

    inline auto _reproduce() const -> bunch
    {
        try
        {
            return bunch{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return bunch{};
        }
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> bunch
    {
        return bunch{bunch::_derived::_static_shared_to_base(std::make_shared<typename bunch_<Item, _Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> bunch
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return bunch{};
        }
        return bunch{it->second()};
    }

    using _Abstraction_ = bunch;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(strange::any::_cats_.cbegin(), strange::any::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();

    inline auto push_back(Item const & item) -> void;

    inline auto push_back(Item && item) -> void;

    inline auto size() const -> std::size_t;

    inline auto operator[](std::size_t pos) const -> Item const &;

    inline auto operator[](std::size_t pos) -> Item &;
};

template<typename Item, typename _Thing, bool _Copy>
struct bunch_ : bunch<Item>
{
    inline bunch_() = default;

    inline bunch_(bunch_ const & other)
    :strange::_common{other}
    ,bunch<Item>{}
    {
    }

    inline bunch_(bunch_ && other)
    :strange::_common{std::move(other)}
    ,bunch<Item>{}
    {
    }

    inline auto operator=(bunch_ const & other) -> bunch_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(bunch_ && other) -> bunch_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline bunch_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,bunch<Item>{}
    {
    }

    explicit inline bunch_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,bunch<Item>{}
    {
    }

private:
    friend struct bunch<Item>;

    struct _instance final : bunch<Item>::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :bunch_::_derived{}
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
                return bunch_::_derived::_static_shared_to_base(std::make_shared<bunch_::_instance>(_thing));
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
                return bunch_::_derived::_static_shared_to_base(std::make_shared<bunch_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return bunch<Item>::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return bunch<Item>::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return bunch_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return bunch_::_name_;
        }

        inline auto push_back(Item const & item) -> void final;

        inline auto push_back(Item && item) -> void final;

        inline auto size() const -> std::size_t final;

        inline auto operator[](std::size_t pos) const -> Item const & final;

        inline auto operator[](std::size_t pos) -> Item & final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    static inline auto _make_(_Args && ... _args) -> bunch_
    {
        return bunch_{bunch_::_derived::_static_shared_to_base(std::make_shared<bunch_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> bunch_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return bunch_{};
        }
        return bunch_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<bunch_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> bunch_
    {
        try
        {
            return bunch_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return bunch_{};
        }
    }

    inline auto _reproduce_() const -> bunch_
    {
        try
        {
            return bunch_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return bunch_{};
        }
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<bunch_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<bunch_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = bunch_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return bunch_::_derived::_static_shared_to_base(std::make_shared<bunch_::_instance>());
            });
        }
        return name;
    }();
};

struct bunch_of_fruit : food, bunch<fruit>
{
    inline bunch_of_fruit() = default;

    inline bunch_of_fruit(bunch_of_fruit const & other)
    :strange::_common{other}
    ,food{}
    ,bunch<fruit>{}
    {
    }

    inline bunch_of_fruit(bunch_of_fruit && other)
    :strange::_common{std::move(other)}
    ,food{}
    ,bunch<fruit>{}
    {
    }

    inline auto operator=(bunch_of_fruit const & other) -> bunch_of_fruit &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(bunch_of_fruit && other) -> bunch_of_fruit &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline bunch_of_fruit(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,food{}
    ,bunch<fruit>{}
    {
    }

    explicit inline bunch_of_fruit(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,food{}
    ,bunch<fruit>{}
    {
    }

    using Item = fruit;

protected:
    struct _derived : food::_derived, bunch<fruit>::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename bunch_of_fruit::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return food::_derived::_static_shared_to_base(derived);
        }

        virtual auto pick() -> void = 0;

        virtual auto picked() const -> bool = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename bunch_of_fruit::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> bunch_of_fruit
    {
        try
        {
            return bunch_of_fruit{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return bunch_of_fruit{};
        }
    }

    inline auto _reproduce() const -> bunch_of_fruit
    {
        try
        {
            return bunch_of_fruit{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return bunch_of_fruit{};
        }
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> bunch_of_fruit
    {
        return bunch_of_fruit{bunch_of_fruit::_derived::_static_shared_to_base(std::make_shared<typename bunch_of_fruit_<_Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> bunch_of_fruit
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return bunch_of_fruit{};
        }
        return bunch_of_fruit{it->second()};
    }

    using _Abstraction_ = bunch_of_fruit;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(food::_cats_.cbegin(), food::_cats_.cend());
        cats.insert(bunch<fruit>::_cats_.cbegin(), bunch<fruit>::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();

    inline auto eat() -> void;

    inline auto push_back(Item const & item) -> void;

    inline auto push_back(Item && item) -> void;

    inline auto size() const -> std::size_t;

    inline auto operator[](std::size_t pos) const -> Item const &;

    inline auto operator[](std::size_t pos) -> Item &;

    inline auto pick() -> void;

    inline auto picked() const -> bool;
};

template<typename _Thing, bool _Copy>
struct bunch_of_fruit_ : bunch_of_fruit
{
    inline bunch_of_fruit_() = default;

    inline bunch_of_fruit_(bunch_of_fruit_ const & other)
    :strange::_common{other}
    ,bunch_of_fruit{}
    {
    }

    inline bunch_of_fruit_(bunch_of_fruit_ && other)
    :strange::_common{std::move(other)}
    ,bunch_of_fruit{}
    {
    }

    inline auto operator=(bunch_of_fruit_ const & other) -> bunch_of_fruit_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(bunch_of_fruit_ && other) -> bunch_of_fruit_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline bunch_of_fruit_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,bunch_of_fruit{}
    {
    }

    explicit inline bunch_of_fruit_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,bunch_of_fruit{}
    {
    }

private:
    friend struct bunch_of_fruit;

    struct _instance final : bunch_of_fruit::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :bunch_of_fruit_::_derived{}
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
                return bunch_of_fruit_::_derived::_static_shared_to_base(std::make_shared<bunch_of_fruit_::_instance>(_thing));
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
                return bunch_of_fruit_::_derived::_static_shared_to_base(std::make_shared<bunch_of_fruit_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return bunch_of_fruit::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return bunch_of_fruit::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return bunch_of_fruit_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return bunch_of_fruit_::_name_;
        }

        inline auto eat() -> void final;

        inline auto push_back(Item const & item) -> void final;

        inline auto push_back(Item && item) -> void final;

        inline auto size() const -> std::size_t final;

        inline auto operator[](std::size_t pos) const -> Item const & final;

        inline auto operator[](std::size_t pos) -> Item & final;

        inline auto pick() -> void final;

        inline auto picked() const -> bool final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    static inline auto _make_(_Args && ... _args) -> bunch_of_fruit_
    {
        return bunch_of_fruit_{bunch_of_fruit_::_derived::_static_shared_to_base(std::make_shared<bunch_of_fruit_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> bunch_of_fruit_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return bunch_of_fruit_{};
        }
        return bunch_of_fruit_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<bunch_of_fruit_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> bunch_of_fruit_
    {
        try
        {
            return bunch_of_fruit_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return bunch_of_fruit_{};
        }
    }

    inline auto _reproduce_() const -> bunch_of_fruit_
    {
        try
        {
            return bunch_of_fruit_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return bunch_of_fruit_{};
        }
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<bunch_of_fruit_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<bunch_of_fruit_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = bunch_of_fruit_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return bunch_of_fruit_::_derived::_static_shared_to_base(std::make_shared<bunch_of_fruit_::_instance>());
            });
        }
        return name;
    }();
};

struct function : virtual strange::_common
{
    inline function() = default;

    inline function(function const & other)
    :strange::_common{other}
    {
    }

    inline function(function && other)
    :strange::_common{std::move(other)}
    {
    }

    inline auto operator=(function const & other) -> function &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(function && other) -> function &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline function(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    {
    }

    explicit inline function(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    {
    }

protected:
    struct _derived : strange::_common::_base
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename function::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return derived;
        }

        virtual auto operator()() const -> void = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename function::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> function
    {
        try
        {
            return function{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return function{};
        }
    }

    inline auto _reproduce() const -> function
    {
        try
        {
            return function{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return function{};
        }
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> function
    {
        return function{function::_derived::_static_shared_to_base(std::make_shared<typename function_<_Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> function
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return function{};
        }
        return function{it->second()};
    }

    using _Abstraction_ = function;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(_cat_);
        return cats;
    }();

    inline auto operator()() const -> void;
};

template<typename _Thing, bool _Copy>
struct function_ : function
{
    inline function_() = default;

    inline function_(function_ const & other)
    :strange::_common{other}
    ,function{}
    {
    }

    inline function_(function_ && other)
    :strange::_common{std::move(other)}
    ,function{}
    {
    }

    inline auto operator=(function_ const & other) -> function_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(function_ && other) -> function_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline function_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,function{}
    {
    }

    explicit inline function_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,function{}
    {
    }

private:
    friend struct function;

    struct _instance final : function::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :function_::_derived{}
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
                return function_::_derived::_static_shared_to_base(std::make_shared<function_::_instance>(_thing));
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
                return function_::_derived::_static_shared_to_base(std::make_shared<function_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return function::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return function::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return function_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return function_::_name_;
        }

        inline auto operator()() const -> void final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    static inline auto _make_(_Args && ... _args) -> function_
    {
        return function_{function_::_derived::_static_shared_to_base(std::make_shared<function_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> function_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return function_{};
        }
        return function_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<function_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> function_
    {
        try
        {
            return function_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return function_{};
        }
    }

    inline auto _reproduce_() const -> function_
    {
        try
        {
            return function_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return function_{};
        }
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<function_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<function_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = function_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return function_::_derived::_static_shared_to_base(std::make_shared<function_::_instance>());
            });
        }
        return name;
    }();
};

inline auto food::eat() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename food::_derived>(strange::_common::_shared)->eat();
}

template<typename _Thing, bool _Copy>
inline auto food_<_Thing, _Copy>::_instance::eat() -> void
{
    _thing.eat();
}

inline auto fruit::eat() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename food::_derived>(strange::_common::_shared)->eat();
}

inline auto fruit::ripen() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename fruit::_derived>(strange::_common::_shared)->ripen();
}

inline auto fruit::ripe() const -> bool
{
    return std::dynamic_pointer_cast<typename fruit::_derived const>(strange::_common::_shared)->ripe();
}

inline auto fruit::peel() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename fruit::_derived>(strange::_common::_shared)->peel();
}

inline auto fruit::peeled() const -> bool
{
    return std::dynamic_pointer_cast<typename fruit::_derived const>(strange::_common::_shared)->peeled();
}

template<typename _Thing, bool _Copy>
inline auto fruit_<_Thing, _Copy>::_instance::eat() -> void
{
    _thing.eat();
}

template<typename _Thing, bool _Copy>
inline auto fruit_<_Thing, _Copy>::_instance::ripen() -> void
{
    _thing.ripen();
}

template<typename _Thing, bool _Copy>
inline auto fruit_<_Thing, _Copy>::_instance::ripe() const -> bool
{
    return _thing.ripe();
}

template<typename _Thing, bool _Copy>
inline auto fruit_<_Thing, _Copy>::_instance::peel() -> void
{
    _thing.peel();
}

template<typename _Thing, bool _Copy>
inline auto fruit_<_Thing, _Copy>::_instance::peeled() const -> bool
{
    return _thing.peeled();
}

template<typename Item>
inline auto bunch<Item>::push_back(Item const & item) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bunch<Item>::_derived>(strange::_common::_shared)->push_back(item);
}

template<typename Item>
inline auto bunch<Item>::push_back(Item && item) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bunch<Item>::_derived>(strange::_common::_shared)->push_back(std::move(item));
}

template<typename Item>
inline auto bunch<Item>::size() const -> std::size_t
{
    return std::dynamic_pointer_cast<typename bunch<Item>::_derived const>(strange::_common::_shared)->size();
}

template<typename Item>
inline auto bunch<Item>::operator[](std::size_t pos) const -> Item const &
{
    return std::dynamic_pointer_cast<typename bunch<Item>::_derived const>(strange::_common::_shared)->operator[](pos);
}

template<typename Item>
inline auto bunch<Item>::operator[](std::size_t pos) -> Item &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename bunch<Item>::_derived>(strange::_common::_shared)->operator[](pos);
}

template<typename Item, typename _Thing, bool _Copy>
inline auto bunch_<Item, _Thing, _Copy>::_instance::push_back(Item const & item) -> void
{
    _thing.push_back(item);
}

template<typename Item, typename _Thing, bool _Copy>
inline auto bunch_<Item, _Thing, _Copy>::_instance::push_back(Item && item) -> void
{
    _thing.push_back(std::move(item));
}

template<typename Item, typename _Thing, bool _Copy>
inline auto bunch_<Item, _Thing, _Copy>::_instance::size() const -> std::size_t
{
    return _thing.size();
}

template<typename Item, typename _Thing, bool _Copy>
inline auto bunch_<Item, _Thing, _Copy>::_instance::operator[](std::size_t pos) const -> Item const &
{
    return _thing.operator[](pos);
}

template<typename Item, typename _Thing, bool _Copy>
inline auto bunch_<Item, _Thing, _Copy>::_instance::operator[](std::size_t pos) -> Item &
{
    return _thing.operator[](pos);
}

inline auto bunch_of_fruit::eat() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename food::_derived>(strange::_common::_shared)->eat();
}

inline auto bunch_of_fruit::push_back(Item const & item) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bunch<fruit>::_derived>(strange::_common::_shared)->push_back(item);
}

inline auto bunch_of_fruit::push_back(Item && item) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bunch<fruit>::_derived>(strange::_common::_shared)->push_back(std::move(item));
}

inline auto bunch_of_fruit::size() const -> std::size_t
{
    return std::dynamic_pointer_cast<typename bunch<fruit>::_derived const>(strange::_common::_shared)->size();
}

inline auto bunch_of_fruit::operator[](std::size_t pos) const -> Item const &
{
    return std::dynamic_pointer_cast<typename bunch<fruit>::_derived const>(strange::_common::_shared)->operator[](pos);
}

inline auto bunch_of_fruit::operator[](std::size_t pos) -> Item &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename bunch<fruit>::_derived>(strange::_common::_shared)->operator[](pos);
}

inline auto bunch_of_fruit::pick() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bunch_of_fruit::_derived>(strange::_common::_shared)->pick();
}

inline auto bunch_of_fruit::picked() const -> bool
{
    return std::dynamic_pointer_cast<typename bunch_of_fruit::_derived const>(strange::_common::_shared)->picked();
}

template<typename _Thing, bool _Copy>
inline auto bunch_of_fruit_<_Thing, _Copy>::_instance::eat() -> void
{
    _thing.eat();
}

template<typename _Thing, bool _Copy>
inline auto bunch_of_fruit_<_Thing, _Copy>::_instance::push_back(Item const & item) -> void
{
    _thing.push_back(item);
}

template<typename _Thing, bool _Copy>
inline auto bunch_of_fruit_<_Thing, _Copy>::_instance::push_back(Item && item) -> void
{
    _thing.push_back(std::move(item));
}

template<typename _Thing, bool _Copy>
inline auto bunch_of_fruit_<_Thing, _Copy>::_instance::size() const -> std::size_t
{
    return _thing.size();
}

template<typename _Thing, bool _Copy>
inline auto bunch_of_fruit_<_Thing, _Copy>::_instance::operator[](std::size_t pos) const -> Item const &
{
    return _thing.operator[](pos);
}

template<typename _Thing, bool _Copy>
inline auto bunch_of_fruit_<_Thing, _Copy>::_instance::operator[](std::size_t pos) -> Item &
{
    return _thing.operator[](pos);
}

template<typename _Thing, bool _Copy>
inline auto bunch_of_fruit_<_Thing, _Copy>::_instance::pick() -> void
{
    _thing.pick();
}

template<typename _Thing, bool _Copy>
inline auto bunch_of_fruit_<_Thing, _Copy>::_instance::picked() const -> bool
{
    return _thing.picked();
}

inline auto function::operator()() const -> void
{
    std::dynamic_pointer_cast<typename function::_derived const>(strange::_common::_shared)->operator()();
}

template<typename _Thing, bool _Copy>
inline auto function_<_Thing, _Copy>::_instance::operator()() const -> void
{
    _thing.operator()();
}

}

