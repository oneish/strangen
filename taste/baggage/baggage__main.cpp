#include "../../sauce/strange/strange.h"
#include "../../sauce/strange/implementation/baggage/strange__implementation__baggage.h"
#include <iostream>
#include <string>

int main()
{
    std::cout << "baggage\n";
    strange::implementation::baggage b;
    auto b2 = strange::baggage::_make();
    return 0;
}
