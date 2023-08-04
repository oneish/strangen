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
};

struct button : widget
{
};

struct number : virtual strange::_common
{
};

struct widget_number : widget, number
{
};

template<typename Data>
struct numeric : number
{
};

}
