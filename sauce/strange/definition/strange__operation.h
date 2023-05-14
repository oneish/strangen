#pragma once
#include <string>

namespace strange
{
struct operation
{
    std::string name;
    std::string parameters;
    std::string return_type;
    bool constness;
};
}
