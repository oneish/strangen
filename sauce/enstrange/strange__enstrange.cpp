// Command-line tool that reads a prototype file, parses it, and generates
// a complete type-erased space header. Combines the strangen preprocessing
// and meta code generation steps into a single command.
//
// Usage: enstrange prototype_file output_file
//
// The output is designed to be compiled with -I path/to/sauce/strange
// to resolve the strange library includes.

#include <fstream>
#include <iostream>
#include "strange/strange.h"
#include "strange/comprehension/strange__comprehension__parser.h"
#include "strange/meta/strange__transformation.h"

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        std::cerr << "usage: enstrange prototype_file output_file" << std::endl;
        return 1;
    }

    std::string input_filename = argv[1];
    std::string output_filename = argv[2];

    std::ifstream ifs{input_filename, std::ios::binary};
    if (!ifs.is_open())
    {
        std::cerr << "enstrange: failed to open input file: " << input_filename << std::endl;
        return 2;
    }

    std::ofstream ofs{output_filename, std::ios::binary | std::ios::trunc};
    if (!ofs.is_open())
    {
        std::cerr << "enstrange: failed to open output file: " << output_filename << std::endl;
        return 3;
    }

    std::istreambuf_iterator<char> it{ifs};
    strange::comprehension::toker toker{it, input_filename};
    strange::comprehension::parser parser{toker};
    auto space = parser.parse();

    if (space._valid())
    {
        strange::transformation(space, ofs).transform();
    }
    else
    {
        ofs << R"(static_assert(false, "enstrange error: )" << space._error() << R"(");
)";
        std::cerr << "enstrange: parse error: " << space._error() << std::endl;
        return 4;
    }

    return 0;
}
