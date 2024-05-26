#pragma once
#include "../reflection/strange__reflection.h"
#include <string>
#include <functional>

namespace strange
{
namespace definition
{
struct parameter
{
    std::string type;
    std::string name;
    std::string argument;
};

}

template<>
struct reflection<strange::definition::parameter>
{
    inline static auto name() -> std::string
    {
        return "strange::definition::parameter";
    }
};

}
