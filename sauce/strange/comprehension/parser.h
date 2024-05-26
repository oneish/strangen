#pragma once
#include "toker.h"
#include "../strange.h"
#include <iostream>

namespace strange
{
namespace comprehension
{
struct parser
{
    toker toke;

    parser(toker tokenizer)
    :toke{tokenizer}
    {
    }

    space parse()
    {
        while (!toke.end)
        {
            auto token = toke.increment();
            switch (token.classification)
            {
                case strange::comprehension::cls::character:
                    std::cout << "character:";
                    break;
                case strange::comprehension::cls::comment:
                    std::cout << "comment:";
                    break;
                case strange::comprehension::cls::mistake:
                    std::cout << "mistake:";
                    break;
                case strange::comprehension::cls::name:
                    if (token.text == "namespace")
                    {
                        return parse_space();
                    }
                    std::cout << "name:";
                    break;
                case strange::comprehension::cls::number:
                    std::cout << "number:";
                    break;
                case strange::comprehension::cls::punctuation:
                    std::cout << "punctuation:";
                    break;
                case strange::comprehension::cls::string:
                    std::cout << "string:";
                    break;
                default:
                    std::cout << "token:";
            }
            std::cout << token.text << std::endl;
        }
        return space{};
    }

    space parse_space()
    {
        return space{};
    }
};
}
}
