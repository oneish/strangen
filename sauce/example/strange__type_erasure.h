#pragma once
#include <memory>

namespace strange
{
struct _common
{
protected:
    struct _base
    {
        virtual std::shared_ptr<_common::_base> _clone() const = 0;
    };

    std::shared_ptr<_common::_base> _shared;
};

struct widget : virtual _common
{
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
        widget w;
        w._shared = std::make_shared<widget::_instance<_Thing>>(std::forward<_Args>(_args) ...);
        return w;
    }

    inline void display() const
    {
        std::static_pointer_cast<widget::_derived>(_shared)->display();
    }

    inline void modify()
    {
        _shared = _shared->_clone();
        std::static_pointer_cast<widget::_derived>(_shared)->modify();
    }
};
}