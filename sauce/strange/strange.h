#pragma once
#include "common/strange__common.h"
#include "common/strange__hash.h"
#include "reflection/strange__reflection.h"

namespace strange
{
namespace comprehension
{
enum class cls;
}
namespace implementation
{
struct baggage;

template <typename Config, typename Signal>
struct graph;
}
}

#include "space/strange__space.h"

namespace strange
{
// deduction guide
template<class InputIt>
vector(InputIt, InputIt)
    -> vector<typename std::iterator_traits<InputIt>::value_type>;

template<typename _Abstraction, typename Message>
auto error(Message && message) -> _Abstraction
{
    _Abstraction abs;
    abs._error(message);
    return abs;
}
}
