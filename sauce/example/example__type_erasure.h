#pragma once
#include <memory>

namespace example
{
struct _common
{
protected:
    struct _base
    {
        virtual std::shared_ptr<_common::_base> _clone() const = 0;
    };

    inline void _mutate()
    {
        if (_shared.use_count() > 1)
        {
            _shared = _shared->_clone();
        }
    }

public:
    std::shared_ptr<_common::_base> _shared;
};

struct widget : virtual _common
{
    widget() = default;
    widget(widget const & other) = default;
    widget(widget && other) = default;
    widget & operator=(widget const & other) = default;

    widget & operator=(widget && other)
    {
        _common::_shared = std::move(other._shared);
        return *this;
    }

    widget(_common const & other)
    {
        _common::_shared = other._shared;
    }

    widget(_common && other)
    {
        _common::_shared = std::move(other._shared);
    }

    widget & operator=(_common const & other)
    {
        _common::_shared = other._shared;
        return *this;
    }

    widget & operator=(_common && other)
    {
        _common::_shared = std::move(other._shared);
        return *this;
    }

    template <typename _Other>
    operator _Other() const
    {
        _Other other;
        other._shared = _common::_shared;
        return other;
    }

protected:
    struct _derived : _common::_base
    {
        virtual void display() const = 0;
        virtual void modify() = 0;
    };

private:
    template<typename _Thing>
    struct _instance final : widget::_derived
    {
        template<typename ... _Args>
        _instance(_Args && ... _args)
        :_thing(std::forward<_Args>(_args) ...)
        {
        }

        std::shared_ptr<_common::_base> _clone() const final
        {
            return std::make_shared<widget::_instance<_Thing>>(_thing);
        }

        void display() const final
        {
            _thing.display();
        }

        void modify() final
        {
            _thing.modify();
        }

        _Thing _thing;
    };

public:
    template<typename _Thing, typename ... _Args>
    static widget _make(_Args && ... _args)
    {
        widget i;
        i._shared = std::make_shared<widget::_instance<_Thing>>(std::forward<_Args>(_args) ...);
        return i;
    }

    inline void display() const
    {
        std::dynamic_pointer_cast<widget::_derived>(_shared)->display();
    }

    inline void modify()
    {
        _mutate();
        std::dynamic_pointer_cast<widget::_derived>(_shared)->modify();
    }
};

struct button : widget
{
    button() = default;
    button(button const & other) = default;
    button(button && other) = default;
    button & operator=(button const & other) = default;

    button & operator=(button && other)
    {
        _common::_shared = std::move(other._shared);
        return *this;
    }

    button(_common const & other)
    {
        _common::_shared = other._shared;
    }

    button(_common && other)
    {
        _common::_shared = std::move(other._shared);
    }

    button & operator=(_common const & other)
    {
        _common::_shared = other._shared;
        return *this;
    }

    button & operator=(_common && other)
    {
        _common::_shared = std::move(other._shared);
        return *this;
    }

    template <typename _Other>
    operator _Other() const
    {
        _Other other;
        other._shared = _common::_shared;
        return other;
    }

protected:
    struct _derived : widget::_derived
    {
        virtual void push() = 0;
    };

private:
    template<typename _Thing>
    struct _instance final : button::_derived
    {
        template<typename ... _Args>
        _instance(_Args && ... _args)
        :_thing(std::forward<_Args>(_args) ...)
        {
        }

        std::shared_ptr<_common::_base> _clone() const final
        {
            return std::make_shared<button::_instance<_Thing>>(_thing);
        }

        void display() const final
        {
            _thing.display();
        }

        void modify() final
        {
            _thing.modify();
        }

        void push() final
        {
            _thing.push();
        }

        _Thing _thing;
    };

public:
    template<typename _Thing, typename ... _Args>
    static button _make(_Args && ... _args)
    {
        button i;
        i._shared = std::make_shared<button::_instance<_Thing>>(std::forward<_Args>(_args) ...);
        return i;
    }

    inline void push()
    {
        _mutate();
        std::dynamic_pointer_cast<button::_derived>(_shared)->push();
    }
};

struct number : virtual _common
{
    number() = default;
    number(number const & other) = default;
    number(number && other) = default;
    number & operator=(number const & other) = default;

    number & operator=(number && other)
    {
        _common::_shared = std::move(other._shared);
        return *this;
    }

    number(_common const & other)
    {
        _common::_shared = other._shared;
    }

    number(_common && other)
    {
        _common::_shared = std::move(other._shared);
    }

    number & operator=(_common const & other)
    {
        _common::_shared = other._shared;
        return *this;
    }

    number & operator=(_common && other)
    {
        _common::_shared = std::move(other._shared);
        return *this;
    }

    template <typename _Other>
    operator _Other() const
    {
        _Other other;
        other._shared = _common::_shared;
        return other;
    }

protected:
    struct _derived : _common::_base
    {
        virtual void inc() = 0;
        virtual void dec() = 0;
    };

private:
    template<typename _Thing>
    struct _instance final : number::_derived
    {
        template<typename ... _Args>
        _instance(_Args && ... _args)
        :_thing(std::forward<_Args>(_args) ...)
        {
        }

        std::shared_ptr<_common::_base> _clone() const final
        {
            return std::make_shared<number::_instance<_Thing>>(_thing);
        }

        void inc() final
        {
            _thing.inc();
        }

        void dec() final
        {
            _thing.dec();
        }

        _Thing _thing;
    };

public:
    template<typename _Thing, typename ... _Args>
    static number _make(_Args && ... _args)
    {
        number i;
        i._shared = std::make_shared<number::_instance<_Thing>>(std::forward<_Args>(_args) ...);
        return i;
    }

    inline void inc()
    {
        _mutate();
        std::dynamic_pointer_cast<number::_derived>(_shared)->inc();
    }

    inline void dec()
    {
        _mutate();
        std::dynamic_pointer_cast<number::_derived>(_shared)->dec();
    }
};
}