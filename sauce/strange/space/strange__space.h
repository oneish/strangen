#pragma once
#include "../common/strange__common.h"
#include "../reflection/strange__reflection.h"
#include "../definition/strange__definition__parameter.h"
#include "../definition/strange__definition__operation.h"
#include "../definition/strange__definition__abstraction.h"
#include "../definition/strange__definition__space.h"
#include <vector>
#include <memory>
#include <string>
#include <type_traits>
#include <unordered_set>

namespace strange
{

struct any;

template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct any_;

struct parameter;

template<typename _Thing = strange::definition::parameter, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct parameter_;

template<typename T>
struct forward_const_iterator;

template<typename T, typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct forward_const_iterator_;

template<typename T>
struct forward_iterator;

template<typename T, typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct forward_iterator_;

template<typename T>
struct bidirectional_const_iterator;

template<typename T, typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct bidirectional_const_iterator_;

template<typename T>
struct bidirectional_iterator;

template<typename T, typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct bidirectional_iterator_;

template<typename T>
struct random_access_const_iterator;

template<typename T, typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct random_access_const_iterator_;

template<typename T>
struct random_access_iterator;

template<typename T, typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct random_access_iterator_;

template<typename T>
struct vector;

template<typename T, typename _Thing = std::vector<T>, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct vector_;

}

