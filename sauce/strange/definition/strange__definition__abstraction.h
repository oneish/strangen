#pragma once
#include "../strange.h"
#include <string>
#include <vector>

namespace strange
{
namespace definition
{
struct abstraction
{
    std::vector<parameter_a> parameters;
    std::string name;
    std::vector<std::string> parents;
    std::vector<operation> operations;
};
}
}