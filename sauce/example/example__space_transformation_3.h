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
template<typename Data = int> struct numeric;

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
};

}
