#pragma once
#include "../common/strange__common.h"
#include "../reflection/strange__reflection.h"
#include <vector>
namespace strange
{
namespace comprehension
{
enum class cls;
}
namespace implementation
{
struct baggage;

template <typename Signal>
struct graph;
}
}
#include <memory>
#include <string>
#include <type_traits>
#include <unordered_set>

namespace strange
{

struct any;

template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct any_;

struct stuff;

template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct stuff_;

struct bag;

template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct bag_;

struct package;

template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct package_;

struct baggage;

template<typename _Thing = strange::implementation::baggage, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct baggage_;

template<typename Signal>
struct processor;

template<typename Signal, typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct processor_;

struct connection;

}

namespace strange
{
namespace implementation
{
struct connection;
}
}

namespace strange
{

template<typename _Thing = strange::implementation::connection, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct connection_;

template<typename Signal>
struct graph;

template<typename Signal, typename _Thing = strange::implementation::graph<Signal>, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct graph_;

struct parameter;

}

namespace strange
{
namespace implementation
{
struct parameter;
}
}

namespace strange
{

template<typename _Thing = strange::implementation::parameter, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct parameter_;

struct operation;

}

namespace strange
{
namespace implementation
{
struct operation;
}
}

namespace strange
{

template<typename _Thing = strange::implementation::operation, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct operation_;

struct abstraction;

}

namespace strange
{
namespace implementation
{
struct abstraction;
}
}

namespace strange
{

template<typename _Thing = strange::implementation::abstraction, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct abstraction_;

struct space;

}

namespace strange
{
namespace implementation
{
struct space;
}
}

namespace strange
{

template<typename _Thing = strange::implementation::space, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct space_;

struct token;

}

namespace strange
{
namespace implementation
{
struct token;
}
}

namespace strange
{

template<typename _Thing = strange::implementation::token, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct token_;

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
    static inline auto name() -> std::string
    {
        return "strange::any";
    }
};

template<typename _Thing, bool _Copy>
struct reflection<strange::any_<_Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "strange::any_<" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<>
struct reflection<strange::stuff>
{
    static inline auto name() -> std::string
    {
        return "strange::stuff";
    }
};

template<typename _Thing, bool _Copy>
struct reflection<strange::stuff_<_Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "strange::stuff_<" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<>
struct reflection<strange::bag>
{
    static inline auto name() -> std::string
    {
        return "strange::bag";
    }
};

template<typename _Thing, bool _Copy>
struct reflection<strange::bag_<_Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "strange::bag_<" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<>
struct reflection<strange::package>
{
    static inline auto name() -> std::string
    {
        return "strange::package";
    }
};

template<typename _Thing, bool _Copy>
struct reflection<strange::package_<_Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "strange::package_<" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<>
struct reflection<strange::baggage>
{
    static inline auto name() -> std::string
    {
        return "strange::baggage";
    }
};

template<typename _Thing, bool _Copy>
struct reflection<strange::baggage_<_Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "strange::baggage_<" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<typename Signal>
struct reflection<strange::processor<Signal>>
{
    static inline auto name() -> std::string
    {
        return "strange::processor<" + reflection<Signal>::name() + ">";
    }
};

template<typename Signal, typename _Thing, bool _Copy>
struct reflection<strange::processor_<Signal, _Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "strange::processor_<" + reflection<Signal>::name() + ", " + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<>
struct reflection<strange::connection>
{
    static inline auto name() -> std::string
    {
        return "strange::connection";
    }
};

template<typename _Thing, bool _Copy>
struct reflection<strange::connection_<_Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "strange::connection_<" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<>
struct reflection<strange::implementation::connection>
{
    static inline auto name() -> std::string
    {
        return "strange::implementation::connection";
    }
};

template<typename Signal>
struct reflection<strange::graph<Signal>>
{
    static inline auto name() -> std::string
    {
        return "strange::graph<" + reflection<Signal>::name() + ">";
    }
};

template<typename Signal, typename _Thing, bool _Copy>
struct reflection<strange::graph_<Signal, _Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "strange::graph_<" + reflection<Signal>::name() + ", " + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<>
struct reflection<strange::parameter>
{
    static inline auto name() -> std::string
    {
        return "strange::parameter";
    }
};

template<typename _Thing, bool _Copy>
struct reflection<strange::parameter_<_Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "strange::parameter_<" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<>
struct reflection<strange::implementation::parameter>
{
    static inline auto name() -> std::string
    {
        return "strange::implementation::parameter";
    }
};

template<>
struct reflection<strange::operation>
{
    static inline auto name() -> std::string
    {
        return "strange::operation";
    }
};

template<typename _Thing, bool _Copy>
struct reflection<strange::operation_<_Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "strange::operation_<" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<>
struct reflection<strange::implementation::operation>
{
    static inline auto name() -> std::string
    {
        return "strange::implementation::operation";
    }
};

template<>
struct reflection<strange::abstraction>
{
    static inline auto name() -> std::string
    {
        return "strange::abstraction";
    }
};

template<typename _Thing, bool _Copy>
struct reflection<strange::abstraction_<_Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "strange::abstraction_<" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<>
struct reflection<strange::implementation::abstraction>
{
    static inline auto name() -> std::string
    {
        return "strange::implementation::abstraction";
    }
};

template<>
struct reflection<strange::space>
{
    static inline auto name() -> std::string
    {
        return "strange::space";
    }
};

template<typename _Thing, bool _Copy>
struct reflection<strange::space_<_Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "strange::space_<" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<>
struct reflection<strange::implementation::space>
{
    static inline auto name() -> std::string
    {
        return "strange::implementation::space";
    }
};

template<>
struct reflection<strange::token>
{
    static inline auto name() -> std::string
    {
        return "strange::token";
    }
};

template<typename _Thing, bool _Copy>
struct reflection<strange::token_<_Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "strange::token_<" + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<>
struct reflection<strange::implementation::token>
{
    static inline auto name() -> std::string
    {
        return "strange::implementation::token";
    }
};

template<typename T>
struct reflection<strange::forward_const_iterator<T>>
{
    static inline auto name() -> std::string
    {
        return "strange::forward_const_iterator<" + reflection<T>::name() + ">";
    }
};

template<typename T, typename _Thing, bool _Copy>
struct reflection<strange::forward_const_iterator_<T, _Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "strange::forward_const_iterator_<" + reflection<T>::name() + ", " + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<typename T>
struct reflection<strange::forward_iterator<T>>
{
    static inline auto name() -> std::string
    {
        return "strange::forward_iterator<" + reflection<T>::name() + ">";
    }
};

template<typename T, typename _Thing, bool _Copy>
struct reflection<strange::forward_iterator_<T, _Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "strange::forward_iterator_<" + reflection<T>::name() + ", " + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<typename T>
struct reflection<strange::bidirectional_const_iterator<T>>
{
    static inline auto name() -> std::string
    {
        return "strange::bidirectional_const_iterator<" + reflection<T>::name() + ">";
    }
};

template<typename T, typename _Thing, bool _Copy>
struct reflection<strange::bidirectional_const_iterator_<T, _Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "strange::bidirectional_const_iterator_<" + reflection<T>::name() + ", " + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<typename T>
struct reflection<strange::bidirectional_iterator<T>>
{
    static inline auto name() -> std::string
    {
        return "strange::bidirectional_iterator<" + reflection<T>::name() + ">";
    }
};

template<typename T, typename _Thing, bool _Copy>
struct reflection<strange::bidirectional_iterator_<T, _Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "strange::bidirectional_iterator_<" + reflection<T>::name() + ", " + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<typename T>
struct reflection<strange::random_access_const_iterator<T>>
{
    static inline auto name() -> std::string
    {
        return "strange::random_access_const_iterator<" + reflection<T>::name() + ">";
    }
};

template<typename T, typename _Thing, bool _Copy>
struct reflection<strange::random_access_const_iterator_<T, _Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "strange::random_access_const_iterator_<" + reflection<T>::name() + ", " + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<typename T>
struct reflection<strange::random_access_iterator<T>>
{
    static inline auto name() -> std::string
    {
        return "strange::random_access_iterator<" + reflection<T>::name() + ">";
    }
};

