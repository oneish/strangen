#pragma once
#include <string>
#include <vector>
#include "strange__operation.h"

namespace strange
{
struct abstraction
{
    std::string name;
    std::vector<strange::operation> operations;
};
}
