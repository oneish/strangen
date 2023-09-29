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

        virtual auto operator++() -> void = 0;

        virtual auto operator--(int i) -> void = 0;
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

        inline auto operator++() -> void final;

        inline auto operator--(int i) -> void final;

    private:
        _Thing _thing;
    };

public:
    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> widget
    {
        return widget{widget::_derived::_static_shared_to_base(std::make_shared<widget::_instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<widget::_derived>(strange::_common::_shared).operator bool();
    }

    inline auto display(button b) const -> void;

    inline auto inc() -> void;

    inline auto operator++() -> widget &;

    inline auto operator--(int i) -> widget;
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

        inline auto display(button b) const -> void final;

        inline auto inc() -> void final;

        inline auto operator++() -> void final;

        inline auto operator--(int i) -> void final;

        inline auto push() -> void final;

    private:
        _Thing _thing;
    };

public:
    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> button
    {
        return button{button::_derived::_static_shared_to_base(std::make_shared<button::_instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<button::_derived>(strange::_common::_shared).operator bool();
    }

    inline auto display(button b) const -> void;

    inline auto inc() -> void;

    inline auto operator++() -> button &;

    inline auto operator--(int i) -> button;

    inline auto push() -> void;
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

public:
    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> number
    {
        return number{number::_derived::_static_shared_to_base(std::make_shared<number::_instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<number::_derived>(strange::_common::_shared).operator bool();
    }

    inline auto inc() -> void;

    inline auto dec() -> void;
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

        inline auto display(button b) const -> void final;

        inline auto inc() -> void final;

        inline auto operator++() -> void final;

        inline auto operator--(int i) -> void final;

        inline auto dec() -> void final;

    private:
        _Thing _thing;
    };

public:
    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> widget_number
    {
        return widget_number{widget_number::_derived::_static_shared_to_base(std::make_shared<widget_number::_instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<widget_number::_derived>(strange::_common::_shared).operator bool();
    }

    inline auto display(button b) const -> void;

    inline auto inc() -> void;

    inline auto operator++() -> widget_number &;

    inline auto operator--(int i) -> widget_number;

    inline auto dec() -> void;
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

        virtual auto x() const -> Data const & = 0;

        virtual auto x() -> Data & = 0;
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

        inline auto inc() -> void final;

        inline auto dec() -> void final;

        inline auto get() const -> Data final;

        inline auto x() const -> Data const & final;

        inline auto x() -> Data & final;

    private:
        _Thing _thing;
    };

public:
    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> numeric
    {
        return numeric{numeric::_derived::_static_shared_to_base(std::make_shared<numeric::_instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<numeric::_derived>(strange::_common::_shared).operator bool();
    }

    inline auto inc() -> void;

    inline auto dec() -> void;

    inline auto get() const -> Data;

    inline auto x() const -> Data const &;

    inline auto x() -> Data &;
};

template<typename _Thing, bool _Copy>
inline auto widget::_instance<_Thing, _Copy>::display(button b) const -> void
{
    _thing.display(b);
}

template<typename _Thing, bool _Copy>
inline auto widget::_instance<_Thing, _Copy>::inc() -> void
{
    _thing.inc();
}

template<typename _Thing, bool _Copy>
inline auto widget::_instance<_Thing, _Copy>::operator++() -> void
{
    _thing.operator++();
}

template<typename _Thing, bool _Copy>
inline auto widget::_instance<_Thing, _Copy>::operator--(int i) -> void
{
    _thing.operator--(i);
}

inline auto widget::display(button b = button()) const -> void
{
    std::dynamic_pointer_cast<widget::_derived>(strange::_common::_shared)->display(b);
}

inline auto widget::inc() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<widget::_derived>(strange::_common::_shared)->inc();
}

inline auto widget::operator++() -> widget &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<widget::_derived>(strange::_common::_shared)->operator++();
    return *this;
}

inline auto widget::operator--(int i) -> widget
{
    auto _result = *this;
    strange::_common::_mutate();
    std::dynamic_pointer_cast<widget::_derived>(strange::_common::_shared)->operator--(i);
    return _result;
}

template<typename _Thing, bool _Copy>
inline auto button::_instance<_Thing, _Copy>::display(button b) const -> void
{
    _thing.display(b);
}

template<typename _Thing, bool _Copy>
inline auto button::_instance<_Thing, _Copy>::inc() -> void
{
    _thing.inc();
}

template<typename _Thing, bool _Copy>
inline auto button::_instance<_Thing, _Copy>::operator++() -> void
{
    _thing.operator++();
}

template<typename _Thing, bool _Copy>
inline auto button::_instance<_Thing, _Copy>::operator--(int i) -> void
{
    _thing.operator--(i);
}

template<typename _Thing, bool _Copy>
inline auto button::_instance<_Thing, _Copy>::push() -> void
{
    _thing.push();
}

inline auto button::display(button b = button()) const -> void
{
    std::dynamic_pointer_cast<widget::_derived>(strange::_common::_shared)->display(b);
}

inline auto button::inc() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<widget::_derived>(strange::_common::_shared)->inc();
}

inline auto button::operator++() -> button &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<widget::_derived>(strange::_common::_shared)->operator++();
    return *this;
}

inline auto button::operator--(int i) -> button
{
    auto _result = *this;
    strange::_common::_mutate();
    std::dynamic_pointer_cast<widget::_derived>(strange::_common::_shared)->operator--(i);
    return _result;
}

inline auto button::push() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<button::_derived>(strange::_common::_shared)->push();
}

template<typename _Thing, bool _Copy>
inline auto number::_instance<_Thing, _Copy>::inc() -> void
{
    _thing.inc();
}

template<typename _Thing, bool _Copy>
inline auto number::_instance<_Thing, _Copy>::dec() -> void
{
    _thing.dec();
}

inline auto number::inc() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<number::_derived>(strange::_common::_shared)->inc();
}