template<typename T, typename _Thing, bool _Copy>
struct reflection<strange::random_access_iterator_<T, _Thing, _Copy>>
{
    static inline auto name() -> std::string
    {
        return "strange::random_access_iterator_<" + reflection<T>::name() + ", " + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<typename T>
struct reflection<strange::vector<T>>
{
    static inline auto name() -> std::string
    {
        return "strange::vector<" + reflection<T>::name() + ">";
    }
};

template<typename T, typename _Thing, bool _Copy>
struct reflection<strange::vector_<T, _Thing, _Copy>>
{
    static inline auto name() -> std::string
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
        return std::dynamic_pointer_cast<typename any::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> any
    {
        try
        {
            return any{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return any{};
        }
    }

    inline auto _reproduce() const -> any
    {
        try
        {
            return any{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return any{};
        }
    }

    inline auto _weak() const -> any
    {
        return any{strange::_common::_weak_base()};
    }

    inline auto _strong() const -> any
    {
        return any{strange::_common::_shared->_strong()};
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> any
    {
        return any{any::_derived::_static_shared_to_base(std::make_shared<typename any_<_Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> any
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return any{};
        }
        return any{it->second()};
    }

    using _Abstraction_ = any;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
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
                throw strange::_common::_no_copy{};
            }
        }

        inline auto _reproduce() const -> std::shared_ptr<strange::_common::_base> final
        {
            if constexpr (std::is_default_constructible_v<_Thing>)
            {
                return any_::_derived::_static_shared_to_base(std::make_shared<any_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
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

        inline auto _copy() const -> bool final
        {
            return any_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return any_::_name_;
        }

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    static inline auto _make_(_Args && ... _args) -> any_
    {
        return any_{any_::_derived::_static_shared_to_base(std::make_shared<any_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> any_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return any_{};
        }
        return any_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<any_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> any_
    {
        try
        {
            return any_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return any_{};
        }
    }

    inline auto _reproduce_() const -> any_
    {
        try
        {
            return any_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return any_{};
        }
    }

    inline auto _weak_() const -> any_
    {
        return any_{strange::_common::_weak_base()};
    }

    inline auto _strong_() const -> any_
    {
        return any_{strange::_common::_shared->_strong()};
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<any_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<any_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = any_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return any_::_derived::_static_shared_to_base(std::make_shared<any_::_instance>());
            });
        }
        return name;
    }();
};

struct stuff : any
{
    inline stuff() = default;

    inline stuff(stuff const & other)
    :strange::_common{other}
    ,any{}
    {
    }

    inline stuff(stuff && other)
    :strange::_common{std::move(other)}
    ,any{}
    {
    }

    inline auto operator=(stuff const & other) -> stuff &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(stuff && other) -> stuff &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline stuff(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,any{}
    {
    }

    explicit inline stuff(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,any{}
    {
    }

protected:
    struct _derived : any::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename stuff::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return any::_derived::_static_shared_to_base(derived);
        }

        virtual auto pack(strange::bag & dest) const -> void = 0;

        virtual auto unpack(strange::bag const & src) -> void = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename stuff::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> stuff
    {
        try
        {
            return stuff{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return stuff{};
        }
    }

    inline auto _reproduce() const -> stuff
    {
        try
        {
            return stuff{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return stuff{};
        }
    }

    inline auto _weak() const -> stuff
    {
        return stuff{strange::_common::_weak_base()};
    }

    inline auto _strong() const -> stuff
    {
        return stuff{strange::_common::_shared->_strong()};
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> stuff
    {
        return stuff{stuff::_derived::_static_shared_to_base(std::make_shared<typename stuff_<_Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> stuff
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return stuff{};
        }
        return stuff{it->second()};
    }

    using _Abstraction_ = stuff;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(any::_cats_.cbegin(), any::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();

    inline auto pack(strange::bag & dest) const -> void;

    inline auto unpack(strange::bag const & src) -> void;
};

template<typename _Thing, bool _Copy>
struct stuff_ : stuff
{
    inline stuff_() = default;

    inline stuff_(stuff_ const & other)
    :strange::_common{other}
    ,stuff{}
    {
    }

    inline stuff_(stuff_ && other)
    :strange::_common{std::move(other)}
    ,stuff{}
    {
    }

    inline auto operator=(stuff_ const & other) -> stuff_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(stuff_ && other) -> stuff_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline stuff_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,stuff{}
    {
    }

    explicit inline stuff_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,stuff{}
    {
    }

private:
    friend struct stuff;

    struct _instance final : stuff::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :stuff_::_derived{}
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
                return stuff_::_derived::_static_shared_to_base(std::make_shared<stuff_::_instance>(_thing));
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
                return stuff_::_derived::_static_shared_to_base(std::make_shared<stuff_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return stuff::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return stuff::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return stuff_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return stuff_::_name_;
        }

        inline auto pack(strange::bag & dest) const -> void final;

        inline auto unpack(strange::bag const & src) -> void final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    static inline auto _make_(_Args && ... _args) -> stuff_
    {
        return stuff_{stuff_::_derived::_static_shared_to_base(std::make_shared<stuff_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> stuff_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return stuff_{};
        }
        return stuff_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<stuff_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> stuff_
    {
        try
        {
            return stuff_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return stuff_{};
        }
    }

    inline auto _reproduce_() const -> stuff_
    {
        try
        {
            return stuff_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return stuff_{};
        }
    }

    inline auto _weak_() const -> stuff_
    {
        return stuff_{strange::_common::_weak_base()};
    }

    inline auto _strong_() const -> stuff_
    {
        return stuff_{strange::_common::_shared->_strong()};
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<stuff_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<stuff_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = stuff_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return stuff_::_derived::_static_shared_to_base(std::make_shared<stuff_::_instance>());
            });
        }
        return name;
    }();
};

struct bag : stuff
{
    inline bag() = default;

    inline bag(bag const & other)
    :strange::_common{other}
    ,stuff{}
    {
    }

    inline bag(bag && other)
    :strange::_common{std::move(other)}
    ,stuff{}
    {
    }

    inline auto operator=(bag const & other) -> bag &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(bag && other) -> bag &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline bag(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,stuff{}
    {
    }

    explicit inline bag(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,stuff{}
    {
    }

protected:
    struct _derived : stuff::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename bag::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return stuff::_derived::_static_shared_to_base(derived);
        }

        virtual auto is_null() const -> bool = 0;

        virtual auto from_null() -> void = 0;

        virtual auto make_null() const -> bag = 0;

        virtual auto is_bool() const -> bool = 0;

        virtual auto as_bool(bool & dest) const -> void = 0;

        virtual auto to_bool() const -> bool = 0;

        virtual auto from_bool() -> void = 0;

        virtual auto from_bool(bool src) -> void = 0;

        virtual auto make_bool() const -> bag = 0;

        virtual auto make_bool(bool src) const -> bag = 0;

        virtual auto is_int64() const -> bool = 0;

        virtual auto as_int64(int64_t & dest) const -> void = 0;

        virtual auto to_int64() const -> int64_t = 0;

        virtual auto from_int64() -> void = 0;

        virtual auto from_int64(int64_t src) -> void = 0;

        virtual auto make_int64() const -> bag = 0;

        virtual auto make_int64(int64_t src) const -> bag = 0;

        virtual auto is_uint64() const -> bool = 0;

        virtual auto as_uint64(uint64_t & dest) const -> void = 0;

        virtual auto to_uint64() const -> uint64_t = 0;

        virtual auto from_uint64() -> void = 0;

        virtual auto from_uint64(uint64_t src) -> void = 0;

        virtual auto make_uint64() const -> bag = 0;

        virtual auto make_uint64(uint64_t src) const -> bag = 0;

        virtual auto is_double() const -> bool = 0;

        virtual auto as_double(double & dest) const -> void = 0;

        virtual auto to_double() const -> double = 0;

        virtual auto from_double() -> void = 0;

        virtual auto from_double(double src) -> void = 0;

        virtual auto make_double() const -> bag = 0;

        virtual auto make_double(double src) const -> bag = 0;

        virtual auto is_string() const -> bool = 0;

        virtual auto as_string(std::string & dest) const -> void = 0;

        virtual auto to_string() const -> std::string = 0;

        virtual auto from_string() -> void = 0;

        virtual auto from_string(std::string const & src) -> void = 0;

        virtual auto make_string() const -> bag = 0;

        virtual auto make_string(std::string const & src) const -> bag = 0;

        virtual auto is_array() const -> bool = 0;

        virtual auto as_array(std::vector<bag> & dest) const -> void = 0;

        virtual auto to_array() const -> std::vector<bag> = 0;

        virtual auto from_array() -> void = 0;

        virtual auto from_array(std::vector<bag> const & src) -> void = 0;

        virtual auto make_array() const -> bag = 0;

        virtual auto make_array(std::vector<bag> const & src) const -> bag = 0;

        virtual auto get_array(std::size_t index) const -> bag = 0;

        virtual auto set_array(std::size_t index, bag const & value) -> void = 0;

        virtual auto front_array() const -> bag = 0;

        virtual auto back_array() const -> bag = 0;

        virtual auto empty_array() const -> bool = 0;

        virtual auto size_array() const -> std::size_t = 0;

        virtual auto reserve_array(std::size_t new_cap) -> void = 0;

        virtual auto capacity_array() const -> std::size_t = 0;

        virtual auto clear_array() -> void = 0;

        virtual auto insert_array(std::size_t pos, bag const & value) -> void = 0;

        virtual auto erase_array(std::size_t pos) -> void = 0;

        virtual auto push_front_array(bag const & value) -> void = 0;

        virtual auto push_back_array(bag const & value) -> void = 0;

        virtual auto pop_front_array() -> bag = 0;

        virtual auto pop_back_array() -> bag = 0;

        virtual auto resize_array(std::size_t count) -> void = 0;

        virtual auto as_array_bool(std::vector<bool> & dest) const -> void = 0;

        virtual auto as_array_int64(std::vector<int64_t> & dest) const -> void = 0;

        virtual auto as_array_uint64(std::vector<uint64_t> & dest) const -> void = 0;

        virtual auto as_array_double(std::vector<double> & dest) const -> void = 0;

        virtual auto as_array_string(std::vector<std::string> & dest) const -> void = 0;

        virtual auto as_array_any(std::vector<strange::any> & dest) const -> void = 0;

        virtual auto to_array_bool() const -> std::vector<bool> = 0;

        virtual auto to_array_int64() const -> std::vector<int64_t> = 0;

        virtual auto to_array_uint64() const -> std::vector<uint64_t> = 0;

        virtual auto to_array_double() const -> std::vector<double> = 0;

        virtual auto to_array_string() const -> std::vector<std::string> = 0;

        virtual auto to_array_any() const -> std::vector<strange::any> = 0;

        virtual auto from_array_bool(std::vector<bool> const & src) -> void = 0;

        virtual auto from_array_int64(std::vector<int64_t> const & src) -> void = 0;

        virtual auto from_array_uint64(std::vector<uint64_t> const & src) -> void = 0;

        virtual auto from_array_double(std::vector<double> const & src) -> void = 0;

        virtual auto from_array_string(std::vector<std::string> const & src) -> void = 0;

        virtual auto from_array_any(std::vector<strange::any> const & src) -> void = 0;

        virtual auto make_array_bool(std::vector<bool> const & src) const -> bag = 0;

        virtual auto make_array_int64(std::vector<int64_t> const & src) const -> bag = 0;

        virtual auto make_array_uint64(std::vector<uint64_t> const & src) const -> bag = 0;

        virtual auto make_array_double(std::vector<double> const & src) const -> bag = 0;

        virtual auto make_array_string(std::vector<std::string> const & src) const -> bag = 0;

        virtual auto make_array_any(std::vector<strange::any> const & src) const -> bag = 0;

        virtual auto is_object() const -> bool = 0;

        virtual auto as_object(std::unordered_map<std::string, bag> & dest) const -> void = 0;

        virtual auto to_object() const -> std::unordered_map<std::string, bag> = 0;

        virtual auto from_object() -> void = 0;

        virtual auto from_object(std::unordered_map<std::string, bag> const & src) -> void = 0;

        virtual auto make_object() const -> bag = 0;

        virtual auto make_object(std::unordered_map<std::string, bag> const & src) const -> bag = 0;

        virtual auto empty_object() const -> bool = 0;

        virtual auto size_object() const -> std::size_t = 0;

        virtual auto clear_object() -> void = 0;

        virtual auto insert_object(std::string const & key, bag const & value) -> void = 0;

        virtual auto erase_object(std::string const & key) -> void = 0;

        virtual auto get_object(std::string const & key) const -> bag = 0;

        virtual auto set_object(std::string const & key, bag const & value) -> void = 0;

        virtual auto contains_object(std::string const & key) const -> bool = 0;

        virtual auto is_any() const -> bool = 0;

        virtual auto as_any(strange::any & dest) const -> void = 0;

        virtual auto to_any() const -> strange::any = 0;

        virtual auto from_any() -> void = 0;

        virtual auto from_any(strange::any const & src) -> void = 0;

        virtual auto make_any() const -> bag = 0;

        virtual auto make_any(strange::any const & src) const -> bag = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> bag
    {
        try
        {
            return bag{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return bag{};
        }
    }

    inline auto _reproduce() const -> bag
    {
        try
        {
            return bag{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return bag{};
        }
    }

    inline auto _weak() const -> bag
    {
        return bag{strange::_common::_weak_base()};
    }

    inline auto _strong() const -> bag
    {
        return bag{strange::_common::_shared->_strong()};
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> bag
    {
        return bag{bag::_derived::_static_shared_to_base(std::make_shared<typename bag_<_Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> bag
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return bag{};
        }
        return bag{it->second()};
    }

    using _Abstraction_ = bag;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(stuff::_cats_.cbegin(), stuff::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();

    inline auto pack(strange::bag & dest) const -> void;

    inline auto unpack(strange::bag const & src) -> void;

    inline auto is_null() const -> bool;

    inline auto from_null() -> void;

    inline auto make_null() const -> bag;

    inline auto is_bool() const -> bool;

    inline auto as_bool(bool & dest) const -> void;

    inline auto to_bool() const -> bool;

    inline auto from_bool() -> void;

    inline auto from_bool(bool src) -> void;

    inline auto make_bool() const -> bag;

    inline auto make_bool(bool src) const -> bag;

    inline auto is_int64() const -> bool;

    inline auto as_int64(int64_t & dest) const -> void;

    inline auto to_int64() const -> int64_t;

    inline auto from_int64() -> void;

    inline auto from_int64(int64_t src) -> void;

    inline auto make_int64() const -> bag;

    inline auto make_int64(int64_t src) const -> bag;

    inline auto is_uint64() const -> bool;

    inline auto as_uint64(uint64_t & dest) const -> void;

    inline auto to_uint64() const -> uint64_t;

    inline auto from_uint64() -> void;

    inline auto from_uint64(uint64_t src) -> void;

    inline auto make_uint64() const -> bag;

    inline auto make_uint64(uint64_t src) const -> bag;

    inline auto is_double() const -> bool;

    inline auto as_double(double & dest) const -> void;

    inline auto to_double() const -> double;

    inline auto from_double() -> void;

    inline auto from_double(double src) -> void;

    inline auto make_double() const -> bag;

    inline auto make_double(double src) const -> bag;

    inline auto is_string() const -> bool;

    inline auto as_string(std::string & dest) const -> void;

    inline auto to_string() const -> std::string;

    inline auto from_string() -> void;

    inline auto from_string(std::string const & src) -> void;

    inline auto make_string() const -> bag;

    inline auto make_string(std::string const & src) const -> bag;

    inline auto is_array() const -> bool;

    inline auto as_array(std::vector<bag> & dest) const -> void;

    inline auto to_array() const -> std::vector<bag>;

    inline auto from_array() -> void;

    inline auto from_array(std::vector<bag> const & src) -> void;

    inline auto make_array() const -> bag;

    inline auto make_array(std::vector<bag> const & src) const -> bag;

    inline auto get_array(std::size_t index) const -> bag;

    inline auto set_array(std::size_t index, bag const & value) -> void;

    inline auto front_array() const -> bag;

    inline auto back_array() const -> bag;

    inline auto empty_array() const -> bool;

    inline auto size_array() const -> std::size_t;

    inline auto reserve_array(std::size_t new_cap) -> void;

    inline auto capacity_array() const -> std::size_t;

    inline auto clear_array() -> void;

    inline auto insert_array(std::size_t pos, bag const & value) -> void;

    inline auto erase_array(std::size_t pos) -> void;

    inline auto push_front_array(bag const & value) -> void;

    inline auto push_back_array(bag const & value) -> void;

    inline auto pop_front_array() -> bag;

    inline auto pop_back_array() -> bag;

    inline auto resize_array(std::size_t count) -> void;

    inline auto as_array_bool(std::vector<bool> & dest) const -> void;

    inline auto as_array_int64(std::vector<int64_t> & dest) const -> void;

    inline auto as_array_uint64(std::vector<uint64_t> & dest) const -> void;

    inline auto as_array_double(std::vector<double> & dest) const -> void;

    inline auto as_array_string(std::vector<std::string> & dest) const -> void;

    inline auto as_array_any(std::vector<strange::any> & dest) const -> void;

    inline auto to_array_bool() const -> std::vector<bool>;

    inline auto to_array_int64() const -> std::vector<int64_t>;

    inline auto to_array_uint64() const -> std::vector<uint64_t>;

    inline auto to_array_double() const -> std::vector<double>;

    inline auto to_array_string() const -> std::vector<std::string>;

    inline auto to_array_any() const -> std::vector<strange::any>;

    inline auto from_array_bool(std::vector<bool> const & src) -> void;

    inline auto from_array_int64(std::vector<int64_t> const & src) -> void;

    inline auto from_array_uint64(std::vector<uint64_t> const & src) -> void;

    inline auto from_array_double(std::vector<double> const & src) -> void;

    inline auto from_array_string(std::vector<std::string> const & src) -> void;

    inline auto from_array_any(std::vector<strange::any> const & src) -> void;

    inline auto make_array_bool(std::vector<bool> const & src) const -> bag;

    inline auto make_array_int64(std::vector<int64_t> const & src) const -> bag;

    inline auto make_array_uint64(std::vector<uint64_t> const & src) const -> bag;

    inline auto make_array_double(std::vector<double> const & src) const -> bag;

    inline auto make_array_string(std::vector<std::string> const & src) const -> bag;

    inline auto make_array_any(std::vector<strange::any> const & src) const -> bag;

    inline auto is_object() const -> bool;

    inline auto as_object(std::unordered_map<std::string, bag> & dest) const -> void;

    inline auto to_object() const -> std::unordered_map<std::string, bag>;

    inline auto from_object() -> void;

    inline auto from_object(std::unordered_map<std::string, bag> const & src) -> void;

    inline auto make_object() const -> bag;

    inline auto make_object(std::unordered_map<std::string, bag> const & src) const -> bag;

    inline auto empty_object() const -> bool;

    inline auto size_object() const -> std::size_t;

    inline auto clear_object() -> void;

    inline auto insert_object(std::string const & key, bag const & value) -> void;

    inline auto erase_object(std::string const & key) -> void;

    inline auto get_object(std::string const & key) const -> bag;

    inline auto set_object(std::string const & key, bag const & value) -> void;

    inline auto contains_object(std::string const & key) const -> bool;

    inline auto is_any() const -> bool;

    inline auto as_any(strange::any & dest) const -> void;

    inline auto to_any() const -> strange::any;

    inline auto from_any() -> void;

    inline auto from_any(strange::any const & src) -> void;

    inline auto make_any() const -> bag;

    inline auto make_any(strange::any const & src) const -> bag;
};

template<typename _Thing, bool _Copy>
struct bag_ : bag
{
    inline bag_() = default;

    inline bag_(bag_ const & other)
    :strange::_common{other}
    ,bag{}
    {
    }

    inline bag_(bag_ && other)
    :strange::_common{std::move(other)}
    ,bag{}
    {
    }

    inline auto operator=(bag_ const & other) -> bag_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(bag_ && other) -> bag_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline bag_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,bag{}
    {
    }

    explicit inline bag_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,bag{}
    {
    }

private:
    friend struct bag;

    struct _instance final : bag::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :bag_::_derived{}
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
                return bag_::_derived::_static_shared_to_base(std::make_shared<bag_::_instance>(_thing));
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
                return bag_::_derived::_static_shared_to_base(std::make_shared<bag_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return bag::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return bag::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return bag_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return bag_::_name_;
        }

        inline auto pack(strange::bag & dest) const -> void final;

        inline auto unpack(strange::bag const & src) -> void final;

        inline auto is_null() const -> bool final;

        inline auto from_null() -> void final;

        inline auto make_null() const -> bag final;

        inline auto is_bool() const -> bool final;

        inline auto as_bool(bool & dest) const -> void final;

        inline auto to_bool() const -> bool final;

        inline auto from_bool() -> void final;

        inline auto from_bool(bool src) -> void final;

        inline auto make_bool() const -> bag final;

        inline auto make_bool(bool src) const -> bag final;

        inline auto is_int64() const -> bool final;

        inline auto as_int64(int64_t & dest) const -> void final;

        inline auto to_int64() const -> int64_t final;

        inline auto from_int64() -> void final;

        inline auto from_int64(int64_t src) -> void final;

        inline auto make_int64() const -> bag final;

        inline auto make_int64(int64_t src) const -> bag final;

        inline auto is_uint64() const -> bool final;

        inline auto as_uint64(uint64_t & dest) const -> void final;

        inline auto to_uint64() const -> uint64_t final;

        inline auto from_uint64() -> void final;

        inline auto from_uint64(uint64_t src) -> void final;

        inline auto make_uint64() const -> bag final;

        inline auto make_uint64(uint64_t src) const -> bag final;

        inline auto is_double() const -> bool final;

        inline auto as_double(double & dest) const -> void final;

        inline auto to_double() const -> double final;

        inline auto from_double() -> void final;

        inline auto from_double(double src) -> void final;

        inline auto make_double() const -> bag final;

        inline auto make_double(double src) const -> bag final;

        inline auto is_string() const -> bool final;

        inline auto as_string(std::string & dest) const -> void final;

        inline auto to_string() const -> std::string final;

        inline auto from_string() -> void final;

        inline auto from_string(std::string const & src) -> void final;

        inline auto make_string() const -> bag final;

        inline auto make_string(std::string const & src) const -> bag final;

        inline auto is_array() const -> bool final;

        inline auto as_array(std::vector<bag> & dest) const -> void final;

        inline auto to_array() const -> std::vector<bag> final;

        inline auto from_array() -> void final;

        inline auto from_array(std::vector<bag> const & src) -> void final;

        inline auto make_array() const -> bag final;

        inline auto make_array(std::vector<bag> const & src) const -> bag final;

        inline auto get_array(std::size_t index) const -> bag final;

        inline auto set_array(std::size_t index, bag const & value) -> void final;

        inline auto front_array() const -> bag final;

        inline auto back_array() const -> bag final;

        inline auto empty_array() const -> bool final;

        inline auto size_array() const -> std::size_t final;

        inline auto reserve_array(std::size_t new_cap) -> void final;

        inline auto capacity_array() const -> std::size_t final;

        inline auto clear_array() -> void final;

        inline auto insert_array(std::size_t pos, bag const & value) -> void final;

        inline auto erase_array(std::size_t pos) -> void final;

        inline auto push_front_array(bag const & value) -> void final;

        inline auto push_back_array(bag const & value) -> void final;

        inline auto pop_front_array() -> bag final;

        inline auto pop_back_array() -> bag final;

        inline auto resize_array(std::size_t count) -> void final;

        inline auto as_array_bool(std::vector<bool> & dest) const -> void final;

        inline auto as_array_int64(std::vector<int64_t> & dest) const -> void final;

        inline auto as_array_uint64(std::vector<uint64_t> & dest) const -> void final;

        inline auto as_array_double(std::vector<double> & dest) const -> void final;

        inline auto as_array_string(std::vector<std::string> & dest) const -> void final;

        inline auto as_array_any(std::vector<strange::any> & dest) const -> void final;

        inline auto to_array_bool() const -> std::vector<bool> final;

        inline auto to_array_int64() const -> std::vector<int64_t> final;

        inline auto to_array_uint64() const -> std::vector<uint64_t> final;

        inline auto to_array_double() const -> std::vector<double> final;

        inline auto to_array_string() const -> std::vector<std::string> final;

        inline auto to_array_any() const -> std::vector<strange::any> final;

        inline auto from_array_bool(std::vector<bool> const & src) -> void final;

        inline auto from_array_int64(std::vector<int64_t> const & src) -> void final;

        inline auto from_array_uint64(std::vector<uint64_t> const & src) -> void final;

        inline auto from_array_double(std::vector<double> const & src) -> void final;

        inline auto from_array_string(std::vector<std::string> const & src) -> void final;

        inline auto from_array_any(std::vector<strange::any> const & src) -> void final;

        inline auto make_array_bool(std::vector<bool> const & src) const -> bag final;

        inline auto make_array_int64(std::vector<int64_t> const & src) const -> bag final;

        inline auto make_array_uint64(std::vector<uint64_t> const & src) const -> bag final;

        inline auto make_array_double(std::vector<double> const & src) const -> bag final;

        inline auto make_array_string(std::vector<std::string> const & src) const -> bag final;

        inline auto make_array_any(std::vector<strange::any> const & src) const -> bag final;

        inline auto is_object() const -> bool final;

        inline auto as_object(std::unordered_map<std::string, bag> & dest) const -> void final;

        inline auto to_object() const -> std::unordered_map<std::string, bag> final;

        inline auto from_object() -> void final;

        inline auto from_object(std::unordered_map<std::string, bag> const & src) -> void final;

        inline auto make_object() const -> bag final;

        inline auto make_object(std::unordered_map<std::string, bag> const & src) const -> bag final;

        inline auto empty_object() const -> bool final;

        inline auto size_object() const -> std::size_t final;

        inline auto clear_object() -> void final;

        inline auto insert_object(std::string const & key, bag const & value) -> void final;

        inline auto erase_object(std::string const & key) -> void final;

        inline auto get_object(std::string const & key) const -> bag final;

        inline auto set_object(std::string const & key, bag const & value) -> void final;

        inline auto contains_object(std::string const & key) const -> bool final;

        inline auto is_any() const -> bool final;

        inline auto as_any(strange::any & dest) const -> void final;

        inline auto to_any() const -> strange::any final;

        inline auto from_any() -> void final;

        inline auto from_any(strange::any const & src) -> void final;

        inline auto make_any() const -> bag final;

        inline auto make_any(strange::any const & src) const -> bag final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    static inline auto _make_(_Args && ... _args) -> bag_
    {
        return bag_{bag_::_derived::_static_shared_to_base(std::make_shared<bag_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> bag_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return bag_{};
        }
        return bag_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<bag_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> bag_
    {
        try
        {
            return bag_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return bag_{};
        }
    }

    inline auto _reproduce_() const -> bag_
    {
        try
        {
            return bag_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return bag_{};
        }
    }

    inline auto _weak_() const -> bag_
    {
        return bag_{strange::_common::_weak_base()};
    }

    inline auto _strong_() const -> bag_
    {
        return bag_{strange::_common::_shared->_strong()};
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<bag_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<bag_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = bag_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return bag_::_derived::_static_shared_to_base(std::make_shared<bag_::_instance>());
            });
        }
        return name;
    }();
};

struct package : stuff
{
    inline package() = default;

    inline package(package const & other)
    :strange::_common{other}
    ,stuff{}
    {
    }

    inline package(package && other)
    :strange::_common{std::move(other)}
    ,stuff{}
    {
    }

    inline auto operator=(package const & other) -> package &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(package && other) -> package &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline package(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,stuff{}
    {
    }

    explicit inline package(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,stuff{}
    {
    }

protected:
    struct _derived : stuff::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename package::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return stuff::_derived::_static_shared_to_base(derived);
        }

        virtual auto seal() -> void = 0;

        virtual auto unseal() -> void = 0;

        virtual auto sealed() const -> bool = 0;

        virtual auto is_binary() const -> bool = 0;

        virtual auto as_binary(std::string & binary) const -> void = 0;

        virtual auto to_binary() const -> std::string = 0;

        virtual auto from_binary(std::string const & binary) -> void = 0;

        virtual auto make_binary(std::string const & binary) const -> package = 0;

        virtual auto is_json() const -> bool = 0;

        virtual auto as_json(std::string & json) const -> void = 0;

        virtual auto to_json() const -> std::string = 0;

        virtual auto from_json(std::string const & json) -> void = 0;

        virtual auto make_json(std::string const & json) const -> package = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename package::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> package
    {
        try
        {
            return package{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return package{};
        }
    }

    inline auto _reproduce() const -> package
    {
        try
        {
            return package{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return package{};
        }
    }

    inline auto _weak() const -> package
    {
        return package{strange::_common::_weak_base()};
    }

    inline auto _strong() const -> package
    {
        return package{strange::_common::_shared->_strong()};
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> package
    {
        return package{package::_derived::_static_shared_to_base(std::make_shared<typename package_<_Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> package
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return package{};
        }
        return package{it->second()};
    }

    using _Abstraction_ = package;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(stuff::_cats_.cbegin(), stuff::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();

    inline auto pack(strange::bag & dest) const -> void;

    inline auto unpack(strange::bag const & src) -> void;

    inline auto seal() -> void;

    inline auto unseal() -> void;

    inline auto sealed() const -> bool;

    inline auto is_binary() const -> bool;

    inline auto as_binary(std::string & binary) const -> void;

    inline auto to_binary() const -> std::string;

    inline auto from_binary(std::string const & binary) -> void;

    inline auto make_binary(std::string const & binary) const -> package;

    inline auto is_json() const -> bool;

    inline auto as_json(std::string & json) const -> void;

    inline auto to_json() const -> std::string;

    inline auto from_json(std::string const & json) -> void;

    inline auto make_json(std::string const & json) const -> package;
};

template<typename _Thing, bool _Copy>
struct package_ : package
{
    inline package_() = default;

    inline package_(package_ const & other)
    :strange::_common{other}
    ,package{}
    {
    }

    inline package_(package_ && other)
    :strange::_common{std::move(other)}
    ,package{}
    {
    }

    inline auto operator=(package_ const & other) -> package_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(package_ && other) -> package_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline package_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,package{}
    {
    }

    explicit inline package_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,package{}
    {
    }

private:
    friend struct package;

    struct _instance final : package::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :package_::_derived{}
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
                return package_::_derived::_static_shared_to_base(std::make_shared<package_::_instance>(_thing));
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
                return package_::_derived::_static_shared_to_base(std::make_shared<package_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return package::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return package::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return package_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return package_::_name_;
        }

        inline auto pack(strange::bag & dest) const -> void final;

        inline auto unpack(strange::bag const & src) -> void final;

        inline auto seal() -> void final;

        inline auto unseal() -> void final;

        inline auto sealed() const -> bool final;

        inline auto is_binary() const -> bool final;

        inline auto as_binary(std::string & binary) const -> void final;

        inline auto to_binary() const -> std::string final;

        inline auto from_binary(std::string const & binary) -> void final;

        inline auto make_binary(std::string const & binary) const -> package final;

        inline auto is_json() const -> bool final;

        inline auto as_json(std::string & json) const -> void final;

        inline auto to_json() const -> std::string final;

        inline auto from_json(std::string const & json) -> void final;

        inline auto make_json(std::string const & json) const -> package final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    static inline auto _make_(_Args && ... _args) -> package_
    {
        return package_{package_::_derived::_static_shared_to_base(std::make_shared<package_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> package_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return package_{};
        }
        return package_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<package_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> package_
    {
        try
        {
            return package_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return package_{};
        }
    }

    inline auto _reproduce_() const -> package_
    {
        try
        {
            return package_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return package_{};
        }
    }

    inline auto _weak_() const -> package_
    {
        return package_{strange::_common::_weak_base()};
    }

    inline auto _strong_() const -> package_
    {
        return package_{strange::_common::_shared->_strong()};
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<package_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<package_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = package_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return package_::_derived::_static_shared_to_base(std::make_shared<package_::_instance>());
            });
        }
        return name;
    }();
};

struct baggage : bag, package
{
    inline baggage() = default;

    inline baggage(baggage const & other)
    :strange::_common{other}
    ,bag{}
    ,package{}
    {
    }

    inline baggage(baggage && other)
    :strange::_common{std::move(other)}
    ,bag{}
    ,package{}
    {
    }

    inline auto operator=(baggage const & other) -> baggage &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(baggage && other) -> baggage &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline baggage(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,bag{}
    ,package{}
    {
    }

    explicit inline baggage(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,bag{}
    ,package{}
    {
    }

protected:
    struct _derived : bag::_derived, package::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename baggage::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return bag::_derived::_static_shared_to_base(derived);
        }
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename baggage::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> baggage
    {
        try
        {
            return baggage{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return baggage{};
        }
    }

    inline auto _reproduce() const -> baggage
    {
        try
        {
            return baggage{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return baggage{};
        }
    }

    inline auto _weak() const -> baggage
    {
        return baggage{strange::_common::_weak_base()};
    }

    inline auto _strong() const -> baggage
    {
        return baggage{strange::_common::_shared->_strong()};
    }

    template<typename _Thing = strange::implementation::baggage, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> baggage
    {
        return baggage{baggage::_derived::_static_shared_to_base(std::make_shared<typename baggage_<_Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> baggage
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return baggage{};
        }
        return baggage{it->second()};
    }

    using _Abstraction_ = baggage;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(bag::_cats_.cbegin(), bag::_cats_.cend());
        cats.insert(package::_cats_.cbegin(), package::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();

    inline auto pack(strange::bag & dest) const -> void;

    inline auto unpack(strange::bag const & src) -> void;

    inline auto is_null() const -> bool;

    inline auto from_null() -> void;

    inline auto make_null() const -> bag;

    inline auto is_bool() const -> bool;

    inline auto as_bool(bool & dest) const -> void;

    inline auto to_bool() const -> bool;

    inline auto from_bool() -> void;

    inline auto from_bool(bool src) -> void;

    inline auto make_bool() const -> bag;

    inline auto make_bool(bool src) const -> bag;

    inline auto is_int64() const -> bool;

    inline auto as_int64(int64_t & dest) const -> void;

    inline auto to_int64() const -> int64_t;

    inline auto from_int64() -> void;

    inline auto from_int64(int64_t src) -> void;

    inline auto make_int64() const -> bag;

    inline auto make_int64(int64_t src) const -> bag;

    inline auto is_uint64() const -> bool;

    inline auto as_uint64(uint64_t & dest) const -> void;

    inline auto to_uint64() const -> uint64_t;

    inline auto from_uint64() -> void;

    inline auto from_uint64(uint64_t src) -> void;

    inline auto make_uint64() const -> bag;

    inline auto make_uint64(uint64_t src) const -> bag;

    inline auto is_double() const -> bool;

    inline auto as_double(double & dest) const -> void;

    inline auto to_double() const -> double;

    inline auto from_double() -> void;

    inline auto from_double(double src) -> void;

    inline auto make_double() const -> bag;

    inline auto make_double(double src) const -> bag;

    inline auto is_string() const -> bool;

    inline auto as_string(std::string & dest) const -> void;

    inline auto to_string() const -> std::string;

    inline auto from_string() -> void;

    inline auto from_string(std::string const & src) -> void;

    inline auto make_string() const -> bag;

    inline auto make_string(std::string const & src) const -> bag;

    inline auto is_array() const -> bool;

    inline auto as_array(std::vector<bag> & dest) const -> void;

    inline auto to_array() const -> std::vector<bag>;

    inline auto from_array() -> void;

    inline auto from_array(std::vector<bag> const & src) -> void;

    inline auto make_array() const -> bag;

    inline auto make_array(std::vector<bag> const & src) const -> bag;

    inline auto get_array(std::size_t index) const -> bag;

    inline auto set_array(std::size_t index, bag const & value) -> void;

    inline auto front_array() const -> bag;

    inline auto back_array() const -> bag;

    inline auto empty_array() const -> bool;

    inline auto size_array() const -> std::size_t;

    inline auto reserve_array(std::size_t new_cap) -> void;

    inline auto capacity_array() const -> std::size_t;

    inline auto clear_array() -> void;

    inline auto insert_array(std::size_t pos, bag const & value) -> void;

    inline auto erase_array(std::size_t pos) -> void;

    inline auto push_front_array(bag const & value) -> void;

    inline auto push_back_array(bag const & value) -> void;

    inline auto pop_front_array() -> bag;

    inline auto pop_back_array() -> bag;

    inline auto resize_array(std::size_t count) -> void;

    inline auto as_array_bool(std::vector<bool> & dest) const -> void;

    inline auto as_array_int64(std::vector<int64_t> & dest) const -> void;

    inline auto as_array_uint64(std::vector<uint64_t> & dest) const -> void;

    inline auto as_array_double(std::vector<double> & dest) const -> void;

    inline auto as_array_string(std::vector<std::string> & dest) const -> void;

    inline auto as_array_any(std::vector<strange::any> & dest) const -> void;

    inline auto to_array_bool() const -> std::vector<bool>;

    inline auto to_array_int64() const -> std::vector<int64_t>;

    inline auto to_array_uint64() const -> std::vector<uint64_t>;

    inline auto to_array_double() const -> std::vector<double>;

    inline auto to_array_string() const -> std::vector<std::string>;

    inline auto to_array_any() const -> std::vector<strange::any>;

    inline auto from_array_bool(std::vector<bool> const & src) -> void;

    inline auto from_array_int64(std::vector<int64_t> const & src) -> void;

    inline auto from_array_uint64(std::vector<uint64_t> const & src) -> void;

    inline auto from_array_double(std::vector<double> const & src) -> void;

    inline auto from_array_string(std::vector<std::string> const & src) -> void;

    inline auto from_array_any(std::vector<strange::any> const & src) -> void;

    inline auto make_array_bool(std::vector<bool> const & src) const -> bag;

    inline auto make_array_int64(std::vector<int64_t> const & src) const -> bag;

    inline auto make_array_uint64(std::vector<uint64_t> const & src) const -> bag;

    inline auto make_array_double(std::vector<double> const & src) const -> bag;

    inline auto make_array_string(std::vector<std::string> const & src) const -> bag;

    inline auto make_array_any(std::vector<strange::any> const & src) const -> bag;

    inline auto is_object() const -> bool;

    inline auto as_object(std::unordered_map<std::string, bag> & dest) const -> void;

    inline auto to_object() const -> std::unordered_map<std::string, bag>;

    inline auto from_object() -> void;

    inline auto from_object(std::unordered_map<std::string, bag> const & src) -> void;

    inline auto make_object() const -> bag;

    inline auto make_object(std::unordered_map<std::string, bag> const & src) const -> bag;

    inline auto empty_object() const -> bool;

    inline auto size_object() const -> std::size_t;

    inline auto clear_object() -> void;

    inline auto insert_object(std::string const & key, bag const & value) -> void;

    inline auto erase_object(std::string const & key) -> void;

    inline auto get_object(std::string const & key) const -> bag;

    inline auto set_object(std::string const & key, bag const & value) -> void;

    inline auto contains_object(std::string const & key) const -> bool;

    inline auto is_any() const -> bool;

    inline auto as_any(strange::any & dest) const -> void;

    inline auto to_any() const -> strange::any;

    inline auto from_any() -> void;

    inline auto from_any(strange::any const & src) -> void;

    inline auto make_any() const -> bag;

    inline auto make_any(strange::any const & src) const -> bag;

    inline auto seal() -> void;

    inline auto unseal() -> void;

    inline auto sealed() const -> bool;

    inline auto is_binary() const -> bool;

    inline auto as_binary(std::string & binary) const -> void;

    inline auto to_binary() const -> std::string;

    inline auto from_binary(std::string const & binary) -> void;

    inline auto make_binary(std::string const & binary) const -> package;

    inline auto is_json() const -> bool;

    inline auto as_json(std::string & json) const -> void;

    inline auto to_json() const -> std::string;

    inline auto from_json(std::string const & json) -> void;

    inline auto make_json(std::string const & json) const -> package;
};

template<typename _Thing, bool _Copy>
struct baggage_ : baggage
{
    inline baggage_() = default;

    inline baggage_(baggage_ const & other)
    :strange::_common{other}
    ,baggage{}
    {
    }

    inline baggage_(baggage_ && other)
    :strange::_common{std::move(other)}
    ,baggage{}
    {
    }

    inline auto operator=(baggage_ const & other) -> baggage_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(baggage_ && other) -> baggage_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline baggage_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,baggage{}
    {
    }

    explicit inline baggage_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,baggage{}
    {
    }

private:
    friend struct baggage;

    struct _instance final : baggage::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :baggage_::_derived{}
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
                return baggage_::_derived::_static_shared_to_base(std::make_shared<baggage_::_instance>(_thing));
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
                return baggage_::_derived::_static_shared_to_base(std::make_shared<baggage_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return baggage::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return baggage::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return baggage_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return baggage_::_name_;
        }

        inline auto pack(strange::bag & dest) const -> void final;

        inline auto unpack(strange::bag const & src) -> void final;

        inline auto is_null() const -> bool final;

        inline auto from_null() -> void final;

        inline auto make_null() const -> bag final;

        inline auto is_bool() const -> bool final;

        inline auto as_bool(bool & dest) const -> void final;

        inline auto to_bool() const -> bool final;

        inline auto from_bool() -> void final;

        inline auto from_bool(bool src) -> void final;

        inline auto make_bool() const -> bag final;

        inline auto make_bool(bool src) const -> bag final;

        inline auto is_int64() const -> bool final;

        inline auto as_int64(int64_t & dest) const -> void final;

        inline auto to_int64() const -> int64_t final;

        inline auto from_int64() -> void final;

        inline auto from_int64(int64_t src) -> void final;

        inline auto make_int64() const -> bag final;

        inline auto make_int64(int64_t src) const -> bag final;

        inline auto is_uint64() const -> bool final;

        inline auto as_uint64(uint64_t & dest) const -> void final;

        inline auto to_uint64() const -> uint64_t final;

        inline auto from_uint64() -> void final;

        inline auto from_uint64(uint64_t src) -> void final;

        inline auto make_uint64() const -> bag final;

        inline auto make_uint64(uint64_t src) const -> bag final;

        inline auto is_double() const -> bool final;

        inline auto as_double(double & dest) const -> void final;

        inline auto to_double() const -> double final;

        inline auto from_double() -> void final;

        inline auto from_double(double src) -> void final;

        inline auto make_double() const -> bag final;

        inline auto make_double(double src) const -> bag final;

        inline auto is_string() const -> bool final;

        inline auto as_string(std::string & dest) const -> void final;

        inline auto to_string() const -> std::string final;

        inline auto from_string() -> void final;

        inline auto from_string(std::string const & src) -> void final;

        inline auto make_string() const -> bag final;

        inline auto make_string(std::string const & src) const -> bag final;

        inline auto is_array() const -> bool final;

        inline auto as_array(std::vector<bag> & dest) const -> void final;

        inline auto to_array() const -> std::vector<bag> final;

        inline auto from_array() -> void final;

        inline auto from_array(std::vector<bag> const & src) -> void final;

        inline auto make_array() const -> bag final;

        inline auto make_array(std::vector<bag> const & src) const -> bag final;

        inline auto get_array(std::size_t index) const -> bag final;

        inline auto set_array(std::size_t index, bag const & value) -> void final;

        inline auto front_array() const -> bag final;

        inline auto back_array() const -> bag final;

        inline auto empty_array() const -> bool final;

        inline auto size_array() const -> std::size_t final;

        inline auto reserve_array(std::size_t new_cap) -> void final;

        inline auto capacity_array() const -> std::size_t final;

        inline auto clear_array() -> void final;

        inline auto insert_array(std::size_t pos, bag const & value) -> void final;

        inline auto erase_array(std::size_t pos) -> void final;

        inline auto push_front_array(bag const & value) -> void final;

        inline auto push_back_array(bag const & value) -> void final;

        inline auto pop_front_array() -> bag final;

        inline auto pop_back_array() -> bag final;

        inline auto resize_array(std::size_t count) -> void final;

        inline auto as_array_bool(std::vector<bool> & dest) const -> void final;

        inline auto as_array_int64(std::vector<int64_t> & dest) const -> void final;

        inline auto as_array_uint64(std::vector<uint64_t> & dest) const -> void final;

        inline auto as_array_double(std::vector<double> & dest) const -> void final;

        inline auto as_array_string(std::vector<std::string> & dest) const -> void final;

        inline auto as_array_any(std::vector<strange::any> & dest) const -> void final;

        inline auto to_array_bool() const -> std::vector<bool> final;

        inline auto to_array_int64() const -> std::vector<int64_t> final;

        inline auto to_array_uint64() const -> std::vector<uint64_t> final;

        inline auto to_array_double() const -> std::vector<double> final;

        inline auto to_array_string() const -> std::vector<std::string> final;

        inline auto to_array_any() const -> std::vector<strange::any> final;

        inline auto from_array_bool(std::vector<bool> const & src) -> void final;

        inline auto from_array_int64(std::vector<int64_t> const & src) -> void final;

        inline auto from_array_uint64(std::vector<uint64_t> const & src) -> void final;

        inline auto from_array_double(std::vector<double> const & src) -> void final;

        inline auto from_array_string(std::vector<std::string> const & src) -> void final;

        inline auto from_array_any(std::vector<strange::any> const & src) -> void final;

        inline auto make_array_bool(std::vector<bool> const & src) const -> bag final;

        inline auto make_array_int64(std::vector<int64_t> const & src) const -> bag final;

        inline auto make_array_uint64(std::vector<uint64_t> const & src) const -> bag final;

        inline auto make_array_double(std::vector<double> const & src) const -> bag final;

        inline auto make_array_string(std::vector<std::string> const & src) const -> bag final;

        inline auto make_array_any(std::vector<strange::any> const & src) const -> bag final;

        inline auto is_object() const -> bool final;

        inline auto as_object(std::unordered_map<std::string, bag> & dest) const -> void final;

        inline auto to_object() const -> std::unordered_map<std::string, bag> final;

        inline auto from_object() -> void final;

        inline auto from_object(std::unordered_map<std::string, bag> const & src) -> void final;

        inline auto make_object() const -> bag final;

        inline auto make_object(std::unordered_map<std::string, bag> const & src) const -> bag final;

        inline auto empty_object() const -> bool final;

        inline auto size_object() const -> std::size_t final;

        inline auto clear_object() -> void final;

        inline auto insert_object(std::string const & key, bag const & value) -> void final;

        inline auto erase_object(std::string const & key) -> void final;

        inline auto get_object(std::string const & key) const -> bag final;

        inline auto set_object(std::string const & key, bag const & value) -> void final;

        inline auto contains_object(std::string const & key) const -> bool final;

        inline auto is_any() const -> bool final;

        inline auto as_any(strange::any & dest) const -> void final;

        inline auto to_any() const -> strange::any final;

        inline auto from_any() -> void final;

        inline auto from_any(strange::any const & src) -> void final;

        inline auto make_any() const -> bag final;

        inline auto make_any(strange::any const & src) const -> bag final;

        inline auto seal() -> void final;

        inline auto unseal() -> void final;

        inline auto sealed() const -> bool final;

        inline auto is_binary() const -> bool final;

        inline auto as_binary(std::string & binary) const -> void final;

        inline auto to_binary() const -> std::string final;

        inline auto from_binary(std::string const & binary) -> void final;

        inline auto make_binary(std::string const & binary) const -> package final;

        inline auto is_json() const -> bool final;

        inline auto as_json(std::string & json) const -> void final;

        inline auto to_json() const -> std::string final;

        inline auto from_json(std::string const & json) -> void final;

        inline auto make_json(std::string const & json) const -> package final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    static inline auto _make_(_Args && ... _args) -> baggage_
    {
        return baggage_{baggage_::_derived::_static_shared_to_base(std::make_shared<baggage_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> baggage_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return baggage_{};
        }
        return baggage_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<baggage_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> baggage_
    {
        try
        {
            return baggage_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return baggage_{};
        }
    }

    inline auto _reproduce_() const -> baggage_
    {
        try
        {
            return baggage_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return baggage_{};
        }
    }

    inline auto _weak_() const -> baggage_
    {
        return baggage_{strange::_common::_weak_base()};
    }

    inline auto _strong_() const -> baggage_
    {
        return baggage_{strange::_common::_shared->_strong()};
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<baggage_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<baggage_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = baggage_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return baggage_::_derived::_static_shared_to_base(std::make_shared<baggage_::_instance>());
            });
        }
        return name;
    }();
};

template<typename Signal>
struct processor : stuff
{
    inline processor() = default;

    inline processor(processor const & other)
    :strange::_common{other}
    ,stuff{}
    {
    }

    inline processor(processor && other)
    :strange::_common{std::move(other)}
    ,stuff{}
    {
    }

    inline auto operator=(processor const & other) -> processor &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(processor && other) -> processor &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline processor(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,stuff{}
    {
    }

    explicit inline processor(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,stuff{}
    {
    }

protected:
    struct _derived : stuff::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename processor::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return stuff::_derived::_static_shared_to_base(derived);
        }

        virtual auto ins(std::unique_ptr<Signal> && overload) const -> uint64_t const & = 0;

        virtual auto ins(std::unique_ptr<Signal> && overload) -> uint64_t & = 0;

        virtual auto outs(std::unique_ptr<Signal> && overload) const -> uint64_t const & = 0;

        virtual auto outs(std::unique_ptr<Signal> && overload) -> uint64_t & = 0;

        virtual auto closure(std::unique_ptr<Signal> && overload) -> std::function<auto (std::vector<Signal>) -> std::vector<Signal>> = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename processor::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> processor
    {
        try
        {
            return processor{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return processor{};
        }
    }

    inline auto _reproduce() const -> processor
    {
        try
        {
            return processor{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return processor{};
        }
    }

    inline auto _weak() const -> processor
    {
        return processor{strange::_common::_weak_base()};
    }

    inline auto _strong() const -> processor
    {
        return processor{strange::_common::_shared->_strong()};
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> processor
    {
        return processor{processor::_derived::_static_shared_to_base(std::make_shared<typename processor_<Signal, _Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> processor
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return processor{};
        }
        return processor{it->second()};
    }

    using _Abstraction_ = processor;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(stuff::_cats_.cbegin(), stuff::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();

    inline auto pack(strange::bag & dest) const -> void;

    inline auto unpack(strange::bag const & src) -> void;

    inline auto ins(std::unique_ptr<Signal> && overload = nullptr) const -> uint64_t const &;

    inline auto ins(std::unique_ptr<Signal> && overload = nullptr) -> uint64_t &;

    inline auto outs(std::unique_ptr<Signal> && overload = nullptr) const -> uint64_t const &;

    inline auto outs(std::unique_ptr<Signal> && overload = nullptr) -> uint64_t &;

    inline auto closure(std::unique_ptr<Signal> && overload = nullptr) -> std::function<auto (std::vector<Signal>) -> std::vector<Signal>>;
};

template<typename Signal, typename _Thing, bool _Copy>
struct processor_ : processor<Signal>
{
    inline processor_() = default;

    inline processor_(processor_ const & other)
    :strange::_common{other}
    ,processor<Signal>{}
    {
    }

    inline processor_(processor_ && other)
    :strange::_common{std::move(other)}
    ,processor<Signal>{}
    {
    }

    inline auto operator=(processor_ const & other) -> processor_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(processor_ && other) -> processor_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline processor_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,processor<Signal>{}
    {
    }

    explicit inline processor_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,processor<Signal>{}
    {
    }

private:
    friend struct processor<Signal>;

    struct _instance final : processor<Signal>::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :processor_::_derived{}
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
                return processor_::_derived::_static_shared_to_base(std::make_shared<processor_::_instance>(_thing));
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
                return processor_::_derived::_static_shared_to_base(std::make_shared<processor_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return processor<Signal>::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return processor<Signal>::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return processor_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return processor_::_name_;
        }

        inline auto pack(strange::bag & dest) const -> void final;

        inline auto unpack(strange::bag const & src) -> void final;

        inline auto ins(std::unique_ptr<Signal> && overload) const -> uint64_t const & final;

        inline auto ins(std::unique_ptr<Signal> && overload) -> uint64_t & final;

        inline auto outs(std::unique_ptr<Signal> && overload) const -> uint64_t const & final;

        inline auto outs(std::unique_ptr<Signal> && overload) -> uint64_t & final;

        inline auto closure(std::unique_ptr<Signal> && overload) -> std::function<auto (std::vector<Signal>) -> std::vector<Signal>> final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    static inline auto _make_(_Args && ... _args) -> processor_
    {
        return processor_{processor_::_derived::_static_shared_to_base(std::make_shared<processor_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> processor_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return processor_{};
        }
        return processor_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<processor_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> processor_
    {
        try
        {
            return processor_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return processor_{};
        }
    }

    inline auto _reproduce_() const -> processor_
    {
        try
        {
            return processor_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return processor_{};
        }
    }

    inline auto _weak_() const -> processor_
    {
        return processor_{strange::_common::_weak_base()};
    }

    inline auto _strong_() const -> processor_
    {
        return processor_{strange::_common::_shared->_strong()};
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<processor_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<processor_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = processor_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return processor_::_derived::_static_shared_to_base(std::make_shared<processor_::_instance>());
            });
        }
        return name;
    }();
};

struct connection : stuff
{
    inline connection() = default;

    inline connection(connection const & other)
    :strange::_common{other}
    ,stuff{}
    {
    }

    inline connection(connection && other)
    :strange::_common{std::move(other)}
    ,stuff{}
    {
    }

    inline auto operator=(connection const & other) -> connection &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(connection && other) -> connection &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline connection(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,stuff{}
    {
    }

    explicit inline connection(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,stuff{}
    {
    }

protected:
    struct _derived : stuff::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename connection::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return stuff::_derived::_static_shared_to_base(derived);
        }

        virtual auto from_id() const -> uint64_t const & = 0;

        virtual auto from_id() -> uint64_t & = 0;

        virtual auto from_out() const -> uint64_t const & = 0;

        virtual auto from_out() -> uint64_t & = 0;

        virtual auto to_id() const -> uint64_t const & = 0;

        virtual auto to_id() -> uint64_t & = 0;

        virtual auto to_in() const -> uint64_t const & = 0;

        virtual auto to_in() -> uint64_t & = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename connection::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> connection
    {
        try
        {
            return connection{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return connection{};
        }
    }

    inline auto _reproduce() const -> connection
    {
        try
        {
            return connection{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return connection{};
        }
    }

    inline auto _weak() const -> connection
    {
        return connection{strange::_common::_weak_base()};
    }

    inline auto _strong() const -> connection
    {
        return connection{strange::_common::_shared->_strong()};
    }

    template<typename _Thing = strange::implementation::connection, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> connection
    {
        return connection{connection::_derived::_static_shared_to_base(std::make_shared<typename connection_<_Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> connection
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return connection{};
        }
        return connection{it->second()};
    }

    using _Abstraction_ = connection;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(stuff::_cats_.cbegin(), stuff::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();

    inline auto pack(strange::bag & dest) const -> void;

    inline auto unpack(strange::bag const & src) -> void;

    inline auto from_id() const -> uint64_t const &;

    inline auto from_id() -> uint64_t &;

    inline auto from_out() const -> uint64_t const &;

    inline auto from_out() -> uint64_t &;

    inline auto to_id() const -> uint64_t const &;

    inline auto to_id() -> uint64_t &;

    inline auto to_in() const -> uint64_t const &;

    inline auto to_in() -> uint64_t &;
};

template<typename _Thing, bool _Copy>
struct connection_ : connection
{
    inline connection_() = default;

    inline connection_(connection_ const & other)
    :strange::_common{other}
    ,connection{}
    {
    }

    inline connection_(connection_ && other)
    :strange::_common{std::move(other)}
    ,connection{}
    {
    }

    inline auto operator=(connection_ const & other) -> connection_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(connection_ && other) -> connection_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline connection_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,connection{}
    {
    }

    explicit inline connection_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,connection{}
    {
    }

private:
    friend struct connection;

    struct _instance final : connection::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :connection_::_derived{}
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
                return connection_::_derived::_static_shared_to_base(std::make_shared<connection_::_instance>(_thing));
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
                return connection_::_derived::_static_shared_to_base(std::make_shared<connection_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return connection::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return connection::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return connection_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return connection_::_name_;
        }

        inline auto pack(strange::bag & dest) const -> void final;

        inline auto unpack(strange::bag const & src) -> void final;

        inline auto from_id() const -> uint64_t const & final;

        inline auto from_id() -> uint64_t & final;

        inline auto from_out() const -> uint64_t const & final;

        inline auto from_out() -> uint64_t & final;

        inline auto to_id() const -> uint64_t const & final;

        inline auto to_id() -> uint64_t & final;

        inline auto to_in() const -> uint64_t const & final;

        inline auto to_in() -> uint64_t & final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    static inline auto _make_(_Args && ... _args) -> connection_
    {
        return connection_{connection_::_derived::_static_shared_to_base(std::make_shared<connection_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> connection_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return connection_{};
        }
        return connection_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<connection_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> connection_
    {
        try
        {
            return connection_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return connection_{};
        }
    }

    inline auto _reproduce_() const -> connection_
    {
        try
        {
            return connection_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return connection_{};
        }
    }

    inline auto _weak_() const -> connection_
    {
        return connection_{strange::_common::_weak_base()};
    }

    inline auto _strong_() const -> connection_
    {
        return connection_{strange::_common::_shared->_strong()};
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<connection_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<connection_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = connection_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return connection_::_derived::_static_shared_to_base(std::make_shared<connection_::_instance>());
            });
        }
        return name;
    }();
};

}

namespace strange
{
namespace implementation
{
struct connection
{
    uint64_t from_id_ {};
    inline auto from_id() const -> uint64_t const & { return from_id_; };
    inline auto from_id() -> uint64_t & { return from_id_; };
    uint64_t from_out_ {};
    inline auto from_out() const -> uint64_t const & { return from_out_; };
    inline auto from_out() -> uint64_t & { return from_out_; };
    uint64_t to_id_ {};
    inline auto to_id() const -> uint64_t const & { return to_id_; };
    inline auto to_id() -> uint64_t & { return to_id_; };
    uint64_t to_in_ {};
    inline auto to_in() const -> uint64_t const & { return to_in_; };
    inline auto to_in() -> uint64_t & { return to_in_; };

    inline auto pack(strange::bag & dest) const -> void
    {
        dest.from_object();
        dest.insert_object("from_id", dest.make_uint64(from_id()));
        dest.insert_object("from_out", dest.make_uint64(from_out()));
        dest.insert_object("to_id", dest.make_uint64(to_id()));
        dest.insert_object("to_in", dest.make_uint64(to_in()));
    }

    inline auto unpack(strange::bag const & src) -> void
    {
        src.get_object("from_id").as_uint64(from_id());
        src.get_object("from_out").as_uint64(from_out());
        src.get_object("to_id").as_uint64(to_id());
        src.get_object("to_in").as_uint64(to_in());
    }
};
}
}

namespace strange
{

template<typename Signal>
struct graph : processor<Signal>
{
    inline graph() = default;

    inline graph(graph const & other)
    :strange::_common{other}
    ,processor<Signal>{}
    {
    }

    inline graph(graph && other)
    :strange::_common{std::move(other)}
    ,processor<Signal>{}
    {
    }

    inline auto operator=(graph const & other) -> graph &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(graph && other) -> graph &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline graph(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,processor<Signal>{}
    {
    }

    explicit inline graph(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,processor<Signal>{}
    {
    }

protected:
    struct _derived : processor<Signal>::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename graph::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return processor<Signal>::_derived::_static_shared_to_base(derived);
        }

        virtual auto add_processor(strange::processor<Signal> proc) -> uint64_t = 0;

        virtual auto remove_processor(uint64_t id, std::unique_ptr<Signal> && overload) -> bool = 0;

        virtual auto add_connection(strange::connection conn, std::unique_ptr<Signal> && overload) -> uint64_t = 0;

        virtual auto remove_connection(uint64_t id, std::unique_ptr<Signal> && overload) -> bool = 0;

        virtual auto processors() -> std::vector<strange::processor<Signal>> & = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename graph::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> graph
    {
        try
        {
            return graph{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return graph{};
        }
    }

    inline auto _reproduce() const -> graph
    {
        try
        {
            return graph{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return graph{};
        }
    }

    inline auto _weak() const -> graph
    {
        return graph{strange::_common::_weak_base()};
    }

    inline auto _strong() const -> graph
    {
        return graph{strange::_common::_shared->_strong()};
    }

    template<typename _Thing = strange::implementation::graph<Signal>, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> graph
    {
        return graph{graph::_derived::_static_shared_to_base(std::make_shared<typename graph_<Signal, _Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> graph
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return graph{};
        }
        return graph{it->second()};
    }

    using _Abstraction_ = graph;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(processor<Signal>::_cats_.cbegin(), processor<Signal>::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();

    inline auto pack(strange::bag & dest) const -> void;

    inline auto unpack(strange::bag const & src) -> void;

    inline auto ins(std::unique_ptr<Signal> && overload = nullptr) const -> uint64_t const &;

    inline auto ins(std::unique_ptr<Signal> && overload = nullptr) -> uint64_t &;

    inline auto outs(std::unique_ptr<Signal> && overload = nullptr) const -> uint64_t const &;

    inline auto outs(std::unique_ptr<Signal> && overload = nullptr) -> uint64_t &;

    inline auto closure(std::unique_ptr<Signal> && overload = nullptr) -> std::function<auto (std::vector<Signal>) -> std::vector<Signal>>;

    inline auto add_processor(strange::processor<Signal> proc) -> uint64_t;

    inline auto remove_processor(uint64_t id, std::unique_ptr<Signal> && overload = nullptr) -> bool;

    inline auto add_connection(strange::connection conn, std::unique_ptr<Signal> && overload = nullptr) -> uint64_t;

    inline auto remove_connection(uint64_t id, std::unique_ptr<Signal> && overload = nullptr) -> bool;

    inline auto processors() -> std::vector<strange::processor<Signal>> &;
};

template<typename Signal, typename _Thing, bool _Copy>
struct graph_ : graph<Signal>
{
    inline graph_() = default;

    inline graph_(graph_ const & other)
    :strange::_common{other}
    ,graph<Signal>{}
    {
    }

    inline graph_(graph_ && other)
    :strange::_common{std::move(other)}
    ,graph<Signal>{}
    {
    }

    inline auto operator=(graph_ const & other) -> graph_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(graph_ && other) -> graph_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline graph_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,graph<Signal>{}
    {
    }

    explicit inline graph_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,graph<Signal>{}
    {
    }

private:
    friend struct graph<Signal>;

    struct _instance final : graph<Signal>::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :graph_::_derived{}
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
                return graph_::_derived::_static_shared_to_base(std::make_shared<graph_::_instance>(_thing));
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
                return graph_::_derived::_static_shared_to_base(std::make_shared<graph_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return graph<Signal>::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return graph<Signal>::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return graph_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return graph_::_name_;
        }

        inline auto pack(strange::bag & dest) const -> void final;

        inline auto unpack(strange::bag const & src) -> void final;

        inline auto ins(std::unique_ptr<Signal> && overload) const -> uint64_t const & final;

        inline auto ins(std::unique_ptr<Signal> && overload) -> uint64_t & final;

        inline auto outs(std::unique_ptr<Signal> && overload) const -> uint64_t const & final;

        inline auto outs(std::unique_ptr<Signal> && overload) -> uint64_t & final;

        inline auto closure(std::unique_ptr<Signal> && overload) -> std::function<auto (std::vector<Signal>) -> std::vector<Signal>> final;

        inline auto add_processor(strange::processor<Signal> proc) -> uint64_t final;

        inline auto remove_processor(uint64_t id, std::unique_ptr<Signal> && overload) -> bool final;

        inline auto add_connection(strange::connection conn, std::unique_ptr<Signal> && overload) -> uint64_t final;

        inline auto remove_connection(uint64_t id, std::unique_ptr<Signal> && overload) -> bool final;

        inline auto processors() -> std::vector<strange::processor<Signal>> & final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    static inline auto _make_(_Args && ... _args) -> graph_
    {
        return graph_{graph_::_derived::_static_shared_to_base(std::make_shared<graph_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> graph_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return graph_{};
        }
        return graph_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<graph_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> graph_
    {
        try
        {
            return graph_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return graph_{};
        }
    }

    inline auto _reproduce_() const -> graph_
    {
        try
        {
            return graph_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return graph_{};
        }
    }

    inline auto _weak_() const -> graph_
    {
        return graph_{strange::_common::_weak_base()};
    }

    inline auto _strong_() const -> graph_
    {
        return graph_{strange::_common::_shared->_strong()};
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<graph_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<graph_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = graph_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return graph_::_derived::_static_shared_to_base(std::make_shared<graph_::_instance>());
            });
        }
        return name;
    }();
};

struct parameter : stuff
{
    inline parameter() = default;

    inline parameter(parameter const & other)
    :strange::_common{other}
    ,stuff{}
    {
    }

    inline parameter(parameter && other)
    :strange::_common{std::move(other)}
    ,stuff{}
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
    ,stuff{}
    {
    }

    explicit inline parameter(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,stuff{}
    {
    }

protected:
    struct _derived : stuff::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename parameter::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return stuff::_derived::_static_shared_to_base(derived);
        }

        virtual auto type() const -> std::string const & = 0;

        virtual auto type() -> std::string & = 0;

        virtual auto name() const -> std::string const & = 0;

        virtual auto name() -> std::string & = 0;

        virtual auto argument() const -> std::string const & = 0;

        virtual auto argument() -> std::string & = 0;

        virtual auto operator==(parameter const & other) const -> bool = 0;

        virtual auto operator!=(parameter const & other) const -> bool = 0;

        virtual auto operator<(parameter const & other) const -> bool = 0;

        virtual auto operator<=(parameter const & other) const -> bool = 0;

        virtual auto operator>(parameter const & other) const -> bool = 0;

        virtual auto operator>=(parameter const & other) const -> bool = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename parameter::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> parameter
    {
        try
        {
            return parameter{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return parameter{};
        }
    }

    inline auto _reproduce() const -> parameter
    {
        try
        {
            return parameter{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return parameter{};
        }
    }

    inline auto _weak() const -> parameter
    {
        return parameter{strange::_common::_weak_base()};
    }

    inline auto _strong() const -> parameter
    {
        return parameter{strange::_common::_shared->_strong()};
    }

    template<typename _Thing = strange::implementation::parameter, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> parameter
    {
        return parameter{parameter::_derived::_static_shared_to_base(std::make_shared<typename parameter_<_Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> parameter
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return parameter{};
        }
        return parameter{it->second()};
    }

    using _Abstraction_ = parameter;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(stuff::_cats_.cbegin(), stuff::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();

    inline auto pack(strange::bag & dest) const -> void;

    inline auto unpack(strange::bag const & src) -> void;

    inline auto type() const -> std::string const &;

    inline auto type() -> std::string &;

    inline auto name() const -> std::string const &;

    inline auto name() -> std::string &;

    inline auto argument() const -> std::string const &;

    inline auto argument() -> std::string &;

    inline auto operator==(parameter const & other) const -> bool;

    inline auto operator!=(parameter const & other) const -> bool;

    inline auto operator<(parameter const & other) const -> bool;

    inline auto operator<=(parameter const & other) const -> bool;

    inline auto operator>(parameter const & other) const -> bool;

    inline auto operator>=(parameter const & other) const -> bool;
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
                throw strange::_common::_no_copy{};
            }
        }

        inline auto _reproduce() const -> std::shared_ptr<strange::_common::_base> final
        {
            if constexpr (std::is_default_constructible_v<_Thing>)
            {
                return parameter_::_derived::_static_shared_to_base(std::make_shared<parameter_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
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

        inline auto _copy() const -> bool final
        {
            return parameter_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return parameter_::_name_;
        }

        inline auto pack(strange::bag & dest) const -> void final;

        inline auto unpack(strange::bag const & src) -> void final;

        inline auto type() const -> std::string const & final;

        inline auto type() -> std::string & final;

        inline auto name() const -> std::string const & final;

        inline auto name() -> std::string & final;

        inline auto argument() const -> std::string const & final;

        inline auto argument() -> std::string & final;

        inline auto operator==(parameter const & other) const -> bool final;

        inline auto operator!=(parameter const & other) const -> bool final;

        inline auto operator<(parameter const & other) const -> bool final;

        inline auto operator<=(parameter const & other) const -> bool final;

        inline auto operator>(parameter const & other) const -> bool final;

        inline auto operator>=(parameter const & other) const -> bool final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    static inline auto _make_(_Args && ... _args) -> parameter_
    {
        return parameter_{parameter_::_derived::_static_shared_to_base(std::make_shared<parameter_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> parameter_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return parameter_{};
        }
        return parameter_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<parameter_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> parameter_
    {
        try
        {
            return parameter_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return parameter_{};
        }
    }

    inline auto _reproduce_() const -> parameter_
    {
        try
        {
            return parameter_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return parameter_{};
        }
    }

    inline auto _weak_() const -> parameter_
    {
        return parameter_{strange::_common::_weak_base()};
    }

    inline auto _strong_() const -> parameter_
    {
        return parameter_{strange::_common::_shared->_strong()};
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<parameter_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<parameter_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = parameter_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return parameter_::_derived::_static_shared_to_base(std::make_shared<parameter_::_instance>());
            });
        }
        return name;
    }();
};

}

namespace strange
{
namespace implementation
{
struct parameter
{
    std::string type_ {};
    inline auto type() const -> std::string const & { return type_; };
    inline auto type() -> std::string & { return type_; };
    std::string name_ {};
    inline auto name() const -> std::string const & { return name_; };
    inline auto name() -> std::string & { return name_; };
    std::string argument_ {};
    inline auto argument() const -> std::string const & { return argument_; };
    inline auto argument() -> std::string & { return argument_; };

    inline auto pack(strange::bag & dest) const -> void
    {
        dest.from_object();
        dest.insert_object("type", dest.make_string(type()));
        dest.insert_object("name", dest.make_string(name()));
        dest.insert_object("argument", dest.make_string(argument()));
    }

    inline auto unpack(strange::bag const & src) -> void
    {
        src.get_object("type").as_string(type());
        src.get_object("name").as_string(name());
        src.get_object("argument").as_string(argument());
    }
};
}
}

namespace strange
{

struct operation : stuff
{
    inline operation() = default;

    inline operation(operation const & other)
    :strange::_common{other}
    ,stuff{}
    {
    }

    inline operation(operation && other)
    :strange::_common{std::move(other)}
    ,stuff{}
    {
    }

    inline auto operator=(operation const & other) -> operation &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(operation && other) -> operation &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline operation(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,stuff{}
    {
    }

    explicit inline operation(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,stuff{}
    {
    }

protected:
    struct _derived : stuff::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename operation::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return stuff::_derived::_static_shared_to_base(derived);
        }

        virtual auto name() const -> std::string const & = 0;

        virtual auto name() -> std::string & = 0;

        virtual auto parameters() const -> std::vector<strange::parameter> const & = 0;

        virtual auto parameters() -> std::vector<strange::parameter> & = 0;

        virtual auto constness() const -> bool const & = 0;

        virtual auto constness() -> bool & = 0;

        virtual auto result() const -> std::string const & = 0;

        virtual auto result() -> std::string & = 0;

        virtual auto data() const -> bool const & = 0;

        virtual auto data() -> bool & = 0;

        virtual auto closure() const -> std::string const & = 0;

        virtual auto closure() -> std::string & = 0;

        virtual auto modification() const -> std::string const & = 0;

        virtual auto modification() -> std::string & = 0;

        virtual auto customisation() const -> std::string const & = 0;

        virtual auto customisation() -> std::string & = 0;

        virtual auto implementation() const -> std::string const & = 0;

        virtual auto implementation() -> std::string & = 0;

        virtual auto operator==(operation const & other) const -> bool = 0;

        virtual auto operator!=(operation const & other) const -> bool = 0;

        virtual auto operator<(operation const & other) const -> bool = 0;

        virtual auto operator<=(operation const & other) const -> bool = 0;

        virtual auto operator>(operation const & other) const -> bool = 0;

        virtual auto operator>=(operation const & other) const -> bool = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename operation::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> operation
    {
        try
        {
            return operation{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return operation{};
        }
    }

    inline auto _reproduce() const -> operation
    {
        try
        {
            return operation{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return operation{};
        }
    }

    inline auto _weak() const -> operation
    {
        return operation{strange::_common::_weak_base()};
    }

    inline auto _strong() const -> operation
    {
        return operation{strange::_common::_shared->_strong()};
    }

    template<typename _Thing = strange::implementation::operation, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> operation
    {
        return operation{operation::_derived::_static_shared_to_base(std::make_shared<typename operation_<_Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> operation
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return operation{};
        }
        return operation{it->second()};
    }

    using _Abstraction_ = operation;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(stuff::_cats_.cbegin(), stuff::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();

    inline auto pack(strange::bag & dest) const -> void;

    inline auto unpack(strange::bag const & src) -> void;

    inline auto name() const -> std::string const &;

    inline auto name() -> std::string &;

    inline auto parameters() const -> std::vector<strange::parameter> const &;

    inline auto parameters() -> std::vector<strange::parameter> &;

    inline auto constness() const -> bool const &;

    inline auto constness() -> bool &;

    inline auto result() const -> std::string const &;

    inline auto result() -> std::string &;

    inline auto data() const -> bool const &;

    inline auto data() -> bool &;

    inline auto closure() const -> std::string const &;

    inline auto closure() -> std::string &;

    inline auto modification() const -> std::string const &;

    inline auto modification() -> std::string &;

    inline auto customisation() const -> std::string const &;

    inline auto customisation() -> std::string &;

    inline auto implementation() const -> std::string const &;

    inline auto implementation() -> std::string &;

    inline auto operator==(operation const & other) const -> bool;

    inline auto operator!=(operation const & other) const -> bool;

    inline auto operator<(operation const & other) const -> bool;

    inline auto operator<=(operation const & other) const -> bool;

    inline auto operator>(operation const & other) const -> bool;

    inline auto operator>=(operation const & other) const -> bool;
};

template<typename _Thing, bool _Copy>
struct operation_ : operation
{
    inline operation_() = default;

    inline operation_(operation_ const & other)
    :strange::_common{other}
    ,operation{}
    {
    }

    inline operation_(operation_ && other)
    :strange::_common{std::move(other)}
    ,operation{}
    {
    }

    inline auto operator=(operation_ const & other) -> operation_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(operation_ && other) -> operation_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline operation_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,operation{}
    {
    }

    explicit inline operation_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,operation{}
    {
    }

private:
    friend struct operation;

    struct _instance final : operation::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :operation_::_derived{}
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
                return operation_::_derived::_static_shared_to_base(std::make_shared<operation_::_instance>(_thing));
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
                return operation_::_derived::_static_shared_to_base(std::make_shared<operation_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return operation::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return operation::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return operation_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return operation_::_name_;
        }

        inline auto pack(strange::bag & dest) const -> void final;

        inline auto unpack(strange::bag const & src) -> void final;

        inline auto name() const -> std::string const & final;

        inline auto name() -> std::string & final;

        inline auto parameters() const -> std::vector<strange::parameter> const & final;

        inline auto parameters() -> std::vector<strange::parameter> & final;

        inline auto constness() const -> bool const & final;

        inline auto constness() -> bool & final;

        inline auto result() const -> std::string const & final;

        inline auto result() -> std::string & final;

        inline auto data() const -> bool const & final;

        inline auto data() -> bool & final;

        inline auto closure() const -> std::string const & final;

        inline auto closure() -> std::string & final;

        inline auto modification() const -> std::string const & final;

        inline auto modification() -> std::string & final;

        inline auto customisation() const -> std::string const & final;

        inline auto customisation() -> std::string & final;

        inline auto implementation() const -> std::string const & final;

        inline auto implementation() -> std::string & final;

        inline auto operator==(operation const & other) const -> bool final;

        inline auto operator!=(operation const & other) const -> bool final;

        inline auto operator<(operation const & other) const -> bool final;

        inline auto operator<=(operation const & other) const -> bool final;

        inline auto operator>(operation const & other) const -> bool final;

        inline auto operator>=(operation const & other) const -> bool final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    static inline auto _make_(_Args && ... _args) -> operation_
    {
        return operation_{operation_::_derived::_static_shared_to_base(std::make_shared<operation_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> operation_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return operation_{};
        }
        return operation_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<operation_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> operation_
    {
        try
        {
            return operation_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return operation_{};
        }
    }

    inline auto _reproduce_() const -> operation_
    {
        try
        {
            return operation_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return operation_{};
        }
    }

    inline auto _weak_() const -> operation_
    {
        return operation_{strange::_common::_weak_base()};
    }

    inline auto _strong_() const -> operation_
    {
        return operation_{strange::_common::_shared->_strong()};
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<operation_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<operation_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = operation_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return operation_::_derived::_static_shared_to_base(std::make_shared<operation_::_instance>());
            });
        }
        return name;
    }();
};

}

namespace strange
{
namespace implementation
{
struct operation
{
    std::string name_ {};
    inline auto name() const -> std::string const & { return name_; };
    inline auto name() -> std::string & { return name_; };
    std::vector<strange::parameter> parameters_ {};
    inline auto parameters() const -> std::vector<strange::parameter> const & { return parameters_; };
    inline auto parameters() -> std::vector<strange::parameter> & { return parameters_; };
    bool constness_ {false};
    inline auto constness() const -> bool const & { return constness_; };
    inline auto constness() -> bool & { return constness_; };
    std::string result_ {};
    inline auto result() const -> std::string const & { return result_; };
    inline auto result() -> std::string & { return result_; };
    bool data_ {false};
    inline auto data() const -> bool const & { return data_; };
    inline auto data() -> bool & { return data_; };
    std::string closure_ {};
    inline auto closure() const -> std::string const & { return closure_; };
    inline auto closure() -> std::string & { return closure_; };
    std::string modification_ {};
    inline auto modification() const -> std::string const & { return modification_; };
    inline auto modification() -> std::string & { return modification_; };
    std::string customisation_ {};
    inline auto customisation() const -> std::string const & { return customisation_; };
    inline auto customisation() -> std::string & { return customisation_; };
    std::string implementation_ {};
    inline auto implementation() const -> std::string const & { return implementation_; };
    inline auto implementation() -> std::string & { return implementation_; };

    inline auto pack(strange::bag & dest) const -> void
    {
        dest.from_object();
        dest.insert_object("name", dest.make_string(name()));
        {
            auto _array = dest.make_array();
            for (auto const & _item : parameters())
            {
                _array.push_back_array(dest.make_any(_item));
            }
            dest.insert_object("parameters", _array);
        }
        dest.insert_object("constness", dest.make_bool(constness()));
        dest.insert_object("result", dest.make_string(result()));
        dest.insert_object("data", dest.make_bool(data()));
        dest.insert_object("closure", dest.make_string(closure()));
        dest.insert_object("modification", dest.make_string(modification()));
        dest.insert_object("customisation", dest.make_string(customisation()));
        dest.insert_object("implementation", dest.make_string(implementation()));
    }

    inline auto unpack(strange::bag const & src) -> void
    {
        src.get_object("name").as_string(name());
        {
            auto _array = src.get_object("parameters").to_array();
            auto _size = _array.size();
            parameters().clear();
            parameters().resize(_size);
            for (std::size_t _index = 0; _index < _size; ++_index)
            {
                _array[_index].as_any(parameters()[_index]);
            }
        }
        src.get_object("constness").as_bool(constness());
        src.get_object("result").as_string(result());
        src.get_object("data").as_bool(data());
        src.get_object("closure").as_string(closure());
        src.get_object("modification").as_string(modification());
        src.get_object("customisation").as_string(customisation());
        src.get_object("implementation").as_string(implementation());
    }
};
}
}

namespace strange
{

struct abstraction : stuff
{
    inline abstraction() = default;

    inline abstraction(abstraction const & other)
    :strange::_common{other}
    ,stuff{}
    {
    }

    inline abstraction(abstraction && other)
    :strange::_common{std::move(other)}
    ,stuff{}
    {
    }

    inline auto operator=(abstraction const & other) -> abstraction &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(abstraction && other) -> abstraction &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline abstraction(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,stuff{}
    {
    }

    explicit inline abstraction(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,stuff{}
    {
    }

protected:
    struct _derived : stuff::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename abstraction::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return stuff::_derived::_static_shared_to_base(derived);
        }

        virtual auto parameters() const -> std::vector<strange::parameter> const & = 0;

        virtual auto parameters() -> std::vector<strange::parameter> & = 0;

        virtual auto name() const -> std::string const & = 0;

        virtual auto name() -> std::string & = 0;

        virtual auto parents() const -> std::vector<std::string> const & = 0;

        virtual auto parents() -> std::vector<std::string> & = 0;

        virtual auto types() const -> std::vector<strange::parameter> const & = 0;

        virtual auto types() -> std::vector<strange::parameter> & = 0;

        virtual auto operations() const -> std::vector<strange::operation> const & = 0;

        virtual auto operations() -> std::vector<strange::operation> & = 0;

        virtual auto thing() const -> std::string const & = 0;

        virtual auto thing() -> std::string & = 0;

        virtual auto implementation() const -> std::string const & = 0;

        virtual auto implementation() -> std::string & = 0;

        virtual auto operator==(abstraction const & other) const -> bool = 0;

        virtual auto operator!=(abstraction const & other) const -> bool = 0;

        virtual auto operator<(abstraction const & other) const -> bool = 0;

        virtual auto operator<=(abstraction const & other) const -> bool = 0;

        virtual auto operator>(abstraction const & other) const -> bool = 0;

        virtual auto operator>=(abstraction const & other) const -> bool = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename abstraction::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> abstraction
    {
        try
        {
            return abstraction{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return abstraction{};
        }
    }

    inline auto _reproduce() const -> abstraction
    {
        try
        {
            return abstraction{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return abstraction{};
        }
    }

    inline auto _weak() const -> abstraction
    {
        return abstraction{strange::_common::_weak_base()};
    }

    inline auto _strong() const -> abstraction
    {
        return abstraction{strange::_common::_shared->_strong()};
    }

    template<typename _Thing = strange::implementation::abstraction, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> abstraction
    {
        return abstraction{abstraction::_derived::_static_shared_to_base(std::make_shared<typename abstraction_<_Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> abstraction
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return abstraction{};
        }
        return abstraction{it->second()};
    }

    using _Abstraction_ = abstraction;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(stuff::_cats_.cbegin(), stuff::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();

    inline auto pack(strange::bag & dest) const -> void;

    inline auto unpack(strange::bag const & src) -> void;

    inline auto parameters() const -> std::vector<strange::parameter> const &;

    inline auto parameters() -> std::vector<strange::parameter> &;

    inline auto name() const -> std::string const &;

    inline auto name() -> std::string &;

    inline auto parents() const -> std::vector<std::string> const &;

    inline auto parents() -> std::vector<std::string> &;

    inline auto types() const -> std::vector<strange::parameter> const &;

    inline auto types() -> std::vector<strange::parameter> &;

    inline auto operations() const -> std::vector<strange::operation> const &;

    inline auto operations() -> std::vector<strange::operation> &;

    inline auto thing() const -> std::string const &;

    inline auto thing() -> std::string &;

    inline auto implementation() const -> std::string const &;

    inline auto implementation() -> std::string &;

    inline auto operator==(abstraction const & other) const -> bool;

    inline auto operator!=(abstraction const & other) const -> bool;

    inline auto operator<(abstraction const & other) const -> bool;

    inline auto operator<=(abstraction const & other) const -> bool;

    inline auto operator>(abstraction const & other) const -> bool;

    inline auto operator>=(abstraction const & other) const -> bool;
};

template<typename _Thing, bool _Copy>
struct abstraction_ : abstraction
{
    inline abstraction_() = default;

    inline abstraction_(abstraction_ const & other)
    :strange::_common{other}
    ,abstraction{}
    {
    }

    inline abstraction_(abstraction_ && other)
    :strange::_common{std::move(other)}
    ,abstraction{}
    {
    }

    inline auto operator=(abstraction_ const & other) -> abstraction_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(abstraction_ && other) -> abstraction_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline abstraction_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,abstraction{}
    {
    }

    explicit inline abstraction_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,abstraction{}
    {
    }

private:
    friend struct abstraction;

    struct _instance final : abstraction::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :abstraction_::_derived{}
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
                return abstraction_::_derived::_static_shared_to_base(std::make_shared<abstraction_::_instance>(_thing));
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
                return abstraction_::_derived::_static_shared_to_base(std::make_shared<abstraction_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return abstraction::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return abstraction::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return abstraction_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return abstraction_::_name_;
        }

        inline auto pack(strange::bag & dest) const -> void final;

        inline auto unpack(strange::bag const & src) -> void final;

        inline auto parameters() const -> std::vector<strange::parameter> const & final;

        inline auto parameters() -> std::vector<strange::parameter> & final;

        inline auto name() const -> std::string const & final;

        inline auto name() -> std::string & final;

        inline auto parents() const -> std::vector<std::string> const & final;

        inline auto parents() -> std::vector<std::string> & final;

        inline auto types() const -> std::vector<strange::parameter> const & final;

        inline auto types() -> std::vector<strange::parameter> & final;

        inline auto operations() const -> std::vector<strange::operation> const & final;

        inline auto operations() -> std::vector<strange::operation> & final;

        inline auto thing() const -> std::string const & final;

        inline auto thing() -> std::string & final;

        inline auto implementation() const -> std::string const & final;

        inline auto implementation() -> std::string & final;

        inline auto operator==(abstraction const & other) const -> bool final;

        inline auto operator!=(abstraction const & other) const -> bool final;

        inline auto operator<(abstraction const & other) const -> bool final;

        inline auto operator<=(abstraction const & other) const -> bool final;

        inline auto operator>(abstraction const & other) const -> bool final;

        inline auto operator>=(abstraction const & other) const -> bool final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    static inline auto _make_(_Args && ... _args) -> abstraction_
    {
        return abstraction_{abstraction_::_derived::_static_shared_to_base(std::make_shared<abstraction_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> abstraction_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return abstraction_{};
        }
        return abstraction_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<abstraction_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> abstraction_
    {
        try
        {
            return abstraction_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return abstraction_{};
        }
    }

    inline auto _reproduce_() const -> abstraction_
    {
        try
        {
            return abstraction_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return abstraction_{};
        }
    }

    inline auto _weak_() const -> abstraction_
    {
        return abstraction_{strange::_common::_weak_base()};
    }

    inline auto _strong_() const -> abstraction_
    {
        return abstraction_{strange::_common::_shared->_strong()};
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<abstraction_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<abstraction_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = abstraction_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return abstraction_::_derived::_static_shared_to_base(std::make_shared<abstraction_::_instance>());
            });
        }
        return name;
    }();
};

}

namespace strange
{
namespace implementation
{
struct abstraction
{
    std::vector<strange::parameter> parameters_ {};
    inline auto parameters() const -> std::vector<strange::parameter> const & { return parameters_; };
    inline auto parameters() -> std::vector<strange::parameter> & { return parameters_; };
    std::string name_ {};
    inline auto name() const -> std::string const & { return name_; };
    inline auto name() -> std::string & { return name_; };
    std::vector<std::string> parents_ {};
    inline auto parents() const -> std::vector<std::string> const & { return parents_; };
    inline auto parents() -> std::vector<std::string> & { return parents_; };
    std::vector<strange::parameter> types_ {};
    inline auto types() const -> std::vector<strange::parameter> const & { return types_; };
    inline auto types() -> std::vector<strange::parameter> & { return types_; };
    std::vector<strange::operation> operations_ {};
    inline auto operations() const -> std::vector<strange::operation> const & { return operations_; };
    inline auto operations() -> std::vector<strange::operation> & { return operations_; };
    std::string thing_ {};
    inline auto thing() const -> std::string const & { return thing_; };
    inline auto thing() -> std::string & { return thing_; };
    std::string implementation_ {};
    inline auto implementation() const -> std::string const & { return implementation_; };
    inline auto implementation() -> std::string & { return implementation_; };

    inline auto pack(strange::bag & dest) const -> void
    {
        dest.from_object();
        {
            auto _array = dest.make_array();
            for (auto const & _item : parameters())
            {
                _array.push_back_array(dest.make_any(_item));
            }
            dest.insert_object("parameters", _array);
        }
        dest.insert_object("name", dest.make_string(name()));
        dest.insert_object("parents", dest.make_array_string(parents()));
        {
            auto _array = dest.make_array();
            for (auto const & _item : types())
            {
                _array.push_back_array(dest.make_any(_item));
            }
            dest.insert_object("types", _array);
        }
        {
            auto _array = dest.make_array();
            for (auto const & _item : operations())
            {
                _array.push_back_array(dest.make_any(_item));
            }
            dest.insert_object("operations", _array);
        }
        dest.insert_object("thing", dest.make_string(thing()));
        dest.insert_object("implementation", dest.make_string(implementation()));
    }

    inline auto unpack(strange::bag const & src) -> void
    {
        {
            auto _array = src.get_object("parameters").to_array();
            auto _size = _array.size();
            parameters().clear();
            parameters().resize(_size);
            for (std::size_t _index = 0; _index < _size; ++_index)
            {
                _array[_index].as_any(parameters()[_index]);
            }
        }
        src.get_object("name").as_string(name());
        src.get_object("parents").as_array_string(parents());
        {
            auto _array = src.get_object("types").to_array();
            auto _size = _array.size();
            types().clear();
            types().resize(_size);
            for (std::size_t _index = 0; _index < _size; ++_index)
            {
                _array[_index].as_any(types()[_index]);
            }
        }
        {
            auto _array = src.get_object("operations").to_array();
            auto _size = _array.size();
            operations().clear();
            operations().resize(_size);
            for (std::size_t _index = 0; _index < _size; ++_index)
            {
                _array[_index].as_any(operations()[_index]);
            }
        }
        src.get_object("thing").as_string(thing());
        src.get_object("implementation").as_string(implementation());
    }
};
}
}

namespace strange
{

struct space : stuff
{
    inline space() = default;

    inline space(space const & other)
    :strange::_common{other}
    ,stuff{}
    {
    }

    inline space(space && other)
    :strange::_common{std::move(other)}
    ,stuff{}
    {
    }

    inline auto operator=(space const & other) -> space &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(space && other) -> space &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline space(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,stuff{}
    {
    }

    explicit inline space(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,stuff{}
    {
    }

protected:
    struct _derived : stuff::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename space::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return stuff::_derived::_static_shared_to_base(derived);
        }

        virtual auto inclusions() const -> std::vector<strange::abstraction> const & = 0;

        virtual auto inclusions() -> std::vector<strange::abstraction> & = 0;

        virtual auto name() const -> std::string const & = 0;

        virtual auto name() -> std::string & = 0;

        virtual auto abstractions() const -> std::vector<strange::abstraction> const & = 0;

        virtual auto abstractions() -> std::vector<strange::abstraction> & = 0;

        virtual auto operator==(space const & other) const -> bool = 0;

        virtual auto operator!=(space const & other) const -> bool = 0;

        virtual auto operator<(space const & other) const -> bool = 0;

        virtual auto operator<=(space const & other) const -> bool = 0;

        virtual auto operator>(space const & other) const -> bool = 0;

        virtual auto operator>=(space const & other) const -> bool = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename space::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> space
    {
        try
        {
            return space{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return space{};
        }
    }

    inline auto _reproduce() const -> space
    {
        try
        {
            return space{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return space{};
        }
    }

    inline auto _weak() const -> space
    {
        return space{strange::_common::_weak_base()};
    }

    inline auto _strong() const -> space
    {
        return space{strange::_common::_shared->_strong()};
    }

    template<typename _Thing = strange::implementation::space, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> space
    {
        return space{space::_derived::_static_shared_to_base(std::make_shared<typename space_<_Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> space
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return space{};
        }
        return space{it->second()};
    }

    using _Abstraction_ = space;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(stuff::_cats_.cbegin(), stuff::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();

    inline auto pack(strange::bag & dest) const -> void;

    inline auto unpack(strange::bag const & src) -> void;

    inline auto inclusions() const -> std::vector<strange::abstraction> const &;

    inline auto inclusions() -> std::vector<strange::abstraction> &;

    inline auto name() const -> std::string const &;

    inline auto name() -> std::string &;

    inline auto abstractions() const -> std::vector<strange::abstraction> const &;

    inline auto abstractions() -> std::vector<strange::abstraction> &;

    inline auto operator==(space const & other) const -> bool;

    inline auto operator!=(space const & other) const -> bool;

    inline auto operator<(space const & other) const -> bool;

    inline auto operator<=(space const & other) const -> bool;

    inline auto operator>(space const & other) const -> bool;

    inline auto operator>=(space const & other) const -> bool;
};

template<typename _Thing, bool _Copy>
struct space_ : space
{
    inline space_() = default;

    inline space_(space_ const & other)
    :strange::_common{other}
    ,space{}
    {
    }

    inline space_(space_ && other)
    :strange::_common{std::move(other)}
    ,space{}
    {
    }

    inline auto operator=(space_ const & other) -> space_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(space_ && other) -> space_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline space_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,space{}
    {
    }

    explicit inline space_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,space{}
    {
    }

private:
    friend struct space;

    struct _instance final : space::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :space_::_derived{}
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
                return space_::_derived::_static_shared_to_base(std::make_shared<space_::_instance>(_thing));
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
                return space_::_derived::_static_shared_to_base(std::make_shared<space_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return space::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return space::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return space_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return space_::_name_;
        }

        inline auto pack(strange::bag & dest) const -> void final;

        inline auto unpack(strange::bag const & src) -> void final;

        inline auto inclusions() const -> std::vector<strange::abstraction> const & final;

        inline auto inclusions() -> std::vector<strange::abstraction> & final;

        inline auto name() const -> std::string const & final;

        inline auto name() -> std::string & final;

        inline auto abstractions() const -> std::vector<strange::abstraction> const & final;

        inline auto abstractions() -> std::vector<strange::abstraction> & final;

        inline auto operator==(space const & other) const -> bool final;

        inline auto operator!=(space const & other) const -> bool final;

        inline auto operator<(space const & other) const -> bool final;

        inline auto operator<=(space const & other) const -> bool final;

        inline auto operator>(space const & other) const -> bool final;

        inline auto operator>=(space const & other) const -> bool final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    static inline auto _make_(_Args && ... _args) -> space_
    {
        return space_{space_::_derived::_static_shared_to_base(std::make_shared<space_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> space_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return space_{};
        }
        return space_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<space_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> space_
    {
        try
        {
            return space_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return space_{};
        }
    }

    inline auto _reproduce_() const -> space_
    {
        try
        {
            return space_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return space_{};
        }
    }

    inline auto _weak_() const -> space_
    {
        return space_{strange::_common::_weak_base()};
    }

    inline auto _strong_() const -> space_
    {
        return space_{strange::_common::_shared->_strong()};
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<space_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<space_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = space_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return space_::_derived::_static_shared_to_base(std::make_shared<space_::_instance>());
            });
        }
        return name;
    }();
};

}

namespace strange
{
namespace implementation
{
struct space
{
    std::vector<strange::abstraction> inclusions_ {};
    inline auto inclusions() const -> std::vector<strange::abstraction> const & { return inclusions_; };
    inline auto inclusions() -> std::vector<strange::abstraction> & { return inclusions_; };
    std::string name_ {};
    inline auto name() const -> std::string const & { return name_; };
    inline auto name() -> std::string & { return name_; };
    std::vector<strange::abstraction> abstractions_ {};
    inline auto abstractions() const -> std::vector<strange::abstraction> const & { return abstractions_; };
    inline auto abstractions() -> std::vector<strange::abstraction> & { return abstractions_; };

    inline auto pack(strange::bag & dest) const -> void
    {
        dest.from_object();
        {
            auto _array = dest.make_array();
            for (auto const & _item : inclusions())
            {
                _array.push_back_array(dest.make_any(_item));
            }
            dest.insert_object("inclusions", _array);
        }
        dest.insert_object("name", dest.make_string(name()));
        {
            auto _array = dest.make_array();
            for (auto const & _item : abstractions())
            {
                _array.push_back_array(dest.make_any(_item));
            }
            dest.insert_object("abstractions", _array);
        }
    }

    inline auto unpack(strange::bag const & src) -> void
    {
        {
            auto _array = src.get_object("inclusions").to_array();
            auto _size = _array.size();
            inclusions().clear();
            inclusions().resize(_size);
            for (std::size_t _index = 0; _index < _size; ++_index)
            {
                _array[_index].as_any(inclusions()[_index]);
            }
        }
        src.get_object("name").as_string(name());
        {
            auto _array = src.get_object("abstractions").to_array();
            auto _size = _array.size();
            abstractions().clear();
            abstractions().resize(_size);
            for (std::size_t _index = 0; _index < _size; ++_index)
            {
                _array[_index].as_any(abstractions()[_index]);
            }
        }
    }
};
}
}

namespace strange
{

struct token : any
{
    inline token() = default;

    inline token(token const & other)
    :strange::_common{other}
    ,any{}
    {
    }

    inline token(token && other)
    :strange::_common{std::move(other)}
    ,any{}
    {
    }

    inline auto operator=(token const & other) -> token &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(token && other) -> token &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline token(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,any{}
    {
    }

    explicit inline token(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,any{}
    {
    }

protected:
    struct _derived : any::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<typename token::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return any::_derived::_static_shared_to_base(derived);
        }

        virtual auto filename() const -> std::string const & = 0;

        virtual auto filename() -> std::string & = 0;

        virtual auto line() const -> int64_t const & = 0;

        virtual auto line() -> int64_t & = 0;

        virtual auto position() const -> int64_t const & = 0;

        virtual auto position() -> int64_t & = 0;

        virtual auto classification() const -> strange::comprehension::cls const & = 0;

        virtual auto classification() -> strange::comprehension::cls & = 0;

        virtual auto text() const -> std::string const & = 0;

        virtual auto text() -> std::string & = 0;

        virtual auto operator==(token const & other) const -> bool = 0;

        virtual auto operator!=(token const & other) const -> bool = 0;

        virtual auto operator<(token const & other) const -> bool = 0;

        virtual auto operator<=(token const & other) const -> bool = 0;

        virtual auto operator>(token const & other) const -> bool = 0;

        virtual auto operator>=(token const & other) const -> bool = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename token::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> token
    {
        try
        {
            return token{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return token{};
        }
    }

    inline auto _reproduce() const -> token
    {
        try
        {
            return token{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return token{};
        }
    }

    inline auto _weak() const -> token
    {
        return token{strange::_common::_weak_base()};
    }

    inline auto _strong() const -> token
    {
        return token{strange::_common::_shared->_strong()};
    }

    template<typename _Thing = strange::implementation::token, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> token
    {
        return token{token::_derived::_static_shared_to_base(std::make_shared<typename token_<_Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> token
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return token{};
        }
        return token{it->second()};
    }

    using _Abstraction_ = token;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(any::_cats_.cbegin(), any::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();

    inline auto filename() const -> std::string const &;

    inline auto filename() -> std::string &;

    inline auto line() const -> int64_t const &;

    inline auto line() -> int64_t &;

    inline auto position() const -> int64_t const &;

    inline auto position() -> int64_t &;

    inline auto classification() const -> strange::comprehension::cls const &;

    inline auto classification() -> strange::comprehension::cls &;

    inline auto text() const -> std::string const &;

    inline auto text() -> std::string &;

    inline auto operator==(token const & other) const -> bool;

    inline auto operator!=(token const & other) const -> bool;

    inline auto operator<(token const & other) const -> bool;

    inline auto operator<=(token const & other) const -> bool;

    inline auto operator>(token const & other) const -> bool;

    inline auto operator>=(token const & other) const -> bool;
};

template<typename _Thing, bool _Copy>
struct token_ : token
{
    inline token_() = default;

    inline token_(token_ const & other)
    :strange::_common{other}
    ,token{}
    {
    }

    inline token_(token_ && other)
    :strange::_common{std::move(other)}
    ,token{}
    {
    }

    inline auto operator=(token_ const & other) -> token_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(token_ && other) -> token_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline token_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,token{}
    {
    }

    explicit inline token_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,token{}
    {
    }

private:
    friend struct token;

    struct _instance final : token::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :token_::_derived{}
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
                return token_::_derived::_static_shared_to_base(std::make_shared<token_::_instance>(_thing));
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
                return token_::_derived::_static_shared_to_base(std::make_shared<token_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
            }
        }

        inline auto _cat() const -> std::string final
        {
            return token::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return token::_cats_;
        }

        inline auto _copy() const -> bool final
        {
            return token_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return token_::_name_;
        }

        inline auto filename() const -> std::string const & final;

        inline auto filename() -> std::string & final;

        inline auto line() const -> int64_t const & final;

        inline auto line() -> int64_t & final;

        inline auto position() const -> int64_t const & final;

        inline auto position() -> int64_t & final;

        inline auto classification() const -> strange::comprehension::cls const & final;

        inline auto classification() -> strange::comprehension::cls & final;

        inline auto text() const -> std::string const & final;

        inline auto text() -> std::string & final;

        inline auto operator==(token const & other) const -> bool final;

        inline auto operator!=(token const & other) const -> bool final;

        inline auto operator<(token const & other) const -> bool final;

        inline auto operator<=(token const & other) const -> bool final;

        inline auto operator>(token const & other) const -> bool final;

        inline auto operator>=(token const & other) const -> bool final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    static inline auto _make_(_Args && ... _args) -> token_
    {
        return token_{token_::_derived::_static_shared_to_base(std::make_shared<token_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> token_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return token_{};
        }
        return token_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<token_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> token_
    {
        try
        {
            return token_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return token_{};
        }
    }

    inline auto _reproduce_() const -> token_
    {
        try
        {
            return token_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return token_{};
        }
    }

    inline auto _weak_() const -> token_
    {
        return token_{strange::_common::_weak_base()};
    }

    inline auto _strong_() const -> token_
    {
        return token_{strange::_common::_shared->_strong()};
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<token_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<token_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = token_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return token_::_derived::_static_shared_to_base(std::make_shared<token_::_instance>());
            });
        }
        return name;
    }();
};

}

namespace strange
{
namespace implementation
{
struct token
{
    std::string filename_ {};
    inline auto filename() const -> std::string const & { return filename_; };
    inline auto filename() -> std::string & { return filename_; };
    int64_t line_ {};
    inline auto line() const -> int64_t const & { return line_; };
    inline auto line() -> int64_t & { return line_; };
    int64_t position_ {};
    inline auto position() const -> int64_t const & { return position_; };
    inline auto position() -> int64_t & { return position_; };
    strange::comprehension::cls classification_ {};
    inline auto classification() const -> strange::comprehension::cls const & { return classification_; };
    inline auto classification() -> strange::comprehension::cls & { return classification_; };
    std::string text_ {};
    inline auto text() const -> std::string const & { return text_; };
    inline auto text() -> std::string & { return text_; };
};
}
}

namespace strange
{

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
        return std::dynamic_pointer_cast<typename forward_const_iterator::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> forward_const_iterator
    {
        try
        {
            return forward_const_iterator{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return forward_const_iterator{};
        }
    }

    inline auto _reproduce() const -> forward_const_iterator
    {
        try
        {
            return forward_const_iterator{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return forward_const_iterator{};
        }
    }

    inline auto _weak() const -> forward_const_iterator
    {
        return forward_const_iterator{strange::_common::_weak_base()};
    }

    inline auto _strong() const -> forward_const_iterator
    {
        return forward_const_iterator{strange::_common::_shared->_strong()};
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> forward_const_iterator
    {
        return forward_const_iterator{forward_const_iterator::_derived::_static_shared_to_base(std::make_shared<typename forward_const_iterator_<T, _Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> forward_const_iterator
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return forward_const_iterator{};
        }
        return forward_const_iterator{it->second()};
    }

    using _Abstraction_ = forward_const_iterator;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
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
                throw strange::_common::_no_copy{};
            }
        }

        inline auto _reproduce() const -> std::shared_ptr<strange::_common::_base> final
        {
            if constexpr (std::is_default_constructible_v<_Thing>)
            {
                return forward_const_iterator_::_derived::_static_shared_to_base(std::make_shared<forward_const_iterator_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
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

        inline auto _copy() const -> bool final
        {
            return forward_const_iterator_::_copy_;
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
    static inline auto _make_(_Args && ... _args) -> forward_const_iterator_
    {
        return forward_const_iterator_{forward_const_iterator_::_derived::_static_shared_to_base(std::make_shared<forward_const_iterator_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> forward_const_iterator_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return forward_const_iterator_{};
        }
        return forward_const_iterator_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<forward_const_iterator_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> forward_const_iterator_
    {
        try
        {
            return forward_const_iterator_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return forward_const_iterator_{};
        }
    }

    inline auto _reproduce_() const -> forward_const_iterator_
    {
        try
        {
            return forward_const_iterator_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return forward_const_iterator_{};
        }
    }

    inline auto _weak_() const -> forward_const_iterator_
    {
        return forward_const_iterator_{strange::_common::_weak_base()};
    }

    inline auto _strong_() const -> forward_const_iterator_
    {
        return forward_const_iterator_{strange::_common::_shared->_strong()};
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<forward_const_iterator_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<forward_const_iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = forward_const_iterator_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return forward_const_iterator_::_derived::_static_shared_to_base(std::make_shared<forward_const_iterator_::_instance>());
            });
        }
        return name;
    }();
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
        return std::dynamic_pointer_cast<typename forward_iterator::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> forward_iterator
    {
        try
        {
            return forward_iterator{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return forward_iterator{};
        }
    }

    inline auto _reproduce() const -> forward_iterator
    {
        try
        {
            return forward_iterator{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return forward_iterator{};
        }
    }

    inline auto _weak() const -> forward_iterator
    {
        return forward_iterator{strange::_common::_weak_base()};
    }

    inline auto _strong() const -> forward_iterator
    {
        return forward_iterator{strange::_common::_shared->_strong()};
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> forward_iterator
    {
        return forward_iterator{forward_iterator::_derived::_static_shared_to_base(std::make_shared<typename forward_iterator_<T, _Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> forward_iterator
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return forward_iterator{};
        }
        return forward_iterator{it->second()};
    }

    using _Abstraction_ = forward_iterator;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
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
                throw strange::_common::_no_copy{};
            }
        }

        inline auto _reproduce() const -> std::shared_ptr<strange::_common::_base> final
        {
            if constexpr (std::is_default_constructible_v<_Thing>)
            {
                return forward_iterator_::_derived::_static_shared_to_base(std::make_shared<forward_iterator_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
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

        inline auto _copy() const -> bool final
        {
            return forward_iterator_::_copy_;
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
    static inline auto _make_(_Args && ... _args) -> forward_iterator_
    {
        return forward_iterator_{forward_iterator_::_derived::_static_shared_to_base(std::make_shared<forward_iterator_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> forward_iterator_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return forward_iterator_{};
        }
        return forward_iterator_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<forward_iterator_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> forward_iterator_
    {
        try
        {
            return forward_iterator_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return forward_iterator_{};
        }
    }

    inline auto _reproduce_() const -> forward_iterator_
    {
        try
        {
            return forward_iterator_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return forward_iterator_{};
        }
    }

    inline auto _weak_() const -> forward_iterator_
    {
        return forward_iterator_{strange::_common::_weak_base()};
    }

    inline auto _strong_() const -> forward_iterator_
    {
        return forward_iterator_{strange::_common::_shared->_strong()};
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<forward_iterator_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<forward_iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = forward_iterator_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return forward_iterator_::_derived::_static_shared_to_base(std::make_shared<forward_iterator_::_instance>());
            });
        }
        return name;
    }();
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
        return std::dynamic_pointer_cast<typename bidirectional_const_iterator::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> bidirectional_const_iterator
    {
        try
        {
            return bidirectional_const_iterator{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return bidirectional_const_iterator{};
        }
    }

    inline auto _reproduce() const -> bidirectional_const_iterator
    {
        try
        {
            return bidirectional_const_iterator{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return bidirectional_const_iterator{};
        }
    }

    inline auto _weak() const -> bidirectional_const_iterator
    {
        return bidirectional_const_iterator{strange::_common::_weak_base()};
    }

    inline auto _strong() const -> bidirectional_const_iterator
    {
        return bidirectional_const_iterator{strange::_common::_shared->_strong()};
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> bidirectional_const_iterator
    {
        return bidirectional_const_iterator{bidirectional_const_iterator::_derived::_static_shared_to_base(std::make_shared<typename bidirectional_const_iterator_<T, _Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> bidirectional_const_iterator
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return bidirectional_const_iterator{};
        }
        return bidirectional_const_iterator{it->second()};
    }

    using _Abstraction_ = bidirectional_const_iterator;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
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
                throw strange::_common::_no_copy{};
            }
        }

        inline auto _reproduce() const -> std::shared_ptr<strange::_common::_base> final
        {
            if constexpr (std::is_default_constructible_v<_Thing>)
            {
                return bidirectional_const_iterator_::_derived::_static_shared_to_base(std::make_shared<bidirectional_const_iterator_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
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

        inline auto _copy() const -> bool final
        {
            return bidirectional_const_iterator_::_copy_;
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
    static inline auto _make_(_Args && ... _args) -> bidirectional_const_iterator_
    {
        return bidirectional_const_iterator_{bidirectional_const_iterator_::_derived::_static_shared_to_base(std::make_shared<bidirectional_const_iterator_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> bidirectional_const_iterator_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return bidirectional_const_iterator_{};
        }
        return bidirectional_const_iterator_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<bidirectional_const_iterator_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> bidirectional_const_iterator_
    {
        try
        {
            return bidirectional_const_iterator_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return bidirectional_const_iterator_{};
        }
    }

    inline auto _reproduce_() const -> bidirectional_const_iterator_
    {
        try
        {
            return bidirectional_const_iterator_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return bidirectional_const_iterator_{};
        }
    }

    inline auto _weak_() const -> bidirectional_const_iterator_
    {
        return bidirectional_const_iterator_{strange::_common::_weak_base()};
    }

    inline auto _strong_() const -> bidirectional_const_iterator_
    {
        return bidirectional_const_iterator_{strange::_common::_shared->_strong()};
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<bidirectional_const_iterator_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<bidirectional_const_iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = bidirectional_const_iterator_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return bidirectional_const_iterator_::_derived::_static_shared_to_base(std::make_shared<bidirectional_const_iterator_::_instance>());
            });
        }
        return name;
    }();
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
        return std::dynamic_pointer_cast<typename bidirectional_iterator::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> bidirectional_iterator
    {
        try
        {
            return bidirectional_iterator{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return bidirectional_iterator{};
        }
    }

    inline auto _reproduce() const -> bidirectional_iterator
    {
        try
        {
            return bidirectional_iterator{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return bidirectional_iterator{};
        }
    }

    inline auto _weak() const -> bidirectional_iterator
    {
        return bidirectional_iterator{strange::_common::_weak_base()};
    }

    inline auto _strong() const -> bidirectional_iterator
    {
        return bidirectional_iterator{strange::_common::_shared->_strong()};
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> bidirectional_iterator
    {
        return bidirectional_iterator{bidirectional_iterator::_derived::_static_shared_to_base(std::make_shared<typename bidirectional_iterator_<T, _Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> bidirectional_iterator
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return bidirectional_iterator{};
        }
        return bidirectional_iterator{it->second()};
    }

    using _Abstraction_ = bidirectional_iterator;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
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
                throw strange::_common::_no_copy{};
            }
        }

        inline auto _reproduce() const -> std::shared_ptr<strange::_common::_base> final
        {
            if constexpr (std::is_default_constructible_v<_Thing>)
            {
                return bidirectional_iterator_::_derived::_static_shared_to_base(std::make_shared<bidirectional_iterator_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
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

        inline auto _copy() const -> bool final
        {
            return bidirectional_iterator_::_copy_;
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
    static inline auto _make_(_Args && ... _args) -> bidirectional_iterator_
    {
        return bidirectional_iterator_{bidirectional_iterator_::_derived::_static_shared_to_base(std::make_shared<bidirectional_iterator_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> bidirectional_iterator_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return bidirectional_iterator_{};
        }
        return bidirectional_iterator_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<bidirectional_iterator_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> bidirectional_iterator_
    {
        try
        {
            return bidirectional_iterator_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return bidirectional_iterator_{};
        }
    }

    inline auto _reproduce_() const -> bidirectional_iterator_
    {
        try
        {
            return bidirectional_iterator_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return bidirectional_iterator_{};
        }
    }

    inline auto _weak_() const -> bidirectional_iterator_
    {
        return bidirectional_iterator_{strange::_common::_weak_base()};
    }

    inline auto _strong_() const -> bidirectional_iterator_
    {
        return bidirectional_iterator_{strange::_common::_shared->_strong()};
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<bidirectional_iterator_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<bidirectional_iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = bidirectional_iterator_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return bidirectional_iterator_::_derived::_static_shared_to_base(std::make_shared<bidirectional_iterator_::_instance>());
            });
        }
        return name;
    }();
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

        virtual auto operator-(random_access_const_iterator<T> const & other) const -> std::ptrdiff_t = 0;

        virtual auto operator[](std::ptrdiff_t n) const -> T const & = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename random_access_const_iterator::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> random_access_const_iterator
    {
        try
        {
            return random_access_const_iterator{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return random_access_const_iterator{};
        }
    }

    inline auto _reproduce() const -> random_access_const_iterator
    {
        try
        {
            return random_access_const_iterator{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return random_access_const_iterator{};
        }
    }

    inline auto _weak() const -> random_access_const_iterator
    {
        return random_access_const_iterator{strange::_common::_weak_base()};
    }

    inline auto _strong() const -> random_access_const_iterator
    {
        return random_access_const_iterator{strange::_common::_shared->_strong()};
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> random_access_const_iterator
    {
        return random_access_const_iterator{random_access_const_iterator::_derived::_static_shared_to_base(std::make_shared<typename random_access_const_iterator_<T, _Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> random_access_const_iterator
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return random_access_const_iterator{};
        }
        return random_access_const_iterator{it->second()};
    }

    using _Abstraction_ = random_access_const_iterator;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
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

    inline auto operator-(random_access_const_iterator<T> const & other) const -> std::ptrdiff_t;

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
                throw strange::_common::_no_copy{};
            }
        }

        inline auto _reproduce() const -> std::shared_ptr<strange::_common::_base> final
        {
            if constexpr (std::is_default_constructible_v<_Thing>)
            {
                return random_access_const_iterator_::_derived::_static_shared_to_base(std::make_shared<random_access_const_iterator_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
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

        inline auto _copy() const -> bool final
        {
            return random_access_const_iterator_::_copy_;
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

        inline auto operator-(random_access_const_iterator<T> const & other) const -> std::ptrdiff_t final;

        inline auto operator[](std::ptrdiff_t n) const -> T const & final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    static inline auto _make_(_Args && ... _args) -> random_access_const_iterator_
    {
        return random_access_const_iterator_{random_access_const_iterator_::_derived::_static_shared_to_base(std::make_shared<random_access_const_iterator_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> random_access_const_iterator_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return random_access_const_iterator_{};
        }
        return random_access_const_iterator_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<random_access_const_iterator_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> random_access_const_iterator_
    {
        try
        {
            return random_access_const_iterator_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return random_access_const_iterator_{};
        }
    }

    inline auto _reproduce_() const -> random_access_const_iterator_
    {
        try
        {
            return random_access_const_iterator_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return random_access_const_iterator_{};
        }
    }

    inline auto _weak_() const -> random_access_const_iterator_
    {
        return random_access_const_iterator_{strange::_common::_weak_base()};
    }

    inline auto _strong_() const -> random_access_const_iterator_
    {
        return random_access_const_iterator_{strange::_common::_shared->_strong()};
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<random_access_const_iterator_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<random_access_const_iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = random_access_const_iterator_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return random_access_const_iterator_::_derived::_static_shared_to_base(std::make_shared<random_access_const_iterator_::_instance>());
            });
        }
        return name;
    }();
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

        virtual auto operator-(random_access_iterator<T> const & other) const -> std::ptrdiff_t = 0;

        virtual auto operator[](std::ptrdiff_t n) -> T & = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<typename random_access_iterator::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> random_access_iterator
    {
        try
        {
            return random_access_iterator{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return random_access_iterator{};
        }
    }

    inline auto _reproduce() const -> random_access_iterator
    {
        try
        {
            return random_access_iterator{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return random_access_iterator{};
        }
    }

    inline auto _weak() const -> random_access_iterator
    {
        return random_access_iterator{strange::_common::_weak_base()};
    }

    inline auto _strong() const -> random_access_iterator
    {
        return random_access_iterator{strange::_common::_shared->_strong()};
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> random_access_iterator
    {
        return random_access_iterator{random_access_iterator::_derived::_static_shared_to_base(std::make_shared<typename random_access_iterator_<T, _Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> random_access_iterator
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return random_access_iterator{};
        }
        return random_access_iterator{it->second()};
    }

    using _Abstraction_ = random_access_iterator;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
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

    inline auto operator-(random_access_const_iterator<T> const & other) const -> std::ptrdiff_t;

    inline auto operator[](std::ptrdiff_t n) const -> T const &;

    inline auto operator==(random_access_iterator<T> const & other) const -> bool;

    inline auto operator!=(random_access_iterator<T> const & other) const -> bool;

    inline auto operator<(random_access_iterator<T> const & other) const -> bool;

    inline auto operator>(random_access_iterator<T> const & other) const -> bool;

    inline auto operator<=(random_access_iterator<T> const & other) const -> bool;

    inline auto operator>=(random_access_iterator<T> const & other) const -> bool;

    inline auto operator+(std::ptrdiff_t n) -> random_access_iterator<T>;

    inline auto operator-(std::ptrdiff_t n) -> random_access_iterator<T>;

    inline auto operator-(random_access_iterator<T> const & other) const -> std::ptrdiff_t;

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
                throw strange::_common::_no_copy{};
            }
        }

        inline auto _reproduce() const -> std::shared_ptr<strange::_common::_base> final
        {
            if constexpr (std::is_default_constructible_v<_Thing>)
            {
                return random_access_iterator_::_derived::_static_shared_to_base(std::make_shared<random_access_iterator_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
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

        inline auto _copy() const -> bool final
        {
            return random_access_iterator_::_copy_;
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

        inline auto operator-(random_access_const_iterator<T> const & other) const -> std::ptrdiff_t final;

        inline auto operator[](std::ptrdiff_t n) const -> T const & final;

        inline auto operator==(random_access_iterator<T> const & other) const -> bool final;

        inline auto operator!=(random_access_iterator<T> const & other) const -> bool final;

        inline auto operator<(random_access_iterator<T> const & other) const -> bool final;

        inline auto operator>(random_access_iterator<T> const & other) const -> bool final;

        inline auto operator<=(random_access_iterator<T> const & other) const -> bool final;

        inline auto operator>=(random_access_iterator<T> const & other) const -> bool final;

        inline auto operator+(std::ptrdiff_t n) -> random_access_iterator<T> final;

        inline auto operator-(std::ptrdiff_t n) -> random_access_iterator<T> final;

        inline auto operator-(random_access_iterator<T> const & other) const -> std::ptrdiff_t final;

        inline auto operator[](std::ptrdiff_t n) -> T & final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    static inline auto _make_(_Args && ... _args) -> random_access_iterator_
    {
        return random_access_iterator_{random_access_iterator_::_derived::_static_shared_to_base(std::make_shared<random_access_iterator_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> random_access_iterator_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return random_access_iterator_{};
        }
        return random_access_iterator_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<random_access_iterator_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> random_access_iterator_
    {
        try
        {
            return random_access_iterator_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return random_access_iterator_{};
        }
    }

    inline auto _reproduce_() const -> random_access_iterator_
    {
        try
        {
            return random_access_iterator_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return random_access_iterator_{};
        }
    }

    inline auto _weak_() const -> random_access_iterator_
    {
        return random_access_iterator_{strange::_common::_weak_base()};
    }

    inline auto _strong_() const -> random_access_iterator_
    {
        return random_access_iterator_{strange::_common::_shared->_strong()};
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<random_access_iterator_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<random_access_iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = random_access_iterator_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return random_access_iterator_::_derived::_static_shared_to_base(std::make_shared<random_access_iterator_::_instance>());
            });
        }
        return name;
    }();
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

        virtual auto assign(std::size_t count, T const & value) -> void = 0;

        virtual auto assign(typename strange::forward_const_iterator<T> first, typename strange::forward_const_iterator<T> last) -> void = 0;

        virtual auto assign(std::initializer_list<T> ilist) -> void = 0;

        virtual auto at(std::size_t pos) -> T & = 0;

        virtual auto at(std::size_t pos) const -> T const & = 0;

        virtual auto operator[](std::size_t pos) -> T & = 0;

        virtual auto operator[](std::size_t pos) const -> T const & = 0;

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

        virtual auto size() const -> std::size_t = 0;

        virtual auto max_size() const -> std::size_t = 0;

        virtual auto reserve(std::size_t new_cap) -> void = 0;

        virtual auto capacity() const -> std::size_t = 0;

        virtual auto shrink_to_fit() -> void = 0;

        virtual auto clear() -> void = 0;

        virtual auto insert(typename strange::random_access_const_iterator<T> pos, T const & value) -> typename strange::random_access_iterator<T> = 0;

        virtual auto insert(typename strange::random_access_const_iterator<T> pos, T && value) -> typename strange::random_access_iterator<T> = 0;

        virtual auto insert(typename strange::random_access_const_iterator<T> pos, std::size_t count, T const & value) -> typename strange::random_access_iterator<T> = 0;

        virtual auto insert(typename strange::random_access_const_iterator<T> pos, forward_const_iterator<T> first, forward_const_iterator<T> last) -> typename strange::random_access_iterator<T> = 0;

        virtual auto insert(typename strange::random_access_const_iterator<T> pos, std::initializer_list<T> ilist) -> typename strange::random_access_iterator<T> = 0;

        virtual auto erase(typename strange::random_access_const_iterator<T> pos) -> typename strange::random_access_iterator<T> = 0;

        virtual auto erase(typename strange::random_access_const_iterator<T> first, typename strange::random_access_const_iterator<T> last) -> typename strange::random_access_iterator<T> = 0;

        virtual auto push_back(T const & value) -> void = 0;

        virtual auto push_back(T && value) -> void = 0;

        virtual auto pop_back() -> void = 0;

        virtual auto resize(std::size_t count) -> void = 0;

        virtual auto resize(std::size_t count, T const & value) -> void = 0;

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
        return std::dynamic_pointer_cast<typename vector::_derived const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone() const -> vector
    {
        try
        {
            return vector{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return vector{};
        }
    }

    inline auto _reproduce() const -> vector
    {
        try
        {
            return vector{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return vector{};
        }
    }

    inline auto _weak() const -> vector
    {
        return vector{strange::_common::_weak_base()};
    }

    inline auto _strong() const -> vector
    {
        return vector{strange::_common::_shared->_strong()};
    }

    template<typename _Thing = std::vector<T>, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    static inline auto _make(_Args && ... _args) -> vector
    {
        return vector{vector::_derived::_static_shared_to_base(std::make_shared<typename vector_<T, _Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture(std::string const & name) -> vector
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return vector{};
        }
        return vector{it->second()};
    }

    using _Abstraction_ = vector;

    static inline std::string const _cat_ = strange::reflection<_Abstraction_>::name();

    static inline std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(any::_cats_.cbegin(), any::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();

    inline auto operator=(std::initializer_list<T> ilist) -> vector &;

    inline auto assign(std::size_t count, T const & value) -> void;

    inline auto assign(typename strange::forward_const_iterator<T> first, typename strange::forward_const_iterator<T> last) -> void;

    inline auto assign(std::initializer_list<T> ilist) -> void;

    inline auto at(std::size_t pos) -> T &;

    inline auto at(std::size_t pos) const -> T const &;

    inline auto operator[](std::size_t pos) -> T &;

    inline auto operator[](std::size_t pos) const -> T const &;

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

    inline auto size() const -> std::size_t;

    inline auto max_size() const -> std::size_t;

    inline auto reserve(std::size_t new_cap) -> void;

    inline auto capacity() const -> std::size_t;

    inline auto shrink_to_fit() -> void;

    inline auto clear() -> void;

    inline auto insert(typename strange::random_access_const_iterator<T> pos, T const & value) -> typename strange::random_access_iterator<T>;

    inline auto insert(typename strange::random_access_const_iterator<T> pos, T && value) -> typename strange::random_access_iterator<T>;

    inline auto insert(typename strange::random_access_const_iterator<T> pos, std::size_t count, T const & value) -> typename strange::random_access_iterator<T>;

    inline auto insert(typename strange::random_access_const_iterator<T> pos, forward_const_iterator<T> first, forward_const_iterator<T> last) -> typename strange::random_access_iterator<T>;

    inline auto insert(typename strange::random_access_const_iterator<T> pos, std::initializer_list<T> ilist) -> typename strange::random_access_iterator<T>;

    inline auto erase(typename strange::random_access_const_iterator<T> pos) -> typename strange::random_access_iterator<T>;

    inline auto erase(typename strange::random_access_const_iterator<T> first, typename strange::random_access_const_iterator<T> last) -> typename strange::random_access_iterator<T>;

    inline auto push_back(T const & value) -> void;

    inline auto push_back(T && value) -> void;

    inline auto pop_back() -> void;

    inline auto resize(std::size_t count) -> void;

    inline auto resize(std::size_t count, T const & value) -> void;

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
                throw strange::_common::_no_copy{};
            }
        }

        inline auto _reproduce() const -> std::shared_ptr<strange::_common::_base> final
        {
            if constexpr (std::is_default_constructible_v<_Thing>)
            {
                return vector_::_derived::_static_shared_to_base(std::make_shared<vector_::_instance>());
            }
            else
            {
                throw strange::_common::_no_default{};
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

        inline auto _copy() const -> bool final
        {
            return vector_::_copy_;
        }

        inline auto _name() const -> std::string final
        {
            return vector_::_name_;
        }

        inline auto operator=(std::initializer_list<T> ilist) -> void final;

        inline auto assign(std::size_t count, T const & value) -> void final;

        inline auto assign(typename strange::forward_const_iterator<T> first, typename strange::forward_const_iterator<T> last) -> void final;

        inline auto assign(std::initializer_list<T> ilist) -> void final;

        inline auto at(std::size_t pos) -> T & final;

        inline auto at(std::size_t pos) const -> T const & final;

        inline auto operator[](std::size_t pos) -> T & final;

        inline auto operator[](std::size_t pos) const -> T const & final;

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

        inline auto size() const -> std::size_t final;

        inline auto max_size() const -> std::size_t final;

        inline auto reserve(std::size_t new_cap) -> void final;

        inline auto capacity() const -> std::size_t final;

        inline auto shrink_to_fit() -> void final;

        inline auto clear() -> void final;

        inline auto insert(typename strange::random_access_const_iterator<T> pos, T const & value) -> typename strange::random_access_iterator<T> final;

        inline auto insert(typename strange::random_access_const_iterator<T> pos, T && value) -> typename strange::random_access_iterator<T> final;

        inline auto insert(typename strange::random_access_const_iterator<T> pos, std::size_t count, T const & value) -> typename strange::random_access_iterator<T> final;

        inline auto insert(typename strange::random_access_const_iterator<T> pos, forward_const_iterator<T> first, forward_const_iterator<T> last) -> typename strange::random_access_iterator<T> final;

        inline auto insert(typename strange::random_access_const_iterator<T> pos, std::initializer_list<T> ilist) -> typename strange::random_access_iterator<T> final;

        inline auto erase(typename strange::random_access_const_iterator<T> pos) -> typename strange::random_access_iterator<T> final;

        inline auto erase(typename strange::random_access_const_iterator<T> first, typename strange::random_access_const_iterator<T> last) -> typename strange::random_access_iterator<T> final;

        inline auto push_back(T const & value) -> void final;

        inline auto push_back(T && value) -> void final;

        inline auto pop_back() -> void final;

        inline auto resize(std::size_t count) -> void final;

        inline auto resize(std::size_t count, T const & value) -> void final;

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
    static inline auto _make_(_Args && ... _args) -> vector_
    {
        return vector_{vector_::_derived::_static_shared_to_base(std::make_shared<vector_::_instance>(std::forward<_Args>(_args) ...))};
    }

    static inline auto _manufacture_(std::string const & name) -> vector_
    {
        auto it = strange::_common::_factory_.find(name);
        if (it == strange::_common::_factory_.end())
        {
            return vector_{};
        }
        return vector_{it->second()};
    }

    inline auto _valid_() const -> bool
    {
        return std::dynamic_pointer_cast<vector_::_instance const>(strange::_common::_shared).operator bool();
    }

    inline auto _clone_() const -> vector_
    {
        try
        {
            return vector_{strange::_common::_shared->_clone()};
        }
        catch(strange::_common::_no_copy const &)
        {
            return vector_{};
        }
    }

    inline auto _reproduce_() const -> vector_
    {
        try
        {
            return vector_{strange::_common::_shared->_reproduce()};
        }
        catch(strange::_common::_no_default const &)
        {
            return vector_{};
        }
    }

    inline auto _weak_() const -> vector_
    {
        return vector_{strange::_common::_weak_base()};
    }

    inline auto _strong_() const -> vector_
    {
        return vector_{strange::_common::_shared->_strong()};
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<vector_::_instance const>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<vector_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Kind_ = vector_;
    using _Thing_ = _Thing;

    static inline bool const _copy_ = _Copy;

    static inline std::string const _name_ = []()
    {
        auto const name = strange::reflection<_Kind_>::name();
        if constexpr (std::is_default_constructible_v<_Thing>)
        {
            strange::_common::_factory_.emplace(name, []()
            {
                return vector_::_derived::_static_shared_to_base(std::make_shared<vector_::_instance>());
            });
        }
        return name;
    }();
};

inline auto stuff::pack(strange::bag & dest) const -> void
{
    std::dynamic_pointer_cast<typename stuff::_derived const>(strange::_common::_shared)->pack(dest);
}

inline auto stuff::unpack(strange::bag const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename stuff::_derived>(strange::_common::_shared)->unpack(src);
}

template<typename _Thing, bool _Copy>
inline auto stuff_<_Thing, _Copy>::_instance::pack(strange::bag & dest) const -> void
{
    _thing.pack(dest);
}

template<typename _Thing, bool _Copy>
inline auto stuff_<_Thing, _Copy>::_instance::unpack(strange::bag const & src) -> void
{
    _thing.unpack(src);
}

inline auto bag::pack(strange::bag & dest) const -> void
{
    std::dynamic_pointer_cast<typename stuff::_derived const>(strange::_common::_shared)->pack(dest);
}

inline auto bag::unpack(strange::bag const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename stuff::_derived>(strange::_common::_shared)->unpack(src);
}

inline auto bag::is_null() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->is_null();
}

inline auto bag::from_null() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_null();
}

inline auto bag::make_null() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_null();
}

inline auto bag::is_bool() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->is_bool();
}

inline auto bag::as_bool(bool & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_bool(dest);
}

inline auto bag::to_bool() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_bool();
}

inline auto bag::from_bool() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_bool();
}

inline auto bag::from_bool(bool src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_bool(src);
}

inline auto bag::make_bool() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_bool();
}

inline auto bag::make_bool(bool src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_bool(src);
}

inline auto bag::is_int64() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->is_int64();
}

inline auto bag::as_int64(int64_t & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_int64(dest);
}

inline auto bag::to_int64() const -> int64_t
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_int64();
}

inline auto bag::from_int64() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_int64();
}

inline auto bag::from_int64(int64_t src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_int64(src);
}

inline auto bag::make_int64() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_int64();
}

inline auto bag::make_int64(int64_t src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_int64(src);
}

inline auto bag::is_uint64() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->is_uint64();
}

inline auto bag::as_uint64(uint64_t & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_uint64(dest);
}

inline auto bag::to_uint64() const -> uint64_t
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_uint64();
}

inline auto bag::from_uint64() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_uint64();
}

inline auto bag::from_uint64(uint64_t src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_uint64(src);
}

inline auto bag::make_uint64() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_uint64();
}

inline auto bag::make_uint64(uint64_t src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_uint64(src);
}

inline auto bag::is_double() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->is_double();
}

inline auto bag::as_double(double & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_double(dest);
}

inline auto bag::to_double() const -> double
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_double();
}

inline auto bag::from_double() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_double();
}

inline auto bag::from_double(double src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_double(src);
}

inline auto bag::make_double() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_double();
}

inline auto bag::make_double(double src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_double(src);
}

inline auto bag::is_string() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->is_string();
}

inline auto bag::as_string(std::string & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_string(dest);
}

inline auto bag::to_string() const -> std::string
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_string();
}

inline auto bag::from_string() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_string();
}

inline auto bag::from_string(std::string const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_string(src);
}

inline auto bag::make_string() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_string();
}

inline auto bag::make_string(std::string const & src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_string(src);
}

inline auto bag::is_array() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->is_array();
}

inline auto bag::as_array(std::vector<bag> & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_array(dest);
}

inline auto bag::to_array() const -> std::vector<bag>
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_array();
}

inline auto bag::from_array() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_array();
}

inline auto bag::from_array(std::vector<bag> const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_array(src);
}

inline auto bag::make_array() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_array();
}

inline auto bag::make_array(std::vector<bag> const & src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_array(src);
}

inline auto bag::get_array(std::size_t index) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->get_array(index);
}

inline auto bag::set_array(std::size_t index, bag const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->set_array(index, value);
}

inline auto bag::front_array() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->front_array();
}

inline auto bag::back_array() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->back_array();
}

inline auto bag::empty_array() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->empty_array();
}

inline auto bag::size_array() const -> std::size_t
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->size_array();
}

inline auto bag::reserve_array(std::size_t new_cap) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->reserve_array(new_cap);
}

inline auto bag::capacity_array() const -> std::size_t
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->capacity_array();
}

inline auto bag::clear_array() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->clear_array();
}

inline auto bag::insert_array(std::size_t pos, bag const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->insert_array(pos, value);
}

inline auto bag::erase_array(std::size_t pos) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->erase_array(pos);
}

inline auto bag::push_front_array(bag const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->push_front_array(value);
}

inline auto bag::push_back_array(bag const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->push_back_array(value);
}

inline auto bag::pop_front_array() -> bag
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->pop_front_array();
}

inline auto bag::pop_back_array() -> bag
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->pop_back_array();
}

inline auto bag::resize_array(std::size_t count) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->resize_array(count);
}

inline auto bag::as_array_bool(std::vector<bool> & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_array_bool(dest);
}

inline auto bag::as_array_int64(std::vector<int64_t> & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_array_int64(dest);
}

inline auto bag::as_array_uint64(std::vector<uint64_t> & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_array_uint64(dest);
}

inline auto bag::as_array_double(std::vector<double> & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_array_double(dest);
}

inline auto bag::as_array_string(std::vector<std::string> & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_array_string(dest);
}

inline auto bag::as_array_any(std::vector<strange::any> & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_array_any(dest);
}

inline auto bag::to_array_bool() const -> std::vector<bool>
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_array_bool();
}

inline auto bag::to_array_int64() const -> std::vector<int64_t>
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_array_int64();
}

inline auto bag::to_array_uint64() const -> std::vector<uint64_t>
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_array_uint64();
}

inline auto bag::to_array_double() const -> std::vector<double>
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_array_double();
}

inline auto bag::to_array_string() const -> std::vector<std::string>
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_array_string();
}

inline auto bag::to_array_any() const -> std::vector<strange::any>
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_array_any();
}

inline auto bag::from_array_bool(std::vector<bool> const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_array_bool(src);
}

inline auto bag::from_array_int64(std::vector<int64_t> const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_array_int64(src);
}

inline auto bag::from_array_uint64(std::vector<uint64_t> const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_array_uint64(src);
}

inline auto bag::from_array_double(std::vector<double> const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_array_double(src);
}

inline auto bag::from_array_string(std::vector<std::string> const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_array_string(src);
}

inline auto bag::from_array_any(std::vector<strange::any> const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_array_any(src);
}

inline auto bag::make_array_bool(std::vector<bool> const & src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_array_bool(src);
}

inline auto bag::make_array_int64(std::vector<int64_t> const & src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_array_int64(src);
}

inline auto bag::make_array_uint64(std::vector<uint64_t> const & src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_array_uint64(src);
}

inline auto bag::make_array_double(std::vector<double> const & src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_array_double(src);
}

inline auto bag::make_array_string(std::vector<std::string> const & src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_array_string(src);
}

inline auto bag::make_array_any(std::vector<strange::any> const & src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_array_any(src);
}

inline auto bag::is_object() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->is_object();
}

inline auto bag::as_object(std::unordered_map<std::string, bag> & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_object(dest);
}

inline auto bag::to_object() const -> std::unordered_map<std::string, bag>
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_object();
}

inline auto bag::from_object() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_object();
}

inline auto bag::from_object(std::unordered_map<std::string, bag> const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_object(src);
}

inline auto bag::make_object() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_object();
}

inline auto bag::make_object(std::unordered_map<std::string, bag> const & src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_object(src);
}

inline auto bag::empty_object() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->empty_object();
}

inline auto bag::size_object() const -> std::size_t
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->size_object();
}

inline auto bag::clear_object() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->clear_object();
}

inline auto bag::insert_object(std::string const & key, bag const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->insert_object(key, value);
}

inline auto bag::erase_object(std::string const & key) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->erase_object(key);
}

inline auto bag::get_object(std::string const & key) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->get_object(key);
}

inline auto bag::set_object(std::string const & key, bag const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->set_object(key, value);
}

inline auto bag::contains_object(std::string const & key) const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->contains_object(key);
}

inline auto bag::is_any() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->is_any();
}

inline auto bag::as_any(strange::any & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_any(dest);
}

inline auto bag::to_any() const -> strange::any
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_any();
}

inline auto bag::from_any() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_any();
}

inline auto bag::from_any(strange::any const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_any(src);
}

inline auto bag::make_any() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_any();
}

inline auto bag::make_any(strange::any const & src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_any(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::pack(strange::bag & dest) const -> void
{
    _thing.pack(dest);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::unpack(strange::bag const & src) -> void
{
    _thing.unpack(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::is_null() const -> bool
{
    return _thing.is_null();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_null() -> void
{
    _thing.from_null();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_null() const -> bag
{
    return _thing.make_null();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::is_bool() const -> bool
{
    return _thing.is_bool();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::as_bool(bool & dest) const -> void
{
    _thing.as_bool(dest);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::to_bool() const -> bool
{
    return _thing.to_bool();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_bool() -> void
{
    _thing.from_bool();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_bool(bool src) -> void
{
    _thing.from_bool(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_bool() const -> bag
{
    return _thing.make_bool();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_bool(bool src) const -> bag
{
    return _thing.make_bool(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::is_int64() const -> bool
{
    return _thing.is_int64();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::as_int64(int64_t & dest) const -> void
{
    _thing.as_int64(dest);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::to_int64() const -> int64_t
{
    return _thing.to_int64();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_int64() -> void
{
    _thing.from_int64();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_int64(int64_t src) -> void
{
    _thing.from_int64(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_int64() const -> bag
{
    return _thing.make_int64();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_int64(int64_t src) const -> bag
{
    return _thing.make_int64(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::is_uint64() const -> bool
{
    return _thing.is_uint64();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::as_uint64(uint64_t & dest) const -> void
{
    _thing.as_uint64(dest);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::to_uint64() const -> uint64_t
{
    return _thing.to_uint64();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_uint64() -> void
{
    _thing.from_uint64();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_uint64(uint64_t src) -> void
{
    _thing.from_uint64(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_uint64() const -> bag
{
    return _thing.make_uint64();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_uint64(uint64_t src) const -> bag
{
    return _thing.make_uint64(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::is_double() const -> bool
{
    return _thing.is_double();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::as_double(double & dest) const -> void
{
    _thing.as_double(dest);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::to_double() const -> double
{
    return _thing.to_double();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_double() -> void
{
    _thing.from_double();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_double(double src) -> void
{
    _thing.from_double(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_double() const -> bag
{
    return _thing.make_double();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_double(double src) const -> bag
{
    return _thing.make_double(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::is_string() const -> bool
{
    return _thing.is_string();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::as_string(std::string & dest) const -> void
{
    _thing.as_string(dest);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::to_string() const -> std::string
{
    return _thing.to_string();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_string() -> void
{
    _thing.from_string();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_string(std::string const & src) -> void
{
    _thing.from_string(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_string() const -> bag
{
    return _thing.make_string();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_string(std::string const & src) const -> bag
{
    return _thing.make_string(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::is_array() const -> bool
{
    return _thing.is_array();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::as_array(std::vector<bag> & dest) const -> void
{
    _thing.as_array(dest);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::to_array() const -> std::vector<bag>
{
    return _thing.to_array();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_array() -> void
{
    _thing.from_array();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_array(std::vector<bag> const & src) -> void
{
    _thing.from_array(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_array() const -> bag
{
    return _thing.make_array();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_array(std::vector<bag> const & src) const -> bag
{
    return _thing.make_array(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::get_array(std::size_t index) const -> bag
{
    return _thing.get_array(index);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::set_array(std::size_t index, bag const & value) -> void
{
    _thing.set_array(index, value);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::front_array() const -> bag
{
    return _thing.front_array();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::back_array() const -> bag
{
    return _thing.back_array();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::empty_array() const -> bool
{
    return _thing.empty_array();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::size_array() const -> std::size_t
{
    return _thing.size_array();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::reserve_array(std::size_t new_cap) -> void
{
    _thing.reserve_array(new_cap);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::capacity_array() const -> std::size_t
{
    return _thing.capacity_array();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::clear_array() -> void
{
    _thing.clear_array();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::insert_array(std::size_t pos, bag const & value) -> void
{
    _thing.insert_array(pos, value);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::erase_array(std::size_t pos) -> void
{
    _thing.erase_array(pos);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::push_front_array(bag const & value) -> void
{
    _thing.push_front_array(value);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::push_back_array(bag const & value) -> void
{
    _thing.push_back_array(value);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::pop_front_array() -> bag
{
    return _thing.pop_front_array();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::pop_back_array() -> bag
{
    return _thing.pop_back_array();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::resize_array(std::size_t count) -> void
{
    _thing.resize_array(count);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::as_array_bool(std::vector<bool> & dest) const -> void
{
    _thing.as_array_bool(dest);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::as_array_int64(std::vector<int64_t> & dest) const -> void
{
    _thing.as_array_int64(dest);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::as_array_uint64(std::vector<uint64_t> & dest) const -> void
{
    _thing.as_array_uint64(dest);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::as_array_double(std::vector<double> & dest) const -> void
{
    _thing.as_array_double(dest);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::as_array_string(std::vector<std::string> & dest) const -> void
{
    _thing.as_array_string(dest);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::as_array_any(std::vector<strange::any> & dest) const -> void
{
    _thing.as_array_any(dest);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::to_array_bool() const -> std::vector<bool>
{
    return _thing.to_array_bool();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::to_array_int64() const -> std::vector<int64_t>
{
    return _thing.to_array_int64();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::to_array_uint64() const -> std::vector<uint64_t>
{
    return _thing.to_array_uint64();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::to_array_double() const -> std::vector<double>
{
    return _thing.to_array_double();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::to_array_string() const -> std::vector<std::string>
{
    return _thing.to_array_string();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::to_array_any() const -> std::vector<strange::any>
{
    return _thing.to_array_any();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_array_bool(std::vector<bool> const & src) -> void
{
    _thing.from_array_bool(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_array_int64(std::vector<int64_t> const & src) -> void
{
    _thing.from_array_int64(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_array_uint64(std::vector<uint64_t> const & src) -> void
{
    _thing.from_array_uint64(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_array_double(std::vector<double> const & src) -> void
{
    _thing.from_array_double(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_array_string(std::vector<std::string> const & src) -> void
{
    _thing.from_array_string(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_array_any(std::vector<strange::any> const & src) -> void
{
    _thing.from_array_any(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_array_bool(std::vector<bool> const & src) const -> bag
{
    return _thing.make_array_bool(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_array_int64(std::vector<int64_t> const & src) const -> bag
{
    return _thing.make_array_int64(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_array_uint64(std::vector<uint64_t> const & src) const -> bag
{
    return _thing.make_array_uint64(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_array_double(std::vector<double> const & src) const -> bag
{
    return _thing.make_array_double(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_array_string(std::vector<std::string> const & src) const -> bag
{
    return _thing.make_array_string(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_array_any(std::vector<strange::any> const & src) const -> bag
{
    return _thing.make_array_any(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::is_object() const -> bool
{
    return _thing.is_object();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::as_object(std::unordered_map<std::string, bag> & dest) const -> void
{
    _thing.as_object(dest);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::to_object() const -> std::unordered_map<std::string, bag>
{
    return _thing.to_object();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_object() -> void
{
    _thing.from_object();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_object(std::unordered_map<std::string, bag> const & src) -> void
{
    _thing.from_object(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_object() const -> bag
{
    return _thing.make_object();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_object(std::unordered_map<std::string, bag> const & src) const -> bag
{
    return _thing.make_object(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::empty_object() const -> bool
{
    return _thing.empty_object();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::size_object() const -> std::size_t
{
    return _thing.size_object();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::clear_object() -> void
{
    _thing.clear_object();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::insert_object(std::string const & key, bag const & value) -> void
{
    _thing.insert_object(key, value);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::erase_object(std::string const & key) -> void
{
    _thing.erase_object(key);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::get_object(std::string const & key) const -> bag
{
    return _thing.get_object(key);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::set_object(std::string const & key, bag const & value) -> void
{
    _thing.set_object(key, value);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::contains_object(std::string const & key) const -> bool
{
    return _thing.contains_object(key);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::is_any() const -> bool
{
    return _thing.is_any();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::as_any(strange::any & dest) const -> void
{
    _thing.as_any(dest);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::to_any() const -> strange::any
{
    return _thing.to_any();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_any() -> void
{
    _thing.from_any();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::from_any(strange::any const & src) -> void
{
    _thing.from_any(src);
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_any() const -> bag
{
    return _thing.make_any();
}

template<typename _Thing, bool _Copy>
inline auto bag_<_Thing, _Copy>::_instance::make_any(strange::any const & src) const -> bag
{
    return _thing.make_any(src);
}

inline auto package::pack(strange::bag & dest) const -> void
{
    std::dynamic_pointer_cast<typename stuff::_derived const>(strange::_common::_shared)->pack(dest);
}

inline auto package::unpack(strange::bag const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename stuff::_derived>(strange::_common::_shared)->unpack(src);
}

inline auto package::seal() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename package::_derived>(strange::_common::_shared)->seal();
}

inline auto package::unseal() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename package::_derived>(strange::_common::_shared)->unseal();
}

inline auto package::sealed() const -> bool
{
    return std::dynamic_pointer_cast<typename package::_derived const>(strange::_common::_shared)->sealed();
}

inline auto package::is_binary() const -> bool
{
    return std::dynamic_pointer_cast<typename package::_derived const>(strange::_common::_shared)->is_binary();
}

inline auto package::as_binary(std::string & binary) const -> void
{
    std::dynamic_pointer_cast<typename package::_derived const>(strange::_common::_shared)->as_binary(binary);
}

inline auto package::to_binary() const -> std::string
{
    return std::dynamic_pointer_cast<typename package::_derived const>(strange::_common::_shared)->to_binary();
}

inline auto package::from_binary(std::string const & binary) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename package::_derived>(strange::_common::_shared)->from_binary(binary);
}

inline auto package::make_binary(std::string const & binary) const -> package
{
    return std::dynamic_pointer_cast<typename package::_derived const>(strange::_common::_shared)->make_binary(binary);
}

inline auto package::is_json() const -> bool
{
    return std::dynamic_pointer_cast<typename package::_derived const>(strange::_common::_shared)->is_json();
}

inline auto package::as_json(std::string & json) const -> void
{
    std::dynamic_pointer_cast<typename package::_derived const>(strange::_common::_shared)->as_json(json);
}

inline auto package::to_json() const -> std::string
{
    return std::dynamic_pointer_cast<typename package::_derived const>(strange::_common::_shared)->to_json();
}

inline auto package::from_json(std::string const & json) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename package::_derived>(strange::_common::_shared)->from_json(json);
}

inline auto package::make_json(std::string const & json) const -> package
{
    return std::dynamic_pointer_cast<typename package::_derived const>(strange::_common::_shared)->make_json(json);
}

template<typename _Thing, bool _Copy>
inline auto package_<_Thing, _Copy>::_instance::pack(strange::bag & dest) const -> void
{
    _thing.pack(dest);
}

template<typename _Thing, bool _Copy>
inline auto package_<_Thing, _Copy>::_instance::unpack(strange::bag const & src) -> void
{
    _thing.unpack(src);
}

template<typename _Thing, bool _Copy>
inline auto package_<_Thing, _Copy>::_instance::seal() -> void
{
    _thing.seal();
}

template<typename _Thing, bool _Copy>
inline auto package_<_Thing, _Copy>::_instance::unseal() -> void
{
    _thing.unseal();
}

template<typename _Thing, bool _Copy>
inline auto package_<_Thing, _Copy>::_instance::sealed() const -> bool
{
    return _thing.sealed();
}

template<typename _Thing, bool _Copy>
inline auto package_<_Thing, _Copy>::_instance::is_binary() const -> bool
{
    return _thing.is_binary();
}

template<typename _Thing, bool _Copy>
inline auto package_<_Thing, _Copy>::_instance::as_binary(std::string & binary) const -> void
{
    _thing.as_binary(binary);
}

template<typename _Thing, bool _Copy>
inline auto package_<_Thing, _Copy>::_instance::to_binary() const -> std::string
{
    return _thing.to_binary();
}

template<typename _Thing, bool _Copy>
inline auto package_<_Thing, _Copy>::_instance::from_binary(std::string const & binary) -> void
{
    _thing.from_binary(binary);
}

template<typename _Thing, bool _Copy>
inline auto package_<_Thing, _Copy>::_instance::make_binary(std::string const & binary) const -> package
{
    return _thing.make_binary(binary);
}

template<typename _Thing, bool _Copy>
inline auto package_<_Thing, _Copy>::_instance::is_json() const -> bool
{
    return _thing.is_json();
}

template<typename _Thing, bool _Copy>
inline auto package_<_Thing, _Copy>::_instance::as_json(std::string & json) const -> void
{
    _thing.as_json(json);
}

template<typename _Thing, bool _Copy>
inline auto package_<_Thing, _Copy>::_instance::to_json() const -> std::string
{
    return _thing.to_json();
}

template<typename _Thing, bool _Copy>
inline auto package_<_Thing, _Copy>::_instance::from_json(std::string const & json) -> void
{
    _thing.from_json(json);
}

template<typename _Thing, bool _Copy>
inline auto package_<_Thing, _Copy>::_instance::make_json(std::string const & json) const -> package
{
    return _thing.make_json(json);
}

inline auto baggage::pack(strange::bag & dest) const -> void
{
    std::dynamic_pointer_cast<typename stuff::_derived const>(strange::_common::_shared)->pack(dest);
}

inline auto baggage::unpack(strange::bag const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename stuff::_derived>(strange::_common::_shared)->unpack(src);
}

inline auto baggage::is_null() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->is_null();
}

inline auto baggage::from_null() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_null();
}

inline auto baggage::make_null() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_null();
}

inline auto baggage::is_bool() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->is_bool();
}

inline auto baggage::as_bool(bool & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_bool(dest);
}

inline auto baggage::to_bool() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_bool();
}

inline auto baggage::from_bool() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_bool();
}

inline auto baggage::from_bool(bool src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_bool(src);
}

inline auto baggage::make_bool() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_bool();
}

inline auto baggage::make_bool(bool src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_bool(src);
}

inline auto baggage::is_int64() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->is_int64();
}

inline auto baggage::as_int64(int64_t & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_int64(dest);
}

inline auto baggage::to_int64() const -> int64_t
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_int64();
}

inline auto baggage::from_int64() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_int64();
}

inline auto baggage::from_int64(int64_t src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_int64(src);
}

inline auto baggage::make_int64() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_int64();
}

inline auto baggage::make_int64(int64_t src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_int64(src);
}

inline auto baggage::is_uint64() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->is_uint64();
}

inline auto baggage::as_uint64(uint64_t & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_uint64(dest);
}

inline auto baggage::to_uint64() const -> uint64_t
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_uint64();
}

inline auto baggage::from_uint64() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_uint64();
}

inline auto baggage::from_uint64(uint64_t src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_uint64(src);
}

inline auto baggage::make_uint64() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_uint64();
}

inline auto baggage::make_uint64(uint64_t src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_uint64(src);
}

inline auto baggage::is_double() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->is_double();
}

inline auto baggage::as_double(double & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_double(dest);
}

inline auto baggage::to_double() const -> double
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_double();
}

inline auto baggage::from_double() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_double();
}

inline auto baggage::from_double(double src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_double(src);
}

inline auto baggage::make_double() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_double();
}

inline auto baggage::make_double(double src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_double(src);
}

inline auto baggage::is_string() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->is_string();
}

inline auto baggage::as_string(std::string & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_string(dest);
}

inline auto baggage::to_string() const -> std::string
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_string();
}

inline auto baggage::from_string() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_string();
}

inline auto baggage::from_string(std::string const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_string(src);
}

inline auto baggage::make_string() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_string();
}

inline auto baggage::make_string(std::string const & src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_string(src);
}

inline auto baggage::is_array() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->is_array();
}

inline auto baggage::as_array(std::vector<bag> & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_array(dest);
}

inline auto baggage::to_array() const -> std::vector<bag>
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_array();
}

inline auto baggage::from_array() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_array();
}

inline auto baggage::from_array(std::vector<bag> const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_array(src);
}

inline auto baggage::make_array() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_array();
}

inline auto baggage::make_array(std::vector<bag> const & src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_array(src);
}

inline auto baggage::get_array(std::size_t index) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->get_array(index);
}

inline auto baggage::set_array(std::size_t index, bag const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->set_array(index, value);
}

inline auto baggage::front_array() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->front_array();
}

inline auto baggage::back_array() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->back_array();
}

inline auto baggage::empty_array() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->empty_array();
}

inline auto baggage::size_array() const -> std::size_t
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->size_array();
}

inline auto baggage::reserve_array(std::size_t new_cap) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->reserve_array(new_cap);
}

inline auto baggage::capacity_array() const -> std::size_t
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->capacity_array();
}

inline auto baggage::clear_array() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->clear_array();
}

inline auto baggage::insert_array(std::size_t pos, bag const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->insert_array(pos, value);
}

inline auto baggage::erase_array(std::size_t pos) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->erase_array(pos);
}

inline auto baggage::push_front_array(bag const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->push_front_array(value);
}

inline auto baggage::push_back_array(bag const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->push_back_array(value);
}

inline auto baggage::pop_front_array() -> bag
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->pop_front_array();
}

inline auto baggage::pop_back_array() -> bag
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->pop_back_array();
}

inline auto baggage::resize_array(std::size_t count) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->resize_array(count);
}

inline auto baggage::as_array_bool(std::vector<bool> & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_array_bool(dest);
}

inline auto baggage::as_array_int64(std::vector<int64_t> & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_array_int64(dest);
}

inline auto baggage::as_array_uint64(std::vector<uint64_t> & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_array_uint64(dest);
}

inline auto baggage::as_array_double(std::vector<double> & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_array_double(dest);
}

inline auto baggage::as_array_string(std::vector<std::string> & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_array_string(dest);
}

inline auto baggage::as_array_any(std::vector<strange::any> & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_array_any(dest);
}

inline auto baggage::to_array_bool() const -> std::vector<bool>
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_array_bool();
}

inline auto baggage::to_array_int64() const -> std::vector<int64_t>
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_array_int64();
}

inline auto baggage::to_array_uint64() const -> std::vector<uint64_t>
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_array_uint64();
}

inline auto baggage::to_array_double() const -> std::vector<double>
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_array_double();
}

inline auto baggage::to_array_string() const -> std::vector<std::string>
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_array_string();
}

inline auto baggage::to_array_any() const -> std::vector<strange::any>
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_array_any();
}

inline auto baggage::from_array_bool(std::vector<bool> const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_array_bool(src);
}

inline auto baggage::from_array_int64(std::vector<int64_t> const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_array_int64(src);
}

inline auto baggage::from_array_uint64(std::vector<uint64_t> const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_array_uint64(src);
}

inline auto baggage::from_array_double(std::vector<double> const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_array_double(src);
}

inline auto baggage::from_array_string(std::vector<std::string> const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_array_string(src);
}

inline auto baggage::from_array_any(std::vector<strange::any> const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_array_any(src);
}

inline auto baggage::make_array_bool(std::vector<bool> const & src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_array_bool(src);
}

inline auto baggage::make_array_int64(std::vector<int64_t> const & src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_array_int64(src);
}

inline auto baggage::make_array_uint64(std::vector<uint64_t> const & src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_array_uint64(src);
}

inline auto baggage::make_array_double(std::vector<double> const & src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_array_double(src);
}

inline auto baggage::make_array_string(std::vector<std::string> const & src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_array_string(src);
}

inline auto baggage::make_array_any(std::vector<strange::any> const & src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_array_any(src);
}

inline auto baggage::is_object() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->is_object();
}

inline auto baggage::as_object(std::unordered_map<std::string, bag> & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_object(dest);
}

inline auto baggage::to_object() const -> std::unordered_map<std::string, bag>
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_object();
}

inline auto baggage::from_object() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_object();
}

inline auto baggage::from_object(std::unordered_map<std::string, bag> const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_object(src);
}

inline auto baggage::make_object() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_object();
}

inline auto baggage::make_object(std::unordered_map<std::string, bag> const & src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_object(src);
}

inline auto baggage::empty_object() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->empty_object();
}

inline auto baggage::size_object() const -> std::size_t
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->size_object();
}

inline auto baggage::clear_object() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->clear_object();
}

inline auto baggage::insert_object(std::string const & key, bag const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->insert_object(key, value);
}

inline auto baggage::erase_object(std::string const & key) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->erase_object(key);
}

inline auto baggage::get_object(std::string const & key) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->get_object(key);
}

inline auto baggage::set_object(std::string const & key, bag const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->set_object(key, value);
}

inline auto baggage::contains_object(std::string const & key) const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->contains_object(key);
}

inline auto baggage::is_any() const -> bool
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->is_any();
}

inline auto baggage::as_any(strange::any & dest) const -> void
{
    std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->as_any(dest);
}

inline auto baggage::to_any() const -> strange::any
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->to_any();
}

inline auto baggage::from_any() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_any();
}

inline auto baggage::from_any(strange::any const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->from_any(src);
}

inline auto baggage::make_any() const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_any();
}

inline auto baggage::make_any(strange::any const & src) const -> bag
{
    return std::dynamic_pointer_cast<typename bag::_derived const>(strange::_common::_shared)->make_any(src);
}

inline auto baggage::seal() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename package::_derived>(strange::_common::_shared)->seal();
}

inline auto baggage::unseal() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename package::_derived>(strange::_common::_shared)->unseal();
}

inline auto baggage::sealed() const -> bool
{
    return std::dynamic_pointer_cast<typename package::_derived const>(strange::_common::_shared)->sealed();
}

inline auto baggage::is_binary() const -> bool
{
    return std::dynamic_pointer_cast<typename package::_derived const>(strange::_common::_shared)->is_binary();
}

inline auto baggage::as_binary(std::string & binary) const -> void
{
    std::dynamic_pointer_cast<typename package::_derived const>(strange::_common::_shared)->as_binary(binary);
}

inline auto baggage::to_binary() const -> std::string
{
    return std::dynamic_pointer_cast<typename package::_derived const>(strange::_common::_shared)->to_binary();
}

inline auto baggage::from_binary(std::string const & binary) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename package::_derived>(strange::_common::_shared)->from_binary(binary);
}

inline auto baggage::make_binary(std::string const & binary) const -> package
{
    return std::dynamic_pointer_cast<typename package::_derived const>(strange::_common::_shared)->make_binary(binary);
}

inline auto baggage::is_json() const -> bool
{
    return std::dynamic_pointer_cast<typename package::_derived const>(strange::_common::_shared)->is_json();
}

inline auto baggage::as_json(std::string & json) const -> void
{
    std::dynamic_pointer_cast<typename package::_derived const>(strange::_common::_shared)->as_json(json);
}

inline auto baggage::to_json() const -> std::string
{
    return std::dynamic_pointer_cast<typename package::_derived const>(strange::_common::_shared)->to_json();
}

inline auto baggage::from_json(std::string const & json) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename package::_derived>(strange::_common::_shared)->from_json(json);
}

inline auto baggage::make_json(std::string const & json) const -> package
{
    return std::dynamic_pointer_cast<typename package::_derived const>(strange::_common::_shared)->make_json(json);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::pack(strange::bag & dest) const -> void
{
    _thing.pack(dest);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::unpack(strange::bag const & src) -> void
{
    _thing.unpack(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::is_null() const -> bool
{
    return _thing.is_null();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_null() -> void
{
    _thing.from_null();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_null() const -> bag
{
    return _thing.make_null();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::is_bool() const -> bool
{
    return _thing.is_bool();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::as_bool(bool & dest) const -> void
{
    _thing.as_bool(dest);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::to_bool() const -> bool
{
    return _thing.to_bool();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_bool() -> void
{
    _thing.from_bool();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_bool(bool src) -> void
{
    _thing.from_bool(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_bool() const -> bag
{
    return _thing.make_bool();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_bool(bool src) const -> bag
{
    return _thing.make_bool(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::is_int64() const -> bool
{
    return _thing.is_int64();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::as_int64(int64_t & dest) const -> void
{
    _thing.as_int64(dest);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::to_int64() const -> int64_t
{
    return _thing.to_int64();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_int64() -> void
{
    _thing.from_int64();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_int64(int64_t src) -> void
{
    _thing.from_int64(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_int64() const -> bag
{
    return _thing.make_int64();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_int64(int64_t src) const -> bag
{
    return _thing.make_int64(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::is_uint64() const -> bool
{
    return _thing.is_uint64();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::as_uint64(uint64_t & dest) const -> void
{
    _thing.as_uint64(dest);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::to_uint64() const -> uint64_t
{
    return _thing.to_uint64();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_uint64() -> void
{
    _thing.from_uint64();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_uint64(uint64_t src) -> void
{
    _thing.from_uint64(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_uint64() const -> bag
{
    return _thing.make_uint64();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_uint64(uint64_t src) const -> bag
{
    return _thing.make_uint64(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::is_double() const -> bool
{
    return _thing.is_double();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::as_double(double & dest) const -> void
{
    _thing.as_double(dest);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::to_double() const -> double
{
    return _thing.to_double();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_double() -> void
{
    _thing.from_double();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_double(double src) -> void
{
    _thing.from_double(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_double() const -> bag
{
    return _thing.make_double();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_double(double src) const -> bag
{
    return _thing.make_double(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::is_string() const -> bool
{
    return _thing.is_string();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::as_string(std::string & dest) const -> void
{
    _thing.as_string(dest);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::to_string() const -> std::string
{
    return _thing.to_string();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_string() -> void
{
    _thing.from_string();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_string(std::string const & src) -> void
{
    _thing.from_string(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_string() const -> bag
{
    return _thing.make_string();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_string(std::string const & src) const -> bag
{
    return _thing.make_string(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::is_array() const -> bool
{
    return _thing.is_array();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::as_array(std::vector<bag> & dest) const -> void
{
    _thing.as_array(dest);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::to_array() const -> std::vector<bag>
{
    return _thing.to_array();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_array() -> void
{
    _thing.from_array();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_array(std::vector<bag> const & src) -> void
{
    _thing.from_array(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_array() const -> bag
{
    return _thing.make_array();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_array(std::vector<bag> const & src) const -> bag
{
    return _thing.make_array(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::get_array(std::size_t index) const -> bag
{
    return _thing.get_array(index);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::set_array(std::size_t index, bag const & value) -> void
{
    _thing.set_array(index, value);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::front_array() const -> bag
{
    return _thing.front_array();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::back_array() const -> bag
{
    return _thing.back_array();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::empty_array() const -> bool
{
    return _thing.empty_array();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::size_array() const -> std::size_t
{
    return _thing.size_array();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::reserve_array(std::size_t new_cap) -> void
{
    _thing.reserve_array(new_cap);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::capacity_array() const -> std::size_t
{
    return _thing.capacity_array();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::clear_array() -> void
{
    _thing.clear_array();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::insert_array(std::size_t pos, bag const & value) -> void
{
    _thing.insert_array(pos, value);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::erase_array(std::size_t pos) -> void
{
    _thing.erase_array(pos);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::push_front_array(bag const & value) -> void
{
    _thing.push_front_array(value);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::push_back_array(bag const & value) -> void
{
    _thing.push_back_array(value);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::pop_front_array() -> bag
{
    return _thing.pop_front_array();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::pop_back_array() -> bag
{
    return _thing.pop_back_array();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::resize_array(std::size_t count) -> void
{
    _thing.resize_array(count);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::as_array_bool(std::vector<bool> & dest) const -> void
{
    _thing.as_array_bool(dest);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::as_array_int64(std::vector<int64_t> & dest) const -> void
{
    _thing.as_array_int64(dest);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::as_array_uint64(std::vector<uint64_t> & dest) const -> void
{
    _thing.as_array_uint64(dest);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::as_array_double(std::vector<double> & dest) const -> void
{
    _thing.as_array_double(dest);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::as_array_string(std::vector<std::string> & dest) const -> void
{
    _thing.as_array_string(dest);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::as_array_any(std::vector<strange::any> & dest) const -> void
{
    _thing.as_array_any(dest);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::to_array_bool() const -> std::vector<bool>
{
    return _thing.to_array_bool();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::to_array_int64() const -> std::vector<int64_t>
{
    return _thing.to_array_int64();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::to_array_uint64() const -> std::vector<uint64_t>
{
    return _thing.to_array_uint64();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::to_array_double() const -> std::vector<double>
{
    return _thing.to_array_double();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::to_array_string() const -> std::vector<std::string>
{
    return _thing.to_array_string();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::to_array_any() const -> std::vector<strange::any>
{
    return _thing.to_array_any();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_array_bool(std::vector<bool> const & src) -> void
{
    _thing.from_array_bool(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_array_int64(std::vector<int64_t> const & src) -> void
{
    _thing.from_array_int64(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_array_uint64(std::vector<uint64_t> const & src) -> void
{
    _thing.from_array_uint64(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_array_double(std::vector<double> const & src) -> void
{
    _thing.from_array_double(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_array_string(std::vector<std::string> const & src) -> void
{
    _thing.from_array_string(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_array_any(std::vector<strange::any> const & src) -> void
{
    _thing.from_array_any(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_array_bool(std::vector<bool> const & src) const -> bag
{
    return _thing.make_array_bool(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_array_int64(std::vector<int64_t> const & src) const -> bag
{
    return _thing.make_array_int64(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_array_uint64(std::vector<uint64_t> const & src) const -> bag
{
    return _thing.make_array_uint64(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_array_double(std::vector<double> const & src) const -> bag
{
    return _thing.make_array_double(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_array_string(std::vector<std::string> const & src) const -> bag
{
    return _thing.make_array_string(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_array_any(std::vector<strange::any> const & src) const -> bag
{
    return _thing.make_array_any(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::is_object() const -> bool
{
    return _thing.is_object();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::as_object(std::unordered_map<std::string, bag> & dest) const -> void
{
    _thing.as_object(dest);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::to_object() const -> std::unordered_map<std::string, bag>
{
    return _thing.to_object();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_object() -> void
{
    _thing.from_object();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_object(std::unordered_map<std::string, bag> const & src) -> void
{
    _thing.from_object(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_object() const -> bag
{
    return _thing.make_object();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_object(std::unordered_map<std::string, bag> const & src) const -> bag
{
    return _thing.make_object(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::empty_object() const -> bool
{
    return _thing.empty_object();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::size_object() const -> std::size_t
{
    return _thing.size_object();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::clear_object() -> void
{
    _thing.clear_object();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::insert_object(std::string const & key, bag const & value) -> void
{
    _thing.insert_object(key, value);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::erase_object(std::string const & key) -> void
{
    _thing.erase_object(key);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::get_object(std::string const & key) const -> bag
{
    return _thing.get_object(key);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::set_object(std::string const & key, bag const & value) -> void
{
    _thing.set_object(key, value);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::contains_object(std::string const & key) const -> bool
{
    return _thing.contains_object(key);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::is_any() const -> bool
{
    return _thing.is_any();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::as_any(strange::any & dest) const -> void
{
    _thing.as_any(dest);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::to_any() const -> strange::any
{
    return _thing.to_any();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_any() -> void
{
    _thing.from_any();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_any(strange::any const & src) -> void
{
    _thing.from_any(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_any() const -> bag
{
    return _thing.make_any();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_any(strange::any const & src) const -> bag
{
    return _thing.make_any(src);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::seal() -> void
{
    _thing.seal();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::unseal() -> void
{
    _thing.unseal();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::sealed() const -> bool
{
    return _thing.sealed();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::is_binary() const -> bool
{
    return _thing.is_binary();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::as_binary(std::string & binary) const -> void
{
    _thing.as_binary(binary);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::to_binary() const -> std::string
{
    return _thing.to_binary();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_binary(std::string const & binary) -> void
{
    _thing.from_binary(binary);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_binary(std::string const & binary) const -> package
{
    return _thing.make_binary(binary);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::is_json() const -> bool
{
    return _thing.is_json();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::as_json(std::string & json) const -> void
{
    _thing.as_json(json);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::to_json() const -> std::string
{
    return _thing.to_json();
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::from_json(std::string const & json) -> void
{
    _thing.from_json(json);
}

template<typename _Thing, bool _Copy>
inline auto baggage_<_Thing, _Copy>::_instance::make_json(std::string const & json) const -> package
{
    return _thing.make_json(json);
}

template<typename Signal>
inline auto processor<Signal>::pack(strange::bag & dest) const -> void
{
    std::dynamic_pointer_cast<typename stuff::_derived const>(strange::_common::_shared)->pack(dest);
}

template<typename Signal>
inline auto processor<Signal>::unpack(strange::bag const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename stuff::_derived>(strange::_common::_shared)->unpack(src);
}

template<typename Signal>
inline auto processor<Signal>::ins(std::unique_ptr<Signal> && overload) const -> uint64_t const &
{
    return std::dynamic_pointer_cast<typename processor<Signal>::_derived const>(strange::_common::_shared)->ins(std::move(overload));
}

template<typename Signal>
inline auto processor<Signal>::ins(std::unique_ptr<Signal> && overload) -> uint64_t &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename processor<Signal>::_derived>(strange::_common::_shared)->ins(std::move(overload));
}

template<typename Signal>
inline auto processor<Signal>::outs(std::unique_ptr<Signal> && overload) const -> uint64_t const &
{
    return std::dynamic_pointer_cast<typename processor<Signal>::_derived const>(strange::_common::_shared)->outs(std::move(overload));
}

template<typename Signal>
inline auto processor<Signal>::outs(std::unique_ptr<Signal> && overload) -> uint64_t &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename processor<Signal>::_derived>(strange::_common::_shared)->outs(std::move(overload));
}

template<typename Signal>
inline auto processor<Signal>::closure(std::unique_ptr<Signal> && overload) -> std::function<auto (std::vector<Signal>) -> std::vector<Signal>>
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename processor<Signal>::_derived>(strange::_common::_shared)->closure(std::move(overload));
}

template<typename Signal, typename _Thing, bool _Copy>
inline auto processor_<Signal, _Thing, _Copy>::_instance::pack(strange::bag & dest) const -> void
{
    _thing.pack(dest);
}

template<typename Signal, typename _Thing, bool _Copy>
inline auto processor_<Signal, _Thing, _Copy>::_instance::unpack(strange::bag const & src) -> void
{
    _thing.unpack(src);
}

template<typename Signal, typename _Thing, bool _Copy>
inline auto processor_<Signal, _Thing, _Copy>::_instance::ins(std::unique_ptr<Signal> && overload) const -> uint64_t const &
{
    return _thing.ins(std::move(overload));
}

template<typename Signal, typename _Thing, bool _Copy>
inline auto processor_<Signal, _Thing, _Copy>::_instance::ins(std::unique_ptr<Signal> && overload) -> uint64_t &
{
    return _thing.ins(std::move(overload));
}

template<typename Signal, typename _Thing, bool _Copy>
inline auto processor_<Signal, _Thing, _Copy>::_instance::outs(std::unique_ptr<Signal> && overload) const -> uint64_t const &
{
    return _thing.outs(std::move(overload));
}

template<typename Signal, typename _Thing, bool _Copy>
inline auto processor_<Signal, _Thing, _Copy>::_instance::outs(std::unique_ptr<Signal> && overload) -> uint64_t &
{
    return _thing.outs(std::move(overload));
}

template<typename Signal, typename _Thing, bool _Copy>
inline auto processor_<Signal, _Thing, _Copy>::_instance::closure(std::unique_ptr<Signal> && overload) -> std::function<auto (std::vector<Signal>) -> std::vector<Signal>>
{
    return _thing.closure(std::move(overload));
}

inline auto connection::pack(strange::bag & dest) const -> void
{
    std::dynamic_pointer_cast<typename stuff::_derived const>(strange::_common::_shared)->pack(dest);
}

inline auto connection::unpack(strange::bag const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename stuff::_derived>(strange::_common::_shared)->unpack(src);
}

inline auto connection::from_id() const -> uint64_t const &
{
    return std::dynamic_pointer_cast<typename connection::_derived const>(strange::_common::_shared)->from_id();
}

inline auto connection::from_id() -> uint64_t &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename connection::_derived>(strange::_common::_shared)->from_id();
}

inline auto connection::from_out() const -> uint64_t const &
{
    return std::dynamic_pointer_cast<typename connection::_derived const>(strange::_common::_shared)->from_out();
}

inline auto connection::from_out() -> uint64_t &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename connection::_derived>(strange::_common::_shared)->from_out();
}

inline auto connection::to_id() const -> uint64_t const &
{
    return std::dynamic_pointer_cast<typename connection::_derived const>(strange::_common::_shared)->to_id();
}

inline auto connection::to_id() -> uint64_t &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename connection::_derived>(strange::_common::_shared)->to_id();
}

inline auto connection::to_in() const -> uint64_t const &
{
    return std::dynamic_pointer_cast<typename connection::_derived const>(strange::_common::_shared)->to_in();
}

inline auto connection::to_in() -> uint64_t &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename connection::_derived>(strange::_common::_shared)->to_in();
}

template<typename _Thing, bool _Copy>
inline auto connection_<_Thing, _Copy>::_instance::pack(strange::bag & dest) const -> void
{
    _thing.pack(dest);
}

template<typename _Thing, bool _Copy>
inline auto connection_<_Thing, _Copy>::_instance::unpack(strange::bag const & src) -> void
{
    _thing.unpack(src);
}

template<typename _Thing, bool _Copy>
inline auto connection_<_Thing, _Copy>::_instance::from_id() const -> uint64_t const &
{
    return _thing.from_id();
}

template<typename _Thing, bool _Copy>
inline auto connection_<_Thing, _Copy>::_instance::from_id() -> uint64_t &
{
    return _thing.from_id();
}

template<typename _Thing, bool _Copy>
inline auto connection_<_Thing, _Copy>::_instance::from_out() const -> uint64_t const &
{
    return _thing.from_out();
}

template<typename _Thing, bool _Copy>
inline auto connection_<_Thing, _Copy>::_instance::from_out() -> uint64_t &
{
    return _thing.from_out();
}

template<typename _Thing, bool _Copy>
inline auto connection_<_Thing, _Copy>::_instance::to_id() const -> uint64_t const &
{
    return _thing.to_id();
}

template<typename _Thing, bool _Copy>
inline auto connection_<_Thing, _Copy>::_instance::to_id() -> uint64_t &
{
    return _thing.to_id();
}

template<typename _Thing, bool _Copy>
inline auto connection_<_Thing, _Copy>::_instance::to_in() const -> uint64_t const &
{
    return _thing.to_in();
}

template<typename _Thing, bool _Copy>
inline auto connection_<_Thing, _Copy>::_instance::to_in() -> uint64_t &
{
    return _thing.to_in();
}

template<typename Signal>
inline auto graph<Signal>::pack(strange::bag & dest) const -> void
{
    std::dynamic_pointer_cast<typename stuff::_derived const>(strange::_common::_shared)->pack(dest);
}

template<typename Signal>
inline auto graph<Signal>::unpack(strange::bag const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename stuff::_derived>(strange::_common::_shared)->unpack(src);
}

template<typename Signal>
inline auto graph<Signal>::ins(std::unique_ptr<Signal> && overload) const -> uint64_t const &
{
    return std::dynamic_pointer_cast<typename processor<Signal>::_derived const>(strange::_common::_shared)->ins(std::move(overload));
}

template<typename Signal>
inline auto graph<Signal>::ins(std::unique_ptr<Signal> && overload) -> uint64_t &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename processor<Signal>::_derived>(strange::_common::_shared)->ins(std::move(overload));
}

template<typename Signal>
inline auto graph<Signal>::outs(std::unique_ptr<Signal> && overload) const -> uint64_t const &
{
    return std::dynamic_pointer_cast<typename processor<Signal>::_derived const>(strange::_common::_shared)->outs(std::move(overload));
}

template<typename Signal>
inline auto graph<Signal>::outs(std::unique_ptr<Signal> && overload) -> uint64_t &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename processor<Signal>::_derived>(strange::_common::_shared)->outs(std::move(overload));
}

template<typename Signal>
inline auto graph<Signal>::closure(std::unique_ptr<Signal> && overload) -> std::function<auto (std::vector<Signal>) -> std::vector<Signal>>
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename processor<Signal>::_derived>(strange::_common::_shared)->closure(std::move(overload));
}

template<typename Signal>
inline auto graph<Signal>::add_processor(strange::processor<Signal> proc) -> uint64_t
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename graph<Signal>::_derived>(strange::_common::_shared)->add_processor(proc);
}

template<typename Signal>
inline auto graph<Signal>::remove_processor(uint64_t id, std::unique_ptr<Signal> && overload) -> bool
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename graph<Signal>::_derived>(strange::_common::_shared)->remove_processor(id, std::move(overload));
}

template<typename Signal>
inline auto graph<Signal>::add_connection(strange::connection conn, std::unique_ptr<Signal> && overload) -> uint64_t
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename graph<Signal>::_derived>(strange::_common::_shared)->add_connection(conn, std::move(overload));
}

template<typename Signal>
inline auto graph<Signal>::remove_connection(uint64_t id, std::unique_ptr<Signal> && overload) -> bool
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename graph<Signal>::_derived>(strange::_common::_shared)->remove_connection(id, std::move(overload));
}

template<typename Signal>
inline auto graph<Signal>::processors() -> std::vector<strange::processor<Signal>> &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename graph<Signal>::_derived>(strange::_common::_shared)->processors();
}

template<typename Signal, typename _Thing, bool _Copy>
inline auto graph_<Signal, _Thing, _Copy>::_instance::pack(strange::bag & dest) const -> void
{
    _thing.pack(dest);
}

template<typename Signal, typename _Thing, bool _Copy>
inline auto graph_<Signal, _Thing, _Copy>::_instance::unpack(strange::bag const & src) -> void
{
    _thing.unpack(src);
}

template<typename Signal, typename _Thing, bool _Copy>
inline auto graph_<Signal, _Thing, _Copy>::_instance::ins(std::unique_ptr<Signal> && overload) const -> uint64_t const &
{
    return _thing.ins(std::move(overload));
}

template<typename Signal, typename _Thing, bool _Copy>
inline auto graph_<Signal, _Thing, _Copy>::_instance::ins(std::unique_ptr<Signal> && overload) -> uint64_t &
{
    return _thing.ins(std::move(overload));
}

template<typename Signal, typename _Thing, bool _Copy>
inline auto graph_<Signal, _Thing, _Copy>::_instance::outs(std::unique_ptr<Signal> && overload) const -> uint64_t const &
{
    return _thing.outs(std::move(overload));
}

template<typename Signal, typename _Thing, bool _Copy>
inline auto graph_<Signal, _Thing, _Copy>::_instance::outs(std::unique_ptr<Signal> && overload) -> uint64_t &
{
    return _thing.outs(std::move(overload));
}

template<typename Signal, typename _Thing, bool _Copy>
inline auto graph_<Signal, _Thing, _Copy>::_instance::closure(std::unique_ptr<Signal> && overload) -> std::function<auto (std::vector<Signal>) -> std::vector<Signal>>
{
    return _thing.closure(std::move(overload));
}

template<typename Signal, typename _Thing, bool _Copy>
inline auto graph_<Signal, _Thing, _Copy>::_instance::add_processor(strange::processor<Signal> proc) -> uint64_t
{
    return _thing.add_processor(proc);
}

template<typename Signal, typename _Thing, bool _Copy>
inline auto graph_<Signal, _Thing, _Copy>::_instance::remove_processor(uint64_t id, std::unique_ptr<Signal> && overload) -> bool
{
    return _thing.remove_processor(id, std::move(overload));
}

template<typename Signal, typename _Thing, bool _Copy>
inline auto graph_<Signal, _Thing, _Copy>::_instance::add_connection(strange::connection conn, std::unique_ptr<Signal> && overload) -> uint64_t
{
    return _thing.add_connection(conn, std::move(overload));
}

template<typename Signal, typename _Thing, bool _Copy>
inline auto graph_<Signal, _Thing, _Copy>::_instance::remove_connection(uint64_t id, std::unique_ptr<Signal> && overload) -> bool
{
    return _thing.remove_connection(id, std::move(overload));
}

template<typename Signal, typename _Thing, bool _Copy>
inline auto graph_<Signal, _Thing, _Copy>::_instance::processors() -> std::vector<strange::processor<Signal>> &
{
    return _thing.processors();
}

inline auto parameter::pack(strange::bag & dest) const -> void
{
    std::dynamic_pointer_cast<typename stuff::_derived const>(strange::_common::_shared)->pack(dest);
}

inline auto parameter::unpack(strange::bag const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename stuff::_derived>(strange::_common::_shared)->unpack(src);
}

inline auto parameter::type() const -> std::string const &
{
    return std::dynamic_pointer_cast<typename parameter::_derived const>(strange::_common::_shared)->type();
}

inline auto parameter::type() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename parameter::_derived>(strange::_common::_shared)->type();
}

inline auto parameter::name() const -> std::string const &
{
    return std::dynamic_pointer_cast<typename parameter::_derived const>(strange::_common::_shared)->name();
}

inline auto parameter::name() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename parameter::_derived>(strange::_common::_shared)->name();
}

inline auto parameter::argument() const -> std::string const &
{
    return std::dynamic_pointer_cast<typename parameter::_derived const>(strange::_common::_shared)->argument();
}

inline auto parameter::argument() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename parameter::_derived>(strange::_common::_shared)->argument();
}

inline auto parameter::operator==(parameter const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename parameter::_derived const>(strange::_common::_shared)->operator==(other);
}

inline auto parameter::operator!=(parameter const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename parameter::_derived const>(strange::_common::_shared)->operator!=(other);
}

inline auto parameter::operator<(parameter const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename parameter::_derived const>(strange::_common::_shared)->operator<(other);
}

inline auto parameter::operator<=(parameter const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename parameter::_derived const>(strange::_common::_shared)->operator<=(other);
}

inline auto parameter::operator>(parameter const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename parameter::_derived const>(strange::_common::_shared)->operator>(other);
}

inline auto parameter::operator>=(parameter const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename parameter::_derived const>(strange::_common::_shared)->operator>=(other);
}

template<typename _Thing, bool _Copy>
inline auto parameter_<_Thing, _Copy>::_instance::pack(strange::bag & dest) const -> void
{
    _thing.pack(dest);
}

template<typename _Thing, bool _Copy>
inline auto parameter_<_Thing, _Copy>::_instance::unpack(strange::bag const & src) -> void
{
    _thing.unpack(src);
}

template<typename _Thing, bool _Copy>
inline auto parameter_<_Thing, _Copy>::_instance::type() const -> std::string const &
{
    return _thing.type();
}

template<typename _Thing, bool _Copy>
inline auto parameter_<_Thing, _Copy>::_instance::type() -> std::string &
{
    return _thing.type();
}

template<typename _Thing, bool _Copy>
inline auto parameter_<_Thing, _Copy>::_instance::name() const -> std::string const &
{
    return _thing.name();
}

template<typename _Thing, bool _Copy>
inline auto parameter_<_Thing, _Copy>::_instance::name() -> std::string &
{
    return _thing.name();
}

template<typename _Thing, bool _Copy>
inline auto parameter_<_Thing, _Copy>::_instance::argument() const -> std::string const &
{
    return _thing.argument();
}

template<typename _Thing, bool _Copy>
inline auto parameter_<_Thing, _Copy>::_instance::argument() -> std::string &
{
    return _thing.argument();
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

template<typename _Thing, bool _Copy>
inline auto parameter_<_Thing, _Copy>::_instance::operator<(parameter const & other) const -> bool
{
    return type() < other.type() || (type() == other.type()
    && (name() < other.name() || (name() == other.name()
    && argument() < other.argument())));
}

template<typename _Thing, bool _Copy>
inline auto parameter_<_Thing, _Copy>::_instance::operator<=(parameter const & other) const -> bool
{
    return operator<(other) || operator==(other);
}

template<typename _Thing, bool _Copy>
inline auto parameter_<_Thing, _Copy>::_instance::operator>(parameter const & other) const -> bool
{
    return !operator<=(other);
}

template<typename _Thing, bool _Copy>
inline auto parameter_<_Thing, _Copy>::_instance::operator>=(parameter const & other) const -> bool
{
    return !operator<(other);
}

inline auto operation::pack(strange::bag & dest) const -> void
{
    std::dynamic_pointer_cast<typename stuff::_derived const>(strange::_common::_shared)->pack(dest);
}

inline auto operation::unpack(strange::bag const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename stuff::_derived>(strange::_common::_shared)->unpack(src);
}

inline auto operation::name() const -> std::string const &
{
    return std::dynamic_pointer_cast<typename operation::_derived const>(strange::_common::_shared)->name();
}

inline auto operation::name() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename operation::_derived>(strange::_common::_shared)->name();
}

inline auto operation::parameters() const -> std::vector<strange::parameter> const &
{
    return std::dynamic_pointer_cast<typename operation::_derived const>(strange::_common::_shared)->parameters();
}

inline auto operation::parameters() -> std::vector<strange::parameter> &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename operation::_derived>(strange::_common::_shared)->parameters();
}

inline auto operation::constness() const -> bool const &
{
    return std::dynamic_pointer_cast<typename operation::_derived const>(strange::_common::_shared)->constness();
}

inline auto operation::constness() -> bool &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename operation::_derived>(strange::_common::_shared)->constness();
}

inline auto operation::result() const -> std::string const &
{
    return std::dynamic_pointer_cast<typename operation::_derived const>(strange::_common::_shared)->result();
}

inline auto operation::result() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename operation::_derived>(strange::_common::_shared)->result();
}

inline auto operation::data() const -> bool const &
{
    return std::dynamic_pointer_cast<typename operation::_derived const>(strange::_common::_shared)->data();
}

inline auto operation::data() -> bool &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename operation::_derived>(strange::_common::_shared)->data();
}

inline auto operation::closure() const -> std::string const &
{
    return std::dynamic_pointer_cast<typename operation::_derived const>(strange::_common::_shared)->closure();
}

inline auto operation::closure() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename operation::_derived>(strange::_common::_shared)->closure();
}

inline auto operation::modification() const -> std::string const &
{
    return std::dynamic_pointer_cast<typename operation::_derived const>(strange::_common::_shared)->modification();
}

inline auto operation::modification() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename operation::_derived>(strange::_common::_shared)->modification();
}

inline auto operation::customisation() const -> std::string const &
{
    return std::dynamic_pointer_cast<typename operation::_derived const>(strange::_common::_shared)->customisation();
}

inline auto operation::customisation() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename operation::_derived>(strange::_common::_shared)->customisation();
}

inline auto operation::implementation() const -> std::string const &
{
    return std::dynamic_pointer_cast<typename operation::_derived const>(strange::_common::_shared)->implementation();
}

inline auto operation::implementation() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename operation::_derived>(strange::_common::_shared)->implementation();
}

inline auto operation::operator==(operation const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename operation::_derived const>(strange::_common::_shared)->operator==(other);
}

inline auto operation::operator!=(operation const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename operation::_derived const>(strange::_common::_shared)->operator!=(other);
}

inline auto operation::operator<(operation const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename operation::_derived const>(strange::_common::_shared)->operator<(other);
}

inline auto operation::operator<=(operation const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename operation::_derived const>(strange::_common::_shared)->operator<=(other);
}

inline auto operation::operator>(operation const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename operation::_derived const>(strange::_common::_shared)->operator>(other);
}

inline auto operation::operator>=(operation const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename operation::_derived const>(strange::_common::_shared)->operator>=(other);
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::pack(strange::bag & dest) const -> void
{
    _thing.pack(dest);
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::unpack(strange::bag const & src) -> void
{
    _thing.unpack(src);
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::name() const -> std::string const &
{
    return _thing.name();
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::name() -> std::string &
{
    return _thing.name();
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::parameters() const -> std::vector<strange::parameter> const &
{
    return _thing.parameters();
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::parameters() -> std::vector<strange::parameter> &
{
    return _thing.parameters();
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::constness() const -> bool const &
{
    return _thing.constness();
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::constness() -> bool &
{
    return _thing.constness();
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::result() const -> std::string const &
{
    return _thing.result();
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::result() -> std::string &
{
    return _thing.result();
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::data() const -> bool const &
{
    return _thing.data();
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::data() -> bool &
{
    return _thing.data();
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::closure() const -> std::string const &
{
    return _thing.closure();
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::closure() -> std::string &
{
    return _thing.closure();
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::modification() const -> std::string const &
{
    return _thing.modification();
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::modification() -> std::string &
{
    return _thing.modification();
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::customisation() const -> std::string const &
{
    return _thing.customisation();
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::customisation() -> std::string &
{
    return _thing.customisation();
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::implementation() const -> std::string const &
{
    return _thing.implementation();
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::implementation() -> std::string &
{
    return _thing.implementation();
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::operator==(operation const & other) const -> bool
{
    return name() == other.name()
    && parameters() == other.parameters()
    && constness() == other.constness()
    && result() == other.result()
    && data() == other.data()
    && modification() == other.modification()
    && customisation() == other.customisation()
    && implementation() == other.implementation();
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::operator!=(operation const & other) const -> bool
{
    return !operator==(other);
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::operator<(operation const & other) const -> bool
{
    return name() < other.name() || (name() == other.name()
    && (parameters() < other.parameters() || (parameters() == other.parameters()
    && (constness() < other.constness() || (constness() == other.constness()
    && (result() < other.result() || (result() == other.result()
    && (data() < other.data() || (data() == other.data()
    && (modification() < other.modification() || (modification() == other.modification()
    && (customisation() < other.customisation() || (customisation() == other.customisation()
    && implementation() < other.implementation())))))))))))));
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::operator<=(operation const & other) const -> bool
{
    return operator<(other) || operator==(other);
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::operator>(operation const & other) const -> bool
{
    return !operator<=(other);
}

template<typename _Thing, bool _Copy>
inline auto operation_<_Thing, _Copy>::_instance::operator>=(operation const & other) const -> bool
{
    return !operator<(other);
}

inline auto abstraction::pack(strange::bag & dest) const -> void
{
    std::dynamic_pointer_cast<typename stuff::_derived const>(strange::_common::_shared)->pack(dest);
}

inline auto abstraction::unpack(strange::bag const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename stuff::_derived>(strange::_common::_shared)->unpack(src);
}

inline auto abstraction::parameters() const -> std::vector<strange::parameter> const &
{
    return std::dynamic_pointer_cast<typename abstraction::_derived const>(strange::_common::_shared)->parameters();
}

inline auto abstraction::parameters() -> std::vector<strange::parameter> &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename abstraction::_derived>(strange::_common::_shared)->parameters();
}

inline auto abstraction::name() const -> std::string const &
{
    return std::dynamic_pointer_cast<typename abstraction::_derived const>(strange::_common::_shared)->name();
}

inline auto abstraction::name() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename abstraction::_derived>(strange::_common::_shared)->name();
}

inline auto abstraction::parents() const -> std::vector<std::string> const &
{
    return std::dynamic_pointer_cast<typename abstraction::_derived const>(strange::_common::_shared)->parents();
}

inline auto abstraction::parents() -> std::vector<std::string> &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename abstraction::_derived>(strange::_common::_shared)->parents();
}

inline auto abstraction::types() const -> std::vector<strange::parameter> const &
{
    return std::dynamic_pointer_cast<typename abstraction::_derived const>(strange::_common::_shared)->types();
}

inline auto abstraction::types() -> std::vector<strange::parameter> &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename abstraction::_derived>(strange::_common::_shared)->types();
}

inline auto abstraction::operations() const -> std::vector<strange::operation> const &
{
    return std::dynamic_pointer_cast<typename abstraction::_derived const>(strange::_common::_shared)->operations();
}

inline auto abstraction::operations() -> std::vector<strange::operation> &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename abstraction::_derived>(strange::_common::_shared)->operations();
}

inline auto abstraction::thing() const -> std::string const &
{
    return std::dynamic_pointer_cast<typename abstraction::_derived const>(strange::_common::_shared)->thing();
}

inline auto abstraction::thing() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename abstraction::_derived>(strange::_common::_shared)->thing();
}

inline auto abstraction::implementation() const -> std::string const &
{
    return std::dynamic_pointer_cast<typename abstraction::_derived const>(strange::_common::_shared)->implementation();
}

inline auto abstraction::implementation() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename abstraction::_derived>(strange::_common::_shared)->implementation();
}

inline auto abstraction::operator==(abstraction const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename abstraction::_derived const>(strange::_common::_shared)->operator==(other);
}

inline auto abstraction::operator!=(abstraction const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename abstraction::_derived const>(strange::_common::_shared)->operator!=(other);
}

inline auto abstraction::operator<(abstraction const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename abstraction::_derived const>(strange::_common::_shared)->operator<(other);
}

inline auto abstraction::operator<=(abstraction const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename abstraction::_derived const>(strange::_common::_shared)->operator<=(other);
}

inline auto abstraction::operator>(abstraction const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename abstraction::_derived const>(strange::_common::_shared)->operator>(other);
}

inline auto abstraction::operator>=(abstraction const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename abstraction::_derived const>(strange::_common::_shared)->operator>=(other);
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::pack(strange::bag & dest) const -> void
{
    _thing.pack(dest);
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::unpack(strange::bag const & src) -> void
{
    _thing.unpack(src);
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::parameters() const -> std::vector<strange::parameter> const &
{
    return _thing.parameters();
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::parameters() -> std::vector<strange::parameter> &
{
    return _thing.parameters();
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::name() const -> std::string const &
{
    return _thing.name();
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::name() -> std::string &
{
    return _thing.name();
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::parents() const -> std::vector<std::string> const &
{
    return _thing.parents();
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::parents() -> std::vector<std::string> &
{
    return _thing.parents();
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::types() const -> std::vector<strange::parameter> const &
{
    return _thing.types();
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::types() -> std::vector<strange::parameter> &
{
    return _thing.types();
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::operations() const -> std::vector<strange::operation> const &
{
    return _thing.operations();
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::operations() -> std::vector<strange::operation> &
{
    return _thing.operations();
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::thing() const -> std::string const &
{
    return _thing.thing();
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::thing() -> std::string &
{
    return _thing.thing();
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::implementation() const -> std::string const &
{
    return _thing.implementation();
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::implementation() -> std::string &
{
    return _thing.implementation();
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::operator==(abstraction const & other) const -> bool
{
    return parameters() == other.parameters()
    && name() == other.name()
    && parents() == other.parents()
    && types() == other.types()
    && operations() == other.operations()
    && thing() == other.thing()
    && implementation() == other.implementation();
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::operator!=(abstraction const & other) const -> bool
{
    return !operator==(other);
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::operator<(abstraction const & other) const -> bool
{
    return parameters() < other.parameters() || (parameters() == other.parameters()
    && (name() < other.name() || (name() == other.name()
    && (parents() < other.parents() || (parents() == other.parents()
    && (types() < other.types() || (types() == other.types()
    && (operations() < other.operations() || (operations() == other.operations()
    && (thing() < other.thing() || (thing() == other.thing()
    && implementation() < other.implementation())))))))))));
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::operator<=(abstraction const & other) const -> bool
{
    return operator<(other) || operator==(other);
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::operator>(abstraction const & other) const -> bool
{
    return !operator<=(other);
}

template<typename _Thing, bool _Copy>
inline auto abstraction_<_Thing, _Copy>::_instance::operator>=(abstraction const & other) const -> bool
{
    return !operator<(other);
}

inline auto space::pack(strange::bag & dest) const -> void
{
    std::dynamic_pointer_cast<typename stuff::_derived const>(strange::_common::_shared)->pack(dest);
}

inline auto space::unpack(strange::bag const & src) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename stuff::_derived>(strange::_common::_shared)->unpack(src);
}

inline auto space::inclusions() const -> std::vector<strange::abstraction> const &
{
    return std::dynamic_pointer_cast<typename space::_derived const>(strange::_common::_shared)->inclusions();
}

inline auto space::inclusions() -> std::vector<strange::abstraction> &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename space::_derived>(strange::_common::_shared)->inclusions();
}

inline auto space::name() const -> std::string const &
{
    return std::dynamic_pointer_cast<typename space::_derived const>(strange::_common::_shared)->name();
}

inline auto space::name() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename space::_derived>(strange::_common::_shared)->name();
}

inline auto space::abstractions() const -> std::vector<strange::abstraction> const &
{
    return std::dynamic_pointer_cast<typename space::_derived const>(strange::_common::_shared)->abstractions();
}

inline auto space::abstractions() -> std::vector<strange::abstraction> &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename space::_derived>(strange::_common::_shared)->abstractions();
}

inline auto space::operator==(space const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename space::_derived const>(strange::_common::_shared)->operator==(other);
}

inline auto space::operator!=(space const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename space::_derived const>(strange::_common::_shared)->operator!=(other);
}

inline auto space::operator<(space const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename space::_derived const>(strange::_common::_shared)->operator<(other);
}

inline auto space::operator<=(space const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename space::_derived const>(strange::_common::_shared)->operator<=(other);
}

inline auto space::operator>(space const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename space::_derived const>(strange::_common::_shared)->operator>(other);
}

inline auto space::operator>=(space const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename space::_derived const>(strange::_common::_shared)->operator>=(other);
}

template<typename _Thing, bool _Copy>
inline auto space_<_Thing, _Copy>::_instance::pack(strange::bag & dest) const -> void
{
    _thing.pack(dest);
}

template<typename _Thing, bool _Copy>
inline auto space_<_Thing, _Copy>::_instance::unpack(strange::bag const & src) -> void
{
    _thing.unpack(src);
}

template<typename _Thing, bool _Copy>
inline auto space_<_Thing, _Copy>::_instance::inclusions() const -> std::vector<strange::abstraction> const &
{
    return _thing.inclusions();
}

template<typename _Thing, bool _Copy>
inline auto space_<_Thing, _Copy>::_instance::inclusions() -> std::vector<strange::abstraction> &
{
    return _thing.inclusions();
}

template<typename _Thing, bool _Copy>
inline auto space_<_Thing, _Copy>::_instance::name() const -> std::string const &
{
    return _thing.name();
}

template<typename _Thing, bool _Copy>
inline auto space_<_Thing, _Copy>::_instance::name() -> std::string &
{
    return _thing.name();
}

template<typename _Thing, bool _Copy>
inline auto space_<_Thing, _Copy>::_instance::abstractions() const -> std::vector<strange::abstraction> const &
{
    return _thing.abstractions();
}

template<typename _Thing, bool _Copy>
inline auto space_<_Thing, _Copy>::_instance::abstractions() -> std::vector<strange::abstraction> &
{
    return _thing.abstractions();
}

template<typename _Thing, bool _Copy>
inline auto space_<_Thing, _Copy>::_instance::operator==(space const & other) const -> bool
{
    return inclusions() == other.inclusions()
    && name() == other.name()
    && abstractions() == other.abstractions();
}

template<typename _Thing, bool _Copy>
inline auto space_<_Thing, _Copy>::_instance::operator!=(space const & other) const -> bool
{
    return !operator==(other);
}

template<typename _Thing, bool _Copy>
inline auto space_<_Thing, _Copy>::_instance::operator<(space const & other) const -> bool
{
    return inclusions() < other.inclusions() || (inclusions() == other.inclusions()
    && (name() < other.name() || (name() == other.name()
    && abstractions() < other.abstractions())));
}

template<typename _Thing, bool _Copy>
inline auto space_<_Thing, _Copy>::_instance::operator<=(space const & other) const -> bool
{
    return operator<(other) || operator==(other);
}

template<typename _Thing, bool _Copy>
inline auto space_<_Thing, _Copy>::_instance::operator>(space const & other) const -> bool
{
    return !operator<=(other);
}

template<typename _Thing, bool _Copy>
inline auto space_<_Thing, _Copy>::_instance::operator>=(space const & other) const -> bool
{
    return !operator<(other);
}

inline auto token::filename() const -> std::string const &
{
    return std::dynamic_pointer_cast<typename token::_derived const>(strange::_common::_shared)->filename();
}

inline auto token::filename() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename token::_derived>(strange::_common::_shared)->filename();
}

inline auto token::line() const -> int64_t const &
{
    return std::dynamic_pointer_cast<typename token::_derived const>(strange::_common::_shared)->line();
}

inline auto token::line() -> int64_t &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename token::_derived>(strange::_common::_shared)->line();
}

inline auto token::position() const -> int64_t const &
{
    return std::dynamic_pointer_cast<typename token::_derived const>(strange::_common::_shared)->position();
}

inline auto token::position() -> int64_t &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename token::_derived>(strange::_common::_shared)->position();
}

inline auto token::classification() const -> strange::comprehension::cls const &
{
    return std::dynamic_pointer_cast<typename token::_derived const>(strange::_common::_shared)->classification();
}

inline auto token::classification() -> strange::comprehension::cls &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename token::_derived>(strange::_common::_shared)->classification();
}

inline auto token::text() const -> std::string const &
{
    return std::dynamic_pointer_cast<typename token::_derived const>(strange::_common::_shared)->text();
}

inline auto token::text() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename token::_derived>(strange::_common::_shared)->text();
}

inline auto token::operator==(token const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename token::_derived const>(strange::_common::_shared)->operator==(other);
}

inline auto token::operator!=(token const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename token::_derived const>(strange::_common::_shared)->operator!=(other);
}

inline auto token::operator<(token const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename token::_derived const>(strange::_common::_shared)->operator<(other);
}

inline auto token::operator<=(token const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename token::_derived const>(strange::_common::_shared)->operator<=(other);
}

inline auto token::operator>(token const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename token::_derived const>(strange::_common::_shared)->operator>(other);
}

inline auto token::operator>=(token const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename token::_derived const>(strange::_common::_shared)->operator>=(other);
}

template<typename _Thing, bool _Copy>
inline auto token_<_Thing, _Copy>::_instance::filename() const -> std::string const &
{
    return _thing.filename();
}

template<typename _Thing, bool _Copy>
inline auto token_<_Thing, _Copy>::_instance::filename() -> std::string &
{
    return _thing.filename();
}

template<typename _Thing, bool _Copy>
inline auto token_<_Thing, _Copy>::_instance::line() const -> int64_t const &
{
    return _thing.line();
}

template<typename _Thing, bool _Copy>
inline auto token_<_Thing, _Copy>::_instance::line() -> int64_t &
{
    return _thing.line();
}

template<typename _Thing, bool _Copy>
inline auto token_<_Thing, _Copy>::_instance::position() const -> int64_t const &
{
    return _thing.position();
}

template<typename _Thing, bool _Copy>
inline auto token_<_Thing, _Copy>::_instance::position() -> int64_t &
{
    return _thing.position();
}

template<typename _Thing, bool _Copy>
inline auto token_<_Thing, _Copy>::_instance::classification() const -> strange::comprehension::cls const &
{
    return _thing.classification();
}

template<typename _Thing, bool _Copy>
inline auto token_<_Thing, _Copy>::_instance::classification() -> strange::comprehension::cls &
{
    return _thing.classification();
}

template<typename _Thing, bool _Copy>
inline auto token_<_Thing, _Copy>::_instance::text() const -> std::string const &
{
    return _thing.text();
}

template<typename _Thing, bool _Copy>
inline auto token_<_Thing, _Copy>::_instance::text() -> std::string &
{
    return _thing.text();
}

template<typename _Thing, bool _Copy>
inline auto token_<_Thing, _Copy>::_instance::operator==(token const & other) const -> bool
{
    return filename() == other.filename()
    && line() == other.line()
    && position() == other.position()
    && classification() == other.classification()
    && text() == other.text();
}

template<typename _Thing, bool _Copy>
inline auto token_<_Thing, _Copy>::_instance::operator!=(token const & other) const -> bool
{
    return !operator==(other);
}

template<typename _Thing, bool _Copy>
inline auto token_<_Thing, _Copy>::_instance::operator<(token const & other) const -> bool
{
    return filename() < other.filename() || (filename() == other.filename()
    && (line() < other.line() || (line() == other.line()
    && (position() < other.position() || (position() == other.position()
    && (classification() < other.classification() || (classification() == other.classification()
    && text() < other.text())))))));
}

template<typename _Thing, bool _Copy>
inline auto token_<_Thing, _Copy>::_instance::operator<=(token const & other) const -> bool
{
    return operator<(other) || operator==(other);
}

template<typename _Thing, bool _Copy>
inline auto token_<_Thing, _Copy>::_instance::operator>(token const & other) const -> bool
{
    return !operator<=(other);
}

template<typename _Thing, bool _Copy>
inline auto token_<_Thing, _Copy>::_instance::operator>=(token const & other) const -> bool
{
    return !operator<(other);
}

template<typename T>
inline auto forward_const_iterator<T>::operator*() const -> T const &
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator*();
}

template<typename T>
inline auto forward_const_iterator<T>::operator->() const -> T const *
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator->();
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
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto forward_const_iterator<T>::operator!=(forward_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator!=(other);
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
    return _thing == other.template _static<forward_const_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto forward_const_iterator_<T, _Thing, _Copy>::_instance::operator!=(forward_const_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T>
inline auto forward_iterator<T>::operator*() const -> T const &
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator*();
}

template<typename T>
inline auto forward_iterator<T>::operator->() const -> T const *
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator->();
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
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto forward_iterator<T>::operator!=(forward_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator!=(other);
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
    return std::dynamic_pointer_cast<typename forward_iterator<T>::_derived const>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto forward_iterator<T>::operator!=(forward_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_iterator<T>::_derived const>(strange::_common::_shared)->operator!=(other);
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
    return _thing == other.template _static<forward_const_iterator_<T, _Thing, _Copy> const>()._thing();
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
    return _thing == other.template _static<forward_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto forward_iterator_<T, _Thing, _Copy>::_instance::operator!=(forward_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T>
inline auto bidirectional_const_iterator<T>::operator*() const -> T const &
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator*();
}

template<typename T>
inline auto bidirectional_const_iterator<T>::operator->() const -> T const *
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator->();
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
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto bidirectional_const_iterator<T>::operator!=(forward_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto bidirectional_const_iterator<T>::operator==(bidirectional_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived const>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto bidirectional_const_iterator<T>::operator!=(bidirectional_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived const>(strange::_common::_shared)->operator!=(other);
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
    return _thing == other.template _static<forward_const_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_const_iterator_<T, _Thing, _Copy>::_instance::operator!=(forward_const_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_const_iterator_<T, _Thing, _Copy>::_instance::operator==(bidirectional_const_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<bidirectional_const_iterator_<T, _Thing, _Copy> const>()._thing();
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
inline auto bidirectional_iterator<T>::operator*() const -> T const &
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator*();
}

template<typename T>
inline auto bidirectional_iterator<T>::operator->() const -> T const *
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator->();
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
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto bidirectional_iterator<T>::operator!=(forward_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator!=(other);
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
    return std::dynamic_pointer_cast<typename forward_iterator<T>::_derived const>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto bidirectional_iterator<T>::operator!=(forward_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_iterator<T>::_derived const>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto bidirectional_iterator<T>::operator==(bidirectional_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived const>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto bidirectional_iterator<T>::operator!=(bidirectional_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived const>(strange::_common::_shared)->operator!=(other);
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
    return std::dynamic_pointer_cast<typename bidirectional_iterator<T>::_derived const>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto bidirectional_iterator<T>::operator!=(bidirectional_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_iterator<T>::_derived const>(strange::_common::_shared)->operator!=(other);
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
    return _thing == other.template _static<forward_const_iterator_<T, _Thing, _Copy> const>()._thing();
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
    return _thing == other.template _static<forward_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_iterator_<T, _Thing, _Copy>::_instance::operator!=(forward_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_iterator_<T, _Thing, _Copy>::_instance::operator==(bidirectional_const_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<bidirectional_const_iterator_<T, _Thing, _Copy> const>()._thing();
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
    return _thing == other.template _static<bidirectional_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto bidirectional_iterator_<T, _Thing, _Copy>::_instance::operator!=(bidirectional_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator*() const -> T const &
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator*();
}

template<typename T>
inline auto random_access_const_iterator<T>::operator->() const -> T const *
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator->();
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
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator!=(forward_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator==(bidirectional_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived const>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator!=(bidirectional_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived const>(strange::_common::_shared)->operator!=(other);
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
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived const>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator!=(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived const>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator<(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived const>(strange::_common::_shared)->operator<(other);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator>(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived const>(strange::_common::_shared)->operator>(other);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator<=(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived const>(strange::_common::_shared)->operator<=(other);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator>=(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived const>(strange::_common::_shared)->operator>=(other);
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
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived const>(strange::_common::_shared)->operator+(n);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator-(std::ptrdiff_t n) const -> random_access_const_iterator<T>
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived const>(strange::_common::_shared)->operator-(n);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator-(random_access_const_iterator<T> const & other) const -> std::ptrdiff_t
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived const>(strange::_common::_shared)->operator-(other);
}

template<typename T>
inline auto random_access_const_iterator<T>::operator[](std::ptrdiff_t n) const -> T const &
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived const>(strange::_common::_shared)->operator[](n);
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
    return _thing == other.template _static<forward_const_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator!=(forward_const_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator==(bidirectional_const_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<bidirectional_const_iterator_<T, _Thing, _Copy> const>()._thing();
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
    return _thing == other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator!=(random_access_const_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator<(random_access_const_iterator<T> const & other) const -> bool
{
    return _thing < other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator>(random_access_const_iterator<T> const & other) const -> bool
{
    return _thing > other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator<=(random_access_const_iterator<T> const & other) const -> bool
{
    return _thing <= other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator>=(random_access_const_iterator<T> const & other) const -> bool
{
    return _thing >= other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing();
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
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator-(random_access_const_iterator<T> const & other) const -> std::ptrdiff_t
{
    return _thing - other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_const_iterator_<T, _Thing, _Copy>::_instance::operator[](std::ptrdiff_t n) const -> T const &
{
    return _thing.operator[](n);
}

template<typename T>
inline auto random_access_iterator<T>::operator*() const -> T const &
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator*();
}

template<typename T>
inline auto random_access_iterator<T>::operator->() const -> T const *
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator->();
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
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator!=(forward_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_const_iterator<T>::_derived const>(strange::_common::_shared)->operator!=(other);
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
    return std::dynamic_pointer_cast<typename forward_iterator<T>::_derived const>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator!=(forward_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename forward_iterator<T>::_derived const>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator==(bidirectional_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived const>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator!=(bidirectional_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_const_iterator<T>::_derived const>(strange::_common::_shared)->operator!=(other);
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
    return std::dynamic_pointer_cast<typename bidirectional_iterator<T>::_derived const>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator!=(bidirectional_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename bidirectional_iterator<T>::_derived const>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator==(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived const>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator!=(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived const>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator<(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived const>(strange::_common::_shared)->operator<(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator>(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived const>(strange::_common::_shared)->operator>(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator<=(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived const>(strange::_common::_shared)->operator<=(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator>=(random_access_const_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived const>(strange::_common::_shared)->operator>=(other);
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
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived const>(strange::_common::_shared)->operator+(n);
}

template<typename T>
inline auto random_access_iterator<T>::operator-(std::ptrdiff_t n) const -> random_access_const_iterator<T>
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived const>(strange::_common::_shared)->operator-(n);
}

template<typename T>
inline auto random_access_iterator<T>::operator-(random_access_const_iterator<T> const & other) const -> std::ptrdiff_t
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived const>(strange::_common::_shared)->operator-(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator[](std::ptrdiff_t n) const -> T const &
{
    return std::dynamic_pointer_cast<typename random_access_const_iterator<T>::_derived const>(strange::_common::_shared)->operator[](n);
}

template<typename T>
inline auto random_access_iterator<T>::operator==(random_access_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_iterator<T>::_derived const>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator!=(random_access_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_iterator<T>::_derived const>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator<(random_access_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_iterator<T>::_derived const>(strange::_common::_shared)->operator<(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator>(random_access_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_iterator<T>::_derived const>(strange::_common::_shared)->operator>(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator<=(random_access_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_iterator<T>::_derived const>(strange::_common::_shared)->operator<=(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator>=(random_access_iterator<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename random_access_iterator<T>::_derived const>(strange::_common::_shared)->operator>=(other);
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
inline auto random_access_iterator<T>::operator-(random_access_iterator<T> const & other) const -> std::ptrdiff_t
{
    return std::dynamic_pointer_cast<typename random_access_iterator<T>::_derived const>(strange::_common::_shared)->operator-(other);
}

template<typename T>
inline auto random_access_iterator<T>::operator[](std::ptrdiff_t n) -> T &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename random_access_iterator<T>::_derived>(strange::_common::_shared)->operator[](n);
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
    return _thing == other.template _static<forward_const_iterator_<T, _Thing, _Copy> const>()._thing();
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
    return _thing == other.template _static<forward_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator!=(forward_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator==(bidirectional_const_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<bidirectional_const_iterator_<T, _Thing, _Copy> const>()._thing();
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
    return _thing == other.template _static<bidirectional_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator!=(bidirectional_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator==(random_access_const_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator!=(random_access_const_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator<(random_access_const_iterator<T> const & other) const -> bool
{
    return _thing < other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator>(random_access_const_iterator<T> const & other) const -> bool
{
    return _thing > other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator<=(random_access_const_iterator<T> const & other) const -> bool
{
    return _thing <= other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator>=(random_access_const_iterator<T> const & other) const -> bool
{
    return _thing >= other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing();
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
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator-(random_access_const_iterator<T> const & other) const -> std::ptrdiff_t
{
    return _thing - other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator[](std::ptrdiff_t n) const -> T const &
{
    return _thing.operator[](n);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator==(random_access_iterator<T> const & other) const -> bool
{
    return _thing == other.template _static<random_access_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator!=(random_access_iterator<T> const & other) const -> bool
{
    return !operator==(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator<(random_access_iterator<T> const & other) const -> bool
{
    return _thing < other.template _static<random_access_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator>(random_access_iterator<T> const & other) const -> bool
{
    return _thing > other.template _static<random_access_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator<=(random_access_iterator<T> const & other) const -> bool
{
    return _thing <= other.template _static<random_access_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator>=(random_access_iterator<T> const & other) const -> bool
{
    return _thing >= other.template _static<random_access_iterator_<T, _Thing, _Copy> const>()._thing();
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
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator-(random_access_iterator<T> const & other) const -> std::ptrdiff_t
{
    return _thing - other.template _static<random_access_iterator_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto random_access_iterator_<T, _Thing, _Copy>::_instance::operator[](std::ptrdiff_t n) -> T &
{
    return _thing.operator[](n);
}

template<typename T>
inline auto vector<T>::operator=(std::initializer_list<T> ilist) -> vector &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->operator=(ilist);
    return *this;
}

template<typename T>
inline auto vector<T>::assign(std::size_t count, T const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->assign(count, value);
}

template<typename T>
inline auto vector<T>::assign(typename strange::forward_const_iterator<T> first, typename strange::forward_const_iterator<T> last) -> void
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
inline auto vector<T>::at(std::size_t pos) -> T &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->at(pos);
}

template<typename T>
inline auto vector<T>::at(std::size_t pos) const -> T const &
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->at(pos);
}

template<typename T>
inline auto vector<T>::operator[](std::size_t pos) -> T &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->operator[](pos);
}

template<typename T>
inline auto vector<T>::operator[](std::size_t pos) const -> T const &
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->operator[](pos);
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
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->front();
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
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->back();
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
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->data();
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
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->begin();
}

template<typename T>
inline auto vector<T>::cbegin() const -> typename strange::random_access_const_iterator<T>
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->cbegin();
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
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->end();
}

template<typename T>
inline auto vector<T>::cend() const -> typename strange::random_access_const_iterator<T>
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->cend();
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
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->rbegin();
}

template<typename T>
inline auto vector<T>::crbegin() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->crbegin();
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
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->rend();
}

template<typename T>
inline auto vector<T>::crend() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->crend();
}

template<typename T>
inline auto vector<T>::empty() const -> bool
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->empty();
}

template<typename T>
inline auto vector<T>::size() const -> std::size_t
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->size();
}

template<typename T>
inline auto vector<T>::max_size() const -> std::size_t
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->max_size();
}

template<typename T>
inline auto vector<T>::reserve(std::size_t new_cap) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->reserve(new_cap);
}

template<typename T>
inline auto vector<T>::capacity() const -> std::size_t
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->capacity();
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
    if (strange::_common::_mutate())
    {
        pos = cbegin() + index;
    }
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, value);
}

template<typename T>
inline auto vector<T>::insert(typename strange::random_access_const_iterator<T> pos, T && value) -> typename strange::random_access_iterator<T>
{
    auto const index = pos - cbegin();
    if (strange::_common::_mutate())
    {
        pos = cbegin() + index;
    }
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, std::move(value));
}

template<typename T>
inline auto vector<T>::insert(typename strange::random_access_const_iterator<T> pos, std::size_t count, T const & value) -> typename strange::random_access_iterator<T>
{
    auto const index = pos - cbegin();
    if (strange::_common::_mutate())
    {
        pos = cbegin() + index;
    }
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, count, value);
}

template<typename T>
inline auto vector<T>::insert(typename strange::random_access_const_iterator<T> pos, forward_const_iterator<T> first, forward_const_iterator<T> last) -> typename strange::random_access_iterator<T>
{
    auto const index = pos - cbegin();
    if (strange::_common::_mutate())
    {
        pos = cbegin() + index;
    }
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, first, last);
}

template<typename T>
inline auto vector<T>::insert(typename strange::random_access_const_iterator<T> pos, std::initializer_list<T> ilist) -> typename strange::random_access_iterator<T>
{
    auto const index = pos - cbegin();
    if (strange::_common::_mutate())
    {
        pos = cbegin() + index;
    }
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, ilist);
}

template<typename T>
inline auto vector<T>::erase(typename strange::random_access_const_iterator<T> pos) -> typename strange::random_access_iterator<T>
{
    auto const index = pos - cbegin();
    if (strange::_common::_mutate())
    {
        pos = cbegin() + index;
    }
    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->erase(pos);
}

template<typename T>
inline auto vector<T>::erase(typename strange::random_access_const_iterator<T> first, typename strange::random_access_const_iterator<T> last) -> typename strange::random_access_iterator<T>
{
    auto const first_index = first - cbegin();
    auto const last_index = last - cbegin();
    if (strange::_common::_mutate())
    {
        first = cbegin() + first_index;
        last = cbegin() + last_index;
    }
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
inline auto vector<T>::resize(std::size_t count) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->resize(count);
}

template<typename T>
inline auto vector<T>::resize(std::size_t count, T const & value) -> void
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
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto vector<T>::operator!=(vector<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->operator!=(other);
}

template<typename T>
inline auto vector<T>::operator<(vector<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->operator<(other);
}

template<typename T>
inline auto vector<T>::operator>(vector<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->operator>(other);
}

template<typename T>
inline auto vector<T>::operator<=(vector<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->operator<=(other);
}

template<typename T>
inline auto vector<T>::operator>=(vector<T> const & other) const -> bool
{
    return std::dynamic_pointer_cast<typename vector<T>::_derived const>(strange::_common::_shared)->operator>=(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::operator=(std::initializer_list<T> ilist) -> void
{
    _thing.operator=(ilist);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::assign(std::size_t count, T const & value) -> void
{
    _thing.assign(count, value);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::assign(typename strange::forward_const_iterator<T> first, typename strange::forward_const_iterator<T> last) -> void
{
    _thing.assign(first, last);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::assign(std::initializer_list<T> ilist) -> void
{
    _thing.assign(ilist);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::at(std::size_t pos) -> T &
{
    return _thing.at(pos);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::at(std::size_t pos) const -> T const &
{
    return _thing.at(pos);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::operator[](std::size_t pos) -> T &
{
    return _thing.operator[](pos);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::operator[](std::size_t pos) const -> T const &
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
    return strange::random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.begin());
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::begin() const -> typename strange::random_access_const_iterator<T>
{
    return strange::random_access_const_iterator<T>::template _make<decltype(_thing.begin())>(_thing.begin());
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::cbegin() const -> typename strange::random_access_const_iterator<T>
{
    return strange::random_access_const_iterator<T>::template _make<decltype(_thing.cbegin())>(_thing.cbegin());
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::end() -> typename strange::random_access_iterator<T>
{
    return strange::random_access_iterator<T>::template _make<decltype(_thing.end())>(_thing.end());
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::end() const -> typename strange::random_access_const_iterator<T>
{
    return strange::random_access_const_iterator<T>::template _make<decltype(_thing.end())>(_thing.end());
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::cend() const -> typename strange::random_access_const_iterator<T>
{
    return strange::random_access_const_iterator<T>::template _make<decltype(_thing.cend())>(_thing.cend());
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::rbegin() -> typename std::reverse_iterator<strange::random_access_iterator<T>>
{
    return typename std::reverse_iterator<strange::random_access_iterator<T>>{strange::random_access_iterator<T>::template _make<decltype(_thing.end())>(_thing.end())};
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::rbegin() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>
{
    return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{strange::random_access_const_iterator<T>::template _make<decltype(_thing.end())>(_thing.end())};
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::crbegin() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>
{
    return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{strange::random_access_const_iterator<T>::template _make<decltype(_thing.cend())>(_thing.cend())};
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::rend() -> typename std::reverse_iterator<strange::random_access_iterator<T>>
{
    return typename std::reverse_iterator<strange::random_access_iterator<T>>{strange::random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.begin())};
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::rend() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>
{
    return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{strange::random_access_const_iterator<T>::template _make<decltype(_thing.begin())>(_thing.begin())};
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::crend() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>
{
    return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{strange::random_access_const_iterator<T>::template _make<decltype(_thing.cbegin())>(_thing.cbegin())};
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::empty() const -> bool
{
    return _thing.empty();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::size() const -> std::size_t
{
    return _thing.size();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::max_size() const -> std::size_t
{
    return _thing.max_size();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::reserve(std::size_t new_cap) -> void
{
    _thing.reserve(new_cap);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::capacity() const -> std::size_t
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
    return strange::random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<strange::random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), value));
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::insert(typename strange::random_access_const_iterator<T> pos, T && value) -> typename strange::random_access_iterator<T>
{
    return strange::random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<strange::random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), std::move(value)));
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::insert(typename strange::random_access_const_iterator<T> pos, std::size_t count, T const & value) -> typename strange::random_access_iterator<T>
{
    return strange::random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<strange::random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), count, value));
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::insert(typename strange::random_access_const_iterator<T> pos, forward_const_iterator<T> first, forward_const_iterator<T> last) -> typename strange::random_access_iterator<T>
{
    return strange::random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<strange::random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), first, last));
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::insert(typename strange::random_access_const_iterator<T> pos, std::initializer_list<T> ilist) -> typename strange::random_access_iterator<T>
{
    return strange::random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<strange::random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), ilist));
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::erase(typename strange::random_access_const_iterator<T> pos) -> typename strange::random_access_iterator<T>
{
    return strange::random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.erase(pos.template _static<strange::random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing()));
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::erase(typename strange::random_access_const_iterator<T> first, typename strange::random_access_const_iterator<T> last) -> typename strange::random_access_iterator<T>
{
    return strange::random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.erase(first.template _static<strange::random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), last.template _static<strange::random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing()));
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
inline auto vector_<T, _Thing, _Copy>::_instance::resize(std::size_t count) -> void
{
    _thing.resize(count);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::resize(std::size_t count, T const & value) -> void
{
    _thing.resize(count, value);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::swap(vector<T> & other) -> void
{
    _thing.swap(other.template _static<strange::vector_<T, _Thing, _Copy>>()._thing());
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::operator==(vector<T> const & other) const -> bool
{
    return _thing == other.template _static<strange::vector_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::operator!=(vector<T> const & other) const -> bool
{
    return _thing != other.template _static<strange::vector_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::operator<(vector<T> const & other) const -> bool
{
    return _thing < other.template _static<strange::vector_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::operator>(vector<T> const & other) const -> bool
{
    return _thing > other.template _static<strange::vector_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::operator<=(vector<T> const & other) const -> bool
{
    return _thing <= other.template _static<strange::vector_<T, _Thing, _Copy> const>()._thing();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::operator>=(vector<T> const & other) const -> bool
{
    return _thing >= other.template _static<strange::vector_<T, _Thing, _Copy> const>()._thing();
}

}

