/*~// meta code
#include <fstream>
#include "../strange.h"
#include "../comprehension/strange__comprehension__parser.h"
#include "strange__transformation.h"
*/#pragma once
#include "../common/strange__common.h"
#include "../reflection/strange__reflection.h"
#include <vector>
namespace strange
{
namespace definition
{
struct parameter;
struct operation;
struct abstraction;
struct space;
}
namespace comprehension
{
enum class cls;
struct token;
}
}
/*~
    // more meta code
    std::ifstream ifs{"strange__space_prototype.h", std::ios::binary};
    std::istreambuf_iterator<char> it{ifs};
    strange::comprehension::toker toker(it);
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
*/
