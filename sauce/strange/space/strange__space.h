#pragma once
#include "../common/strange__common.h"
#include "../reflection/strange__reflection.h"
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

template<typename T>
struct iterator;

template<typename T, typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct iterator_;

template<typename T>
struct input_iterator;

template<typename T, typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>>
struct input_iterator_;

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

template<typename T>
struct reflection<strange::iterator<T>>
{
    inline static auto name() -> std::string
    {
        return "strange::iterator<" + reflection<T>::name() + ">";
    }
};

template<typename T, typename _Thing, bool _Copy>
struct reflection<strange::iterator_<T, _Thing, _Copy>>
{
    inline static auto name() -> std::string
    {
        return "strange::iterator_<" + reflection<T>::name() + ", " + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
    }
};

template<typename T>
struct reflection<strange::input_iterator<T>>
{
    inline static auto name() -> std::string
    {
        return "strange::input_iterator<" + reflection<T>::name() + ">";
    }
};

template<typename T, typename _Thing, bool _Copy>
struct reflection<strange::input_iterator_<T, _Thing, _Copy>>
{
    inline static auto name() -> std::string
    {
        return "strange::input_iterator_<" + reflection<T>::name() + ", " + reflection<_Thing>::name() + ", " + (_Copy ? "true" : "false") + ">";
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
        static inline auto _static_shared_to_base(std::shared_ptr<any::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return derived;
        }
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<any::_derived>(strange::_common::_shared).operator bool();
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

template<typename T>
struct iterator : any
{
    inline iterator() = default;

    inline iterator(iterator const & other)
    :strange::_common{other}
    ,any{}
    {
    }

    inline iterator(iterator && other)
    :strange::_common{std::move(other)}
    ,any{}
    {
    }

    inline auto operator=(iterator const & other) -> iterator &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(iterator && other) -> iterator &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline iterator(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,any{}
    {
    }

    explicit inline iterator(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,any{}
    {
    }

    using value_type = T;

    using difference_type = std::ptrdiff_t;

    using reference = value_type &;

    using pointer = value_type *;

protected:
    struct _derived : any::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<iterator::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return any::_derived::_static_shared_to_base(derived);
        }

        virtual auto operator*() -> T & = 0;

        virtual auto operator*() const -> T const & = 0;

        virtual auto operator->() -> T * = 0;

        virtual auto operator->() const -> T const * = 0;

        virtual auto operator++() -> void = 0;

        virtual auto operator++(int i) -> void = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<iterator::_derived>(strange::_common::_shared).operator bool();
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> iterator
    {
        return iterator{iterator::_derived::_static_shared_to_base(std::make_shared<typename iterator_<T, _Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    using _Kind_ = iterator;

    inline static std::string const _cat_ = strange::reflection<_Kind_>::name();

    inline static std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(any::_cats_.cbegin(), any::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();


    inline auto operator*() -> T &;

    inline auto operator*() const -> T const &;

    inline auto operator->() -> T *;

    inline auto operator->() const -> T const *;

    inline auto operator++() -> iterator &;

    inline auto operator++(int i) -> iterator;
};

template<typename T, typename _Thing, bool _Copy>
struct iterator_ : iterator<T>
{
    inline iterator_() = default;

    inline iterator_(iterator_ const & other)
    :strange::_common{other}
    ,iterator<T>{}
    {
    }

    inline iterator_(iterator_ && other)
    :strange::_common{std::move(other)}
    ,iterator<T>{}
    {
    }

    inline auto operator=(iterator_ const & other) -> iterator_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(iterator_ && other) -> iterator_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline iterator_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,iterator<T>{}
    {
    }

    explicit inline iterator_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,iterator<T>{}
    {
    }

private:
    friend struct iterator<T>;

    struct _instance final : iterator<T>::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :iterator_::_derived{}
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
                return iterator_::_derived::_static_shared_to_base(std::make_shared<iterator_::_instance>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto _cat() const -> std::string final
        {
            return iterator<T>::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return iterator<T>::_cats_;
        }

        inline auto _name() const -> std::string final
        {
            return iterator_::_name_;
        }

        inline auto operator*() -> T & final;

        inline auto operator*() const -> T const & final;

        inline auto operator->() -> T * final;

        inline auto operator->() const -> T const * final;

        inline auto operator++() -> void final;

        inline auto operator++(int i) -> void final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    inline static auto _make_(_Args && ... _args) -> iterator_
    {
        return iterator_{iterator_::_derived::_static_shared_to_base(std::make_shared<iterator_::_instance>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<iterator_::_instance>(strange::_common::_shared).operator bool();
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Abstraction_ = iterator_;
    using _Thing_ = _Thing;

    inline static std::string const _name_ = strange::reflection<_Abstraction_>::name();
};

template<typename T>
struct input_iterator : iterator<T>
{
    inline input_iterator() = default;

    inline input_iterator(input_iterator const & other)
    :strange::_common{other}
    ,iterator<T>{}
    {
    }

    inline input_iterator(input_iterator && other)
    :strange::_common{std::move(other)}
    ,iterator<T>{}
    {
    }

    inline auto operator=(input_iterator const & other) -> input_iterator &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(input_iterator && other) -> input_iterator &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline input_iterator(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,iterator<T>{}
    {
    }

    explicit inline input_iterator(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,iterator<T>{}
    {
    }

    using iterator_category = std::input_iterator_tag;

protected:
    struct _derived : iterator<T>::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<input_iterator::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return iterator<T>::_derived::_static_shared_to_base(derived);
        }

        virtual auto operator==(input_iterator<T> const & other) -> bool = 0;

        virtual auto operator!=(input_iterator<T> const & other) -> bool = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<input_iterator::_derived>(strange::_common::_shared).operator bool();
    }

    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> input_iterator
    {
        return input_iterator{input_iterator::_derived::_static_shared_to_base(std::make_shared<typename input_iterator_<T, _Thing, _Copy>::_instance>(std::forward<_Args>(_args) ...))};
    }

    using _Kind_ = input_iterator;

    inline static std::string const _cat_ = strange::reflection<_Kind_>::name();

    inline static std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(iterator<T>::_cats_.cbegin(), iterator<T>::_cats_.cend());
        cats.insert(_cat_);
        return cats;
    }();


    inline auto operator==(input_iterator<T> const & other) -> bool;

    inline auto operator!=(input_iterator<T> const & other) -> bool;
};

template<typename T, typename _Thing, bool _Copy>
struct input_iterator_ : input_iterator<T>
{
    inline input_iterator_() = default;

    inline input_iterator_(input_iterator_ const & other)
    :strange::_common{other}
    ,input_iterator<T>{}
    {
    }

    inline input_iterator_(input_iterator_ && other)
    :strange::_common{std::move(other)}
    ,input_iterator<T>{}
    {
    }

    inline auto operator=(input_iterator_ const & other) -> input_iterator_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(input_iterator_ && other) -> input_iterator_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline input_iterator_(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    ,input_iterator<T>{}
    {
    }

    explicit inline input_iterator_(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    ,input_iterator<T>{}
    {
    }

private:
    friend struct input_iterator<T>;

    struct _instance final : input_iterator<T>::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :input_iterator_::_derived{}
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
                return input_iterator_::_derived::_static_shared_to_base(std::make_shared<input_iterator_::_instance>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto _cat() const -> std::string final
        {
            return input_iterator<T>::_cat_;
        }

        inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return input_iterator<T>::_cats_;
        }

        inline auto _name() const -> std::string final
        {
            return input_iterator_::_name_;
        }

        inline auto operator==(input_iterator<T> const & other) -> bool final;

        inline auto operator!=(input_iterator<T> const & other) -> bool final;

        _Thing _thing;
    };

public:
    template<typename ... _Args>
    inline static auto _make_(_Args && ... _args) -> input_iterator_
    {
        return input_iterator_{input_iterator_::_derived::_static_shared_to_base(std::make_shared<input_iterator_::_instance>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<input_iterator_::_instance>(strange::_common::_shared).operator bool();
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<input_iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<input_iterator_::_instance>(strange::_common::_shared)->_thing;
    }

    using _Abstraction_ = input_iterator_;
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

    using iterator = typename std::vector<T>::iterator;

    using const_iterator = typename std::vector<T>::const_iterator;

    using reverse_iterator = typename std::vector<T>::reverse_iterator;

    using const_reverse_iterator = typename std::vector<T>::const_reverse_iterator;

protected:
    struct _derived : any::_derived
    {
        static inline auto _static_shared_to_base(std::shared_ptr<vector::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return any::_derived::_static_shared_to_base(derived);
        }

        virtual auto operator=(std::vector<T> const & other) -> void = 0;

        virtual auto operator=(std::vector<T> && other) -> void = 0;

        virtual auto operator=(std::initializer_list<T> ilist) -> void = 0;

        virtual auto assign(size_t count, T const & value) -> void = 0;

        virtual auto assign(input_iterator<T> first, input_iterator<T> last) -> void = 0;

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

        virtual auto begin() -> typename std::vector<T>::iterator = 0;

        virtual auto begin() const -> typename std::vector<T>::const_iterator = 0;

        virtual auto cbegin() const -> typename std::vector<T>::const_iterator = 0;

        virtual auto end() -> typename std::vector<T>::iterator = 0;

        virtual auto end() const -> typename std::vector<T>::const_iterator = 0;

        virtual auto cend() const -> typename std::vector<T>::const_iterator = 0;

        virtual auto rbegin() -> typename std::vector<T>::reverse_iterator = 0;

        virtual auto rbegin() const -> typename std::vector<T>::const_reverse_iterator = 0;

        virtual auto crbegin() const -> typename std::vector<T>::const_reverse_iterator = 0;

        virtual auto rend() -> typename std::vector<T>::reverse_iterator = 0;

        virtual auto rend() const -> typename std::vector<T>::const_reverse_iterator = 0;

        virtual auto crend() const -> typename std::vector<T>::const_reverse_iterator = 0;

        virtual auto empty() const -> bool = 0;

        virtual auto size() const -> size_t = 0;

        virtual auto max_size() const -> size_t = 0;

        virtual auto reserve(size_t new_cap) -> void = 0;

        virtual auto capacity() const -> size_t = 0;

        virtual auto shrink_to_fit() -> void = 0;

        virtual auto clear() -> void = 0;

        virtual auto insert(typename std::vector<T>::const_iterator pos, T const & value) -> typename std::vector<T>::iterator = 0;

        virtual auto insert(typename std::vector<T>::const_iterator pos, T && value) -> typename std::vector<T>::iterator = 0;

        virtual auto insert(typename std::vector<T>::const_iterator pos, size_t count, T const & value) -> typename std::vector<T>::iterator = 0;

        virtual auto insert(typename std::vector<T>::const_iterator pos, input_iterator<T> first, input_iterator<T> last) -> void = 0;

        virtual auto insert(typename std::vector<T>::const_iterator pos, std::initializer_list<T> ilist) -> typename std::vector<T>::iterator = 0;

        virtual auto erase(typename std::vector<T>::const_iterator pos) -> typename std::vector<T>::iterator = 0;

        virtual auto erase(typename std::vector<T>::const_iterator first, typename std::vector<T>::const_iterator last) -> typename std::vector<T>::iterator = 0;

        virtual auto push_back(T const & value) -> void = 0;

        virtual auto push_back(T && value) -> void = 0;

        virtual auto pop_back() -> void = 0;

        virtual auto resize(size_t count) -> void = 0;

        virtual auto resize(size_t count, T const & value) -> void = 0;

        virtual auto swap(std::vector<T> & other) -> void = 0;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<vector::_derived>(strange::_common::_shared).operator bool();
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


    inline auto operator=(std::vector<T> const & other) -> vector &;

    inline auto operator=(std::vector<T> && other) -> vector &;

    inline auto operator=(std::initializer_list<T> ilist) -> vector &;

    inline auto assign(size_t count, T const & value) -> void;

    inline auto assign(input_iterator<T> first, input_iterator<T> last) -> void;

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

    inline auto begin() -> typename std::vector<T>::iterator;

    inline auto begin() const -> typename std::vector<T>::const_iterator;

    inline auto cbegin() const -> typename std::vector<T>::const_iterator;

    inline auto end() -> typename std::vector<T>::iterator;

    inline auto end() const -> typename std::vector<T>::const_iterator;

    inline auto cend() const -> typename std::vector<T>::const_iterator;

    inline auto rbegin() -> typename std::vector<T>::reverse_iterator;

    inline auto rbegin() const -> typename std::vector<T>::const_reverse_iterator;

    inline auto crbegin() const -> typename std::vector<T>::const_reverse_iterator;

    inline auto rend() -> typename std::vector<T>::reverse_iterator;

    inline auto rend() const -> typename std::vector<T>::const_reverse_iterator;

    inline auto crend() const -> typename std::vector<T>::const_reverse_iterator;

    inline auto empty() const -> bool;

    inline auto size() const -> size_t;

    inline auto max_size() const -> size_t;

    inline auto reserve(size_t new_cap) -> void;

    inline auto capacity() const -> size_t;

    inline auto shrink_to_fit() -> void;

    inline auto clear() -> void;

    inline auto insert(typename std::vector<T>::const_iterator pos, T const & value) -> typename std::vector<T>::iterator;

    inline auto insert(typename std::vector<T>::const_iterator pos, T && value) -> typename std::vector<T>::iterator;

    inline auto insert(typename std::vector<T>::const_iterator pos, size_t count, T const & value) -> typename std::vector<T>::iterator;

    inline auto insert(typename std::vector<T>::const_iterator pos, input_iterator<T> first, input_iterator<T> last) -> void;

    inline auto insert(typename std::vector<T>::const_iterator pos, std::initializer_list<T> ilist) -> typename std::vector<T>::iterator;

    inline auto erase(typename std::vector<T>::const_iterator pos) -> typename std::vector<T>::iterator;

    inline auto erase(typename std::vector<T>::const_iterator first, typename std::vector<T>::const_iterator last) -> typename std::vector<T>::iterator;

    inline auto push_back(T const & value) -> void;

    inline auto push_back(T && value) -> void;

    inline auto pop_back() -> void;

    inline auto resize(size_t count) -> void;

    inline auto resize(size_t count, T const & value) -> void;

    inline auto swap(std::vector<T> & other) -> void;
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

        inline auto operator=(std::vector<T> const & other) -> void final;

        inline auto operator=(std::vector<T> && other) -> void final;

        inline auto operator=(std::initializer_list<T> ilist) -> void final;

        inline auto assign(size_t count, T const & value) -> void final;

        inline auto assign(input_iterator<T> first, input_iterator<T> last) -> void final;

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

        inline auto begin() -> typename std::vector<T>::iterator final;

        inline auto begin() const -> typename std::vector<T>::const_iterator final;

        inline auto cbegin() const -> typename std::vector<T>::const_iterator final;

        inline auto end() -> typename std::vector<T>::iterator final;

        inline auto end() const -> typename std::vector<T>::const_iterator final;

        inline auto cend() const -> typename std::vector<T>::const_iterator final;

        inline auto rbegin() -> typename std::vector<T>::reverse_iterator final;

        inline auto rbegin() const -> typename std::vector<T>::const_reverse_iterator final;

        inline auto crbegin() const -> typename std::vector<T>::const_reverse_iterator final;

        inline auto rend() -> typename std::vector<T>::reverse_iterator final;

        inline auto rend() const -> typename std::vector<T>::const_reverse_iterator final;

        inline auto crend() const -> typename std::vector<T>::const_reverse_iterator final;

        inline auto empty() const -> bool final;

        inline auto size() const -> size_t final;

        inline auto max_size() const -> size_t final;

        inline auto reserve(size_t new_cap) -> void final;

        inline auto capacity() const -> size_t final;

        inline auto shrink_to_fit() -> void final;

        inline auto clear() -> void final;

        inline auto insert(typename std::vector<T>::const_iterator pos, T const & value) -> typename std::vector<T>::iterator final;

        inline auto insert(typename std::vector<T>::const_iterator pos, T && value) -> typename std::vector<T>::iterator final;

        inline auto insert(typename std::vector<T>::const_iterator pos, size_t count, T const & value) -> typename std::vector<T>::iterator final;

        inline auto insert(typename std::vector<T>::const_iterator pos, input_iterator<T> first, input_iterator<T> last) -> void final;

        inline auto insert(typename std::vector<T>::const_iterator pos, std::initializer_list<T> ilist) -> typename std::vector<T>::iterator final;

        inline auto erase(typename std::vector<T>::const_iterator pos) -> typename std::vector<T>::iterator final;

        inline auto erase(typename std::vector<T>::const_iterator first, typename std::vector<T>::const_iterator last) -> typename std::vector<T>::iterator final;

        inline auto push_back(T const & value) -> void final;

        inline auto push_back(T && value) -> void final;

        inline auto pop_back() -> void final;

        inline auto resize(size_t count) -> void final;

        inline auto resize(size_t count, T const & value) -> void final;

        inline auto swap(std::vector<T> & other) -> void final;

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

template<typename T, typename _Thing, bool _Copy>
inline auto iterator_<T, _Thing, _Copy>::_instance::operator*() -> T &
{
    return _thing.operator*();
}

template<typename T, typename _Thing, bool _Copy>
inline auto iterator_<T, _Thing, _Copy>::_instance::operator*() const -> T const &
{
    return _thing.operator*();
}

template<typename T, typename _Thing, bool _Copy>
inline auto iterator_<T, _Thing, _Copy>::_instance::operator->() -> T *
{
    return _thing.operator->();
}

template<typename T, typename _Thing, bool _Copy>
inline auto iterator_<T, _Thing, _Copy>::_instance::operator->() const -> T const *
{
    return _thing.operator->();
}

template<typename T, typename _Thing, bool _Copy>
inline auto iterator_<T, _Thing, _Copy>::_instance::operator++() -> void
{
    _thing.operator++();
}

template<typename T, typename _Thing, bool _Copy>
inline auto iterator_<T, _Thing, _Copy>::_instance::operator++(int i) -> void
{
    _thing.operator++(i);
}

template<typename T>
inline auto iterator<T>::operator*() -> T &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<iterator<T>::_derived>(strange::_common::_shared)->operator*();
}

template<typename T>
inline auto iterator<T>::operator*() const -> T const &
{
    return std::dynamic_pointer_cast<iterator<T>::_derived>(strange::_common::_shared)->operator*();
}

template<typename T>
inline auto iterator<T>::operator->() -> T *
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<iterator<T>::_derived>(strange::_common::_shared)->operator->();
}

template<typename T>
inline auto iterator<T>::operator->() const -> T const *
{
    return std::dynamic_pointer_cast<iterator<T>::_derived>(strange::_common::_shared)->operator->();
}

template<typename T>
inline auto iterator<T>::operator++() -> iterator &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<iterator<T>::_derived>(strange::_common::_shared)->operator++();
    return *this;
}

template<typename T>
inline auto iterator<T>::operator++(int i) -> iterator
{
    auto _result = *this;
    strange::_common::_mutate();
    std::dynamic_pointer_cast<iterator<T>::_derived>(strange::_common::_shared)->operator++(i);
    return _result;
}

template<typename T, typename _Thing, bool _Copy>
inline auto input_iterator_<T, _Thing, _Copy>::_instance::operator==(input_iterator<T> const & other) -> bool
{
    return _thing.operator==(other.template _static<input_iterator_<T, _Thing, _Copy>>()._thing());
}

template<typename T, typename _Thing, bool _Copy>
inline auto input_iterator_<T, _Thing, _Copy>::_instance::operator!=(input_iterator<T> const & other) -> bool
{
    return _thing.operator!=(other.template _static<input_iterator_<T, _Thing, _Copy>>()._thing());
}

template<typename T>
inline auto input_iterator<T>::operator==(input_iterator<T> const & other) -> bool
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<input_iterator<T>::_derived>(strange::_common::_shared)->operator==(other);
}

template<typename T>
inline auto input_iterator<T>::operator!=(input_iterator<T> const & other) -> bool
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<input_iterator<T>::_derived>(strange::_common::_shared)->operator!=(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::operator=(std::vector<T> const & other) -> void
{
    _thing.operator=(other);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::operator=(std::vector<T> && other) -> void
{
    _thing.operator=(other);
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
inline auto vector_<T, _Thing, _Copy>::_instance::assign(input_iterator<T> first, input_iterator<T> last) -> void
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
inline auto vector_<T, _Thing, _Copy>::_instance::begin() -> typename std::vector<T>::iterator
{
    return _thing.begin();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::begin() const -> typename std::vector<T>::const_iterator
{
    return _thing.begin();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::cbegin() const -> typename std::vector<T>::const_iterator
{
    return _thing.cbegin();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::end() -> typename std::vector<T>::iterator
{
    return _thing.end();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::end() const -> typename std::vector<T>::const_iterator
{
    return _thing.end();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::cend() const -> typename std::vector<T>::const_iterator
{
    return _thing.cend();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::rbegin() -> typename std::vector<T>::reverse_iterator
{
    return _thing.rbegin();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::rbegin() const -> typename std::vector<T>::const_reverse_iterator
{
    return _thing.rbegin();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::crbegin() const -> typename std::vector<T>::const_reverse_iterator
{
    return _thing.crbegin();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::rend() -> typename std::vector<T>::reverse_iterator
{
    return _thing.rend();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::rend() const -> typename std::vector<T>::const_reverse_iterator
{
    return _thing.rend();
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::crend() const -> typename std::vector<T>::const_reverse_iterator
{
    return _thing.crend();
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
inline auto vector_<T, _Thing, _Copy>::_instance::insert(typename std::vector<T>::const_iterator pos, T const & value) -> typename std::vector<T>::iterator
{
    return _thing.insert(pos, value);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::insert(typename std::vector<T>::const_iterator pos, T && value) -> typename std::vector<T>::iterator
{
    return _thing.insert(pos, value);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::insert(typename std::vector<T>::const_iterator pos, size_t count, T const & value) -> typename std::vector<T>::iterator
{
    return _thing.insert(pos, count, value);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::insert(typename std::vector<T>::const_iterator pos, input_iterator<T> first, input_iterator<T> last) -> void
{
    _thing.insert(pos, first, last);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::insert(typename std::vector<T>::const_iterator pos, std::initializer_list<T> ilist) -> typename std::vector<T>::iterator
{
    return _thing.insert(pos, ilist);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::erase(typename std::vector<T>::const_iterator pos) -> typename std::vector<T>::iterator
{
    return _thing.erase(pos);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::erase(typename std::vector<T>::const_iterator first, typename std::vector<T>::const_iterator last) -> typename std::vector<T>::iterator
{
    return _thing.erase(first, last);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::push_back(T const & value) -> void
{
    _thing.push_back(value);
}

template<typename T, typename _Thing, bool _Copy>
inline auto vector_<T, _Thing, _Copy>::_instance::push_back(T && value) -> void
{
    _thing.push_back(value);
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
inline auto vector_<T, _Thing, _Copy>::_instance::swap(std::vector<T> & other) -> void
{
    _thing.swap(other);
}

template<typename T>
inline auto vector<T>::operator=(std::vector<T> const & other) -> vector &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->operator=(other);
    return *this;
}

template<typename T>
inline auto vector<T>::operator=(std::vector<T> && other) -> vector &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->operator=(other);
    return *this;
}

template<typename T>
inline auto vector<T>::operator=(std::initializer_list<T> ilist) -> vector &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->operator=(ilist);
    return *this;
}

template<typename T>
inline auto vector<T>::assign(size_t count, T const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->assign(count, value);
}

template<typename T>
inline auto vector<T>::assign(input_iterator<T> first, input_iterator<T> last) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->assign(first, last);
}

template<typename T>
inline auto vector<T>::assign(std::initializer_list<T> ilist) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->assign(ilist);
}

template<typename T>
inline auto vector<T>::at(size_t pos) -> T &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->at(pos);
}

template<typename T>
inline auto vector<T>::at(size_t pos) const -> T const &
{
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->at(pos);
}

template<typename T>
inline auto vector<T>::operator[](size_t pos) -> T &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->operator[](pos);
}

template<typename T>
inline auto vector<T>::operator[](size_t pos) const -> T const &
{
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->operator[](pos);
}

template<typename T>
inline auto vector<T>::front() -> T &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->front();
}

template<typename T>
inline auto vector<T>::front() const -> T const &
{
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->front();
}

template<typename T>
inline auto vector<T>::back() -> T &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->back();
}

template<typename T>
inline auto vector<T>::back() const -> T const &
{
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->back();
}

template<typename T>
inline auto vector<T>::data() -> T *
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->data();
}

template<typename T>
inline auto vector<T>::data() const -> T const *
{
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->data();
}

template<typename T>
inline auto vector<T>::begin() -> typename std::vector<T>::iterator
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->begin();
}

template<typename T>
inline auto vector<T>::begin() const -> typename std::vector<T>::const_iterator
{
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->begin();
}

template<typename T>
inline auto vector<T>::cbegin() const -> typename std::vector<T>::const_iterator
{
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->cbegin();
}

template<typename T>
inline auto vector<T>::end() -> typename std::vector<T>::iterator
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->end();
}

template<typename T>
inline auto vector<T>::end() const -> typename std::vector<T>::const_iterator
{
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->end();
}

template<typename T>
inline auto vector<T>::cend() const -> typename std::vector<T>::const_iterator
{
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->cend();
}

template<typename T>
inline auto vector<T>::rbegin() -> typename std::vector<T>::reverse_iterator
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->rbegin();
}

template<typename T>
inline auto vector<T>::rbegin() const -> typename std::vector<T>::const_reverse_iterator
{
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->rbegin();
}

template<typename T>
inline auto vector<T>::crbegin() const -> typename std::vector<T>::const_reverse_iterator
{
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->crbegin();
}

template<typename T>
inline auto vector<T>::rend() -> typename std::vector<T>::reverse_iterator
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->rend();
}

template<typename T>
inline auto vector<T>::rend() const -> typename std::vector<T>::const_reverse_iterator
{
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->rend();
}

template<typename T>
inline auto vector<T>::crend() const -> typename std::vector<T>::const_reverse_iterator
{
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->crend();
}

template<typename T>
inline auto vector<T>::empty() const -> bool
{
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->empty();
}

template<typename T>
inline auto vector<T>::size() const -> size_t
{
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->size();
}

template<typename T>
inline auto vector<T>::max_size() const -> size_t
{
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->max_size();
}

template<typename T>
inline auto vector<T>::reserve(size_t new_cap) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->reserve(new_cap);
}

template<typename T>
inline auto vector<T>::capacity() const -> size_t
{
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->capacity();
}

template<typename T>
inline auto vector<T>::shrink_to_fit() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->shrink_to_fit();
}

template<typename T>
inline auto vector<T>::clear() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->clear();
}

template<typename T>
inline auto vector<T>::insert(typename std::vector<T>::const_iterator pos, T const & value) -> typename std::vector<T>::iterator
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->insert(pos, value);
}

template<typename T>
inline auto vector<T>::insert(typename std::vector<T>::const_iterator pos, T && value) -> typename std::vector<T>::iterator
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->insert(pos, value);
}

template<typename T>
inline auto vector<T>::insert(typename std::vector<T>::const_iterator pos, size_t count, T const & value) -> typename std::vector<T>::iterator
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->insert(pos, count, value);
}

template<typename T>
inline auto vector<T>::insert(typename std::vector<T>::const_iterator pos, input_iterator<T> first, input_iterator<T> last) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->insert(pos, first, last);
}

template<typename T>
inline auto vector<T>::insert(typename std::vector<T>::const_iterator pos, std::initializer_list<T> ilist) -> typename std::vector<T>::iterator
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->insert(pos, ilist);
}

template<typename T>
inline auto vector<T>::erase(typename std::vector<T>::const_iterator pos) -> typename std::vector<T>::iterator
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->erase(pos);
}

template<typename T>
inline auto vector<T>::erase(typename std::vector<T>::const_iterator first, typename std::vector<T>::const_iterator last) -> typename std::vector<T>::iterator
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->erase(first, last);
}

template<typename T>
inline auto vector<T>::push_back(T const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->push_back(value);
}

template<typename T>
inline auto vector<T>::push_back(T && value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->push_back(value);
}

template<typename T>
inline auto vector<T>::pop_back() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->pop_back();
}

template<typename T>
inline auto vector<T>::resize(size_t count) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->resize(count);
}

template<typename T>
inline auto vector<T>::resize(size_t count, T const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->resize(count, value);
}

template<typename T>
inline auto vector<T>::swap(std::vector<T> & other) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector<T>::_derived>(strange::_common::_shared)->swap(other);
}

}
