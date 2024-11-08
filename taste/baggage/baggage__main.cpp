#include "../../sauce/strange/strange.h"
#include "../../sauce/strange/implementation/baggage/strange__implementation__baggage.h"
#include <iostream>
#include <string>

int main()
{
    std::cout << "baggage\n";
    auto b = strange::baggage::_make();
    return 0;
}
