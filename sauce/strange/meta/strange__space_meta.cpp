// meta code
#include <fstream>
#include "../strange.h"
#include "../comprehension/strange__comprehension__parser.h"
#include "strange__transformation.h"

#include <iostream>
int main()
{
std::cout << R"~(#pragma once
#include "../common/strange__common.h"
#include "../reflection/strange__reflection.h"
#include <vector>
namespace strange
{
namespace comprehension
{
enum class cls;
}
}
)~";

    // more meta code
    char const * const prototype = "strange__space_prototype.h";
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
        std::cout << R"#(static_assert(false, "strange space error: )#" << space._error() << R"#(");
)#";
    }

std::cout << R"~(
)~";

return 0;
}
