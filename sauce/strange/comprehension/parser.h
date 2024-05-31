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
                    return error<space>("strange::parser::parse() expected namespace, but got character: " + token.text);
                case strange::comprehension::cls::comment:
                    std::cout << "comment: " << token.text << std::endl;
                    break;
                case strange::comprehension::cls::mistake:
                    return error<space>("strange::parser::parse() expected namespace, but got mistake: " + token.text);
                case strange::comprehension::cls::name:
                    if (token.text == "namespace")
                    {
                        return parse_space();
                    }
                    return error<space>("strange::parser::parse() expected namespace, but got name: " + token.text);
                case strange::comprehension::cls::number:
                    return error<space>("strange::parser::parse() expected namespace, but got number: " + token.text);
                case strange::comprehension::cls::punctuation:
                    return error<space>("strange::parser::parse() expected namespace, but got punctuation: " + token.text);
                case strange::comprehension::cls::string:
                    return error<space>("strange::parser::parse() expected namespace, but got string: " + token.text);
                default:
                    return error<space>("strange::parser::parse() expected namespace, but got token: " + token.text);
            }
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