namespace strange
{

template<>
struct reflection<strange::any>
{
    inline static auto name() -> std::string
    {
        return "strange::any";
    }
};

template<typename _Thing, bool _Copy>
struct reflection<strange::any_<_Thing, _Copy>>
{
    inline static auto name() -> std::string
    {
        return "strange::any_<" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<>
struct reflection<strange::parameter>
{
    inline static auto name() -> std::string
    {
        return "strange::parameter";
    }
};

template<typename _Thing, bool _Copy>
struct reflection<strange::parameter_<_Thing, _Copy>>
{
    inline static auto name() -> std::string
    {
        return "strange::parameter_<" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<typename T>
struct reflection<strange::forward_const_iterator<T>>
{
    inline static auto name() -> std::string
    {
        return "strange::forward_const_iterator<" + reflection<T>::name() + ">";
    }
};

template<typename T, typename _Thing, bool _Copy>
struct reflection<strange::forward_const_iterator_<T, _Thing, _Copy>>
{
    inline static auto name() -> std::string
    {
        return "strange::forward_const_iterator_<" + reflection<T>::name() + ", " + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<typename T>
struct reflection<strange::forward_iterator<T>>
{
    inline static auto name() -> std::string
    {
        return "strange::forward_iterator<" + reflection<T>::name() + ">";
    }
};

template<typename T, typename _Thing, bool _Copy>
struct reflection<strange::forward_iterator_<T, _Thing, _Copy>>
{
    inline static auto name() -> std::string
    {
        return "strange::forward_iterator_<" + reflection<T>::name() + ", " + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<typename T>
struct reflection<strange::bidirectional_const_iterator<T>>
{
    inline static auto name() -> std::string
    {
        return "strange::bidirectional_const_iterator<" + reflection<T>::name() + ">";
    }
};

template<typename T, typename _Thing, bool _Copy>
struct reflection<strange::bidirectional_const_iterator_<T, _Thing, _Copy>>
{
    inline static auto name() -> std::string
    {
        return "strange::bidirectional_const_iterator_<" + reflection<T>::name() + ", " + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<typename T>
struct reflection<strange::bidirectional_iterator<T>>
{
    inline static auto name() -> std::string
    {
        return "strange::bidirectional_iterator<" + reflection<T>::name() + ">";
    }
};

template<typename T, typename _Thing, bool _Copy>
struct reflection<strange::bidirectional_iterator_<T, _Thing, _Copy>>
{
    inline static auto name() -> std::string
    {
        return "strange::bidirectional_iterator_<" + reflection<T>::name() + ", " + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<typename T>
struct reflection<strange::random_access_const_iterator<T>>
{
    inline static auto name() -> std::string
    {
        return "strange::random_access_const_iterator<" + reflection<T>::name() + ">";
    }
};

template<typename T, typename _Thing, bool _Copy>
struct reflection<strange::random_access_const_iterator_<T, _Thing, _Copy>>
{
    inline static auto name() -> std::string
    {
        return "strange::random_access_const_iterator_<" + reflection<T>::name() + ", " + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<typename T>
struct reflection<strange::random_access_iterator<T>>
{
    inline static auto name() -> std::string
    {
        return "strange::random_access_iterator<" + reflection<T>::name() + ">";
    }
};

template<typename T, typename _Thing, bool _Copy>
struct reflection<strange::random_access_iterator_<T, _Thing, _Copy>>
{
    inline static auto name() -> std::string
    {
        return "strange::random_access_iterator_<" + reflection<T>::name() + ", " + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<typename T>
struct reflection<strange::vector<T>>
{
    inline static auto name() -> std::string
    {
        return "strange::vector<" + reflection<T>::name() + ">";
    }
};

template<typename T, typename _Thing, bool _Copy>
struct reflection<strange::vector_<T, _Thing, _Copy>>
{
    inline static auto name() -> std::string
    {
        return "strange::vector_<" + reflection<T>::name() + ", " + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

}

namespace strange
{

struct any : virtual strange::_common
{
    inline any() = default;

    inline any(any const & other)
    :strange::_common{other}
    {
    }

    inline any(any && other)
    :strange::_common{std::move(other)}
    {
    }

    inline auto operator=(any const & other) -> any &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(any && other) -> any &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline any(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    {
    }

    explicit inline any(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    {
    }

protected:
    struct _derived : strange::_common::_base
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename any::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return derived;
        }
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename any::_derived>(strange::_common::_shared).operator bool();
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> any
    {
        return any{any::_derived::_static_shared_to_base(std::make_shared<typename any_<_Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    using _Kind_ = any;

    inline static std::string const _cat_ = strange::reflection<_Kind_>::name();

    inline static std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(_cat_);
        return cats;
    }();

};

template<typename _Thing, bool _Copy>
struct any_ : any
{
    inline any_() = default;

    inline any_(any_ const & other)
    :strange::_common{other}
    ,any{}
    {
    }

    inline any_(any_ && other)
    :strange::_common{std::move(other)}
    ,any{}
    {
    }

    inline auto operator=(any_ const & other) -> any_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(any_ && other) -> any_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline any_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,any{}
    {
    }

    explicit inline any_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,any{}
    {
    }

private:
    friend struct any;

    struct _instance final : any::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :any_::_derived{}
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
                return any_::_derived::_static_shared_to_base(std::make_shared<any_::_instance>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto _cat() const -> std::string final
        {
            return any::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return any::_cats_;
        }

        inline auto _name() const -> std::string final
        {
            return any_::_name_;
        }

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    inline static auto _make_(_Args && ... _args) -> any_
    {
        return any_{any_::_derived::_static_shared_to_base(std::make_shared<any_::_instance>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<any_::_instance>(strange::_common::_shared).operator bool();
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<any_::_instance>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<any_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Abstraction_ = any_;
    using _Thing_ = _Thing;

    inline static std::string const _name_ = strange::reflection<_Abstraction_>::name();
};

struct parameter : any
{
    inline parameter() = default;

    inline parameter(parameter const & other)
    :strange::_common{other}
    ,any{}
    {
    }

    inline parameter(parameter && other)
    :strange::_common{std::move(other)}
    ,any{}
    {
    }

    inline auto operator=(parameter const & other) -> parameter &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(parameter && other) -> parameter &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline parameter(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,any{}
    {
    }

    explicit inline parameter(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,any{}
    {
    }

protected:
    struct _derived : any::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename parameter::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return any::_derived::_static_shared_to_base(derived);
        }

        virtual auto type() const -> std::string const & = 0;

        virtual auto type() -> std::string & = 0;

        virtual auto name() const -> std::string const & = 0;

        virtual auto name() -> std::string & = 0;

        virtual auto argument() const -> std::string const & = 0;

        virtual auto argument() -> std::string & = 0;

        virtual auto operator==(parameter const & other) const -> bool = 0;

        virtual auto operator!=(parameter const & other) const -> bool = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename parameter::_derived>(strange::_common::_shared).operator bool();
    }

    template<typename _Thing = strange::definition::parameter, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> parameter
    {
        return parameter{parameter::_derived::_static_shared_to_base(std::make_shared<typename parameter_<_Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    using _Kind_ = parameter;

    inline static std::string const _cat_ = strange::reflection<_Kind_>::name();

    inline static std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(any::_cats_.cbegin(), any::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();


    inline auto type() const -> std::string const &;

    inline auto type() -> std::string &;

    inline auto name() const -> std::string const &;

    inline auto name() -> std::string &;

    inline auto argument() const -> std::string const &;

    inline auto argument() -> std::string &;

    inline auto operator==(parameter const & other) const -> bool;

    inline auto operator!=(parameter const & other) const -> bool;
};

template<typename _Thing, bool _Copy>
struct parameter_ : parameter
{
    inline parameter_() = default;

    inline parameter_(parameter_ const & other)
    :strange::_common{other}
    ,parameter{}
    {
    }

    inline parameter_(parameter_ && other)
    :strange::_common{std::move(other)}
    ,parameter{}
    {
    }

    inline auto operator=(parameter_ const & other) -> parameter_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(parameter_ && other) -> parameter_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline parameter_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,parameter{}
    {
    }

    explicit inline parameter_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,parameter{}
    {
    }

private:
    friend struct parameter;

    struct _instance final : parameter::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :parameter_::_derived{}
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
                return parameter_::_derived::_static_shared_to_base(std::make_shared<parameter_::_instance>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto _cat() const -> std::string final
        {
            return parameter::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return parameter::_cats_;
        }

        inline auto _name() const -> std::string final
        {
            return parameter_::_name_;
        }

        inline auto type() const -> std::string const & final;

        inline auto type() -> std::string & final;

        inline auto name() const -> std::string const & final;

        inline auto name() -> std::string & final;

        inline auto argument() const -> std::string const & final;

        inline auto argument() -> std::string & final;

        inline auto operator==(parameter const & other) const -> bool final;

        inline auto operator!=(parameter const & other) const -> bool final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    inline static auto _make_(_Args && ... _args) -> parameter_
    {
        return parameter_{parameter_::_derived::_static_shared_to_base(std::make_shared<parameter_::_instance>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<parameter_::_instance>(strange::_common::_shared).operator bool();
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<parameter_::_instance>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<parameter_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Abstraction_ = parameter_;
    using _Thing_ = _Thing;

    inline static std::string const _name_ = strange::reflection<_Abstraction_>::name();
};

template<typename T>
struct forward_const_iterator : any
{
    inline forward_const_iterator() = default;

    inline forward_const_iterator(forward_const_iterator const & other)
    :strange::_common{other}
    ,any{}
    {
    }

    inline forward_const_iterator(forward_const_iterator && other)
    :strange::_common{std::move(other)}
    ,any{}
    {
    }

    inline auto operator=(forward_const_iterator const & other) -> forward_const_iterator &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(forward_const_iterator && other) -> forward_const_iterator &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline forward_const_iterator(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,any{}
    {
    }

    explicit inline forward_const_iterator(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,any{}
    {
    }

    using value_type = T;

    using difference_type = std::ptrdiff_t;

    using reference = value_type &;

    using pointer = value_type *;

    using iterator_category = std::forward_iterator_tag;

protected:
    struct _derived : any::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename forward_const_iterator::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return any::_derived::_static_shared_to_base(derived);
        }

        virtual auto operator*() const -> T const & = 0;

        virtual auto operator->() const -> T const * = 0;

        virtual auto operator++() -> void = 0;

        virtual auto operator++(int i) -> void = 0;

        virtual auto operator==(forward_const_iterator<T> const & other) const -> bool = 0;

        virtual auto operator!=(forward_const_iterator<T> const & other) const -> bool = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename forward_const_iterator::_derived>(strange::_common::_shared).operator bool();
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> forward_const_iterator
    {
        return forward_const_iterator{forward_const_iterator::_derived::_static_shared_to_base(std::make_shared<typename forward_const_iterator_<T, _Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    using _Kind_ = forward_const_iterator;

    inline static std::string const _cat_ = strange::reflection<_Kind_>::name();

    inline static std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(any::_cats_.cbegin(), any::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();


    inline auto operator*() const -> T const &;

    inline auto operator->() const -> T const *;

    inline auto operator++() -> forward_const_iterator &;

    inline auto operator++(int i) -> forward_const_iterator;

    inline auto operator==(forward_const_iterator<T> const & other) const -> bool;

    inline auto operator!=(forward_const_iterator<T> const & other) const -> bool;
};

template<typename T, typename _Thing, bool _Copy>
struct forward_const_iterator_ : forward_const_iterator<T>
{
    inline forward_const_iterator_() = default;

    inline forward_const_iterator_(forward_const_iterator_ const & other)
    :strange::_common{other}
    ,forward_const_iterator<T>{}
    {
    }

    inline forward_const_iterator_(forward_const_iterator_ && other)
    :strange::_common{std::move(other)}
    ,forward_const_iterator<T>{}
    {
    }

    inline auto operator=(forward_const_iterator_ const & other) -> forward_const_iterator_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(forward_const_iterator_ && other) -> forward_const_iterator_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline forward_const_iterator_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,forward_const_iterator<T>{}
    {
    }

    explicit inline forward_const_iterator_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,forward_const_iterator<T>{}
    {
    }

private:
    friend struct forward_const_iterator<T>;

    struct _instance final : forward_const_iterator<T>::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :forward_const_iterator_::_derived{}
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
                return forward_const_iterator_::_derived::_static_shared_to_base(std::make_shared<forward_const_iterator_::_instance>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto _cat() const -> std::string final
        {
            return forward_const_iterator<T>::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return forward_const_iterator<T>::_cats_;
        }

        inline auto _name() const -> std::string final
        {
            return forward_const_iterator_::_name_;
        }

        inline auto operator*() const -> T const & final;

        inline auto operator->() const -> T const * final;

        inline auto operator++() -> void final;

        inline auto operator++(int i) -> void final;

        inline auto operator==(forward_const_iterator<T> const & other) const -> bool final;

        inline auto operator!=(forward_const_iterator<T> const & other) const -> bool final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    inline static auto _make_(_Args && ... _args) -> forward_const_iterator_
    {
        return forward_const_iterator_{forward_const_iterator_::_derived::_static_shared_to_base(std::make_shared<forward_const_iterator_::_instance>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<forward_const_iterator_::_instance>(strange::_common::_shared).operator bool();
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<forward_const_iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<forward_const_iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Abstraction_ = forward_const_iterator_;
    using _Thing_ = _Thing;

    inline static std::string const _name_ = strange::reflection<_Abstraction_>::name();
};

template<typename T>
struct forward_iterator : forward_const_iterator<T>
{
    inline forward_iterator() = default;

    inline forward_iterator(forward_iterator const & other)
    :strange::_common{other}
    ,forward_const_iterator<T>{}
    {
    }

    inline forward_iterator(forward_iterator && other)
    :strange::_common{std::move(other)}
    ,forward_const_iterator<T>{}
    {
    }

    inline auto operator=(forward_iterator const & other) -> forward_iterator &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(forward_iterator && other) -> forward_iterator &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline forward_iterator(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,forward_const_iterator<T>{}
    {
    }

    explicit inline forward_iterator(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,forward_const_iterator<T>{}
    {
    }

    using value_type = T;

    using difference_type = std::ptrdiff_t;

    using reference = value_type &;

    using pointer = value_type *;

    using iterator_category = std::forward_iterator_tag;

protected:
    struct _derived : forward_const_iterator<T>::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename forward_iterator::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return forward_const_iterator<T>::_derived::_static_shared_to_base(derived);
        }

        virtual auto operator*() -> T & = 0;

        virtual auto operator->() -> T * = 0;

        virtual auto operator==(forward_iterator<T> const & other) const -> bool = 0;

        virtual auto operator!=(forward_iterator<T> const & other) const -> bool = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename forward_iterator::_derived>(strange::_common::_shared).operator bool();
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> forward_iterator
    {
        return forward_iterator{forward_iterator::_derived::_static_shared_to_base(std::make_shared<typename forward_iterator_<T, _Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    using _Kind_ = forward_iterator;

    inline static std::string const _cat_ = strange::reflection<_Kind_>::name();

    inline static std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(forward_const_iterator<T>::_cats_.cbegin(), forward_const_iterator<T>::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();


    inline auto operator*() const -> T const &;

    inline auto operator->() const -> T const *;

    inline auto operator++() -> forward_iterator &;

    inline auto operator++(int i) -> forward_iterator;

    inline auto operator==(forward_const_iterator<T> const & other) const -> bool;

    inline auto operator!=(forward_const_iterator<T> const & other) const -> bool;

    inline auto operator*() -> T &;

    inline auto operator->() -> T *;

    inline auto operator==(forward_iterator<T> const & other) const -> bool;

    inline auto operator!=(forward_iterator<T> const & other) const -> bool;
};

template<typename T, typename _Thing, bool _Copy>
struct forward_iterator_ : forward_iterator<T>
{
    inline forward_iterator_() = default;

    inline forward_iterator_(forward_iterator_ const & other)
    :strange::_common{other}
    ,forward_iterator<T>{}
    {
    }

    inline forward_iterator_(forward_iterator_ && other)
    :strange::_common{std::move(other)}
    ,forward_iterator<T>{}
    {
    }

    inline auto operator=(forward_iterator_ const & other) -> forward_iterator_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(forward_iterator_ && other) -> forward_iterator_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline forward_iterator_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,forward_iterator<T>{}
    {
    }

    explicit inline forward_iterator_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,forward_iterator<T>{}
    {
    }

private:
    friend struct forward_iterator<T>;

    struct _instance final : forward_iterator<T>::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :forward_iterator_::_derived{}
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
                return forward_iterator_::_derived::_static_shared_to_base(std::make_shared<forward_iterator_::_instance>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto _cat() const -> std::string final
        {
            return forward_iterator<T>::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return forward_iterator<T>::_cats_;
        }

        inline auto _name() const -> std::string final
        {
            return forward_iterator_::_name_;
        }

        inline auto operator*() const -> T const & final;

        inline auto operator->() const -> T const * final;

        inline auto operator++() -> void final;

        inline auto operator++(int i) -> void final;

        inline auto operator==(forward_const_iterator<T> const & other) const -> bool final;

        inline auto operator!=(forward_const_iterator<T> const & other) const -> bool final;

        inline auto operator*() -> T & final;

        inline auto operator->() -> T * final;

        inline auto operator==(forward_iterator<T> const & other) const -> bool final;

        inline auto operator!=(forward_iterator<T> const & other) const -> bool final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    inline static auto _make_(_Args && ... _args) -> forward_iterator_
    {
        return forward_iterator_{forward_iterator_::_derived::_static_shared_to_base(std::make_shared<forward_iterator_::_instance>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<forward_iterator_::_instance>(strange::_common::_shared).operator bool();
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<forward_iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<forward_iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Abstraction_ = forward_iterator_;
    using _Thing_ = _Thing;

    inline static std::string const _name_ = strange::reflection<_Abstraction_>::name();
};

template<typename T>
struct bidirectional_const_iterator : forward_const_iterator<T>
{
    inline bidirectional_const_iterator() = default;

    inline bidirectional_const_iterator(bidirectional_const_iterator const & other)
    :strange::_common{other}
    ,forward_const_iterator<T>{}
    {
    }

    inline bidirectional_const_iterator(bidirectional_const_iterator && other)
    :strange::_common{std::move(other)}
    ,forward_const_iterator<T>{}
    {
    }

    inline auto operator=(bidirectional_const_iterator const & other) -> bidirectional_const_iterator &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(bidirectional_const_iterator && other) -> bidirectional_const_iterator &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline bidirectional_const_iterator(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,forward_const_iterator<T>{}
    {
    }

    explicit inline bidirectional_const_iterator(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,forward_const_iterator<T>{}
    {
    }

    using iterator_category = std::bidirectional_iterator_tag;

protected:
    struct _derived : forward_const_iterator<T>::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename bidirectional_const_iterator::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return forward_const_iterator<T>::_derived::_static_shared_to_base(derived);
        }

        virtual auto operator==(bidirectional_const_iterator<T> const & other) const -> bool = 0;

        virtual auto operator!=(bidirectional_const_iterator<T> const & other) const -> bool = 0;

        virtual auto operator--() -> void = 0;

        virtual auto operator--(int i) -> void = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename bidirectional_const_iterator::_derived>(strange::_common::_shared).operator bool();
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> bidirectional_const_iterator
    {
        return bidirectional_const_iterator{bidirectional_const_iterator::_derived::_static_shared_to_base(std::make_shared<typename bidirectional_const_iterator_<T, _Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    using _Kind_ = bidirectional_const_iterator;

    inline static std::string const _cat_ = strange::reflection<_Kind_>::name();

    inline static std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(forward_const_iterator<T>::_cats_.cbegin(), forward_const_iterator<T>::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();


    inline auto operator*() const -> T const &;

    inline auto operator->() const -> T const *;

    inline auto operator++() -> bidirectional_const_iterator &;

    inline auto operator++(int i) -> bidirectional_const_iterator;

    inline auto operator==(forward_const_iterator<T> const & other) const -> bool;

    inline auto operator!=(forward_const_iterator<T> const & other) const -> bool;

    inline auto operator==(bidirectional_const_iterator<T> const & other) const -> bool;

    inline auto operator!=(bidirectional_const_iterator<T> const & other) const -> bool;

    inline auto operator--() -> bidirectional_const_iterator &;

    inline auto operator--(int i) -> bidirectional_const_iterator;
};

template<typename T, typename _Thing, bool _Copy>
struct bidirectional_const_iterator_ : bidirectional_const_iterator<T>
{
    inline bidirectional_const_iterator_() = default;

    inline bidirectional_const_iterator_(bidirectional_const_iterator_ const & other)
    :strange::_common{other}
    ,bidirectional_const_iterator<T>{}
    {
    }

    inline bidirectional_const_iterator_(bidirectional_const_iterator_ && other)
    :strange::_common{std::move(other)}
    ,bidirectional_const_iterator<T>{}
    {
    }

    inline auto operator=(bidirectional_const_iterator_ const & other) -> bidirectional_const_iterator_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(bidirectional_const_iterator_ && other) -> bidirectional_const_iterator_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline bidirectional_const_iterator_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,bidirectional_const_iterator<T>{}
    {
    }

    explicit inline bidirectional_const_iterator_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,bidirectional_const_iterator<T>{}
    {
    }

private:
    friend struct bidirectional_const_iterator<T>;

    struct _instance final : bidirectional_const_iterator<T>::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :bidirectional_const_iterator_::_derived{}
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
                return bidirectional_const_iterator_::_derived::_static_shared_to_base(std::make_shared<bidirectional_const_iterator_::_instance>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto _cat() const -> std::string final
        {
            return bidirectional_const_iterator<T>::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return bidirectional_const_iterator<T>::_cats_;
        }

        inline auto _name() const -> std::string final
        {
            return bidirectional_const_iterator_::_name_;
        }

        inline auto operator*() const -> T const & final;

        inline auto operator->() const -> T const * final;

        inline auto operator++() -> void final;

        inline auto operator++(int i) -> void final;

        inline auto operator==(forward_const_iterator<T> const & other) const -> bool final;

        inline auto operator!=(forward_const_iterator<T> const & other) const -> bool final;

        inline auto operator==(bidirectional_const_iterator<T> const & other) const -> bool final;

        inline auto operator!=(bidirectional_const_iterator<T> const & other) const -> bool final;

        inline auto operator--() -> void final;

        inline auto operator--(int i) -> void final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    inline static auto _make_(_Args && ... _args) -> bidirectional_const_iterator_
    {
        return bidirectional_const_iterator_{bidirectional_const_iterator_::_derived::_static_shared_to_base(std::make_shared<bidirectional_const_iterator_::_instance>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<bidirectional_const_iterator_::_instance>(strange::_common::_shared).operator bool();
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<bidirectional_const_iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<bidirectional_const_iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Abstraction_ = bidirectional_const_iterator_;
    using _Thing_ = _Thing;

    inline static std::string const _name_ = strange::reflection<_Abstraction_>::name();
};

template<typename T>
struct bidirectional_iterator : forward_iterator<T>, bidirectional_const_iterator<T>
{
    inline bidirectional_iterator() = default;

    inline bidirectional_iterator(bidirectional_iterator const & other)
    :strange::_common{other}
    ,forward_iterator<T>{}
    ,bidirectional_const_iterator<T>{}
    {
    }

    inline bidirectional_iterator(bidirectional_iterator && other)
    :strange::_common{std::move(other)}
    ,forward_iterator<T>{}
    ,bidirectional_const_iterator<T>{}
    {
    }

    inline auto operator=(bidirectional_iterator const & other) -> bidirectional_iterator &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(bidirectional_iterator && other) -> bidirectional_iterator &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline bidirectional_iterator(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,forward_iterator<T>{}
    ,bidirectional_const_iterator<T>{}
    {
    }

    explicit inline bidirectional_iterator(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,forward_iterator<T>{}
    ,bidirectional_const_iterator<T>{}
    {
    }

    using value_type = T;

    using difference_type = std::ptrdiff_t;

    using reference = value_type &;

    using pointer = value_type *;

    using iterator_category = std::bidirectional_iterator_tag;

protected:
    struct _derived : forward_iterator<T>::_derived, bidirectional_const_iterator<T>::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename bidirectional_iterator::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return forward_iterator<T>::_derived::_static_shared_to_base(derived);
        }

        virtual auto operator==(bidirectional_iterator<T> const & other) const -> bool = 0;

        virtual auto operator!=(bidirectional_iterator<T> const & other) const -> bool = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename bidirectional_iterator::_derived>(strange::_common::_shared).operator bool();
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> bidirectional_iterator
    {
        return bidirectional_iterator{bidirectional_iterator::_derived::_static_shared_to_base(std::make_shared<typename bidirectional_iterator_<T, _Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    using _Kind_ = bidirectional_iterator;

    inline static std::string const _cat_ = strange::reflection<_Kind_>::name();

    inline static std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(forward_iterator<T>::_cats_.cbegin(), forward_iterator<T>::_cats_.cend());
        cats.insert(bidirectional_const_iterator<T>::_cats_.cbegin(), bidirectional_const_iterator<T>::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();


    inline auto operator*() const -> T const &;

    inline auto operator->() const -> T const *;

    inline auto operator++() -> bidirectional_iterator &;

    inline auto operator++(int i) -> bidirectional_iterator;

    inline auto operator==(forward_const_iterator<T> const & other) const -> bool;

    inline auto operator!=(forward_const_iterator<T> const & other) const -> bool;

    inline auto operator*() -> T &;

    inline auto operator->() -> T *;

    inline auto operator==(forward_iterator<T> const & other) const -> bool;

    inline auto operator!=(forward_iterator<T> const & other) const -> bool;

    inline auto operator==(bidirectional_const_iterator<T> const & other) const -> bool;

    inline auto operator!=(bidirectional_const_iterator<T> const & other) const -> bool;

    inline auto operator--() -> bidirectional_iterator &;

    inline auto operator--(int i) -> bidirectional_iterator;

    inline auto operator==(bidirectional_iterator<T> const & other) const -> bool;

    inline auto operator!=(bidirectional_iterator<T> const & other) const -> bool;
};

template<typename T, typename _Thing, bool _Copy>
struct bidirectional_iterator_ : bidirectional_iterator<T>
{
    inline bidirectional_iterator_() = default;

    inline bidirectional_iterator_(bidirectional_iterator_ const & other)
    :strange::_common{other}
    ,bidirectional_iterator<T>{}
    {
    }

    inline bidirectional_iterator_(bidirectional_iterator_ && other)
    :strange::_common{std::move(other)}
    ,bidirectional_iterator<T>{}
    {
    }

    inline auto operator=(bidirectional_iterator_ const & other) -> bidirectional_iterator_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(bidirectional_iterator_ && other) -> bidirectional_iterator_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline bidirectional_iterator_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,bidirectional_iterator<T>{}
    {
    }

    explicit inline bidirectional_iterator_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,bidirectional_iterator<T>{}
    {
    }

private:
    friend struct bidirectional_iterator<T>;

    struct _instance final : bidirectional_iterator<T>::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :bidirectional_iterator_::_derived{}
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
                return bidirectional_iterator_::_derived::_static_shared_to_base(std::make_shared<bidirectional_iterator_::_instance>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto _cat() const -> std::string final
        {
            return bidirectional_iterator<T>::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return bidirectional_iterator<T>::_cats_;
        }

        inline auto _name() const -> std::string final
        {
            return bidirectional_iterator_::_name_;
        }

        inline auto operator*() const -> T const & final;

        inline auto operator->() const -> T const * final;

        inline auto operator++() -> void final;

        inline auto operator++(int i) -> void final;

        inline auto operator==(forward_const_iterator<T> const & other) const -> bool final;

        inline auto operator!=(forward_const_iterator<T> const & other) const -> bool final;

        inline auto operator*() -> T & final;

        inline auto operator->() -> T * final;

        inline auto operator==(forward_iterator<T> const & other) const -> bool final;

        inline auto operator!=(forward_iterator<T> const & other) const -> bool final;

        inline auto operator==(bidirectional_const_iterator<T> const & other) const -> bool final;

        inline auto operator!=(bidirectional_const_iterator<T> const & other) const -> bool final;

        inline auto operator--() -> void final;

        inline auto operator--(int i) -> void final;

        inline auto operator==(bidirectional_iterator<T> const & other) const -> bool final;

        inline auto operator!=(bidirectional_iterator<T> const & other) const -> bool final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    inline static auto _make_(_Args && ... _args) -> bidirectional_iterator_
    {
        return bidirectional_iterator_{bidirectional_iterator_::_derived::_static_shared_to_base(std::make_shared<bidirectional_iterator_::_instance>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<bidirectional_iterator_::_instance>(strange::_common::_shared).operator bool();
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<bidirectional_iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<bidirectional_iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Abstraction_ = bidirectional_iterator_;
    using _Thing_ = _Thing;

    inline static std::string const _name_ = strange::reflection<_Abstraction_>::name();
};

template<typename T>
struct random_access_const_iterator : bidirectional_const_iterator<T>
{
    inline random_access_const_iterator() = default;

    inline random_access_const_iterator(random_access_const_iterator const & other)
    :strange::_common{other}
    ,bidirectional_const_iterator<T>{}
    {
    }

    inline random_access_const_iterator(random_access_const_iterator && other)
    :strange::_common{std::move(other)}
    ,bidirectional_const_iterator<T>{}
    {
    }

    inline auto operator=(random_access_const_iterator const & other) -> random_access_const_iterator &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(random_access_const_iterator && other) -> random_access_const_iterator &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline random_access_const_iterator(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,bidirectional_const_iterator<T>{}
    {
    }

    explicit inline random_access_const_iterator(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,bidirectional_const_iterator<T>{}
    {
    }

    using value_type = T;

    using difference_type = std::ptrdiff_t;

    using reference = value_type &;

    using pointer = value_type *;

    using iterator_category = std::random_access_iterator_tag;

protected:
    struct _derived : bidirectional_const_iterator<T>::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename random_access_const_iterator::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return bidirectional_const_iterator<T>::_derived::_static_shared_to_base(derived);
        }

        virtual auto operator==(random_access_const_iterator<T> const & other) const -> bool = 0;

        virtual auto operator!=(random_access_const_iterator<T> const & other) const -> bool = 0;

        virtual auto operator<(random_access_const_iterator<T> const & other) const -> bool = 0;

        virtual auto operator>(random_access_const_iterator<T> const & other) const -> bool = 0;

        virtual auto operator<=(random_access_const_iterator<T> const & other) const -> bool = 0;

        virtual auto operator>=(random_access_const_iterator<T> const & other) const -> bool = 0;

        virtual auto operator+=(std::ptrdiff_t n) -> void = 0;

        virtual auto operator-=(std::ptrdiff_t n) -> void = 0;

        virtual auto operator+(std::ptrdiff_t n) const -> random_access_const_iterator<T> = 0;

        virtual auto operator-(std::ptrdiff_t n) const -> random_access_const_iterator<T> = 0;

        virtual auto operator-(random_access_const_iterator<T> other) const -> std::ptrdiff_t = 0;

        virtual auto operator[](std::ptrdiff_t n) const -> T const & = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename random_access_const_iterator::_derived>(strange::_common::_shared).operator bool();
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> random_access_const_iterator
    {
        return random_access_const_iterator{random_access_const_iterator::_derived::_static_shared_to_base(std::make_shared<typename random_access_const_iterator_<T, _Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    using _Kind_ = random_access_const_iterator;

    inline static std::string const _cat_ = strange::reflection<_Kind_>::name();

    inline static std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(bidirectional_const_iterator<T>::_cats_.cbegin(), bidirectional_const_iterator<T>::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();


    inline auto operator*() const -> T const &;

    inline auto operator->() const -> T const *;

    inline auto operator++() -> random_access_const_iterator &;

    inline auto operator++(int i) -> random_access_const_iterator;

    inline auto operator==(forward_const_iterator<T> const & other) const -> bool;

    inline auto operator!=(forward_const_iterator<T> const & other) const -> bool;

    inline auto operator==(bidirectional_const_iterator<T> const & other) const -> bool;

    inline auto operator!=(bidirectional_const_iterator<T> const & other) const -> bool;

    inline auto operator--() -> random_access_const_iterator &;

    inline auto operator--(int i) -> random_access_const_iterator;

    inline auto operator==(random_access_const_iterator<T> const & other) const -> bool;

    inline auto operator!=(random_access_const_iterator<T> const & other) const -> bool;

    inline auto operator<(random_access_const_iterator<T> const & other) const -> bool;

    inline auto operator>(random_access_const_iterator<T> const & other) const -> bool;

    inline auto operator<=(random_access_const_iterator<T> const & other) const -> bool;

    inline auto operator>=(random_access_const_iterator<T> const & other) const -> bool;

    inline auto operator+=(std::ptrdiff_t n) -> random_access_const_iterator &;

    inline auto operator-=(std::ptrdiff_t n) -> random_access_const_iterator &;

    inline auto operator+(std::ptrdiff_t n) const -> random_access_const_iterator<T>;

    inline auto operator-(std::ptrdiff_t n) const -> random_access_const_iterator<T>;

    inline auto operator-(random_access_const_iterator<T> other) const -> std::ptrdiff_t;

    inline auto operator[](std::ptrdiff_t n) const -> T const &;
};

template<typename T, typename _Thing, bool _Copy>
struct random_access_const_iterator_ : random_access_const_iterator<T>
{
    inline random_access_const_iterator_() = default;

    inline random_access_const_iterator_(random_access_const_iterator_ const & other)
    :strange::_common{other}
    ,random_access_const_iterator<T>{}
    {
    }

    inline random_access_const_iterator_(random_access_const_iterator_ && other)
    :strange::_common{std::move(other)}
    ,random_access_const_iterator<T>{}
    {
    }

    inline auto operator=(random_access_const_iterator_ const & other) -> random_access_const_iterator_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(random_access_const_iterator_ && other) -> random_access_const_iterator_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline random_access_const_iterator_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,random_access_const_iterator<T>{}
    {
    }

    explicit inline random_access_const_iterator_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,random_access_const_iterator<T>{}
    {
    }

private:
    friend struct random_access_const_iterator<T>;

    struct _instance final : random_access_const_iterator<T>::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :random_access_const_iterator_::_derived{}
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
                return random_access_const_iterator_::_derived::_static_shared_to_base(std::make_shared<random_access_const_iterator_::_instance>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto _cat() const -> std::string final
        {
            return random_access_const_iterator<T>::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return random_access_const_iterator<T>::_cats_;
        }

        inline auto _name() const -> std::string final
        {
            return random_access_const_iterator_::_name_;
        }

        inline auto operator*() const -> T const & final;

        inline auto operator->() const -> T const * final;

        inline auto operator++() -> void final;

        inline auto operator++(int i) -> void final;

        inline auto operator==(forward_const_iterator<T> const & other) const -> bool final;

        inline auto operator!=(forward_const_iterator<T> const & other) const -> bool final;

        inline auto operator==(bidirectional_const_iterator<T> const & other) const -> bool final;

        inline auto operator!=(bidirectional_const_iterator<T> const & other) const -> bool final;

        inline auto operator--() -> void final;

        inline auto operator--(int i) -> void final;

        inline auto operator==(random_access_const_iterator<T> const & other) const -> bool final;

        inline auto operator!=(random_access_const_iterator<T> const & other) const -> bool final;

        inline auto operator<(random_access_const_iterator<T> const & other) const -> bool final;

        inline auto operator>(random_access_const_iterator<T> const & other) const -> bool final;

        inline auto operator<=(random_access_const_iterator<T> const & other) const -> bool final;

        inline auto operator>=(random_access_const_iterator<T> const & other) const -> bool final;

        inline auto operator+=(std::ptrdiff_t n) -> void final;

        inline auto operator-=(std::ptrdiff_t n) -> void final;

        inline auto operator+(std::ptrdiff_t n) const -> random_access_const_iterator<T> final;

        inline auto operator-(std::ptrdiff_t n) const -> random_access_const_iterator<T> final;

        inline auto operator-(random_access_const_iterator<T> other) const -> std::ptrdiff_t final;

        inline auto operator[](std::ptrdiff_t n) const -> T const & final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    inline static auto _make_(_Args && ... _args) -> random_access_const_iterator_
    {
        return random_access_const_iterator_{random_access_const_iterator_::_derived::_static_shared_to_base(std::make_shared<random_access_const_iterator_::_instance>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<random_access_const_iterator_::_instance>(strange::_common::_shared).operator bool();
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<random_access_const_iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<random_access_const_iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Abstraction_ = random_access_const_iterator_;
    using _Thing_ = _Thing;

    inline static std::string const _name_ = strange::reflection<_Abstraction_>::name();
};

template<typename T>
struct random_access_iterator : bidirectional_iterator<T>, random_access_const_iterator<T>
{
    inline random_access_iterator() = default;

    inline random_access_iterator(random_access_iterator const & other)
    :strange::_common{other}
    ,bidirectional_iterator<T>{}
    ,random_access_const_iterator<T>{}
    {
    }

    inline random_access_iterator(random_access_iterator && other)
    :strange::_common{std::move(other)}
    ,bidirectional_iterator<T>{}
    ,random_access_const_iterator<T>{}
    {
    }

    inline auto operator=(random_access_iterator const & other) -> random_access_iterator &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(random_access_iterator && other) -> random_access_iterator &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline random_access_iterator(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,bidirectional_iterator<T>{}
    ,random_access_const_iterator<T>{}
    {
    }

    explicit inline random_access_iterator(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,bidirectional_iterator<T>{}
    ,random_access_const_iterator<T>{}
    {
    }

    using value_type = T;

    using difference_type = std::ptrdiff_t;

    using reference = value_type &;

    using pointer = value_type *;

    using iterator_category = std::random_access_iterator_tag;

protected:
    struct _derived : bidirectional_iterator<T>::_derived, random_access_const_iterator<T>::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename random_access_iterator::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return bidirectional_iterator<T>::_derived::_static_shared_to_base(derived);
        }

        virtual auto operator==(random_access_iterator<T> const & other) const -> bool = 0;

        virtual auto operator!=(random_access_iterator<T> const & other) const -> bool = 0;

        virtual auto operator<(random_access_iterator<T> const & other) const -> bool = 0;

        virtual auto operator>(random_access_iterator<T> const & other) const -> bool = 0;

        virtual auto operator<=(random_access_iterator<T> const & other) const -> bool = 0;

        virtual auto operator>=(random_access_iterator<T> const & other) const -> bool = 0;

        virtual auto operator+(std::ptrdiff_t n) -> random_access_iterator<T> = 0;

        virtual auto operator-(std::ptrdiff_t n) -> random_access_iterator<T> = 0;

        virtual auto operator-(random_access_iterator<T> other) const -> std::ptrdiff_t = 0;

        virtual auto operator[](std::ptrdiff_t n) -> T & = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename random_access_iterator::_derived>(strange::_common::_shared).operator bool();
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> random_access_iterator
    {
        return random_access_iterator{random_access_iterator::_derived::_static_shared_to_base(std::make_shared<typename random_access_iterator_<T, _Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    using _Kind_ = random_access_iterator;

    inline static std::string const _cat_ = strange::reflection<_Kind_>::name();

    inline static std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(bidirectional_iterator<T>::_cats_.cbegin(), bidirectional_iterator<T>::_cats_.cend());
        cats.insert(random_access_const_iterator<T>::_cats_.cbegin(), random_access_const_iterator<T>::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();


    inline auto operator*() const -> T const &;

    inline auto operator->() const -> T const *;

    inline auto operator++() -> random_access_iterator &;

    inline auto operator++(int i) -> random_access_iterator;

    inline auto operator==(forward_const_iterator<T> const & other) const -> bool;

    inline auto operator!=(forward_const_iterator<T> const & other) const -> bool;

    inline auto operator*() -> T &;

    inline auto operator->() -> T *;

    inline auto operator==(forward_iterator<T> const & other) const -> bool;

    inline auto operator!=(forward_iterator<T> const & other) const -> bool;

    inline auto operator==(bidirectional_const_iterator<T> const & other) const -> bool;

    inline auto operator!=(bidirectional_const_iterator<T> const & other) const -> bool;

    inline auto operator--() -> random_access_iterator &;

    inline auto operator--(int i) -> random_access_iterator;

    inline auto operator==(bidirectional_iterator<T> const & other) const -> bool;

    inline auto operator!=(bidirectional_iterator<T> const & other) const -> bool;

    inline auto operator==(random_access_const_iterator<T> const & other) const -> bool;

    inline auto operator!=(random_access_const_iterator<T> const & other) const -> bool;

    inline auto operator<(random_access_const_iterator<T> const & other) const -> bool;

    inline auto operator>(random_access_const_iterator<T> const & other) const -> bool;

    inline auto operator<=(random_access_const_iterator<T> const & other) const -> bool;

    inline auto operator>=(random_access_const_iterator<T> const & other) const -> bool;

    inline auto operator+=(std::ptrdiff_t n) -> random_access_iterator &;

    inline auto operator-=(std::ptrdiff_t n) -> random_access_iterator &;

    inline auto operator+(std::ptrdiff_t n) const -> random_access_const_iterator<T>;

    inline auto operator-(std::ptrdiff_t n) const -> random_access_const_iterator<T>;

    inline auto operator-(random_access_const_iterator<T> other) const -> std::ptrdiff_t;

    inline auto operator[](std::ptrdiff_t n) const -> T const &;

    inline auto operator==(random_access_iterator<T> const & other) const -> bool;

    inline auto operator!=(random_access_iterator<T> const & other) const -> bool;

    inline auto operator<(random_access_iterator<T> const & other) const -> bool;

    inline auto operator>(random_access_iterator<T> const & other) const -> bool;

    inline auto operator<=(random_access_iterator<T> const & other) const -> bool;

    inline auto operator>=(random_access_iterator<T> const & other) const -> bool;

    inline auto operator+(std::ptrdiff_t n) -> random_access_iterator<T>;

    inline auto operator-(std::ptrdiff_t n) -> random_access_iterator<T>;

    inline auto operator-(random_access_iterator<T> other) const -> std::ptrdiff_t;

    inline auto operator[](std::ptrdiff_t n) -> T &;
};

template<typename T, typename _Thing, bool _Copy>
struct random_access_iterator_ : random_access_iterator<T>
{
    inline random_access_iterator_() = default;

    inline random_access_iterator_(random_access_iterator_ const & other)
    :strange::_common{other}
    ,random_access_iterator<T>{}
    {
    }

    inline random_access_iterator_(random_access_iterator_ && other)
    :strange::_common{std::move(other)}
    ,random_access_iterator<T>{}
    {
    }

    inline auto operator=(random_access_iterator_ const & other) -> random_access_iterator_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(random_access_iterator_ && other) -> random_access_iterator_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline random_access_iterator_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,random_access_iterator<T>{}
    {
    }

    explicit inline random_access_iterator_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,random_access_iterator<T>{}
    {
    }

private:
    friend struct random_access_iterator<T>;

    struct _instance final : random_access_iterator<T>::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :random_access_iterator_::_derived{}
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
                return random_access_iterator_::_derived::_static_shared_to_base(std::make_shared<random_access_iterator_::_instance>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto _cat() const -> std::string final
        {
            return random_access_iterator<T>::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return random_access_iterator<T>::_cats_;
        }

        inline auto _name() const -> std::string final
        {
            return random_access_iterator_::_name_;
        }

        inline auto operator*() const -> T const & final;

        inline auto operator->() const -> T const * final;

        inline auto operator++() -> void final;

        inline auto operator++(int i) -> void final;

        inline auto operator==(forward_const_iterator<T> const & other) const -> bool final;

        inline auto operator!=(forward_const_iterator<T> const & other) const -> bool final;

        inline auto operator*() -> T & final;

        inline auto operator->() -> T * final;

        inline auto operator==(forward_iterator<T> const & other) const -> bool final;

        inline auto operator!=(forward_iterator<T> const & other) const -> bool final;

        inline auto operator==(bidirectional_const_iterator<T> const & other) const -> bool final;

        inline auto operator!=(bidirectional_const_iterator<T> const & other) const -> bool final;

        inline auto operator--() -> void final;

        inline auto operator--(int i) -> void final;

        inline auto operator==(bidirectional_iterator<T> const & other) const -> bool final;

        inline auto operator!=(bidirectional_iterator<T> const & other) const -> bool final;

        inline auto operator==(random_access_const_iterator<T> const & other) const -> bool final;

        inline auto operator!=(random_access_const_iterator<T> const & other) const -> bool final;

        inline auto operator<(random_access_const_iterator<T> const & other) const -> bool final;

        inline auto operator>(random_access_const_iterator<T> const & other) const -> bool final;

        inline auto operator<=(random_access_const_iterator<T> const & other) const -> bool final;

        inline auto operator>=(random_access_const_iterator<T> const & other) const -> bool final;

        inline auto operator+=(std::ptrdiff_t n) -> void final;

        inline auto operator-=(std::ptrdiff_t n) -> void final;

        inline auto operator+(std::ptrdiff_t n) const -> random_access_const_iterator<T> final;

        inline auto operator-(std::ptrdiff_t n) const -> random_access_const_iterator<T> final;

        inline auto operator-(random_access_const_iterator<T> other) const -> std::ptrdiff_t final;

        inline auto operator[](std::ptrdiff_t n) const -> T const & final;

        inline auto operator==(random_access_iterator<T> const & other) const -> bool final;

        inline auto operator!=(random_access_iterator<T> const & other) const -> bool final;

        inline auto operator<(random_access_iterator<T> const & other) const -> bool final;

        inline auto operator>(random_access_iterator<T> const & other) const -> bool final;

        inline auto operator<=(random_access_iterator<T> const & other) const -> bool final;

        inline auto operator>=(random_access_iterator<T> const & other) const -> bool final;

        inline auto operator+(std::ptrdiff_t n) -> random_access_iterator<T> final;

        inline auto operator-(std::ptrdiff_t n) -> random_access_iterator<T> final;

        inline auto operator-(random_access_iterator<T> other) const -> std::ptrdiff_t final;

        inline auto operator[](std::ptrdiff_t n) -> T & final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    inline static auto _make_(_Args && ... _args) -> random_access_iterator_
    {
        return random_access_iterator_{random_access_iterator_::_derived::_static_shared_to_base(std::make_shared<random_access_iterator_::_instance>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<random_access_iterator_::_instance>(strange::_common::_shared).operator bool();
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<random_access_iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<random_access_iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Abstraction_ = random_access_iterator_;
    using _Thing_ = _Thing;

    inline static std::string const _name_ = strange::reflection<_Abstraction_>::name();
};

template<typename T>
struct vector : any
{
    inline vector() = default;

    inline vector(vector const & other)
    :strange::_common{other}
    ,any{}
    {
    }

    inline vector(vector && other)
    :strange::_common{std::move(other)}
    ,any{}
    {
    }

    inline auto operator=(vector const & other) -> vector &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(vector && other) -> vector &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline vector(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,any{}
    {
    }

    explicit inline vector(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,any{}
    {
    }

    using value_type = T;

    using size_type = std::size_t;

    using difference_type = std::ptrdiff_t;

    using reference = value_type &;

    using const_reference = value_type const &;

    using pointer = value_type *;

    using const_pointer = value_type const *;

    using iterator = typename strange::random_access_iterator<T>;

    using const_iterator = typename strange::random_access_const_iterator<T>;

    using reverse_iterator = typename std::reverse_iterator<iterator>;

    using const_reverse_iterator = typename std::reverse_iterator<const_iterator>;

protected:
    struct _derived : any::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename vector::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return any::_derived::_static_shared_to_base(derived);
        }

        virtual auto operator=(std::initializer_list<T> ilist) -> void = 0;

        virtual auto assign(size_t count, T const & value) -> void = 0;

        virtual auto assign(forward_const_iterator<T> first, forward_const_iterator<T> last) -> void = 0;

        virtual auto assign(std::initializer_list<T> ilist) -> void = 0;

        virtual auto at(size_t pos) -> T & = 0;

        virtual auto at(size_t pos) const -> T const & = 0;

        virtual auto operator[](size_t pos) -> T & = 0;

        virtual auto operator[](size_t pos) const -> T const & = 0;

        virtual auto front() -> T & = 0;

        virtual auto front() const -> T const & = 0;

        virtual auto back() -> T & = 0;

        virtual auto back() const -> T const & = 0;

        virtual auto data() -> T * = 0;

        virtual auto data() const -> T const * = 0;

        virtual auto begin() -> typename strange::random_access_iterator<T> = 0;

        virtual auto begin() const -> typename strange::random_access_const_iterator<T> = 0;

        virtual auto cbegin() const -> typename strange::random_access_const_iterator<T> = 0;

        virtual auto end() -> typename strange::random_access_iterator<T> = 0;

        virtual auto end() const -> typename strange::random_access_const_iterator<T> = 0;

        virtual auto cend() const -> typename strange::random_access_const_iterator<T> = 0;

        virtual auto rbegin() -> typename std::reverse_iterator<strange::random_access_iterator<T>> = 0;

        virtual auto rbegin() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>> = 0;

        virtual auto crbegin() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>> = 0;

        virtual auto rend() -> typename std::reverse_iterator<strange::random_access_iterator<T>> = 0;

        virtual auto rend() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>> = 0;

        virtual auto crend() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>> = 0;

        virtual auto empty() const -> bool = 0;

        virtual auto size() const -> size_t = 0;

        virtual auto max_size() const -> size_t = 0;

        virtual auto reserve(size_t new_cap) -> void = 0;

        virtual auto capacity() const -> size_t = 0;

        virtual auto shrink_to_fit() -> void = 0;

        virtual auto clear() -> void = 0;

        virtual auto insert(typename strange::random_access_const_iterator<T> pos, T const & value) -> typename strange::random_access_iterator<T> = 0;

        virtual auto insert(typename strange::random_access_const_iterator<T> pos, T && value) -> typename strange::random_access_iterator<T> = 0;

        virtual auto insert(typename strange::random_access_const_iterator<T> pos, size_t count, T const & value) -> typename strange::random_access_iterator<T> = 0;

        virtual auto insert(typename strange::random_access_const_iterator<T> pos, forward_const_iterator<T> first, forward_const_iterator<T> last) -> typename strange::random_access_iterator<T> = 0;

        virtual auto insert(typename strange::random_access_const_iterator<T> pos, std::initializer_list<T> ilist) -> typename strange::random_access_iterator<T> = 0;

        virtual auto erase(typename strange::random_access_const_iterator<T> pos) -> typename strange::random_access_iterator<T> = 0;

        virtual auto erase(typename strange::random_access_const_iterator<T> first, typename strange::random_access_const_iterator<T> last) -> typename strange::random_access_iterator<T> = 0;

        virtual auto push_back(T const & value) -> void = 0;

        virtual auto push_back(T && value) -> void = 0;

        virtual auto pop_back() -> void = 0;

        virtual auto resize(size_t count) -> void = 0;

        virtual auto resize(size_t count, T const & value) -> void = 0;

        virtual auto swap(vector<T> & other) -> void = 0;

        virtual auto operator==(vector<T> const & other) const -> bool = 0;

        virtual auto operator!=(vector<T> const & other) const -> bool = 0;

        virtual auto operator<(vector<T> const & other) const -> bool = 0;

        virtual auto operator>(vector<T> const & other) const -> bool = 0;

        virtual auto operator<=(vector<T> const & other) const -> bool = 0;

        virtual auto operator>=(vector<T> const & other) const -> bool = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename vector::_derived>(strange::_common::_shared).operator bool();
    }

    template<typename _Thing = std::vector<T>, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> vector
    {
        return vector{vector::_derived::_static_shared_to_base(std::make_shared<typename vector_<T, _Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    using _Kind_ = vector;

    inline static std::string const _cat_ = strange::reflection<_Kind_>::name();

    inline static std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(any::_cats_.cbegin(), any::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();


    inline auto operator=(std::initializer_list<T> ilist) -> vector &;

    inline auto assign(size_t count, T const & value) -> void;

    inline auto assign(forward_const_iterator<T> first, forward_const_iterator<T> last) -> void;

    inline auto assign(std::initializer_list<T> ilist) -> void;

    inline auto at(size_t pos) -> T &;

    inline auto at(size_t pos) const -> T const &;

    inline auto operator[](size_t pos) -> T &;

    inline auto operator[](size_t pos) const -> T const &;

    inline auto front() -> T &;

    inline auto front() const -> T const &;

    inline auto back() -> T &;

    inline auto back() const -> T const &;

    inline auto data() -> T *;

    inline auto data() const -> T const *;

    inline auto begin() -> typename strange::random_access_iterator<T>;

    inline auto begin() const -> typename strange::random_access_const_iterator<T>;

    inline auto cbegin() const -> typename strange::random_access_const_iterator<T>;

    inline auto end() -> typename strange::random_access_iterator<T>;

    inline auto end() const -> typename strange::random_access_const_iterator<T>;

    inline auto cend() const -> typename strange::random_access_const_iterator<T>;

    inline auto rbegin() -> typename std::reverse_iterator<strange::random_access_iterator<T>>;

    inline auto rbegin() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>;

    inline auto crbegin() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>;

    inline auto rend() -> typename std::reverse_iterator<strange::random_access_iterator<T>>;

    inline auto rend() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>;

    inline auto crend() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>;

    inline auto empty() const -> bool;

    inline auto size() const -> size_t;

    inline auto max_size() const -> size_t;

    inline auto reserve(size_t new_cap) -> void;

    inline auto capacity() const -> size_t;

    inline auto shrink_to_fit() -> void;

    inline auto clear() -> void;

    inline auto insert(typename strange::random_access_const_iterator<T> pos, T const & value) -> typename strange::random_access_iterator<T>;

    inline auto insert(typename strange::random_access_const_iterator<T> pos, T && value) -> typename strange::random_access_iterator<T>;

    inline auto insert(typename strange::random_access_const_iterator<T> pos, size_t count, T const & value) -> typename strange::random_access_iterator<T>;

    inline auto insert(typename strange::random_access_const_iterator<T> pos, forward_const_iterator<T> first, forward_const_iterator<T> last) -> typename strange::random_access_iterator<T>;

    inline auto insert(typename strange::random_access_const_iterator<T> pos, std::initializer_list<T> ilist) -> typename strange::random_access_iterator<T>;

    inline auto erase(typename strange::random_access_const_iterator<T> pos) -> typename strange::random_access_iterator<T>;

    inline auto erase(typename strange::random_access_const_iterator<T> first, typename strange::random_access_const_iterator<T> last) -> typename strange::random_access_iterator<T>;

    inline auto push_back(T const & value) -> void;

    inline auto push_back(T && value) -> void;

    inline auto pop_back() -> void;

    inline auto resize(size_t count) -> void;

    inline auto resize(size_t count, T const & value) -> void;

    inline auto swap(vector<T> & other) -> void;

    inline auto operator==(vector<T> const & other) const -> bool;

    inline auto operator!=(vector<T> const & other) const -> bool;

    inline auto operator<(vector<T> const & other) const -> bool;

    inline auto operator>(vector<T> const & other) const -> bool;

    inline auto operator<=(vector<T> const & other) const -> bool;

    inline auto operator>=(vector<T> const & other) const -> bool;
};

template<typename T, typename _Thing, bool _Copy>
struct vector_ : vector<T>
{
    inline vector_() = default;

    inline vector_(vector_ const & other)
    :strange::_common{other}
    ,vector<T>{}
    {
    }

    inline vector_(vector_ && other)
    :strange::_common{std::move(other)}
    ,vector<T>{}
    {
    }

    inline auto operator=(vector_ const & other) -> vector_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(vector_ && other) -> vector_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline vector_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,vector<T>{}
    {
    }

    explicit inline vector_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,vector<T>{}
    {
    }

private:
    friend struct vector<T>;

    struct _instance final : vector<T>::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :vector_::_derived{}
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
                return vector_::_derived::_static_shared_to_base(std::make_shared<vector_::_instance>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto _cat() const -> std::string final
        {
            return vector<T>::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return vector<T>::_cats_;
        }

        inline auto _name() const -> std::string final
        {
            return vector_::_name_;
        }

        inline auto operator=(std::initializer_list<T> ilist) -> void final;

        inline auto assign(size_t count, T const & value) -> void final;

        inline auto assign(forward_const_iterator<T> first, forward_const_iterator<T> last) -> void final;

        inline auto assign(std::initializer_list<T> ilist) -> void final;

        inline auto at(size_t pos) -> T & final;

        inline auto at(size_t pos) const -> T const & final;

        inline auto operator[](size_t pos) -> T & final;

        inline auto operator[](size_t pos) const -> T const & final;

        inline auto front() -> T & final;

        inline auto front() const -> T const & final;

        inline auto back() -> T & final;

        inline auto back() const -> T const & final;

        inline auto data() -> T * final;

        inline auto data() const -> T const * final;

        inline auto begin() -> typename strange::random_access_iterator<T> final;

        inline auto begin() const -> typename strange::random_access_const_iterator<T> final;

        inline auto cbegin() const -> typename strange::random_access_const_iterator<T> final;

        inline auto end() -> typename strange::random_access_iterator<T> final;

        inline auto end() const -> typename strange::random_access_const_iterator<T> final;

        inline auto cend() const -> typename strange::random_access_const_iterator<T> final;

        inline auto rbegin() -> typename std::reverse_iterator<strange::random_access_iterator<T>> final;

        inline auto rbegin() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>> final;

        inline auto crbegin() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>> final;

        inline auto rend() -> typename std::reverse_iterator<strange::random_access_iterator<T>> final;

        inline auto rend() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>> final;

        inline auto crend() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>> final;

        inline auto empty() const -> bool final;

        inline auto size() const -> size_t final;

        inline auto max_size() const -> size_t final;

        inline auto reserve(size_t new_cap) -> void final;

        inline auto capacity() const -> size_t final;

        inline auto shrink_to_fit() -> void final;

        inline auto clear() -> void final;

        inline auto insert(typename strange::random_access_const_iterator<T> pos, T const & value) -> typename strange::random_access_iterator<T> final;

        inline auto insert(typename strange::random_access_const_iterator<T> pos, T && value) -> typename strange::random_access_iterator<T> final;

        inline auto insert(typename strange::random_access_const_iterator<T> pos, size_t count, T const & value) -> typename strange::random_access_iterator<T> final;

        inline auto insert(typename strange::random_access_const_iterator<T> pos, forward_const_iterator<T> first, forward_const_iterator<T> last) -> typename strange::random_access_iterator<T> final;

        inline auto insert(typename strange::random_access_const_iterator<T> pos, std::initializer_list<T> ilist) -> typename strange::random_access_iterator<T> final;

        inline auto erase(typename strange::random_access_const_iterator<T> pos) -> typename strange::random_access_iterator<T> final;

        inline auto erase(typename strange::random_access_const_iterator<T> first, typename strange::random_access_const_iterator<T> last) -> typename strange::random_access_iterator<T> final;

        inline auto push_back(T const & value) -> void final;

        inline auto push_back(T && value) -> void final;

        inline auto pop_back() -> void final;

        inline auto resize(size_t count) -> void final;

        inline auto resize(size_t count, T const & value) -> void final;

        inline auto swap(vector<T> & other) -> void final;

        inline auto operator==(vector<T> const & other) const -> bool final;

        inline auto operator!=(vector<T> const & other) const -> bool final;

        inline auto operator<(vector<T> const & other) const -> bool final;

        inline auto operator>(vector<T> const & other) const -> bool final;

        inline auto operator<=(vector<T> const & other) const -> bool final;

        inline auto operator>=(vector<T> const & other) const -> bool final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    inline static auto _make_(_Args && ... _args) -> vector_
    {
        return vector_{vector_::_derived::_static_shared_to_base(std::make_shared<vector_::_instance>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<vector_::_instance>(strange::_common::_shared).operator bool();
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<vector_::_instance>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<vector_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Abstraction_ = vector_;
    using _Thing_ = _Thing;

    inline static std::string const _name_ = strange::reflection<_Abstraction_>::name();
};

template<typename _Thing, bool _Copy>
inline auto parameter_<_Thing, _Copy>::_instance::type() const -> std::string const &
{
    return _thing.type;
}

template<typename _Thing, bool _Copy>
inline auto parameter_<_Thing, _Copy>::_instance::type() -> std::string &
{
    return _thing.type;
}

template<typename _Thing, bool _Copy>
inline auto parameter_<_Thing, _Copy>::_instance::name() const -> std::string const &
{
    return _thing.name;
}

template<typename _Thing, bool _Copy>
inline auto parameter_<_Thing, _Copy>::_instance::name() -> std::string &
{
    return _thing.name;
}

template<typename _Thing, bool _Copy>
inline auto parameter_<_Thing, _Copy>::_instance::argument() const -> std::string const &
{
    return _thing.argument;
}

template<typename _Thing, bool _Copy>
inline auto parameter_<_Thing, _Copy>::_instance::argument() -> std::string &
{
    return _thing.argument;
}

template<typename _Thing, bool _Copy>
inline auto parameter_<_Thing, _Copy>::_instance::operator==(parameter const & other) const -> bool
{
    return type() == other.type()
        && name() == other.name()
        && argument() == other.argument();
}

template<typename _Thing, bool _Copy>
inline auto parameter_<_Thing, _Copy>::_instance::operator!=(parameter const & other) const -> bool
{
    return !operator==(other);
}

inline auto parameter::type() const -> std::string const &
{
    return std::dynamic_pointer_cast<typename parameter::_derived>(strange::_common::_shared)->type();
}

inline auto parameter::type() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename parameter::_derived>(strange::_common::_shared)->type();
}

inline auto parameter::name() const -> std::string const &
{
    return std::dynamic_pointer_cast<typename parameter::_derived>(strange::_common::_shared)->name();
}

inline auto parameter::name() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename parameter::_derived>(strange::_common::_shared)->name();
}

inline auto parameter::argument() const -> std::string const &
{
    return std::dynamic_pointer_cast<typename parameter::_derived>(strange::_common::_shared)->argument();
}

inline auto parameter::argument() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename parameter::_derived>(strange::_common::_shared)->argument();
}

inline auto parameter::operator==(parameter const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename parameter::_derived>(strange::_common::_shared)->operator==(other);
}

inline auto parameter::operator!=(parameter const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename parameter::_derived>(strange::_common::_shared)->operator!=(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto forward_const_iterator_<T, _Thing, _Copy>::_instance::operator*() const -> T const &
{
    return _thing.operator*();
}

template<typename T, typename _Thing, bool _Copy>
inline auto forward_const_iterator_<T, _Thing, _Copy>::_instance::operator->() const -> T const *
{
    return _thing.operator->();
}

template<typename T, typename _Thing, bool _Copy>
inline auto forward_const_iterator_<T, _Thing, _Copy>::_instance::operator++() -> void
{
    _thing.operator++();
}

template<typename T, typename _Thing, bool _Copy>
inline auto forward_const_iterator_<T, _Thing, _Copy>::_instance::operator++(int i) -> void
{
    _thing.operator++(i);
}

template<typename T, typename _Thing, bool _Copy>
inline auto forward_const_iterator_<T, _Thing, _Copy>::_instance::operator==(forward_const_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<forward_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto forward_const_iterator_<T, _Thing, _Copy>::_instance::operator!=(forward_const_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T>
inline auto forward_const_iterator<T>::operator*() const -> T const &
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator*();
}

template<typename T>
inline auto forward_const_iterator<T>::operator->() const -> T const *
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator->();
}

template<typename T>
inline auto forward_const_iterator<T>::operator++() -> forward_const_iterator &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator++();
    return *this;
}

template<typename T>
inline auto forward_const_iterator<T>::operator++(int i) -> forward_const_iterator
{
    auto _result = *this;
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator++(i);
    return _result;
}

template<typename T>
inline auto forward_const_iterator<T>::operator==(forward_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto forward_const_iterator<T>::operator!=(forward_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator!=(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto forward_iterator_<T, _Thing, _Copy>::_instance::operator*() const -> T const &
{
    return _thing.operator*();
}

template<typename T, typename _Thing, bool _Copy>
inline auto forward_iterator_<T, _Thing, _Copy>::_instance::operator->() const -> T const *
{
    return _thing.operator->();
}

template<typename T, typename _Thing, bool _Copy>
inline auto forward_iterator_<T, _Thing, _Copy>::_instance::operator++() -> void
{
    _thing.operator++();
}

template<typename T, typename _Thing, bool _Copy>
inline auto forward_iterator_<T, _Thing, _Copy>::_instance::operator++(int i) -> void
{
    _thing.operator++(i);
}

template<typename T, typename _Thing, bool _Copy>
inline auto forward_iterator_<T, _Thing, _Copy>::_instance::operator==(forward_const_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<forward_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto forward_iterator_<T, _Thing, _Copy>::_instance::operator!=(forward_const_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto forward_iterator_<T, _Thing, _Copy>::_instance::operator*() -> T &
{
    return _thing.operator*();
}

template<typename T, typename _Thing, bool _Copy>
inline auto forward_iterator_<T, _Thing, _Copy>::_instance::operator->() -> T *
{
    return _thing.operator->();
}

template<typename T, typename _Thing, bool _Copy>
inline auto forward_iterator_<T, _Thing, _Copy>::_instance::operator==(forward_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<forward_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto forward_iterator_<T, _Thing, _Copy>::_instance::operator!=(forward_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T>
inline auto forward_iterator<T>::operator*() const -> T const &
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator*();
}

template<typename T>
inline auto forward_iterator<T>::operator->() const -> T const *
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator->();
}

template<typename T>
inline auto forward_iterator<T>::operator++() -> forward_iterator &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator++();
    return *this;
}

template<typename T>
inline auto forward_iterator<T>::operator++(int i) -> forward_iterator
{
    auto _result = *this;
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator++(i);
    return _result;
}

template<typename T>
inline auto forward_iterator<T>::operator==(forward_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto forward_iterator<T>::operator!=(forward_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto forward_iterator<T>::operator*() -> T &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename forward_iterator<T>::_derived>(strange::_common::_shared)->operator*();
}

template<typename T>
inline auto forward_iterator<T>::operator->() -> T *
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename forward_iterator<T>::_derived>(strange::_common::_shared)->operator->();
}

template<typename T>
inline auto forward_iterator<T>::operator==(forward_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_iterator<T>::_derived>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto forward_iterator<T>::operator!=(forward_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_iterator<T>::_derived>(strange::_common::_shared)->operator!=(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_const_iterator_<T, _Thing, _Copy>::_instance::operator*() const -> T const &
{
    return _thing.operator*();
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_const_iterator_<T, _Thing, _Copy>::_instance::operator->() const -> T const *
{
    return _thing.operator->();
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_const_iterator_<T, _Thing, _Copy>::_instance::operator++() -> void
{
    _thing.operator++();
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_const_iterator_<T, _Thing, _Copy>::_instance::operator++(int i) -> void
{
    _thing.operator++(i);
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_const_iterator_<T, _Thing, _Copy>::_instance::operator==(forward_const_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<forward_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_const_iterator_<T, _Thing, _Copy>::_instance::operator!=(forward_const_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_const_iterator_<T, _Thing, _Copy>::_instance::operator==(bidirectional_const_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<bidirectional_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_const_iterator_<T, _Thing, _Copy>::_instance::operator!=(bidirectional_const_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_const_iterator_<T, _Thing, _Copy>::_instance::operator--() -> void
{
    _thing.operator--();
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_const_iterator_<T, _Thing, _Copy>::_instance::operator--(int i) -> void
{
    _thing.operator--(i);
}

template<typename T>
inline auto bidirectional_const_iterator<T>::operator*() const -> T const &
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator*();
}

template<typename T>
inline auto bidirectional_const_iterator<T>::operator->() const -> T const *
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator->();
}

template<typename T>
inline auto bidirectional_const_iterator<T>::operator++() -> bidirectional_const_iterator &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator++();
    return *this;
}

template<typename T>
inline auto bidirectional_const_iterator<T>::operator++(int i) -> bidirectional_const_iterator
{
    auto _result = *this;
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator++(i);
    return _result;
}

template<typename T>
inline auto bidirectional_const_iterator<T>::operator==(forward_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto bidirectional_const_iterator<T>::operator!=(forward_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto bidirectional_const_iterator<T>::operator==(bidirectional_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto bidirectional_const_iterator<T>::operator!=(bidirectional_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto bidirectional_const_iterator<T>::operator--() -> bidirectional_const_iterator &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived>(strange::_common::_shared)->operator--();
    return *this;
}

template<typename T>
inline auto bidirectional_const_iterator<T>::operator--(int i) -> bidirectional_const_iterator
{
    auto _result = *this;
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived>(strange::_common::_shared)->operator--(i);
    return _result;
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_iterator_<T, _Thing, _Copy>::_instance::operator*() const -> T const &
{
    return _thing.operator*();
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_iterator_<T, _Thing, _Copy>::_instance::operator->() const -> T const *
{
    return _thing.operator->();
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_iterator_<T, _Thing, _Copy>::_instance::operator++() -> void
{
    _thing.operator++();
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_iterator_<T, _Thing, _Copy>::_instance::operator++(int i) -> void
{
    _thing.operator++(i);
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_iterator_<T, _Thing, _Copy>::_instance::operator==(forward_const_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<forward_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_iterator_<T, _Thing, _Copy>::_instance::operator!=(forward_const_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_iterator_<T, _Thing, _Copy>::_instance::operator*() -> T &
{
    return _thing.operator*();
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_iterator_<T, _Thing, _Copy>::_instance::operator->() -> T *
{
    return _thing.operator->();
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_iterator_<T, _Thing, _Copy>::_instance::operator==(forward_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<forward_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_iterator_<T, _Thing, _Copy>::_instance::operator!=(forward_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_iterator_<T, _Thing, _Copy>::_instance::operator==(bidirectional_const_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<bidirectional_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_iterator_<T, _Thing, _Copy>::_instance::operator!=(bidirectional_const_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_iterator_<T, _Thing, _Copy>::_instance::operator--() -> void
{
    _thing.operator--();
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_iterator_<T, _Thing, _Copy>::_instance::operator--(int i) -> void
{
    _thing.operator--(i);
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_iterator_<T, _Thing, _Copy>::_instance::operator==(bidirectional_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<bidirectional_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_iterator_<T, _Thing, _Copy>::_instance::operator!=(bidirectional_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T>
inline auto bidirectional_iterator<T>::operator*() const -> T const &
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator*();
}

template<typename T>
inline auto bidirectional_iterator<T>::operator->() const -> T const *
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator->();
}

template<typename T>
inline auto bidirectional_iterator<T>::operator++() -> bidirectional_iterator &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator++();
    return *this;
}

template<typename T>
inline auto bidirectional_iterator<T>::operator++(int i) -> bidirectional_iterator
{
    auto _result = *this;
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator++(i);
    return _result;
}

template<typename T>
inline auto bidirectional_iterator<T>::operator==(forward_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto bidirectional_iterator<T>::operator!=(forward_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto bidirectional_iterator<T>::operator*() -> T &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename forward_iterator<T>::_derived>(strange::_common::_shared)->operator*();
}

template<typename T>
inline auto bidirectional_iterator<T>::operator->() -> T *
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename forward_iterator<T>::_derived>(strange::_common::_shared)->operator->();
}

template<typename T>
inline auto bidirectional_iterator<T>::operator==(forward_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_iterator<T>::_derived>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto bidirectional_iterator<T>::operator!=(forward_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_iterator<T>::_derived>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto bidirectional_iterator<T>::operator==(bidirectional_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto bidirectional_iterator<T>::operator!=(bidirectional_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto bidirectional_iterator<T>::operator--() -> bidirectional_iterator &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived>(strange::_common::_shared)->operator--();
    return *this;
}

template<typename T>
inline auto bidirectional_iterator<T>::operator--(int i) -> bidirectional_iterator
{
    auto _result = *this;
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived>(strange::_common::_shared)->operator--(i);
    return _result;
}

template<typename T>
inline auto bidirectional_iterator<T>::operator==(bidirectional_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_iterator<T>::_derived>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto bidirectional_iterator<T>::operator!=(bidirectional_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_iterator<T>::_derived>(strange::_common::_shared)->operator!=(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator*() const -> T const &
{
    return _thing.operator*();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator->() const -> T const *
{
    return _thing.operator->();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator++() -> void
{
    _thing.operator++();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator++(int i) -> void
{
    _thing.operator++(i);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator==(forward_const_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<forward_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator!=(forward_const_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator==(bidirectional_const_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<bidirectional_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator!=(bidirectional_const_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator--() -> void
{
    _thing.operator--();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator--(int i) -> void
{
    _thing.operator--(i);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator==(random_access_const_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<random_access_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator!=(random_access_const_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator<(random_access_const_iterator<T> const & other) const -> bool
{
    return _thing < other.template _static<random_access_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator>(random_access_const_iterator<T> const & other) const -> bool
{
    return _thing > other.template _static<random_access_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator<=(random_access_const_iterator<T> const & other) const -> bool
{
    return _thing <= other.template _static<random_access_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator>=(random_access_const_iterator<T> const & other) const -> bool
{
    return _thing >= other.template _static<random_access_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator+=(std::ptrdiff_t n) -> void
{
    _thing.operator+=(n);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator-=(std::ptrdiff_t n) -> void
{
    _thing.operator-=(n);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator+(std::ptrdiff_t n) const -> random_access_const_iterator<T>
{
    return random_access_const_iterator<T>::template _make<_Thing, _Copy>(_thing + n);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator-(std::ptrdiff_t n) const -> random_access_const_iterator<T>
{
    return random_access_const_iterator<T>::template _make<_Thing, _Copy>(_thing - n);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator-(random_access_const_iterator<T> other) const -> std::ptrdiff_t
{
    return _thing - other.template _static<random_access_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator[](std::ptrdiff_t n) const -> T const &
{
    return _thing.operator[](n);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator*() const -> T const &
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator*();
}

template<typename T>
inline auto random_access_const_iterator<T>::operator->() const -> T const *
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator->();
}

template<typename T>
inline auto random_access_const_iterator<T>::operator++() -> random_access_const_iterator &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator++();
    return *this;
}

template<typename T>
inline auto random_access_const_iterator<T>::operator++(int i) -> random_access_const_iterator
{
    auto _result = *this;
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator++(i);
    return _result;
}

template<typename T>
inline auto random_access_const_iterator<T>::operator==(forward_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator!=(forward_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator==(bidirectional_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator!=(bidirectional_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator--() -> random_access_const_iterator &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived>(strange::_common::_shared)->operator--();
    return *this;
}

template<typename T>
inline auto random_access_const_iterator<T>::operator--(int i) -> random_access_const_iterator
{
    auto _result = *this;
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived>(strange::_common::_shared)->operator--(i);
    return _result;
}

template<typename T>
inline auto random_access_const_iterator<T>::operator==(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator!=(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator<(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator<(other);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator>(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator>(other);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator<=(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator<=(other);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator>=(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator>=(other);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator+=(std::ptrdiff_t n) -> random_access_const_iterator &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator+=(n);
    return *this;
}

template<typename T>
inline auto random_access_const_iterator<T>::operator-=(std::ptrdiff_t n) -> random_access_const_iterator &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator-=(n);
    return *this;
}

template<typename T>
inline auto random_access_const_iterator<T>::operator+(std::ptrdiff_t n) const -> random_access_const_iterator<T>
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator+(n);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator-(std::ptrdiff_t n) const -> random_access_const_iterator<T>
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator-(n);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator-(random_access_const_iterator<T> other) const -> std::ptrdiff_t
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator-(other);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator[](std::ptrdiff_t n) const -> T const &
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator[](n);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator*() const -> T const &
{
    return _thing.operator*();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator->() const -> T const *
{
    return _thing.operator->();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator++() -> void
{
    _thing.operator++();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator++(int i) -> void
{
    _thing.operator++(i);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator==(forward_const_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<forward_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator!=(forward_const_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator*() -> T &
{
    return _thing.operator*();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator->() -> T *
{
    return _thing.operator->();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator==(forward_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<forward_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator!=(forward_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator==(bidirectional_const_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<bidirectional_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator!=(bidirectional_const_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator--() -> void
{
    _thing.operator--();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator--(int i) -> void
{
    _thing.operator--(i);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator==(bidirectional_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<bidirectional_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator!=(bidirectional_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator==(random_access_const_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<random_access_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator!=(random_access_const_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator<(random_access_const_iterator<T> const & other) const -> bool
{
    return _thing < other.template _static<random_access_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator>(random_access_const_iterator<T> const & other) const -> bool
{
    return _thing > other.template _static<random_access_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator<=(random_access_const_iterator<T> const & other) const -> bool
{
    return _thing <= other.template _static<random_access_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator>=(random_access_const_iterator<T> const & other) const -> bool
{
    return _thing >= other.template _static<random_access_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator+=(std::ptrdiff_t n) -> void
{
    _thing.operator+=(n);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator-=(std::ptrdiff_t n) -> void
{
    _thing.operator-=(n);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator+(std::ptrdiff_t n) const -> random_access_const_iterator<T>
{
    return random_access_const_iterator<T>::template _make<_Thing, _Copy>(_thing + n);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator-(std::ptrdiff_t n) const -> random_access_const_iterator<T>
{
    return random_access_const_iterator<T>::template _make<_Thing, _Copy>(_thing - n);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator-(random_access_const_iterator<T> other) const -> std::ptrdiff_t
{
    return _thing - other.template _static<random_access_const_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator[](std::ptrdiff_t n) const -> T const &
{
    return _thing.operator[](n);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator==(random_access_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<random_access_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator!=(random_access_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator<(random_access_iterator<T> const & other) const -> bool
{
    return _thing < other.template _static<random_access_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator>(random_access_iterator<T> const & other) const -> bool
{
    return _thing > other.template _static<random_access_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator<=(random_access_iterator<T> const & other) const -> bool
{
    return _thing <= other.template _static<random_access_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator>=(random_access_iterator<T> const & other) const -> bool
{
    return _thing >= other.template _static<random_access_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator+(std::ptrdiff_t n) -> random_access_iterator<T>
{
    return random_access_iterator<T>::template _make<_Thing, _Copy>(_thing + n);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator-(std::ptrdiff_t n) -> random_access_iterator<T>
{
    return random_access_iterator<T>::template _make<_Thing, _Copy>(_thing - n);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator-(random_access_iterator<T> other) const -> std::ptrdiff_t
{
    return _thing - other.template _static<random_access_iterator_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator[](std::ptrdiff_t n) -> T &
{
    return _thing.operator[](n);
}

template<typename T>
inline auto random_access_iterator<T>::operator*() const -> T const &
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator*();
}

template<typename T>
inline auto random_access_iterator<T>::operator->() const -> T const *
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator->();
}

template<typename T>
inline auto random_access_iterator<T>::operator++() -> random_access_iterator &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator++();
    return *this;
}

template<typename T>
inline auto random_access_iterator<T>::operator++(int i) -> random_access_iterator
{
    auto _result = *this;
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator++(i);
    return _result;
}

template<typename T>
inline auto random_access_iterator<T>::operator==(forward_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator!=(forward_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator*() -> T &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename forward_iterator<T>::_derived>(strange::_common::_shared)->operator*();
}

template<typename T>
inline auto random_access_iterator<T>::operator->() -> T *
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename forward_iterator<T>::_derived>(strange::_common::_shared)->operator->();
}

template<typename T>
inline auto random_access_iterator<T>::operator==(forward_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_iterator<T>::_derived>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator!=(forward_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_iterator<T>::_derived>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator==(bidirectional_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator!=(bidirectional_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator--() -> random_access_iterator &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived>(strange::_common::_shared)->operator--();
    return *this;
}

template<typename T>
inline auto random_access_iterator<T>::operator--(int i) -> random_access_iterator
{
    auto _result = *this;
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived>(strange::_common::_shared)->operator--(i);
    return _result;
}

template<typename T>
inline auto random_access_iterator<T>::operator==(bidirectional_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_iterator<T>::_derived>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator!=(bidirectional_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_iterator<T>::_derived>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator==(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator!=(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator<(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator<(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator>(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator>(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator<=(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator<=(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator>=(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator>=(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator+=(std::ptrdiff_t n) -> random_access_iterator &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator+=(n);
    return *this;
}

template<typename T>
inline auto random_access_iterator<T>::operator-=(std::ptrdiff_t n) -> random_access_iterator &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator-=(n);
    return *this;
}

template<typename T>
inline auto random_access_iterator<T>::operator+(std::ptrdiff_t n) const -> random_access_const_iterator<T>
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator+(n);
}

template<typename T>
inline auto random_access_iterator<T>::operator-(std::ptrdiff_t n) const -> random_access_const_iterator<T>
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator-(n);
}

template<typename T>
inline auto random_access_iterator<T>::operator-(random_access_const_iterator<T> other) const -> std::ptrdiff_t
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator-(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator[](std::ptrdiff_t n) const -> T const &
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived>(strange::_common::_shared)->operator[](n);
}

template<typename T>
inline auto random_access_iterator<T>::operator==(random_access_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_iterator<T>::_derived>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator!=(random_access_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_iterator<T>::_derived>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator<(random_access_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_iterator<T>::_derived>(strange::_common::_shared)->operator<(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator>(random_access_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_iterator<T>::_derived>(strange::_common::_shared)->operator>(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator<=(random_access_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_iterator<T>::_derived>(strange::_common::_shared)->operator<=(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator>=(random_access_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_iterator<T>::_derived>(strange::_common::_shared)->operator>=(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator+(std::ptrdiff_t n) -> random_access_iterator<T>
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename random_access_iterator<T>::_derived>(strange::_common::_shared)->operator+(n);
}

template<typename T>
inline auto random_access_iterator<T>::operator-(std::ptrdiff_t n) -> random_access_iterator<T>
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename random_access_iterator<T>::_derived>(strange::_common::_shared)->operator-(n);
}

template<typename T>
inline auto random_access_iterator<T>::operator-(random_access_iterator<T> other) const -> std::ptrdiff_t
{
    return std::dynamic_pointer_cast<typename random_access_iterator<T>::_derived>(strange::_common::_shared)->operator-(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator[](std::ptrdiff_t n) -> T &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename random_access_iterator<T>::_derived>(strange::_common::_shared)->operator[](n);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::operator=(std::initializer_list<T> ilist) -> void
{
    _thing.operator=(ilist);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::assign(size_t count, T const & value) -> void
{
    _thing.assign(count, value);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::assign(forward_const_iterator<T> first, forward_const_iterator<T> last) -> void
{
    _thing.assign(first, last);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::assign(std::initializer_list<T> ilist) -> void
{
    _thing.assign(ilist);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::at(size_t pos) -> T &
{
    return _thing.at(pos);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::at(size_t pos) const -> T const &
{
    return _thing.at(pos);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::operator[](size_t pos) -> T &
{
    return _thing.operator[](pos);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::operator[](size_t pos) const -> T const &
{
    return _thing.operator[](pos);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::front() -> T &
{
    return _thing.front();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::front() const -> T const &
{
    return _thing.front();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::back() -> T &
{
    return _thing.back();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::back() const -> T const &
{
    return _thing.back();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::data() -> T *
{
    return _thing.data();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::data() const -> T const *
{
    return _thing.data();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::begin() -> typename strange::random_access_iterator<T>
{
    return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.begin());
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::begin() const -> typename strange::random_access_const_iterator<T>
{
    return random_access_const_iterator<T>::template _make<decltype(_thing.cbegin())>(_thing.cbegin());
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::cbegin() const -> typename strange::random_access_const_iterator<T>
{
    return random_access_const_iterator<T>::template _make<decltype(_thing.cbegin())>(_thing.cbegin());
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::end() -> typename strange::random_access_iterator<T>
{
    return random_access_iterator<T>::template _make<decltype(_thing.end())>(_thing.end());
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::end() const -> typename strange::random_access_const_iterator<T>
{
    return random_access_const_iterator<T>::template _make<decltype(_thing.cend())>(_thing.cend());
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::cend() const -> typename strange::random_access_const_iterator<T>
{
    return random_access_const_iterator<T>::template _make<decltype(_thing.cend())>(_thing.cend());
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::rbegin() -> typename std::reverse_iterator<strange::random_access_iterator<T>>
{
    return typename std::reverse_iterator<strange::random_access_iterator<T>>{random_access_iterator<T>::template _make<decltype(_thing.end())>(_thing.end())};
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::rbegin() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>
{
    return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{random_access_const_iterator<T>::template _make<decltype(_thing.cend())>(_thing.cend())};
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::crbegin() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>
{
    return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{random_access_const_iterator<T>::template _make<decltype(_thing.cend())>(_thing.cend())};
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::rend() -> typename std::reverse_iterator<strange::random_access_iterator<T>>
{
    return typename std::reverse_iterator<strange::random_access_iterator<T>>{random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.begin())};
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::rend() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>
{
    return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{random_access_const_iterator<T>::template _make<decltype(_thing.cbegin())>(_thing.cbegin())};
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::crend() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>
{
    return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{random_access_const_iterator<T>::template _make<decltype(_thing.cbegin())>(_thing.cbegin())};
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::empty() const -> bool
{
    return _thing.empty();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::size() const -> size_t
{
    return _thing.size();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::max_size() const -> size_t
{
    return _thing.max_size();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::reserve(size_t new_cap) -> void
{
    _thing.reserve(new_cap);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::capacity() const -> size_t
{
    return _thing.capacity();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::shrink_to_fit() -> void
{
    _thing.shrink_to_fit();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::clear() -> void
{
    _thing.clear();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::insert(typename strange::random_access_const_iterator<T> pos, T const & value) -> typename strange::random_access_iterator<T>
{
    return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), value));
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::insert(typename strange::random_access_const_iterator<T> pos, T && value) -> typename strange::random_access_iterator<T>
{
    return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), std::move(value)));
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::insert(typename strange::random_access_const_iterator<T> pos, size_t count, T const & value) -> typename strange::random_access_iterator<T>
{
    return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), count, value));
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::insert(typename strange::random_access_const_iterator<T> pos, forward_const_iterator<T> first, forward_const_iterator<T> last) -> typename strange::random_access_iterator<T>
{
    return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), first, last));
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::insert(typename strange::random_access_const_iterator<T> pos, std::initializer_list<T> ilist) -> typename strange::random_access_iterator<T>
{
    return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), ilist));
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::erase(typename strange::random_access_const_iterator<T> pos) -> typename strange::random_access_iterator<T>
{
    return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.erase(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing()));
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::erase(typename strange::random_access_const_iterator<T> first, typename strange::random_access_const_iterator<T> last) -> typename strange::random_access_iterator<T>
{
    return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.erase(first.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), last.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing()));
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::push_back(T const & value) -> void
{
    _thing.push_back(value);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::push_back(T && value) -> void
{
    _thing.push_back(std::move(value));
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::pop_back() -> void
{
    _thing.pop_back();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::resize(size_t count) -> void
{
    _thing.resize(count);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::resize(size_t count, T const & value) -> void
{
    _thing.resize(count, value);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::swap(vector<T> & other) -> void
{
    _thing.swap(other.template _static<vector_<T, _Thing, _Copy>>()._thing());
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::operator==(vector<T> const & other) const -> bool
{
    return _thing == other.template _static<vector_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::operator!=(vector<T> const & other) const -> bool
{
    return _thing != other.template _static<vector_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::operator<(vector<T> const & other) const -> bool
{
    return _thing < other.template _static<vector_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::operator>(vector<T> const & other) const -> bool
{
    return _thing > other.template _static<vector_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::operator<=(vector<T> const & other) const -> bool
{
    return _thing <= other.template _static<vector_<T, _Thing, _Copy>>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::operator>=(vector<T> const & other) const -> bool
{
    return _thing >= other.template _static<vector_<T, _Thing, _Copy>>()._thing();
}

template<typename T>
inline auto vector<T>::operator=(std::initializer_list<T> ilist) -> vector &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->operator=(ilist);
    return *this;
}

template<typename T>
inline auto vector<T>::assign(size_t count, T const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->assign(count, value);
}

template<typename T>
inline auto vector<T>::assign(forward_const_iterator<T> first, forward_const_iterator<T> last) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->assign(first, last);
}

template<typename T>
inline auto vector<T>::assign(std::initializer_list<T> ilist) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->assign(ilist);
}

template<typename T>
inline auto vector<T>::at(size_t pos) -> T &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->at(pos);
}

template<typename T>
inline auto vector<T>::at(size_t pos) const -> T const &
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->at(pos);
}

template<typename T>
inline auto vector<T>::operator[](size_t pos) -> T &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->operator[](pos);
}

template<typename T>
inline auto vector<T>::operator[](size_t pos) const -> T const &
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->operator[](pos);
}

template<typename T>
inline auto vector<T>::front() -> T &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->front();
}

template<typename T>
inline auto vector<T>::front() const -> T const &
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->front();
}

template<typename T>
inline auto vector<T>::back() -> T &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->back();
}

template<typename T>
inline auto vector<T>::back() const -> T const &
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->back();
}

template<typename T>
inline auto vector<T>::data() -> T *
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->data();
}

template<typename T>
inline auto vector<T>::data() const -> T const *
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->data();
}

template<typename T>
inline auto vector<T>::begin() -> typename strange::random_access_iterator<T>
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->begin();
}

template<typename T>
inline auto vector<T>::begin() const -> typename strange::random_access_const_iterator<T>
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->begin();
}

template<typename T>
inline auto vector<T>::cbegin() const -> typename strange::random_access_const_iterator<T>
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->cbegin();
}

template<typename T>
inline auto vector<T>::end() -> typename strange::random_access_iterator<T>
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->end();
}

template<typename T>
inline auto vector<T>::end() const -> typename strange::random_access_const_iterator<T>
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->end();
}

template<typename T>
inline auto vector<T>::cend() const -> typename strange::random_access_const_iterator<T>
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->cend();
}

template<typename T>
inline auto vector<T>::rbegin() -> typename std::reverse_iterator<strange::random_access_iterator<T>>
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->rbegin();
}

template<typename T>
inline auto vector<T>::rbegin() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->rbegin();
}

template<typename T>
inline auto vector<T>::crbegin() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->crbegin();
}

template<typename T>
inline auto vector<T>::rend() -> typename std::reverse_iterator<strange::random_access_iterator<T>>
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->rend();
}

template<typename T>
inline auto vector<T>::rend() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->rend();
}

template<typename T>
inline auto vector<T>::crend() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->crend();
}

template<typename T>
inline auto vector<T>::empty() const -> bool
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->empty();
}

template<typename T>
inline auto vector<T>::size() const -> size_t
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->size();
}

template<typename T>
inline auto vector<T>::max_size() const -> size_t
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->max_size();
}

template<typename T>
inline auto vector<T>::reserve(size_t new_cap) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->reserve(new_cap);
}

template<typename T>
inline auto vector<T>::capacity() const -> size_t
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->capacity();
}

template<typename T>
inline auto vector<T>::shrink_to_fit() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->shrink_to_fit();
}

template<typename T>
inline auto vector<T>::clear() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->clear();
}

template<typename T>
inline auto vector<T>::insert(typename strange::random_access_const_iterator<T> pos, T const & value) -> typename strange::random_access_iterator<T>
{
    auto const index = pos - cbegin();
    strange::_common::_mutate(); // could invalidate iterators
    pos = cbegin() + index;
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, value);
}

template<typename T>
inline auto vector<T>::insert(typename strange::random_access_const_iterator<T> pos, T && value) -> typename strange::random_access_iterator<T>
{
    auto const index = pos - cbegin();
    strange::_common::_mutate(); // could invalidate iterators
    pos = cbegin() + index;
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, std::move(value));
}

template<typename T>
inline auto vector<T>::insert(typename strange::random_access_const_iterator<T> pos, size_t count, T const & value) -> typename strange::random_access_iterator<T>
{
    auto const index = pos - cbegin();
    strange::_common::_mutate(); // could invalidate iterators
    pos = cbegin() + index;
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, count, value);
}

template<typename T>
inline auto vector<T>::insert(typename strange::random_access_const_iterator<T> pos, forward_const_iterator<T> first, forward_const_iterator<T> last) -> typename strange::random_access_iterator<T>
{
    auto const index = pos - cbegin();
    strange::_common::_mutate(); // could invalidate iterators
    pos = cbegin() + index;
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, first, last);
}

template<typename T>
inline auto vector<T>::insert(typename strange::random_access_const_iterator<T> pos, std::initializer_list<T> ilist) -> typename strange::random_access_iterator<T>
{
    auto const index = pos - cbegin();
    strange::_common::_mutate(); // could invalidate iterators
    pos = cbegin() + index;
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, ilist);
}

template<typename T>
inline auto vector<T>::erase(typename strange::random_access_const_iterator<T> pos) -> typename strange::random_access_iterator<T>
{
    auto const index = pos - cbegin();
    strange::_common::_mutate(); // could invalidate iterators
    pos = cbegin() + index;
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->erase(pos);
}

template<typename T>
inline auto vector<T>::erase(typename strange::random_access_const_iterator<T> first, typename strange::random_access_const_iterator<T> last) -> typename strange::random_access_iterator<T>
{
    auto const first_index = first - cbegin();
    auto const last_index = last - cbegin();
    strange::_common::_mutate(); // could invalidate iterators
    first = cbegin() + first_index;
    last = cbegin() + last_index;
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->erase(first, last);
}

template<typename T>
inline auto vector<T>::push_back(T const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->push_back(value);
}

template<typename T>
inline auto vector<T>::push_back(T && value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->push_back(std::move(value));
}

template<typename T>
inline auto vector<T>::pop_back() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->pop_back();
}

template<typename T>
inline auto vector<T>::resize(size_t count) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->resize(count);
}

template<typename T>
inline auto vector<T>::resize(size_t count, T const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->resize(count, value);
}

template<typename T>
inline auto vector<T>::swap(vector<T> & other) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->swap(other);
}

template<typename T>
inline auto vector<T>::operator==(vector<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto vector<T>::operator!=(vector<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto vector<T>::operator<(vector<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->operator<(other);
}

template<typename T>
inline auto vector<T>::operator>(vector<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->operator>(other);
}

template<typename T>
inline auto vector<T>::operator<=(vector<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->operator<=(other);
}

template<typename T>
inline auto vector<T>::operator>=(vector<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->operator>=(other);
}

}

