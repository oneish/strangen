#pragma once
#include <memory>
#include <string>
#include <stdexcept>
#include <type_traits>

namespace example
{

struct widget;
struct button;
struct number;
struct widget_number;
template<typename Data = int> struct numeric;

struct _common
{
protected:
    struct _base
    {
        virtual auto _clone() const -> std::shared_ptr<_common::_base> = 0;

        virtual inline auto _error() const -> std::string
        {
            return std::string();
        }
    };

    std::shared_ptr<_common::_base> _shared;

    inline _common() = default;

    explicit inline _common(std::shared_ptr<_common::_base> const & shared)
    :_shared(shared)
    {
    }

    explicit inline _common(std::shared_ptr<_common::_base> && shared)
    :_shared(std::move(shared))
    {
    }

    inline auto _mutate() -> void
    {
        if (_shared.use_count() > 1)
        {
            try
            {
                _shared = _shared->_clone();
            }
            catch(bool const &)
            {
            }
        }
    }

private:
    struct _message final : _common::_base
    {
        template<typename Message>
        inline _message(Message && msg)
        :message(std::forward<Message>(msg))
        {
        }

        inline auto _clone() const -> std::shared_ptr<_common::_base> final
        {
            throw false;
        }

        inline auto _error() const -> std::string final
        {
            return message;
        }

    private:
        std::string const message;
    };

public:
    inline auto _something() const -> bool
    {
        return _shared.operator bool();
    }

    template<typename Message>
    inline auto _error(Message && message) -> void
    {
        _shared = std::make_shared<_common::_message>(message);
    }

    inline auto _error() const -> std::string
    {
        if (_shared)
        {
            return _shared->_error();
        }
        return std::string();
    }

    template<typename Other>
    inline auto _static() const -> Other
    {
        return Other(_shared);
    }

    template<typename Other>
    inline auto _dynamic() const -> Other
    {
        Other other(_shared);
        if (other._valid())
        {
            return other;
        }
        return Other();
    }
};

struct widget : virtual _common
{
    inline widget() = default;

    inline widget(widget const & other)
    :_common(other)
    {
    }

    inline widget(widget && other)
    :_common(std::move(other))
    {
    }

    inline auto operator=(widget const & other) -> widget &
    {
        _common::operator=(other);
        return *this;
    }

    inline auto operator=(widget && other) -> widget &
    {
        _common::operator=(std::move(other));
        return *this;
    }

    explicit inline widget(std::shared_ptr<_common::_base> const & shared)
    :_common(shared)
    {
    }

    explicit inline widget(std::shared_ptr<_common::_base> && shared)
    :_common(std::move(shared))
    {
    }

protected:
    struct _derived : _common::_base
    {
        virtual auto display(button b) const -> void = 0;
        virtual auto inc() -> void = 0;
    };

private:
    template<typename _Thing>
    struct _instance final : widget::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :widget::_derived()
        ,_thing(std::forward<_Args>(_args) ...)
        {
        }

        inline auto _clone() const -> std::shared_ptr<_common::_base> final
        {
            if constexpr (std::is_copy_constructible_v<_Thing>)
            {
                return std::make_shared<widget::_instance<_Thing>>(_thing);
            }
            throw true;
        }

        inline auto display(button b) const -> void final;

        inline auto inc() -> void final;

    private:
        _Thing _thing;
    };

public:
    template<typename _Thing, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> widget
    {
        return widget(std::make_shared<widget::_instance<_Thing>>(std::forward<_Args>(_args) ...));
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<widget::_derived>(_common::_shared).operator bool();
    }

    inline auto display(button b) const -> void;

    inline auto inc() -> void;
};

struct button : widget
{
    inline button() = default;

    inline button(button const & other)
    :_common(other)
    ,widget()
    {
    }

    inline button(button && other)
    :_common(std::move(other))
    ,widget()
    {
    }

    inline auto operator=(button const & other) -> button &
    {
        widget::operator=(other);
        return *this;
    }

    inline auto operator=(button && other) -> button &
    {
        widget::operator=(std::move(other));
        return *this;
    }

    explicit inline button(std::shared_ptr<_common::_base> const & shared)
    :_common(shared)
    ,widget()
    {
    }

    explicit inline button(std::shared_ptr<_common::_base> && shared)
    :_common(std::move(shared))
    ,widget()
    {
    }

protected:
    struct _derived : widget::_derived
    {
        virtual auto push() -> void = 0;
    };

private:
    template<typename _Thing>
    struct _instance final : button::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :button::_derived()
        ,_thing(std::forward<_Args>(_args) ...)
        {
        }

        inline auto _clone() const -> std::shared_ptr<_common::_base> final
        {
            if constexpr (std::is_copy_constructible_v<_Thing>)
            {
                return std::make_shared<button::_instance<_Thing>>(_thing);
            }
            throw true;
        }

