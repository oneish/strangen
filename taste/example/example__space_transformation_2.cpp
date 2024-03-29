// meta code
#include "example__space_definition.h"
#include "../../sauce/strange/meta/strange__transformation.h"

#include <iostream>
int main()
{
std::cout << R"~(#pragma once
#include "../../sauce/strange/common/strange__common.h"
#include "../../sauce/strange/reflection/strange__reflection.h"
)~";

// more meta code
strange::transformation(example::meta::definition(), std::cout).transform();

std::cout << R"~()~";

return 0;
}
