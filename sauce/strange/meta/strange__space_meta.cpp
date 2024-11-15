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
#include "../implementation/vector/strange__implementation__vector.h"
namespace strange
{
namespace comprehension
{
enum class cls;
}
namespace implementation
{
struct baggage;
}
}
)~";

    // more meta code
    char const * const prototype = "strange__space_prototype.h";
    std::ifstream ifs{prototype, std::ios::binary};
    std::istreambuf_iterator<char> it{ifs};
    strange::comprehension::toker toker{it, prototype};
    strange::comprehension::parser parser{toker};
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
template<typename T>
inline auto strange::implementation::vector<T>::pack(bag & dest) const -> void
{
    dest.from_array();
    for (auto const & item : *this)
    {
        if constexpr (std::is_same_v<bool, T>)
        {
            dest.push_back_array(dest.make_bool(item));
        }
        else if constexpr (std::is_integral_v<T>)
        {
            dest.push_back_array(dest.make_int64(item));
        }
        else if constexpr (std::is_floating_point_v<T>)
        {
            dest.push_back_array(dest.make_double(item));
        }
        else if constexpr (std::is_same_v<std::string, T>)
        {
            dest.push_back_array(dest.make_string(item));
        }
        else if constexpr (std::is_base_of_v<strange::any, T>)
        {
            dest.push_back_array(dest.make_any(item));
        }
    }
}
template<typename T>
inline auto strange::implementation::vector<T>::unpack(bag const & src) -> void
{
    std::vector<T>::clear();
    auto source = src.to_array();
    for (auto const & item : source)
    {
        if constexpr (std::is_same_v<bool, T>)
        {
            std::vector<T>::push_back(item.to_bool());
        }
        else if constexpr (std::is_integral_v<T>)
        {
            std::vector<T>::push_back(item.to_int64());
        }
        else if constexpr (std::is_floating_point_v<T>)
        {
            std::vector<T>::push_back(item.to_double());
        }
        else if constexpr (std::is_same_v<std::string, T>)
        {
            std::vector<T>::push_back(item.to_string());
        }
        else if constexpr (std::is_base_of_v<strange::any, T>)
        {
            std::vector<T>::push_back(item.to_any());
        }
    }
}
)~";

return 0;
}
