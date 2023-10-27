
// meta code
#include <iostream>
#include "example__space_definition.h"
#include "../../sauce/strange/transformation/strange__transformation.h"

#include <iostream>
int main()
{
std::cout << R"~(#pragma once
#include "../../sauce/strange/common/strange__common.h"
)~";

// more meta code
strange::transformation(example::definition(), std::cout).transform();

std::cout << R"~()~";

return 0;
}