inline auto number::dec() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<number::_derived>(strange::_common::_shared)->dec();
}

template<typename _Thing, bool _Copy>
inline auto widget_number::_instance<_Thing, _Copy>::display(button b) const -> void
{
    _thing.display(b);
}

template<typename _Thing, bool _Copy>
inline auto widget_number::_instance<_Thing, _Copy>::inc() -> void
{
    _thing.inc();
}

template<typename _Thing, bool _Copy>
inline auto widget_number::_instance<_Thing, _Copy>::operator++() -> void
{
    _thing.operator++();
}

template<typename _Thing, bool _Copy>
inline auto widget_number::_instance<_Thing, _Copy>::operator--(int i) -> void
{
    _thing.operator--(i);
}

template<typename _Thing, bool _Copy>
inline auto widget_number::_instance<_Thing, _Copy>::dec() -> void
{
    _thing.dec();
}

inline auto widget_number::display(button b = button()) const -> void
{
    std::dynamic_pointer_cast<widget::_derived>(strange::_common::_shared)->display(b);
}

inline auto widget_number::inc() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<widget::_derived>(strange::_common::_shared)->inc();
}

inline auto widget_number::operator++() -> widget_number &
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<widget::_derived>(strange::_common::_shared)->operator++();
    return *this;
}

inline auto widget_number::operator--(int i) -> widget_number
{
    auto _result = *this;
    strange::_common::_mutate();
    std::dynamic_pointer_cast<widget::_derived>(strange::_common::_shared)->operator--(i);
    return _result;
}

inline auto widget_number::dec() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<number::_derived>(strange::_common::_shared)->dec();
}

template<typename Data>
template<typename _Thing, bool _Copy>
inline auto numeric<Data>::_instance<_Thing, _Copy>::inc() -> void
{
    _thing.inc();
}

template<typename Data>
template<typename _Thing, bool _Copy>
inline auto numeric<Data>::_instance<_Thing, _Copy>::dec() -> void
{
    _thing.dec();
}

template<typename Data>
template<typename _Thing, bool _Copy>
inline auto numeric<Data>::_instance<_Thing, _Copy>::get() const -> Data
{
    return _thing.get();
}

template<typename Data>
template<typename _Thing, bool _Copy>
inline auto numeric<Data>::_instance<_Thing, _Copy>::x() const -> Data const &
{
    return _thing.x;
}

template<typename Data>
template<typename _Thing, bool _Copy>
inline auto numeric<Data>::_instance<_Thing, _Copy>::x() -> Data &
{
    return _thing.x;
}

template<typename Data>
inline auto numeric<Data>::inc() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<number::_derived>(strange::_common::_shared)->inc();
}

template<typename Data>
inline auto numeric<Data>::dec() -> void
{
    strange::_common::_mutate();
    std::dynamic_pointer_cast<number::_derived>(strange::_common::_shared)->dec();
}

template<typename Data>
inline auto numeric<Data>::get() const -> Data
{
    return std::dynamic_pointer_cast<numeric<Data>::_derived>(strange::_common::_shared)->get();
}

template<typename Data>
inline auto numeric<Data>::x() const -> Data const &
{
    return std::dynamic_pointer_cast<numeric<Data>::_derived>(strange::_common::_shared)->x();
}

template<typename Data>
inline auto numeric<Data>::x() -> Data &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<numeric<Data>::_derived>(strange::_common::_shared)->x();
}

}
