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

    std::shared_ptr<_common::_base> _shared;

    inline _common() = default;

    inline _common(std::shared_ptr<_common::_base> const & shared)
    :_shared(shared)
    {
    }

    inline _common(std::shared_ptr<_common::_base> && shared)
    :_shared(std::move(shared))
    {
    }

    inline void _mutate()
    {
        if (_shared.use_count() > 1)
        {
            _shared = _shared->_clone();
        }
    }

public:
    inline bool _something()
    {
        return _shared.operator bool();
    }
};

struct widget : virtual _common
{
    inline widget() = default;

    inline widget(std::shared_ptr<_common::_base> const & shared)
    :_common(shared)
    {
    }

    inline widget(std::shared_ptr<_common::_base> && shared)
    :_common(std::move(shared))
    {
    }

    inline widget(widget const & other)
    :_common(other)
    {
    }

    inline widget(widget && other)
    :_common(std::move(other))
    {
    }

    inline widget & operator=(widget const & other)
    {
        _common::operator=(other);
        return *this;
    }

    inline widget & operator=(widget && other)
    {
        _common::operator=(std::move(other));
        return *this;
    }

    inline widget(_common const & other)
    :_common(other)
    {
    }

    inline widget(_common && other)
    :_common(std::move(other))
    {
    }

    inline widget & operator=(_common const & other)
    {
        _common::operator=(other);
        return *this;
    }

    inline widget & operator=(_common && other)
    {
        _common::operator=(std::move(other));
        return *this;
    }

    template <typename _Other>
    inline operator _Other() const
    {
        return _Other(*this);
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
        inline _instance(_Args && ... _args)
        :widget::_derived()
        ,_thing(std::forward<_Args>(_args) ...)
        {
        }

        inline std::shared_ptr<_common::_base> _clone() const final
        {
            return std::make_shared<widget::_instance<_Thing>>(_thing);
        }

        inline void display() const final
        {
            _thing.display();
        }

        inline void modify() final
        {
            _thing.modify();
        }

    private:
        _Thing _thing;
    };

public:
    template<typename _Thing, typename ... _Args>
    inline static widget _make(_Args && ... _args)
    {
        return widget(std::make_shared<widget::_instance<_Thing>>(std::forward<_Args>(_args) ...));
    }

    inline bool _dynamic() const
    {
        return std::dynamic_pointer_cast<widget::_derived>(_common::_shared).operator bool();
    }

    inline void display() const
    {
        std::dynamic_pointer_cast<widget::_derived>(_common::_shared)->display();
    }

    inline void modify()
    {
        _common::_mutate();
        std::dynamic_pointer_cast<widget::_derived>(_common::_shared)->modify();
    }
};

struct button : widget
{
    inline button() = default;

    inline button(std::shared_ptr<_common::_base> const & shared)
    :_common(shared)
    ,widget()
    {
    }

    inline button(std::shared_ptr<_common::_base> && shared)
    :_common(std::move(shared))
    ,widget()
    {
    }

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

    inline button & operator=(button const & other)
    {
        widget::operator=(other);
        return *this;
    }

    inline button & operator=(button && other)
    {
        widget::operator=(std::move(other));
        return *this;
    }

    inline button(_common const & other)
    :_common(other)
    ,widget()
    {
    }

    inline button(_common && other)
    :_common(std::move(other))
    ,widget()
    {
    }

    inline button & operator=(_common const & other)
    {
        widget::operator=(other);
        return *this;
    }

    inline button & operator=(_common && other)
    {
        widget::operator=(std::move(other));
        return *this;
    }

    template <typename _Other>
    inline operator _Other() const
    {
        return _Other(*this);
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
        inline _instance(_Args && ... _args)
        :button::_derived()
        ,_thing(std::forward<_Args>(_args) ...)
        {
        }

        inline std::shared_ptr<_common::_base> _clone() const final
        {
            return std::make_shared<button::_instance<_Thing>>(_thing);
        }

        inline void display() const final
        {
            _thing.display();
        }

        inline void modify() final
        {
            _thing.modify();
        }

        inline void push() final
        {
            _thing.push();
        }

    private:
        _Thing _thing;
    };

public:
    template<typename _Thing, typename ... _Args>
    inline static button _make(_Args && ... _args)
    {
        return button(std::make_shared<button::_instance<_Thing>>(std::forward<_Args>(_args) ...));
    }

    inline bool _dynamic() const
    {
        return std::dynamic_pointer_cast<button::_derived>(_common::_shared).operator bool();
    }

