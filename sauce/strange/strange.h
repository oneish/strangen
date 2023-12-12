#pragma once
#include "space/strange__space.h"

namespace strange
{
// deduction guide
template<class InputIt>
vector(InputIt, InputIt)
    -> vector<typename std::iterator_traits<InputIt>::value_type>;
}
