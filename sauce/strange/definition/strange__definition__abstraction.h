#pragma once
#include <string>
#include <vector>
#include "strange__definition__operation.h"
#include "strange__definition__parameter.h"

namespace strange
{
namespace definition
{
struct abstraction
{
    std::vector<parameter> parameters;
    std::string name;
    std::vector<std::string> parents;
    std::vector<operation> operations;
};
}
}