    inline void push()
    {
        _common::_mutate();
        std::dynamic_pointer_cast<button::_derived>(_common::_shared)->push();
    }
};

struct number : virtual _common
{
    inline number() = default;

    inline number(std::shared_ptr<_common::_base> const & shared)
    :_common(shared)
    {
    }

    inline number(std::shared_ptr<_common::_base> && shared)
    :_common(std::move(shared))
    {
    }

    inline number(number const & other)
    :_common(other)
    {
    }

    inline number(number && other)
    :_common(std::move(other))
    {
    }

    inline number & operator=(number const & other)
    {
        _common::operator=(other);
        return *this;
    }

    inline number & operator=(number && other)
    {
        _common::operator=(std::move(other));
        return *this;
    }

    inline number(_common const & other)
    :_common(other)
    {
    }

    inline number(_common && other)
    :_common(std::move(other))
    {
    }

    inline number & operator=(_common const & other)
    {
        _common::operator=(other);
        return *this;
    }

    inline number & operator=(_common && other)
    {
        _common::operator=(std::move(other));
        return *this;
    }

    template <typename _Other>
    inline operator _Other() const
    {
        return _Other(*this);
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
        inline _instance(_Args && ... _args)
        :number::_derived()
        ,_thing(std::forward<_Args>(_args) ...)
        {
        }

        inline std::shared_ptr<_common::_base> _clone() const final
        {
            return std::make_shared<number::_instance<_Thing>>(_thing);
        }

        inline void inc() final
        {
            _thing.inc();
        }

        inline void dec() final
        {
            _thing.dec();
        }

    private:
        _Thing _thing;
    };

public:
    template<typename _Thing, typename ... _Args>
    inline static number _make(_Args && ... _args)
    {
        return number(std::make_shared<number::_instance<_Thing>>(std::forward<_Args>(_args) ...));
    }

    inline bool _dynamic() const
    {
        return std::dynamic_pointer_cast<number::_derived>(_common::_shared).operator bool();
    }

    inline void inc()
    {
        _common::_mutate();
        std::dynamic_pointer_cast<number::_derived>(_common::_shared)->inc();
    }

    inline void dec()
    {
        _common::_mutate();
        std::dynamic_pointer_cast<number::_derived>(_common::_shared)->dec();
    }
};

struct widget_number : widget, number
{
    inline widget_number() = default;

    inline widget_number(std::shared_ptr<_common::_base> const & shared)
    :_common(shared)
    ,widget()
    ,number()
    {
    }

    inline widget_number(std::shared_ptr<_common::_base> && shared)
    :_common(std::move(shared))
    ,widget()
    ,number()
    {
    }

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

    inline widget_number & operator=(widget_number const & other)
    {
        number::operator=(other);
        return *this;
    }

    inline widget_number & operator=(widget_number && other)
    {
        number::operator=(std::move(other));
        return *this;
    }

    inline widget_number(_common const & other)
    :_common(other)
    ,widget()
    ,number()
    {
    }

    inline widget_number(_common && other)
    :_common(std::move(other))
    ,widget()
    ,number()
    {
    }

    inline widget_number & operator=(_common const & other)
    {
        number::operator=(other);
        return *this;
    }

    inline widget_number & operator=(_common && other)
    {
        number::operator=(std::move(other));
        return *this;
    }

    template <typename _Other>
    inline operator _Other() const
    {
        return _Other(*this);
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

        inline std::shared_ptr<_common::_base> _clone() const final
        {
            return std::static_pointer_cast<widget::_derived>(
                std::make_shared<widget_number::_instance<_Thing>>(_thing));
        }

        inline void display() const final
        {
            _thing.display();
        }

        inline void modify() final
        {
            _thing.modify();
        }

        inline void inc() final
        {
            _thing.inc();
        }

        inline void dec() final
        {
            _thing.dec();
        }

    private:
        _Thing _thing;
    };

public:
    template<typename _Thing, typename ... _Args>
    inline static widget_number _make(_Args && ... _args)
    {
        return widget_number(std::static_pointer_cast<widget::_derived>(
            std::make_shared<widget_number::_instance<_Thing>>(std::forward<_Args>(_args) ...)));
    }

    inline bool _dynamic() const
    {
        return std::dynamic_pointer_cast<widget_number::_derived>(_common::_shared).operator bool();
    }

    inline void inc()
    {
        _common::_mutate();
        std::dynamic_pointer_cast<widget_number::_derived>(_common::_shared)->inc();
    }

    inline void dec()
    {
        _common::_mutate();
        std::dynamic_pointer_cast<widget_number::_derived>(_common::_shared)->dec();
    }
};
}