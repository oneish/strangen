#pragma once
#include <string>
#include <vector>
#include "strange__abstraction.h"

namespace strange
{

struct space
{
    std::string name;
    std::vector<strange::abstraction> abstractions;
};

}
