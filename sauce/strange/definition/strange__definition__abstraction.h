#pragma once
#include "../space/strange__space.h"
#include "../reflection/strange__reflection.h"
#include <string>

namespace strange
{
namespace definition
{
struct abstraction
{
    strange::vector<strange::parameter> parameters = strange::vector<strange::parameter>::_make();
    std::string name;
    strange::vector<std::string> parents = strange::vector<std::string>::_make();
    strange::vector<strange::parameter> types = strange::vector<strange::parameter>::_make();
    strange::vector<strange::operation> operations = strange::vector<strange::operation>::_make();
    std::string thing;
};

}

template<>
struct reflection<strange::definition::abstraction>
{
    inline static auto name() -> std::string
    {
        return "strange::definition::abstraction";
    }
};

}
