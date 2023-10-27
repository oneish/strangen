#pragma once
#include "strange__definition__abstraction.h"
#include <string>
#include <vector>

namespace strange
{
namespace definition
{
struct space
{
    std::string name;
    std::vector<abstraction> abstractions;
};
}
}