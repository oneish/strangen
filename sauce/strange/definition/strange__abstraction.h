#pragma once
#include <string>
#include <vector>
#include "strange__operation.h"
#include "strange__parameter.h"

namespace strange
{

struct abstraction
{
    std::vector<strange::parameter> parameters;
    std::string name;
    std::vector<std::string> parents;
    std::vector<strange::operation> operations;
};

}
