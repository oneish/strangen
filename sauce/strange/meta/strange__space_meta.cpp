// meta code
#include "strange__space_definition.h"
#include "strange__transformation.h"

#include <iostream>
int main()
{
std::cout << R"~(#pragma once
#include "../common/strange__common.h"
#include "../reflection/strange__reflection.h"
#include "../definition/strange__definition__parameter.h"
#include <vector>
)~";

// more meta code
strange::transformation(strange::meta::definition(), std::cout).transform();

std::cout << R"~(
)~";

return 0;
}
