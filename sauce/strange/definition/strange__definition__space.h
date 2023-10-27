#pragma once
#include <string>
#include <vector>
#include "strange__definition__abstraction.h"

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