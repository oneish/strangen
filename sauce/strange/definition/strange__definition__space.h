#pragma once
#include "../space/strange__space.h"
#include "../reflection/strange__reflection.h"
#include <string>

namespace strange
{
namespace definition
{
struct space
{
    std::string name;
    strange::vector<strange::abstraction> abstractions;
};

}

template<>
struct reflection<strange::definition::space>
{
    inline static auto name() -> std::string
    {
        return "strange::definition::space";
    }
};

}
