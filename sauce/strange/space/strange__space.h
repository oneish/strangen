#pragma once
#include "../reflection/strange__reflection.h"
#include "../common/strange__common.h"
#include <string>
#include <vector>

#include <memory>
#include <type_traits>

namespace strange
{

template<typename T>
struct vector_a;

template<typename _Thing, typename T>
struct vector_a_;

struct parameter_a;

template<typename _Thing>
struct parameter_a_;

struct operation_a;

template<typename _Thing>
struct operation_a_;

struct abstraction_a;

template<typename _Thing>
struct abstraction_a_;

struct space_a;

template<typename _Thing>
struct space_a_;

}

namespace strange
{

template<typename T>
struct reflection<strange::vector_a<T>>
{
    inline static auto name() -> std::string
    {
        return "strange::vector_a<" + reflection<T>::name() + ">";
    }
};

template<typename _Thing, typename T>
struct reflection<strange::vector_a_<_Thing, T>>
{
    inline static auto name() -> std::string
    {
        return "strange::vector_a_<" + reflection<_Thing>::name() + ", " + reflection<T>::name() + ">";
    }
};

template<>
struct reflection<strange::parameter_a>
{
    inline static auto name() -> std::string
    {
        return "strange::parameter_a";
    }
};

template<typename _Thing>
struct reflection<strange::parameter_a_<_Thing>>
{
    inline static auto name() -> std::string
    {
        return "strange::parameter_a_<" + reflection<_Thing>::name() + ">";
    }
};

template<>
struct reflection<strange::operation_a>
{
    inline static auto name() -> std::string
    {
        return "strange::operation_a";
    }
};

template<typename _Thing>
struct reflection<strange::operation_a_<_Thing>>
{
    inline static auto name() -> std::string
    {
        return "strange::operation_a_<" + reflection<_Thing>::name() + ">";
    }
};

template<>
struct reflection<strange::abstraction_a>
{
    inline static auto name() -> std::string
    {
        return "strange::abstraction_a";
    }
};

template<typename _Thing>
struct reflection<strange::abstraction_a_<_Thing>>
{
    inline static auto name() -> std::string
    {
        return "strange::abstraction_a_<" + reflection<_Thing>::name() + ">";
    }
};

template<>
struct reflection<strange::space_a>
{
    inline static auto name() -> std::string
    {
        return "strange::space_a";
    }
};

template<typename _Thing>
struct reflection<strange::space_a_<_Thing>>
{
    inline static auto name() -> std::string
    {
        return "strange::space_a_<" + reflection<_Thing>::name() + ">";
    }
};

}

namespace strange
{

template<typename T>
struct vector_a : virtual strange::_common
{
    inline vector_a() = default;

    inline vector_a(vector_a const & other)
    :strange::_common{other}
    {
    }

    inline vector_a(vector_a && other)
    :strange::_common{std::move(other)}
    {
    }

