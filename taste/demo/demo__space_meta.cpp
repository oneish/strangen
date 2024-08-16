// meta code
#include <fstream>
#include "../../sauce/strange/strange.h"
#include "../../sauce/strange/comprehension/strange__comprehension__parser.h"
#include "../../sauce/strange/meta/strange__transformation.h"

#include <iostream>
int main()
{
std::cout << R"~(#pragma once
#include "../../sauce/strange/common/strange__common.h"
#include "../../sauce/strange/reflection/strange__reflection.h"
)~";

    // more meta code
    char const * const prototype = "demo__space_prototype.h";
    std::ifstream ifs{prototype, std::ios::binary};
    std::istreambuf_iterator<char> it{ifs};
    strange::comprehension::toker toker(it, prototype);
    strange::comprehension::parser parser(toker);
    auto space = parser.parse();
    if (space._valid())
    {
        strange::transformation(space, std::cout).transform();
    }
    else
    {
        std::cout << R"#(static_assert(false, "demo space error: )#" << space._error() << R"#(");
)#";
    }

std::cout << R"~(
)~";

return 0;
}
