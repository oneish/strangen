#pragma once
#include <string>
#include <vector>
#include "strange__operation.h"

namespace strange
{
struct abstraction
{
    std::string space;
    std::string parameters;
    std::string name;
    std::vector<std::string> parents;
    std::vector<strange::operation> operations;
};
}