        inline auto display(button b) const -> void final;

        inline auto inc() -> void final;

        inline auto push() -> void final;

    private:
        _Thing _thing;
    };

public:
    template<typename _Thing, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> button
    {
        return button(std::make_shared<button::_instance<_Thing>>(std::forward<_Args>(_args) ...));
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<button::_derived>(_common::_shared).operator bool();
    }

    inline auto display(button b) const -> void;

    inline auto inc() -> void;

    inline auto push() -> void;
};

struct number : virtual _common
{
    inline number() = default;

    inline number(number const & other)
    :_common(other)
    {
    }

    inline number(number && other)
    :_common(std::move(other))
    {
    }

    inline auto operator=(number const & other) -> number &
    {
        _common::operator=(other);
        return *this;
    }

    inline auto operator=(number && other) -> number &
    {
        _common::operator=(std::move(other));
        return *this;
    }

    explicit inline number(std::shared_ptr<_common::_base> const & shared)
    :_common(shared)
    {
    }

    explicit inline number(std::shared_ptr<_common::_base> && shared)
    :_common(std::move(shared))
    {
    }

protected:
    struct _derived : _common::_base
    {
        virtual auto inc() -> void = 0;
        virtual auto dec() -> void = 0;
    };

private:
    template<typename _Thing>
    struct _instance final : number::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :number::_derived()
        ,_thing(std::forward<_Args>(_args) ...)
        {
        }

        inline auto _clone() const -> std::shared_ptr<_common::_base> final
        {
            if constexpr (std::is_copy_constructible_v<_Thing>)
            {
                return std::make_shared<number::_instance<_Thing>>(_thing);
            }
            throw true;
        }

        inline auto inc() -> void final;

        inline auto dec() -> void final;

    private:
        _Thing _thing;
    };

public:
    template<typename _Thing, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> number
    {
        return number(std::make_shared<number::_instance<_Thing>>(std::forward<_Args>(_args) ...));
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<number::_derived>(_common::_shared).operator bool();
    }

    inline auto inc() -> void;

    inline auto dec() -> void;
};

struct widget_number : widget, number
{
    inline widget_number() = default;

    inline widget_number(widget_number const & other)
    :_common(other)
    ,widget()
    ,number()
    {
    }

    inline widget_number(widget_number && other)
    :_common(std::move(other))
    ,widget()
    ,number()
    {
    }

    inline auto operator=(widget_number const & other) -> widget_number &
    {
        number::operator=(other);
        return *this;
    }

    inline auto operator=(widget_number && other) -> widget_number &
    {
        number::operator=(std::move(other));
        return *this;
    }

    explicit inline widget_number(std::shared_ptr<_common::_base> const & shared)
    :_common(shared)
    ,widget()
    ,number()
    {
    }

    explicit inline widget_number(std::shared_ptr<_common::_base> && shared)
    :_common(std::move(shared))
    ,widget()
    ,number()
    {
    }

protected:
    struct _derived : widget::_derived, number::_derived
    {
    };

private:
    template<typename _Thing>
    struct _instance final : widget_number::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :widget_number::_derived()
        ,_thing(std::forward<_Args>(_args) ...)
        {
        }

        inline auto _clone() const -> std::shared_ptr<_common::_base> final
        {
            if constexpr (std::is_copy_constructible_v<_Thing>)
            {
                return std::static_pointer_cast<widget::_derived>(
                    std::make_shared<widget_number::_instance<_Thing>>(_thing));
            }
            throw true;
        }

        inline auto display(button b) const -> void final;

        inline auto inc() -> void final;

        inline auto dec() -> void final;

    private:
        _Thing _thing;
    };

public:
    template<typename _Thing, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> widget_number
    {
        return widget_number(std::static_pointer_cast<widget::_derived>(
            std::make_shared<widget_number::_instance<_Thing>>(std::forward<_Args>(_args) ...)));
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<widget_number::_derived>(_common::_shared).operator bool();
    }

    inline auto display(button b) const -> void;

    inline auto inc() -> void;

    inline auto dec() -> void;
};

template<typename Data>
struct numeric : number
{
    inline numeric() = default;

    inline numeric(numeric const & other)
    :_common(other)
    ,number()
    {
    }

    inline numeric(numeric && other)
    :_common(std::move(other))
    ,number()
    {
    }

    inline auto operator=(numeric const & other) -> numeric &
    {
        number::operator=(other);
        return *this;
    }

    inline auto operator=(numeric && other) -> numeric &
    {
        number::operator=(std::move(other));
        return *this;
    }

    explicit inline numeric(std::shared_ptr<_common::_base> const & shared)
    :_common(shared)
    ,number()
    {
    }