    inline auto operator=(vector_a const & other) -> vector_a &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(vector_a && other) -> vector_a &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline vector_a(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    {
    }

    explicit inline vector_a(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    {
    }

protected:
    struct _derived : strange::_common::_base
    {
        static inline auto _static_shared_to_base(std::shared_ptr<vector_a::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return derived;
        }

        virtual auto operator=(std::vector<T> const & other) -> void = 0;

        virtual auto operator=(std::vector<T> && other) -> void = 0;

        virtual auto operator=(std::initializer_list<T> ilist) -> void = 0;

        virtual auto assign(size_t count, T const & value) -> void = 0;

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

//private:
    template<typename _Thing, bool _Copy>
    struct _instance final : vector_a::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :vector_a::_derived{}
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
                return vector_a::_derived::_static_shared_to_base(std::make_shared<vector_a::_instance<_Thing, _Copy>>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto operator=(std::vector<T> const & other) -> void final;

        inline auto operator=(std::vector<T> && other) -> void final;

        inline auto operator=(std::initializer_list<T> ilist) -> void final;

        inline auto assign(size_t count, T const & value) -> void final;

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

        inline auto insert(typename std::vector<T>::const_iterator pos, std::initializer_list<T> ilist) -> typename std::vector<T>::iterator final;

        inline auto erase(typename std::vector<T>::const_iterator pos) -> typename std::vector<T>::iterator final;

        inline auto erase(typename std::vector<T>::const_iterator first, typename std::vector<T>::const_iterator last) -> typename std::vector<T>::iterator final;

        inline auto push_back(T const & value) -> void final;

        inline auto push_back(T && value) -> void final;

        inline auto pop_back() -> void final;

        inline auto resize(size_t count) -> void final;

        inline auto resize(size_t count, T const & value) -> void final;

        inline auto swap(std::vector<T> & other) -> void final;

    //private:
        _Thing _thing;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<vector_a::_derived>(strange::_common::_shared).operator bool();
    }

    inline auto operator=(std::vector<T> const & other) -> vector_a &;

    inline auto operator=(std::vector<T> && other) -> vector_a &;

    inline auto operator=(std::initializer_list<T> ilist) -> vector_a &;

    inline auto assign(size_t count, T const & value) -> void;

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

template<typename _Thing, typename T>
struct vector_a_ : vector_a<T>
{
private:
    struct _tag_ {};

    explicit inline vector_a_(_tag_, std::shared_ptr<strange::_common::_base> && shared = std::shared_ptr<strange::_common::_base>{})
    :strange::_common{std::move(shared)}
    ,vector_a<T>{}
    {
    }

public:
    inline static auto _null() -> vector_a<T>
    {
        return vector_a<T>{};
    }

    inline static auto _null_() -> vector_a_
    {
        return vector_a_{_tag_{}};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> vector_a<T>
    {
        return vector_a<T>{vector_a_::_derived::_static_shared_to_base(std::make_shared<typename vector_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make_(_Args && ... _args) -> vector_a_
    {
        return vector_a_{_tag_{}, vector_a_::_derived::_static_shared_to_base(std::make_shared<typename vector_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _incognito(_Args && ... _args) -> vector_a<T>
    {
        return vector_a<T>{vector_a_::_derived::_static_shared_to_base(std::make_shared<typename vector_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _incognito_(_Args && ... _args) -> vector_a_
    {
        return vector_a_{_tag_{}, vector_a_::_derived::_static_shared_to_base(std::make_shared<typename vector_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<typename ... _Args>
    explicit inline vector_a_(_Args && ... _args)
    :strange::_common{vector_a_::_derived::_static_shared_to_base(std::make_shared<typename vector_a_::template _instance<_Thing, std::is_copy_constructible_v<_Thing>>>(std::forward<_Args>(_args) ...))}
    ,vector_a<T>{}
    {
    }

    inline auto operator=(vector_a_ const & other) -> vector_a_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(vector_a_ && other) -> vector_a_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<typename vector_a_::template _instance<_Thing, std::is_copy_constructible_v<_Thing>>>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<typename vector_a_::template _instance<_Thing, std::is_copy_constructible_v<_Thing>>>(strange::_common::_shared)->_thing;
    }

    using _Abstraction_ = vector_a_;
    using _Thing_ = _Thing;
    using _Kind_ = vector_a<T>;

    inline static std::string const _name_ = strange::reflection<_Abstraction_>::name();

    inline static std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(strange::reflection<_Kind_>::name());
        return cats;
    }();
};

struct parameter_a : virtual strange::_common
{
    inline parameter_a() = default;

    inline parameter_a(parameter_a const & other)
    :strange::_common{other}
    {
    }

    inline parameter_a(parameter_a && other)
    :strange::_common{std::move(other)}
    {
    }

    inline auto operator=(parameter_a const & other) -> parameter_a &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(parameter_a && other) -> parameter_a &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline parameter_a(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    {
    }

    explicit inline parameter_a(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    {
    }

protected:
    struct _derived : strange::_common::_base
    {
        static inline auto _static_shared_to_base(std::shared_ptr<parameter_a::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return derived;
        }

        virtual auto type() const -> std::string const & = 0;

        virtual auto type() -> std::string & = 0;

        virtual auto name() const -> std::string const & = 0;

        virtual auto name() -> std::string & = 0;

        virtual auto argument() const -> std::string const & = 0;

        virtual auto argument() -> std::string & = 0;
    };

//private:
    template<typename _Thing, bool _Copy>
    struct _instance final : parameter_a::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :parameter_a::_derived{}
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
                return parameter_a::_derived::_static_shared_to_base(std::make_shared<parameter_a::_instance<_Thing, _Copy>>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto type() const -> std::string const & final;

        inline auto type() -> std::string & final;

        inline auto name() const -> std::string const & final;

        inline auto name() -> std::string & final;

        inline auto argument() const -> std::string const & final;

        inline auto argument() -> std::string & final;

    //private:
        _Thing _thing;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<parameter_a::_derived>(strange::_common::_shared).operator bool();
    }

    inline auto type() const -> std::string const &;

    inline auto type() -> std::string &;

    inline auto name() const -> std::string const &;

    inline auto name() -> std::string &;

    inline auto argument() const -> std::string const &;

    inline auto argument() -> std::string &;
};

template<typename _Thing>
struct parameter_a_ : parameter_a
{
private:
    struct _tag_ {};

    explicit inline parameter_a_(_tag_, std::shared_ptr<strange::_common::_base> && shared = std::shared_ptr<strange::_common::_base>{})
    :strange::_common{std::move(shared)}
    ,parameter_a{}
    {
    }

public:
    inline static auto _null() -> parameter_a
    {
        return parameter_a{};
    }

    inline static auto _null_() -> parameter_a_
    {
        return parameter_a_{_tag_{}};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> parameter_a
    {
        return parameter_a{parameter_a_::_derived::_static_shared_to_base(std::make_shared<typename parameter_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make_(_Args && ... _args) -> parameter_a_
    {
        return parameter_a_{_tag_{}, parameter_a_::_derived::_static_shared_to_base(std::make_shared<typename parameter_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _incognito(_Args && ... _args) -> parameter_a
    {
        return parameter_a{parameter_a_::_derived::_static_shared_to_base(std::make_shared<typename parameter_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _incognito_(_Args && ... _args) -> parameter_a_
    {
        return parameter_a_{_tag_{}, parameter_a_::_derived::_static_shared_to_base(std::make_shared<typename parameter_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<typename ... _Args>
    explicit inline parameter_a_(_Args && ... _args)
    :strange::_common{parameter_a_::_derived::_static_shared_to_base(std::make_shared<typename parameter_a_::template _instance<_Thing, std::is_copy_constructible_v<_Thing>>>(std::forward<_Args>(_args) ...))}
    ,parameter_a{}
    {
    }

    inline auto operator=(parameter_a_ const & other) -> parameter_a_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(parameter_a_ && other) -> parameter_a_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<typename parameter_a_::template _instance<_Thing, std::is_copy_constructible_v<_Thing>>>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<typename parameter_a_::template _instance<_Thing, std::is_copy_constructible_v<_Thing>>>(strange::_common::_shared)->_thing;
    }

    using _Abstraction_ = parameter_a_;
    using _Thing_ = _Thing;
    using _Kind_ = parameter_a;

    inline static std::string const _name_ = strange::reflection<_Abstraction_>::name();

    inline static std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(strange::reflection<_Kind_>::name());
        return cats;
    }();
};

struct operation_a : virtual strange::_common
{
    inline operation_a() = default;

    inline operation_a(operation_a const & other)
    :strange::_common{other}
    {
    }

    inline operation_a(operation_a && other)
    :strange::_common{std::move(other)}
    {
    }

    inline auto operator=(operation_a const & other) -> operation_a &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(operation_a && other) -> operation_a &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline operation_a(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    {
    }

    explicit inline operation_a(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    {
    }

protected:
    struct _derived : strange::_common::_base
    {
        static inline auto _static_shared_to_base(std::shared_ptr<operation_a::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return derived;
        }

        virtual auto name() const -> std::string const & = 0;

        virtual auto name() -> std::string & = 0;

        virtual auto parameters() const -> std::vector<parameter_a> const & = 0;

        virtual auto parameters() -> std::vector<parameter_a> & = 0;

        virtual auto constness() const -> bool const & = 0;

        virtual auto constness() -> bool & = 0;

        virtual auto result() const -> std::string const & = 0;

        virtual auto result() -> std::string & = 0;

        virtual auto data() const -> bool const & = 0;

        virtual auto data() -> bool & = 0;
    };

//private:
    template<typename _Thing, bool _Copy>
    struct _instance final : operation_a::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :operation_a::_derived{}
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
                return operation_a::_derived::_static_shared_to_base(std::make_shared<operation_a::_instance<_Thing, _Copy>>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto name() const -> std::string const & final;

        inline auto name() -> std::string & final;

        inline auto parameters() const -> std::vector<parameter_a> const & final;

        inline auto parameters() -> std::vector<parameter_a> & final;

        inline auto constness() const -> bool const & final;

        inline auto constness() -> bool & final;

        inline auto result() const -> std::string const & final;

        inline auto result() -> std::string & final;

        inline auto data() const -> bool const & final;

        inline auto data() -> bool & final;

    //private:
        _Thing _thing;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared).operator bool();
    }

    inline auto name() const -> std::string const &;

    inline auto name() -> std::string &;

    inline auto parameters() const -> std::vector<parameter_a> const &;

    inline auto parameters() -> std::vector<parameter_a> &;

    inline auto constness() const -> bool const &;

    inline auto constness() -> bool &;

    inline auto result() const -> std::string const &;

    inline auto result() -> std::string &;

    inline auto data() const -> bool const &;

    inline auto data() -> bool &;
};

template<typename _Thing>
struct operation_a_ : operation_a
{
private:
    struct _tag_ {};

    explicit inline operation_a_(_tag_, std::shared_ptr<strange::_common::_base> && shared = std::shared_ptr<strange::_common::_base>{})
    :strange::_common{std::move(shared)}
    ,operation_a{}
    {
    }

public:
    inline static auto _null() -> operation_a
    {
        return operation_a{};
    }

    inline static auto _null_() -> operation_a_
    {
        return operation_a_{_tag_{}};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> operation_a
    {
        return operation_a{operation_a_::_derived::_static_shared_to_base(std::make_shared<typename operation_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make_(_Args && ... _args) -> operation_a_
    {
        return operation_a_{_tag_{}, operation_a_::_derived::_static_shared_to_base(std::make_shared<typename operation_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _incognito(_Args && ... _args) -> operation_a
    {
        return operation_a{operation_a_::_derived::_static_shared_to_base(std::make_shared<typename operation_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _incognito_(_Args && ... _args) -> operation_a_
    {
        return operation_a_{_tag_{}, operation_a_::_derived::_static_shared_to_base(std::make_shared<typename operation_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<typename ... _Args>
    explicit inline operation_a_(_Args && ... _args)
    :strange::_common{operation_a_::_derived::_static_shared_to_base(std::make_shared<typename operation_a_::template _instance<_Thing, std::is_copy_constructible_v<_Thing>>>(std::forward<_Args>(_args) ...))}
    ,operation_a{}
    {
    }

    inline auto operator=(operation_a_ const & other) -> operation_a_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(operation_a_ && other) -> operation_a_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<typename operation_a_::template _instance<_Thing, std::is_copy_constructible_v<_Thing>>>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<typename operation_a_::template _instance<_Thing, std::is_copy_constructible_v<_Thing>>>(strange::_common::_shared)->_thing;
    }

    using _Abstraction_ = operation_a_;
    using _Thing_ = _Thing;
    using _Kind_ = operation_a;

    inline static std::string const _name_ = strange::reflection<_Abstraction_>::name();

    inline static std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(strange::reflection<_Kind_>::name());
        return cats;
    }();
};

struct abstraction_a : virtual strange::_common
{
    inline abstraction_a() = default;

    inline abstraction_a(abstraction_a const & other)
    :strange::_common{other}
    {
    }

    inline abstraction_a(abstraction_a && other)
    :strange::_common{std::move(other)}
    {
    }

    inline auto operator=(abstraction_a const & other) -> abstraction_a &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(abstraction_a && other) -> abstraction_a &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline abstraction_a(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    {
    }

    explicit inline abstraction_a(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    {
    }

protected:
    struct _derived : strange::_common::_base
    {
        static inline auto _static_shared_to_base(std::shared_ptr<abstraction_a::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return derived;
        }

        virtual auto parameters() const -> std::vector<parameter_a> const & = 0;

        virtual auto parameters() -> std::vector<parameter_a> & = 0;

        virtual auto name() const -> std::string const & = 0;

        virtual auto name() -> std::string & = 0;

        virtual auto parents() const -> std::vector<std::string> const & = 0;

        virtual auto parents() -> std::vector<std::string> & = 0;

        virtual auto operations() const -> std::vector<operation_a> const & = 0;

        virtual auto operations() -> std::vector<operation_a> & = 0;
    };

//private:
    template<typename _Thing, bool _Copy>
    struct _instance final : abstraction_a::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :abstraction_a::_derived{}
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
                return abstraction_a::_derived::_static_shared_to_base(std::make_shared<abstraction_a::_instance<_Thing, _Copy>>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto parameters() const -> std::vector<parameter_a> const & final;

        inline auto parameters() -> std::vector<parameter_a> & final;

        inline auto name() const -> std::string const & final;

        inline auto name() -> std::string & final;

        inline auto parents() const -> std::vector<std::string> const & final;

        inline auto parents() -> std::vector<std::string> & final;

        inline auto operations() const -> std::vector<operation_a> const & final;

        inline auto operations() -> std::vector<operation_a> & final;

    //private:
        _Thing _thing;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<abstraction_a::_derived>(strange::_common::_shared).operator bool();
    }

    inline auto parameters() const -> std::vector<parameter_a> const &;

    inline auto parameters() -> std::vector<parameter_a> &;

    inline auto name() const -> std::string const &;

    inline auto name() -> std::string &;

    inline auto parents() const -> std::vector<std::string> const &;

    inline auto parents() -> std::vector<std::string> &;

    inline auto operations() const -> std::vector<operation_a> const &;

    inline auto operations() -> std::vector<operation_a> &;
};

template<typename _Thing>
struct abstraction_a_ : abstraction_a
{
private:
    struct _tag_ {};

    explicit inline abstraction_a_(_tag_, std::shared_ptr<strange::_common::_base> && shared = std::shared_ptr<strange::_common::_base>{})
    :strange::_common{std::move(shared)}
    ,abstraction_a{}
    {
    }

public:
    inline static auto _null() -> abstraction_a
    {
        return abstraction_a{};
    }

    inline static auto _null_() -> abstraction_a_
    {
        return abstraction_a_{_tag_{}};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> abstraction_a
    {
        return abstraction_a{abstraction_a_::_derived::_static_shared_to_base(std::make_shared<typename abstraction_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make_(_Args && ... _args) -> abstraction_a_
    {
        return abstraction_a_{_tag_{}, abstraction_a_::_derived::_static_shared_to_base(std::make_shared<typename abstraction_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _incognito(_Args && ... _args) -> abstraction_a
    {
        return abstraction_a{abstraction_a_::_derived::_static_shared_to_base(std::make_shared<typename abstraction_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _incognito_(_Args && ... _args) -> abstraction_a_
    {
        return abstraction_a_{_tag_{}, abstraction_a_::_derived::_static_shared_to_base(std::make_shared<typename abstraction_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<typename ... _Args>
    explicit inline abstraction_a_(_Args && ... _args)
    :strange::_common{abstraction_a_::_derived::_static_shared_to_base(std::make_shared<typename abstraction_a_::template _instance<_Thing, std::is_copy_constructible_v<_Thing>>>(std::forward<_Args>(_args) ...))}
    ,abstraction_a{}
    {
    }

    inline auto operator=(abstraction_a_ const & other) -> abstraction_a_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(abstraction_a_ && other) -> abstraction_a_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<typename abstraction_a_::template _instance<_Thing, std::is_copy_constructible_v<_Thing>>>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<typename abstraction_a_::template _instance<_Thing, std::is_copy_constructible_v<_Thing>>>(strange::_common::_shared)->_thing;
    }

    using _Abstraction_ = abstraction_a_;
    using _Thing_ = _Thing;
    using _Kind_ = abstraction_a;

    inline static std::string const _name_ = strange::reflection<_Abstraction_>::name();

    inline static std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(strange::reflection<_Kind_>::name());
        return cats;
    }();
};

struct space_a : virtual strange::_common
{
    inline space_a() = default;

    inline space_a(space_a const & other)
    :strange::_common{other}
    {
    }

    inline space_a(space_a && other)
    :strange::_common{std::move(other)}
    {
    }

    inline auto operator=(space_a const & other) -> space_a &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(space_a && other) -> space_a &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline space_a(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    {
    }

    explicit inline space_a(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    {
    }

protected:
    struct _derived : strange::_common::_base
    {
        static inline auto _static_shared_to_base(std::shared_ptr<space_a::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return derived;
        }

        virtual auto name() const -> std::string const & = 0;

        virtual auto name() -> std::string & = 0;

        virtual auto abstractions() const -> std::vector<abstraction_a> const & = 0;

        virtual auto abstractions() -> std::vector<abstraction_a> & = 0;
    };

//private:
    template<typename _Thing, bool _Copy>
    struct _instance final : space_a::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :space_a::_derived{}
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
                return space_a::_derived::_static_shared_to_base(std::make_shared<space_a::_instance<_Thing, _Copy>>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto name() const -> std::string const & final;

        inline auto name() -> std::string & final;

        inline auto abstractions() const -> std::vector<abstraction_a> const & final;

        inline auto abstractions() -> std::vector<abstraction_a> & final;

    //private:
        _Thing _thing;
    };

public:
    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<space_a::_derived>(strange::_common::_shared).operator bool();
    }

    inline auto name() const -> std::string const &;

    inline auto name() -> std::string &;

    inline auto abstractions() const -> std::vector<abstraction_a> const &;

    inline auto abstractions() -> std::vector<abstraction_a> &;
};

template<typename _Thing>
struct space_a_ : space_a
{
private:
    struct _tag_ {};

    explicit inline space_a_(_tag_, std::shared_ptr<strange::_common::_base> && shared = std::shared_ptr<strange::_common::_base>{})
    :strange::_common{std::move(shared)}
    ,space_a{}
    {
    }

public:
    inline static auto _null() -> space_a
    {
        return space_a{};
    }

    inline static auto _null_() -> space_a_
    {
        return space_a_{_tag_{}};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> space_a
    {
        return space_a{space_a_::_derived::_static_shared_to_base(std::make_shared<typename space_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make_(_Args && ... _args) -> space_a_
    {
        return space_a_{_tag_{}, space_a_::_derived::_static_shared_to_base(std::make_shared<typename space_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _incognito(_Args && ... _args) -> space_a
    {
        return space_a{space_a_::_derived::_static_shared_to_base(std::make_shared<typename space_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _incognito_(_Args && ... _args) -> space_a_
    {
        return space_a_{_tag_{}, space_a_::_derived::_static_shared_to_base(std::make_shared<typename space_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<typename ... _Args>
    explicit inline space_a_(_Args && ... _args)
    :strange::_common{space_a_::_derived::_static_shared_to_base(std::make_shared<typename space_a_::template _instance<_Thing, std::is_copy_constructible_v<_Thing>>>(std::forward<_Args>(_args) ...))}
    ,space_a{}
    {
    }

    inline auto operator=(space_a_ const & other) -> space_a_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(space_a_ && other) -> space_a_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<typename space_a_::template _instance<_Thing, std::is_copy_constructible_v<_Thing>>>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<typename space_a_::template _instance<_Thing, std::is_copy_constructible_v<_Thing>>>(strange::_common::_shared)->_thing;
    }

    using _Abstraction_ = space_a_;
    using _Thing_ = _Thing;
    using _Kind_ = space_a;

    inline static std::string const _name_ = strange::reflection<_Abstraction_>::name();

    inline static std::unordered_set<std::string> const _cats_ = []()
    {
        std::unordered_set<std::string> cats;
        cats.insert(strange::reflection<_Kind_>::name());
        return cats;
    }();
};

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::operator=(std::vector<T> const & other) -> void
{
    _thing.operator=(other);
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::operator=(std::vector<T> && other) -> void
{
    _thing.operator=(other);
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::operator=(std::initializer_list<T> ilist) -> void
{
    _thing.operator=(ilist);
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::assign(size_t count, T const & value) -> void
{
    _thing.assign(count, value);
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::assign(std::initializer_list<T> ilist) -> void
{
    _thing.assign(ilist);
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::at(size_t pos) -> T &
{
    return _thing.at(pos);
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::at(size_t pos) const -> T const &
{
    return _thing.at(pos);
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::operator[](size_t pos) -> T &
{
    return _thing.operator[](pos);
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::operator[](size_t pos) const -> T const &
{
    return _thing.operator[](pos);
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::front() -> T &
{
    return _thing.front();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::front() const -> T const &
{
    return _thing.front();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::back() -> T &
{
    return _thing.back();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::back() const -> T const &
{
    return _thing.back();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::data() -> T *
{
    return _thing.data();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::data() const -> T const *
{
    return _thing.data();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::begin() -> typename std::vector<T>::iterator
{
    return _thing.begin();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::begin() const -> typename std::vector<T>::const_iterator
{
    return _thing.begin();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::cbegin() const -> typename std::vector<T>::const_iterator
{
    return _thing.cbegin();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::end() -> typename std::vector<T>::iterator
{
    return _thing.end();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::end() const -> typename std::vector<T>::const_iterator
{
    return _thing.end();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::cend() const -> typename std::vector<T>::const_iterator
{
    return _thing.cend();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::rbegin() -> typename std::vector<T>::reverse_iterator
{
    return _thing.rbegin();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::rbegin() const -> typename std::vector<T>::const_reverse_iterator
{
    return _thing.rbegin();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::crbegin() const -> typename std::vector<T>::const_reverse_iterator
{
    return _thing.crbegin();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::rend() -> typename std::vector<T>::reverse_iterator
{
    return _thing.rend();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::rend() const -> typename std::vector<T>::const_reverse_iterator
{
    return _thing.rend();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::crend() const -> typename std::vector<T>::const_reverse_iterator
{
    return _thing.crend();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::empty() const -> bool
{
    return _thing.empty();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::size() const -> size_t
{
    return _thing.size();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::max_size() const -> size_t
{
    return _thing.max_size();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::reserve(size_t new_cap) -> void
{
    _thing.reserve(new_cap);
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::capacity() const -> size_t
{
    return _thing.capacity();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::shrink_to_fit() -> void
{
    _thing.shrink_to_fit();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::clear() -> void
{
    _thing.clear();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::insert(typename std::vector<T>::const_iterator pos, T const & value) -> typename std::vector<T>::iterator
{
    return _thing.insert(pos, value);
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::insert(typename std::vector<T>::const_iterator pos, T && value) -> typename std::vector<T>::iterator
{
    return _thing.insert(pos, value);
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::insert(typename std::vector<T>::const_iterator pos, size_t count, T const & value) -> typename std::vector<T>::iterator
{
    return _thing.insert(pos, count, value);
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::insert(typename std::vector<T>::const_iterator pos, std::initializer_list<T> ilist) -> typename std::vector<T>::iterator
{
    return _thing.insert(pos, ilist);
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::erase(typename std::vector<T>::const_iterator pos) -> typename std::vector<T>::iterator
{
    return _thing.erase(pos);
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::erase(typename std::vector<T>::const_iterator first, typename std::vector<T>::const_iterator last) -> typename std::vector<T>::iterator
{
    return _thing.erase(first, last);
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::push_back(T const & value) -> void
{
    _thing.push_back(value);
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::push_back(T && value) -> void
{
    _thing.push_back(value);
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::pop_back() -> void
{
    _thing.pop_back();
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::resize(size_t count) -> void
{
    _thing.resize(count);
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::resize(size_t count, T const & value) -> void
{
    _thing.resize(count, value);
}

template<typename T>
template<typename _Thing, bool _Copy>
inline auto vector_a<T>::_instance<_Thing, _Copy>::swap(std::vector<T> & other) -> void
{
    _thing.swap(other);
}

template<typename T>
inline auto vector_a<T>::operator=(std::vector<T> const & other) -> vector_a &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->operator=(other);
    return *this;
}

template<typename T>
inline auto vector_a<T>::operator=(std::vector<T> && other) -> vector_a &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->operator=(other);
    return *this;
}

template<typename T>
inline auto vector_a<T>::operator=(std::initializer_list<T> ilist) -> vector_a &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->operator=(ilist);
    return *this;
}

template<typename T>
inline auto vector_a<T>::assign(size_t count, T const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->assign(count, value);
}

template<typename T>
inline auto vector_a<T>::assign(std::initializer_list<T> ilist) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->assign(ilist);
}

template<typename T>
inline auto vector_a<T>::at(size_t pos) -> T &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->at(pos);
}

template<typename T>
inline auto vector_a<T>::at(size_t pos) const -> T const &
{
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->at(pos);
}

template<typename T>
inline auto vector_a<T>::operator[](size_t pos) -> T &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->operator[](pos);
}

template<typename T>
inline auto vector_a<T>::operator[](size_t pos) const -> T const &
{
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->operator[](pos);
}

template<typename T>
inline auto vector_a<T>::front() -> T &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->front();
}

template<typename T>
inline auto vector_a<T>::front() const -> T const &
{
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->front();
}

template<typename T>
inline auto vector_a<T>::back() -> T &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->back();
}

template<typename T>
inline auto vector_a<T>::back() const -> T const &
{
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->back();
}

template<typename T>
inline auto vector_a<T>::data() -> T *
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->data();
}

template<typename T>
inline auto vector_a<T>::data() const -> T const *
{
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->data();
}

template<typename T>
inline auto vector_a<T>::begin() -> typename std::vector<T>::iterator
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->begin();
}

template<typename T>
inline auto vector_a<T>::begin() const -> typename std::vector<T>::const_iterator
{
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->begin();
}

template<typename T>
inline auto vector_a<T>::cbegin() const -> typename std::vector<T>::const_iterator
{
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->cbegin();
}

template<typename T>
inline auto vector_a<T>::end() -> typename std::vector<T>::iterator
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->end();
}

template<typename T>
inline auto vector_a<T>::end() const -> typename std::vector<T>::const_iterator
{
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->end();
}

template<typename T>
inline auto vector_a<T>::cend() const -> typename std::vector<T>::const_iterator
{
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->cend();
}

template<typename T>
inline auto vector_a<T>::rbegin() -> typename std::vector<T>::reverse_iterator
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->rbegin();
}

template<typename T>
inline auto vector_a<T>::rbegin() const -> typename std::vector<T>::const_reverse_iterator
{
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->rbegin();
}

template<typename T>
inline auto vector_a<T>::crbegin() const -> typename std::vector<T>::const_reverse_iterator
{
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->crbegin();
}

template<typename T>
inline auto vector_a<T>::rend() -> typename std::vector<T>::reverse_iterator
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->rend();
}

template<typename T>
inline auto vector_a<T>::rend() const -> typename std::vector<T>::const_reverse_iterator
{
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->rend();
}

template<typename T>
inline auto vector_a<T>::crend() const -> typename std::vector<T>::const_reverse_iterator
{
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->crend();
}

template<typename T>
inline auto vector_a<T>::empty() const -> bool
{
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->empty();
}

template<typename T>
inline auto vector_a<T>::size() const -> size_t
{
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->size();
}

template<typename T>
inline auto vector_a<T>::max_size() const -> size_t
{
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->max_size();
}

template<typename T>
inline auto vector_a<T>::reserve(size_t new_cap) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->reserve(new_cap);
}

template<typename T>
inline auto vector_a<T>::capacity() const -> size_t
{
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->capacity();
}

template<typename T>
inline auto vector_a<T>::shrink_to_fit() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->shrink_to_fit();
}

template<typename T>
inline auto vector_a<T>::clear() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->clear();
}

template<typename T>
inline auto vector_a<T>::insert(typename std::vector<T>::const_iterator pos, T const & value) -> typename std::vector<T>::iterator
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->insert(pos, value);
}

template<typename T>
inline auto vector_a<T>::insert(typename std::vector<T>::const_iterator pos, T && value) -> typename std::vector<T>::iterator
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->insert(pos, value);
}

template<typename T>
inline auto vector_a<T>::insert(typename std::vector<T>::const_iterator pos, size_t count, T const & value) -> typename std::vector<T>::iterator
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->insert(pos, count, value);
}

template<typename T>
inline auto vector_a<T>::insert(typename std::vector<T>::const_iterator pos, std::initializer_list<T> ilist) -> typename std::vector<T>::iterator
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->insert(pos, ilist);
}

template<typename T>
inline auto vector_a<T>::erase(typename std::vector<T>::const_iterator pos) -> typename std::vector<T>::iterator
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->erase(pos);
}

template<typename T>
inline auto vector_a<T>::erase(typename std::vector<T>::const_iterator first, typename std::vector<T>::const_iterator last) -> typename std::vector<T>::iterator
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->erase(first, last);
}

template<typename T>
inline auto vector_a<T>::push_back(T const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->push_back(value);
}

template<typename T>
inline auto vector_a<T>::push_back(T && value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->push_back(value);
}

template<typename T>
inline auto vector_a<T>::pop_back() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->pop_back();
}

template<typename T>
inline auto vector_a<T>::resize(size_t count) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->resize(count);
}

template<typename T>
inline auto vector_a<T>::resize(size_t count, T const & value) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->resize(count, value);
}

template<typename T>
inline auto vector_a<T>::swap(std::vector<T> & other) -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<vector_a<T>::_derived>(strange::_common::_shared)->swap(other);
}

template<typename _Thing, bool _Copy>
inline auto parameter_a::_instance<_Thing, _Copy>::type() const -> std::string const &
{
    return _thing.type;
}

template<typename _Thing, bool _Copy>
inline auto parameter_a::_instance<_Thing, _Copy>::type() -> std::string &
{
    return _thing.type;
}

template<typename _Thing, bool _Copy>
inline auto parameter_a::_instance<_Thing, _Copy>::name() const -> std::string const &
{
    return _thing.name;
}

template<typename _Thing, bool _Copy>
inline auto parameter_a::_instance<_Thing, _Copy>::name() -> std::string &
{
    return _thing.name;
}

template<typename _Thing, bool _Copy>
inline auto parameter_a::_instance<_Thing, _Copy>::argument() const -> std::string const &
{
    return _thing.argument;
}

template<typename _Thing, bool _Copy>
inline auto parameter_a::_instance<_Thing, _Copy>::argument() -> std::string &
{
    return _thing.argument;
}

inline auto parameter_a::type() const -> std::string const &
{
    return std::dynamic_pointer_cast<parameter_a::_derived>(strange::_common::_shared)->type();
}

inline auto parameter_a::type() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<parameter_a::_derived>(strange::_common::_shared)->type();
}

inline auto parameter_a::name() const -> std::string const &
{
    return std::dynamic_pointer_cast<parameter_a::_derived>(strange::_common::_shared)->name();
}

inline auto parameter_a::name() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<parameter_a::_derived>(strange::_common::_shared)->name();
}

inline auto parameter_a::argument() const -> std::string const &
{
    return std::dynamic_pointer_cast<parameter_a::_derived>(strange::_common::_shared)->argument();
}

inline auto parameter_a::argument() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<parameter_a::_derived>(strange::_common::_shared)->argument();
}

template<typename _Thing, bool _Copy>
inline auto operation_a::_instance<_Thing, _Copy>::name() const -> std::string const &
{
    return _thing.name;
}

template<typename _Thing, bool _Copy>
inline auto operation_a::_instance<_Thing, _Copy>::name() -> std::string &
{
    return _thing.name;
}

template<typename _Thing, bool _Copy>
inline auto operation_a::_instance<_Thing, _Copy>::parameters() const -> std::vector<parameter_a> const &
{
    return _thing.parameters;
}

template<typename _Thing, bool _Copy>
inline auto operation_a::_instance<_Thing, _Copy>::parameters() -> std::vector<parameter_a> &
{
    return _thing.parameters;
}

template<typename _Thing, bool _Copy>
inline auto operation_a::_instance<_Thing, _Copy>::constness() const -> bool const &
{
    return _thing.constness;
}

template<typename _Thing, bool _Copy>
inline auto operation_a::_instance<_Thing, _Copy>::constness() -> bool &
{
    return _thing.constness;
}

template<typename _Thing, bool _Copy>
inline auto operation_a::_instance<_Thing, _Copy>::result() const -> std::string const &
{
    return _thing.result;
}

template<typename _Thing, bool _Copy>
inline auto operation_a::_instance<_Thing, _Copy>::result() -> std::string &
{
    return _thing.result;
}

template<typename _Thing, bool _Copy>
inline auto operation_a::_instance<_Thing, _Copy>::data() const -> bool const &
{
    return _thing.data;
}

template<typename _Thing, bool _Copy>
inline auto operation_a::_instance<_Thing, _Copy>::data() -> bool &
{
    return _thing.data;
}

inline auto operation_a::name() const -> std::string const &
{
    return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared)->name();
}

inline auto operation_a::name() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared)->name();
}

inline auto operation_a::parameters() const -> std::vector<parameter_a> const &
{
    return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared)->parameters();
}

inline auto operation_a::parameters() -> std::vector<parameter_a> &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared)->parameters();
}

inline auto operation_a::constness() const -> bool const &
{
    return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared)->constness();
}

inline auto operation_a::constness() -> bool &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared)->constness();
}

inline auto operation_a::result() const -> std::string const &
{
    return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared)->result();
}

inline auto operation_a::result() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared)->result();
}

inline auto operation_a::data() const -> bool const &
{
    return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared)->data();
}

inline auto operation_a::data() -> bool &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared)->data();
}

template<typename _Thing, bool _Copy>
inline auto abstraction_a::_instance<_Thing, _Copy>::parameters() const -> std::vector<parameter_a> const &
{
    return _thing.parameters;
}

template<typename _Thing, bool _Copy>
inline auto abstraction_a::_instance<_Thing, _Copy>::parameters() -> std::vector<parameter_a> &
{
    return _thing.parameters;
}

template<typename _Thing, bool _Copy>
inline auto abstraction_a::_instance<_Thing, _Copy>::name() const -> std::string const &
{
    return _thing.name;
}

template<typename _Thing, bool _Copy>
inline auto abstraction_a::_instance<_Thing, _Copy>::name() -> std::string &
{
    return _thing.name;
}

template<typename _Thing, bool _Copy>
inline auto abstraction_a::_instance<_Thing, _Copy>::parents() const -> std::vector<std::string> const &
{
    return _thing.parents;
}

template<typename _Thing, bool _Copy>
inline auto abstraction_a::_instance<_Thing, _Copy>::parents() -> std::vector<std::string> &
{
    return _thing.parents;
}

template<typename _Thing, bool _Copy>
inline auto abstraction_a::_instance<_Thing, _Copy>::operations() const -> std::vector<operation_a> const &
{
    return _thing.operations;
}

template<typename _Thing, bool _Copy>
inline auto abstraction_a::_instance<_Thing, _Copy>::operations() -> std::vector<operation_a> &
{
    return _thing.operations;
}

inline auto abstraction_a::parameters() const -> std::vector<parameter_a> const &
{
    return std::dynamic_pointer_cast<abstraction_a::_derived>(strange::_common::_shared)->parameters();
}

inline auto abstraction_a::parameters() -> std::vector<parameter_a> &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<abstraction_a::_derived>(strange::_common::_shared)->parameters();
}

inline auto abstraction_a::name() const -> std::string const &
{
    return std::dynamic_pointer_cast<abstraction_a::_derived>(strange::_common::_shared)->name();
}

inline auto abstraction_a::name() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<abstraction_a::_derived>(strange::_common::_shared)->name();
}

inline auto abstraction_a::parents() const -> std::vector<std::string> const &
{
    return std::dynamic_pointer_cast<abstraction_a::_derived>(strange::_common::_shared)->parents();
}

inline auto abstraction_a::parents() -> std::vector<std::string> &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<abstraction_a::_derived>(strange::_common::_shared)->parents();
}

inline auto abstraction_a::operations() const -> std::vector<operation_a> const &
{
    return std::dynamic_pointer_cast<abstraction_a::_derived>(strange::_common::_shared)->operations();
}

inline auto abstraction_a::operations() -> std::vector<operation_a> &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<abstraction_a::_derived>(strange::_common::_shared)->operations();
}

template<typename _Thing, bool _Copy>
inline auto space_a::_instance<_Thing, _Copy>::name() const -> std::string const &
{
    return _thing.name;
}

template<typename _Thing, bool _Copy>
inline auto space_a::_instance<_Thing, _Copy>::name() -> std::string &
{
    return _thing.name;
}

template<typename _Thing, bool _Copy>
inline auto space_a::_instance<_Thing, _Copy>::abstractions() const -> std::vector<abstraction_a> const &
{
    return _thing.abstractions;
}

template<typename _Thing, bool _Copy>
inline auto space_a::_instance<_Thing, _Copy>::abstractions() -> std::vector<abstraction_a> &
{
    return _thing.abstractions;
}

inline auto space_a::name() const -> std::string const &
{
    return std::dynamic_pointer_cast<space_a::_derived>(strange::_common::_shared)->name();
}

inline auto space_a::name() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<space_a::_derived>(strange::_common::_shared)->name();
}

inline auto space_a::abstractions() const -> std::vector<abstraction_a> const &
{
    return std::dynamic_pointer_cast<space_a::_derived>(strange::_common::_shared)->abstractions();
}

inline auto space_a::abstractions() -> std::vector<abstraction_a> &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<space_a::_derived>(strange::_common::_shared)->abstractions();
}

}
