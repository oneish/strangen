
// meta code
#include "strange__space_definition.h"
#include "../transformation/strange__transformation.h"

#include <iostream>
int main()
{
std::cout << R"~(#pragma once
#include "../common/strange__common.h"
#include <string>
#include <vector>
)~";

// more meta code
strange::transformation(strange::meta::definition(), std::cout).transform();

std::cout << R"~()~";

return 0;
}