    explicit inline numeric(std::shared_ptr<_common::_base> && shared)
    :_common(std::move(shared))
    ,number()
    {
    }

protected:
    struct _derived : number::_derived
    {
        virtual auto get() const -> Data = 0;
    };

private:
    template<typename _Thing>
    struct _instance final : numeric::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :numeric::_derived()
        ,_thing(std::forward<_Args>(_args) ...)
        {
        }

        inline auto _clone() const -> std::shared_ptr<_common::_base> final
        {
            if constexpr (std::is_copy_constructible_v<_Thing>)
            {
                return std::make_shared<numeric::_instance<_Thing>>(_thing);
            }
            throw true;
        }

        inline auto inc() -> void final;

        inline auto dec() -> void final;

        inline auto get() const -> Data final;

    private:
        _Thing _thing;
    };

public:
    template<typename _Thing, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> numeric
    {
        return numeric(std::make_shared<numeric::_instance<_Thing>>(std::forward<_Args>(_args) ...));
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<numeric::_derived>(_common::_shared).operator bool();
    }

    inline auto inc() -> void;

    inline auto dec() -> void;

    inline auto get() const -> Data;
};

template<typename _Thing>
inline auto widget::_instance<_Thing>::display(button b) const -> void
{
    _thing.display(b);
}

template<typename _Thing>
inline auto widget::_instance<_Thing>::inc() -> void
{
    _thing.inc();
}

inline auto widget::display(button b = button()) const -> void
{
    std::dynamic_pointer_cast<widget::_derived>(_common::_shared)->display(b);
}

inline auto widget::inc() -> void
{
    _common::_mutate();
    std::dynamic_pointer_cast<widget::_derived>(_common::_shared)->inc();
}

template<typename _Thing>
inline auto button::_instance<_Thing>::display(button b) const -> void
{
    _thing.display(b);
}

template<typename _Thing>
inline auto button::_instance<_Thing>::inc() -> void
{
    _thing.inc();
}

template<typename _Thing>
inline auto button::_instance<_Thing>::push() -> void
{
    _thing.push();
}

inline auto button::display(button b = button()) const -> void
{
    std::dynamic_pointer_cast<widget::_derived>(_common::_shared)->display(b);
}

inline auto button::inc() -> void
{
    _common::_mutate();
    std::dynamic_pointer_cast<widget::_derived>(_common::_shared)->inc();
}

inline auto button::push() -> void
{
    _common::_mutate();
    std::dynamic_pointer_cast<button::_derived>(_common::_shared)->push();
}

template<typename _Thing>
inline auto number::_instance<_Thing>::inc() -> void
{
    _thing.inc();
}

template<typename _Thing>
inline auto number::_instance<_Thing>::dec() -> void
{
    _thing.dec();
}

inline auto number::inc() -> void
{
    _common::_mutate();
    std::dynamic_pointer_cast<number::_derived>(_common::_shared)->inc();
}

inline auto number::dec() -> void
{
    _common::_mutate();
    std::dynamic_pointer_cast<number::_derived>(_common::_shared)->dec();
}

template<typename _Thing>
inline auto widget_number::_instance<_Thing>::display(button b) const -> void
{
    _thing.display(b);
}

template<typename _Thing>
inline auto widget_number::_instance<_Thing>::inc() -> void
{
    _thing.inc();
}

template<typename _Thing>
inline auto widget_number::_instance<_Thing>::dec() -> void
{
    _thing.dec();
}

inline auto widget_number::display(button b = button()) const -> void
{
    std::dynamic_pointer_cast<widget::_derived>(_common::_shared)->display(b);
}

inline auto widget_number::inc() -> void
{
    _common::_mutate();
    std::dynamic_pointer_cast<widget::_derived>(_common::_shared)->inc();
}

inline auto widget_number::dec() -> void
{
    _common::_mutate();
    std::dynamic_pointer_cast<number::_derived>(_common::_shared)->dec();
}

template<typename Data>
template<typename _Thing>
inline auto numeric<Data>::_instance<_Thing>::inc() -> void
{
    _thing.inc();
}

template<typename Data>
template<typename _Thing>
inline auto numeric<Data>::_instance<_Thing>::dec() -> void
{
    _thing.dec();
}

template<typename Data>
template<typename _Thing>
inline auto numeric<Data>::_instance<_Thing>::get() const -> Data
{
    return _thing.get();
}

template<typename Data>
inline auto numeric<Data>::inc() -> void
{
    _common::_mutate();
    std::dynamic_pointer_cast<number::_derived>(_common::_shared)->inc();
}

template<typename Data>
inline auto numeric<Data>::dec() -> void
{
    _common::_mutate();
    std::dynamic_pointer_cast<number::_derived>(_common::_shared)->dec();
}

template<typename Data>
inline auto numeric<Data>::get() const -> Data
{
    return std::dynamic_pointer_cast<numeric<Data>::_derived>(_common::_shared)->get();
}

}