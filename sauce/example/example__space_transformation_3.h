#pragma once

#include <memory>
#include <type_traits>
#include "../common/strange__common.h"

namespace example
{

struct widget;

struct button;

struct number;

struct widget_number;

template<typename Data = int>
struct numeric;

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
        static inline auto _static_shared_to_base(std::shared_ptr<widget::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return derived;
        }

        virtual auto display(button b) const -> void = 0;

        virtual auto inc() -> void = 0;
    };

private:
    template<typename _Thing, bool _Copy>
    struct _instance final : widget::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :widget::_derived{}
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
                return widget::_derived::_static_shared_to_base(std::make_shared<widget::_instance<_Thing, _Copy>>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto display(button b) const -> void final;

        inline auto inc() -> void final;

    private:
        _Thing _thing;
    };
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
        static inline auto _static_shared_to_base(std::shared_ptr<button::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return widget::_derived::_static_shared_to_base(derived);
        }

        virtual auto push() -> void = 0;
    };

private:
    template<typename _Thing, bool _Copy>
    struct _instance final : button::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :button::_derived{}
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
                return button::_derived::_static_shared_to_base(std::make_shared<button::_instance<_Thing, _Copy>>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto push() -> void final;

    private:
        _Thing _thing;
    };
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
        static inline auto _static_shared_to_base(std::shared_ptr<number::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return derived;
        }

        virtual auto inc() -> void = 0;

        virtual auto dec() -> void = 0;
    };

private:
    template<typename _Thing, bool _Copy>
    struct _instance final : number::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :number::_derived{}
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
                return number::_derived::_static_shared_to_base(std::make_shared<number::_instance<_Thing, _Copy>>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto inc() -> void final;

        inline auto dec() -> void final;

    private:
        _Thing _thing;
    };
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
        static inline auto _static_shared_to_base(std::shared_ptr<widget_number::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return widget::_derived::_static_shared_to_base(derived);
        }
    };

private:
    template<typename _Thing, bool _Copy>
    struct _instance final : widget_number::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :widget_number::_derived{}
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
                return widget_number::_derived::_static_shared_to_base(std::make_shared<widget_number::_instance<_Thing, _Copy>>(_thing));
            }
            else
            {
                throw true;
            }
        }

    private:
        _Thing _thing;
    };
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
        static inline auto _static_shared_to_base(std::shared_ptr<numeric::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return number::_derived::_static_shared_to_base(derived);
        }

        virtual auto get() const -> Data = 0;
    };

private:
    template<typename _Thing, bool _Copy>
    struct _instance final : numeric::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :numeric::_derived{}
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
                return numeric::_derived::_static_shared_to_base(std::make_shared<numeric::_instance<_Thing, _Copy>>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto get() const -> Data final;

    private:
        _Thing _thing;
    };
};

}
