#pragma once
#include "../common/strange__common.h"
#include <string>
#include <vector>

#include <memory>
#include <type_traits>

namespace strange
{

struct parameter_a;

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

private:
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

    private:
        _Thing _thing;
    };

public:
    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> parameter_a
    {
        return parameter_a{parameter_a::_derived::_static_shared_to_base(std::make_shared<parameter_a::_instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

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

}
