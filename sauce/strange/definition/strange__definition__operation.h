#pragma once
#include "../strange.h"
#include <string>
#include <vector>

namespace strange
{
namespace definition
{
struct operation
{
    std::string name;
    std::vector<parameter_a> parameters;
    bool constness = false;
    std::string result;
    bool data = false;
};
}
}