
// meta code
#include <iostream>
#include "example__space_definition.h"
#include "../strange/transformation/strange__transformation.h"

#include <iostream>
int main()
{
std::cout << R"~(
// normal code
)~";

// more meta code
strange::transformation(example::definition(), std::cout).transform();

std::cout << R"~()~";

return 0;
}
