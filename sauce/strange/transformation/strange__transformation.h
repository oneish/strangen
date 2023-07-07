#pragma once
#include <ostream>
#include "../definition/strange__space.h"

namespace strange
{

struct transformation
{
protected:
    strange::space _space;
    std::ostream & _out;

public:
    transformation(strange::space space, std::ostream & out)
    :_space(space)
    ,_out(out)
    {
    }

    void transform()
    {
        _out << R"#(
#pragma once
#include <memory>
)#";
        _namespace();
    }

protected:
    void _namespace()
    {
        _out << R"#(
namespace )#" << _space.name << R"#(
{
)#";
        // _forward_declarations();
        _out << R"#(
}
)#";
    }

    void _()
    {
        _out << R"#(
)#";
    }
};

}