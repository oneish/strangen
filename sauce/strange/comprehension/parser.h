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

    auto parse() -> space
    {
        token tok;
        parse_name(tok);
        if (tok.classification == cls::mistake)
        {
            return error<space>(tok.text);
        }
        if (tok.text != "namespace")
        {
            return error<space>("strange::parser::parse() expected 'namespace', but got name: " + tok.text);
        }
        auto spc = space::_make();
        parse_space(spc);
        return spc;
    }

    void parse_space(space & spc)
    {
        token tok;
        parse_name(tok);
        if (tok.classification == cls::mistake)
        {
            spc._error(tok.text);
            return;
        }
        spc.name() = tok.text;
        parse_punctuation(tok);
        if (tok.classification == cls::mistake)
        {
            spc._error(tok.text);
            return;
        }
        if (tok.text != "{")
        {
            spc._error("strange::parser::parse_space() expected '{', but got punctuation: " + tok.text);
            return;
        }
        for(;;)
        {
            parse_name_or_punctuation(tok);
            if (tok.classification == cls::mistake)
            {
                spc._error(tok.text);
                return;
            }
            if (tok.classification == cls::punctuation)
            {
                if (tok.text != "}")
                {
                    spc._error("strange::parser::parse_space() expected '}', but got punctuation: " + tok.text);
                    return;
                }
                return;
            }
            auto abs = abstraction::_make();
            parse_abstraction(tok, abs);
            if (!abs._valid())
            {
                spc._error(abs._error());
                return;
            }
            spc.abstractions().push_back(abs);
        }
    }

    void parse_abstraction(token & tok, abstraction & abs)
    {

    }

    void parse_name(token & tok)
    {
        while (!toke.end)
        {
            tok = toke.increment();
            switch (tok.classification)
            {
                case strange::comprehension::cls::character:
                    tok.classification = cls::mistake;
                    tok.text = "strange::parser::parse_name() got character: " + tok.text;
                    return;
                case strange::comprehension::cls::comment:
                    std::cout << "comment: " << tok.text << std::endl;
                    break;
                case strange::comprehension::cls::mistake:
                    return;
                case strange::comprehension::cls::name:
                    return;
                case strange::comprehension::cls::number:
                    tok.classification = cls::mistake;
                    tok.text = "strange::parser::parse_name() got number: " + tok.text;
                    return;
                case strange::comprehension::cls::punctuation:
                    tok.classification = cls::mistake;
                    tok.text = "strange::parser::parse_name() got punctuation: " + tok.text;
                    return;
                case strange::comprehension::cls::string:
                    tok.classification = cls::mistake;
                    tok.text = "strange::parser::parse_name() got string: " + tok.text;
                    return;
                default:
                    tok.classification = cls::mistake;
                    tok.text = "strange::parser::parse_name() got token: " + tok.text;
                    return;
            }
        }
        tok.classification = cls::mistake;
        tok.text = "strange::parser::parse_name() reached end of tokens";
    }

    void parse_punctuation(token & tok)
    {
        while (!toke.end)
        {
            tok = toke.increment();
            switch (tok.classification)
            {
                case strange::comprehension::cls::character:
                    tok.classification = cls::mistake;
                    tok.text = "strange::parser::parse_punctuation() got character: " + tok.text;
                    return;
                case strange::comprehension::cls::comment:
                    std::cout << "comment: " << tok.text << std::endl;
                    break;
                case strange::comprehension::cls::mistake:
                    return;
                case strange::comprehension::cls::name:
                    tok.classification = cls::mistake;
                    tok.text = "strange::parser::parse_punctuation() got name: " + tok.text;
                    return;
                case strange::comprehension::cls::number:
                    tok.classification = cls::mistake;
                    tok.text = "strange::parser::parse_punctuation() got number: " + tok.text;
                    return;
                case strange::comprehension::cls::punctuation:
                    return;
                case strange::comprehension::cls::string:
                    tok.classification = cls::mistake;
                    tok.text = "strange::parser::parse_punctuation() got string: " + tok.text;
                    return;
                default:
                    tok.classification = cls::mistake;
                    tok.text = "strange::parser::parse_punctuation() got token: " + tok.text;
                    return;
            }
        }
        tok.classification = cls::mistake;
        tok.text = "strange::parser::parse_punctuation() reached end of tokens";
    }

    void parse_name_or_punctuation(token & tok)
    {
        while (!toke.end)
        {
            tok = toke.increment();
            switch (tok.classification)
            {
                case strange::comprehension::cls::character:
                    tok.classification = cls::mistake;
                    tok.text = "strange::parser::parse_name_or_punctuation() got character: " + tok.text;
                    return;
                case strange::comprehension::cls::comment:
                    std::cout << "comment: " << tok.text << std::endl;
                    break;
                case strange::comprehension::cls::mistake:
                    return;
                case strange::comprehension::cls::name:
                    return;
                case strange::comprehension::cls::number:
                    tok.classification = cls::mistake;
                    tok.text = "strange::parser::parse_name_or_punctuation() got number: " + tok.text;
                    return;
                case strange::comprehension::cls::punctuation:
                    return;
                case strange::comprehension::cls::string:
                    tok.classification = cls::mistake;
                    tok.text = "strange::parser::parse_name_or_punctuation() got string: " + tok.text;
                    return;
                default:
                    tok.classification = cls::mistake;
                    tok.text = "strange::parser::parse_name_or_punctuation() got token: " + tok.text;
                    return;
            }
        }
        tok.classification = cls::mistake;
        tok.text = "strange::parser::parse_name_or_punctuation() reached end of tokens";
    }
};
}
}
