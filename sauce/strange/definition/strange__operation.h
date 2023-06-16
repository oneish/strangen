#pragma once
#include <string>
#include <vector>
#include "strange__parameter.h"

namespace strange
{

struct operation
{
    std::string name;
    std::vector<strange::parameter> parameters;
    bool constness;
    std::string result;
};

}
