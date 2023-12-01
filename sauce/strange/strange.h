#pragma once

#include "space/strange__space.h"
#include <functional>

#include "definition/strange__definition__parameter.h"

namespace strange
{
inline auto make_parameter(definition::parameter param) -> definition::parameter
{
    return param;
}
}

#include "definition/strange__definition__operation.h"

namespace strange
{
inline auto make_operation(definition::operation oper) -> definition::operation
{
    return oper;
}
}

#include "definition/strange__definition__abstraction.h"

namespace strange
{
inline auto make_abstraction(definition::abstraction abs) -> definition::abstraction
{
    return abs;
}
}

#include "definition/strange__definition__space.h"

namespace strange
{
inline auto make_space(definition::space spc) -> definition::space
{
    return spc;
}
}
