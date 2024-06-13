#pragma once
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
        strange::token tok;
        parse_name(tok);
        if (tok.classification() == cls::mistake)
        {
            return error<space>(tok.text());
        }
        if (tok.text() != "namespace")
        {
            return error<space>("strange::parser::parse() expected 'namespace', but got name: " + tok.text());
        }
        auto spc = space::_make();
        parse_space(spc);
        return spc;
    }

    void parse_space(space & spc)
    {
        strange::token tok;
        parse_name(tok);
        if (tok.classification() == cls::mistake)
        {
            spc._error(tok.text());
            return;
        }
        spc.name() = tok.text();
        parse_punctuation(tok);
        if (tok.classification() == cls::mistake)
        {
            spc._error(tok.text());
            return;
        }
        if (tok.text() != "{")
        {
            spc._error("strange::parser::parse_space() expected '{', but got punctuation: " + tok.text());
            return;
        }
        for (;;)
        {
            parse_name_or_punctuation(tok);
            if (tok.classification() == cls::mistake)
            {
                spc._error(tok.text());
                return;
            }
            if (tok.classification() == cls::punctuation)
            {
                if (tok.text() != "}")
                {
                    spc._error("strange::parser::parse_space() expected name or '}', but got punctuation: " + tok.text());
                    return;
                }
                break;
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

    void parse_abstraction(strange::token & tok, abstraction & abs)
    {
        if (tok.text() == "template")
        {
            parse_template(abs);
            if (!abs._valid())
            {
                return;
            }
            parse_name(tok);
            if (tok.classification() == cls::mistake)
            {
                abs._error(tok.text());
                return;
            }
        }
        if (tok.text() != "struct")
        {
            abs._error("strange::parser::parse_abstraction() expected 'struct', but got name: " + tok.text());
            return;
        }
        parse_name_or_punctuation(tok);
        if (tok.classification() == cls::mistake)
        {
            abs._error(tok.text());
            return;
        }
        if (tok.classification() == cls::punctuation)
        {
            if (tok.text() != "[[")
            {
                abs._error("strange::parser::parse_abstraction() expected name or '[[', but got punctuation: " + tok.text());
                return;
            }
            parse_abstraction_attribute(abs);
            if (!abs._valid())
            {
                return;
            }
            parse_name(tok);
            if (tok.classification() == cls::mistake)
            {
                abs._error(tok.text());
                return;
            }
        }
        abs.name() = tok.text();
        parse_punctuation(tok);
        if (tok.classification() == cls::mistake)
        {
            abs._error(tok.text());
            return;
        }
        if (tok.text() == ":")
        {
            parse_parents(tok, abs);
            if (!abs._valid())
            {
                return;
            }
        }
        if (tok.text() != "{")
        {
            abs._error("strange::parser::parse_abstraction() expected '{', but got punctuation: " + tok.text());
            return;
        }
        for (;;)
        {
            parse_name_or_punctuation(tok);
            if (tok.classification() == cls::mistake)
            {
                abs._error(tok.text());
                return;
            }
            if (tok.text() == "}")
            {
                break;
            }
            if (tok.text() == "using")
            {
                auto type = parameter::_make();
                parse_type(type);
                if (!type._valid())
                {
                    abs._error(type._error());
                    return;
                }
                abs.types().push_back(type);
                continue;
            }
            auto oper = operation::_make();
            parse_operation(tok, oper);
            if (!oper._valid())
            {
                abs._error(oper._error());
                return;
            }
            abs.operations().push_back(oper);
            if (oper.data() && !oper.constness())
            {
                oper.constness() = true;
                oper.result() += " const";
                abs.operations().push_back(oper);
            }
        }
        parse_punctuation(tok);
        if (tok.classification() == cls::mistake)
        {
            abs._error(tok.text());
            return;
        }
        if (tok.text() != ";")
        {
            abs._error("strange::parser::parse_abstraction() expected ';', but got punctuation: " + tok.text());
        }
    }

    void parse_template(abstraction & abs)
    {
        strange::token tok;
        parse_punctuation(tok);
        if (tok.classification() == cls::mistake)
        {
            abs._error(tok.text());
            return;
        }
        if (tok.text() != "<")
        {
            abs._error("strange::parser::parse_template() expected '<', but got punctuation: " + tok.text());
            return;
        }
        for (;;)
        {
            parse_name(tok);
            if (tok.classification() == cls::mistake)
            {
                abs._error(tok.text());
                return;
            }
            if (tok.text() != "typename")
            {
                abs._error("strange::parser::parse_template() expected 'typename', but got name: " + tok.text());
                return;
            }
            auto param = strange::parameter::_make();
            param.type() = tok.text();
            parse_name(tok);
            if (tok.classification() == cls::mistake)
            {
                abs._error(tok.text());
                return;
            }
            param.name() = tok.text();
            parse_punctuation(tok);
            if (tok.classification() == cls::mistake)
            {
                abs._error(tok.text());
                return;
            }
            if (tok.text() == ">")
            {
                abs.parameters().push_back(param);
                return;
            }
            if (tok.text() == ",")
            {
                abs.parameters().push_back(param);
                continue;
            }
            if (tok.text() != "=")
            {
                abs._error("strange::parser::parse_template() expected '=', ',' or '>', but got punctuation: " + tok.text());
                return;
            }
            parse_argument(tok, param.argument());
            if (tok.classification() == cls::mistake)
            {
                abs._error(tok.text());
                return;
            }
            abs.parameters().push_back(param);
            if (tok.text() == ">")
            {
                return;
            }
            if (tok.text() != ",")
            {
                abs._error("strange::parser::parse_template() expected ',' or '>', but got punctuation: " + tok.text());
                return;
            }
        }
    }

    void parse_parents(strange::token & tok, abstraction & abs)
    {
        for (;;)
        {
            std::string parent;
            parse_argument(tok, parent, true);
            if (tok.classification() == cls::mistake)
            {
                abs._error(tok.text());
                return;
            }
            abs.parents().push_back(parent);
            if (tok.text() == "{")
            {
                break;
            }
            if (tok.text() != ",")
            {
                abs._error("strange::parser::parse_parents() expected ',' or '{', but got punctuation: " + tok.text());
                return;
            }
        }
    }

    void parse_argument(strange::token & tok, std::string & arg, bool parent = false)
    {
        int64_t angle = arg == "<" ? 1 : 0;
        int64_t curly = arg == "{" ? 1 : 0;
        int64_t round = arg == "(" ? 1 : 0;
        int64_t square = arg == "[" ? 1 : 0;
        while (!toke.end)
        {
            tok = toke.increment();
            if (!arg.empty())
            {
                arg += " ";
            }
            switch (tok.classification())
            {
                case strange::comprehension::cls::character:
                    arg += "'" + tok.text() + "'";
                    break;
                case strange::comprehension::cls::comment:
                    std::cout << "comment: " << tok.text() << std::endl;
                    break;
                case strange::comprehension::cls::mistake:
                    return;
                case strange::comprehension::cls::name:
                    arg += tok.text();
                    break;
                case strange::comprehension::cls::number:
                    arg += tok.text();
                    break;
                case strange::comprehension::cls::punctuation:
                    if (tok.text() == "<")
                    {
                        ++angle;
                    }
                    else if (tok.text() == ">")
                    {
                        --angle;
                    }
                    else if (tok.text() == "{")
                    {
                        if (parent && angle == 0 && curly == 0 && round == 0 && square == 0)
                        {
                            return;
                        }
                        ++curly;
                    }
                    else if (tok.text() == "}")
                    {
                        --curly;
                    }
                    else if (tok.text() == "(")
                    {
                        ++round;
                    }
                    else if (tok.text() == ")")
                    {
                        --round;
                    }
                    else if (tok.text() == "[")
                    {
                        ++square;
                    }
                    else if (tok.text() == "]")
                    {
                        --square;
                    }
                    if (tok.text() != "," && tok.text() != ";")
                    {
                        arg += tok.text();
                    }
                    if (angle < 0 || curly < 0 || round < 0 || square < 0 || tok.text() == "," || tok.text() == ";")
                    {
                        if (angle > 0 || curly > 0 || round > 0 || square > 0)
                        {
                            tok.classification() = cls::mistake;
                            tok.text() = "strange::parser::parse_argument() mismatched brackets: " + tok.text();
                        }
                        return;
                    }
                    break;
                case strange::comprehension::cls::string:
                    arg += "\"" + tok.text() + "\"";
                    break;
                default:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_argument() got token: " + tok.text();
                    return;
            }
        }
        tok.classification() = cls::mistake;
        tok.text() = "strange::parser::parse_argument() reached end of tokens";
    }

    void parse_abstraction_attribute(abstraction & abs)
    {
        strange::token tok;
        parse_name(tok);
        if (tok.classification() == cls::mistake)
        {
            abs._error(tok.text());
            return;
        }
        if (tok.text() != "strange")
        {
            abs._error("strange::parser::parse_abstraction_attribute() expected 'strange', but got name: " + tok.text());
            return;
        }
        parse_punctuation(tok);
        if (tok.classification() == cls::mistake)
        {
            abs._error(tok.text());
            return;
        }
        if (tok.text() != "::")
        {
            abs._error("strange::parser::parse_abstraction_attribute() expected '::', but got punctuation: " + tok.text());
            return;
        }
        parse_name(tok);
        if (tok.classification() == cls::mistake)
        {
            abs._error(tok.text());
            return;
        }
        if (tok.text() != "thing")
        {
            abs._error("strange::parser::parse_abstraction_attribute() expected 'thing', but got name: " + tok.text());
            return;
        }
        parse_punctuation(tok);
        if (tok.classification() == cls::mistake)
        {
            abs._error(tok.text());
            return;
        }
        if (tok.text() != "(")
        {
            abs._error("strange::parser::parse_abstraction_attribute() expected '(', but got punctuation: " + tok.text());
            return;
        }
        parse_string(tok);
        if (tok.classification() == cls::mistake)
        {
            abs._error(tok.text());
            return;
        }
        abs.thing() = tok.text();
        parse_punctuation(tok);
        if (tok.classification() == cls::mistake)
        {
            abs._error(tok.text());
            return;
        }
        if (tok.text() != ")")
        {
            abs._error("strange::parser::parse_abstraction_attribute() expected ')', but got punctuation: " + tok.text());
            return;
        }
        parse_punctuation(tok);
        if (tok.classification() == cls::mistake)
        {
            abs._error(tok.text());
            return;
        }
        if (tok.text() != "]]")
        {
            abs._error("strange::parser::parse_abstraction_attribute() expected ']]', but got punctuation: " + tok.text());
            return;
        }
    }

    void parse_type(parameter & type)
    {
        type.type() = "using";
        strange::token tok;
        parse_name(tok);
        if (tok.classification() == cls::mistake)
        {
            type._error(tok.text());
            return;
        }
        type.name() = tok.text();
        parse_punctuation(tok);
        if (tok.classification() == cls::mistake)
        {
            type._error(tok.text());
            return;
        }
        if (tok.text() != "=")
        {
            type._error("strange::parser::parse_type() expected '=', but got punctuation: " + tok.text());
            return;
        }
        parse_argument(tok, type.argument());
        if (tok.classification() == cls::mistake)
        {
            type._error(tok.text());
            return;
        }
        if (tok.text() != ";")
        {
            type._error("strange::parser::parse_type() expected ';', but got punctuation: " + tok.text());
            return;
        }
    }

    void parse_operation(strange::token & tok, operation & oper)
    {
        while (tok.classification() == cls::punctuation)
        {
            if (tok.text() != "[[")
            {
                oper._error("strange::parser::parse_operation() expected name or '[[', but got punctuation: " + tok.text());
                return;
            }
            parse_operation_attribute(oper);
            if (!oper._valid())
            {
                return;
            }
            parse_name_or_punctuation(tok);
            if (tok.classification() == cls::mistake)
            {
                oper._error(tok.text());
                return;
            }
        }
        if (tok.text() == "auto")
        {
            for (;;)
            {
                parse_name_or_punctuation(tok);
                if (tok.classification() == cls::mistake)
                {
                    oper._error(tok.text());
                    return;
                }
                if (tok.text() == "(")
                {
                    break;
                }
                if (!oper.name().empty())
                {
                    oper.name() += " ";
                }
                oper.name() += tok.text();
            }
            parse_parameters(oper);
            parse_name_or_punctuation(tok);
            if (tok.classification() == cls::mistake)
            {
                oper._error(tok.text());
                return;
            }
            if (tok.text() == "const")
            {
                oper.constness() = true;
                parse_name_or_punctuation(tok);
                if (tok.classification() == cls::mistake)
                {
                    oper._error(tok.text());
                    return;
                }
            }
            if (tok.text() != "->")
            {
                oper._error("strange::parser::parse_operation() expected 'const' or '->', but got text: " + tok.text());
                return;
            }
            bool ignore = !oper.result().empty();
            for (;;)
            {
                parse_name_or_punctuation(tok);
                if (tok.classification() == cls::mistake)
                {
                    oper._error(tok.text());
                    return;
                }
                if (tok.text() == ";")
                {
                    return;
                }
                if (ignore)
                {
                    continue;
                }
                if (!oper.result().empty())
                {
                    oper.result() != " ";
                }
                oper.result() += tok.text();
            }
        }
        oper.data() = true;
        std::string last = tok.text();
        std::string previous;
        for (;;)
        {
            parse_name_or_punctuation(tok);
            if (tok.classification() == cls::mistake)
            {
                oper._error(tok.text());
                return;
            }
            if (!oper.result().empty())
            {
                oper.result() += " ";
            }
            oper.result() += previous;
            if (tok.text() == "{" || tok.text() == ";")
            {
                break;
            }
            previous = last;
            last = tok.text();
        }
        if (previous == "const")
        {
            oper.constness() = true;
        }
        oper.name() = last;
        if (tok.text() != ";")
        {
            oper.implementation() = tok.text();
            parse_argument(tok, oper.implementation());
            if (tok.classification() == cls::mistake)
            {
                oper._error(tok.text());
                return;
            }
            if (tok.text() != ";")
            {
                oper._error("strange::parser::parse_operation() expected ';', but got punctuation: " + tok.text());
                return;
            }
        }
    }

    void parse_operation_attribute(operation & oper)
    {
        strange::token tok;
        parse_name(tok);
        if (tok.classification() == cls::mistake)
        {
            oper._error(tok.text());
            return;
        }
        if (tok.text() != "strange")
        {
            oper._error("strange::parser::parse_operation_attribute() expected 'strange', but got name: " + tok.text());
            return;
        }
        parse_punctuation(tok);
        if (tok.classification() == cls::mistake)
        {
            oper._error(tok.text());
            return;
        }
        if (tok.text() != "::")
        {
            oper._error("strange::parser::parse_operation_attribute() expected '::', but got punctuation: " + tok.text());
            return;
        }
        parse_name(tok);
        if (tok.classification() == cls::mistake)
        {
            oper._error(tok.text());
            return;
        }
        bool result = false;
        bool modification = false;
        if (tok.text() == "result")
        {
            result = true;
        }
        else if (tok.text() == "modification")
        {
            modification = true;
        }
        else if (tok.text() != "customisation")
        {
            oper._error("strange::parser::parse_operation_attribute() expected 'result', 'modification' or 'customisation', but got name: " + tok.text());
            return;
        }
        parse_punctuation(tok);
        if (tok.classification() == cls::mistake)
        {
            oper._error(tok.text());
            return;
        }
        if (tok.text() != "(")
        {
            oper._error("strange::parser::parse_operation_attribute() expected '(', but got punctuation: " + tok.text());
            return;
        }
        parse_string(tok);
        if (tok.classification() == cls::mistake)
        {
            oper._error(tok.text());
            return;
        }
        if (result)
        {
            oper.result() = tok.text();
        }
        else if (modification)
        {
            oper.modification() = tok.text();
        }
        else
        {
            oper.customisation() = tok.text();
        }
        parse_punctuation(tok);
        if (tok.classification() == cls::mistake)
        {
            oper._error(tok.text());
            return;
        }
        if (tok.text() != ")")
        {
            oper._error("strange::parser::parse_operation_attribute() expected ')', but got punctuation: " + tok.text());
            return;
        }
        parse_punctuation(tok);
        if (tok.classification() == cls::mistake)
        {
            oper._error(tok.text());
            return;
        }
        if (tok.text() != "]]")
        {
            oper._error("strange::parser::parse_operation_attribute() expected ']]', but got punctuation: " + tok.text());
            return;
        }
    }

    void parse_parameters(operation & oper)
    {
        strange::token tok;
        for (;;)
        {
            auto param = strange::parameter::_make();
            std::string last;
            for (;;)
            {
                parse_name_or_punctuation(tok);
                if (tok.classification() == cls::mistake)
                {
                    oper._error(tok.text());
                    return;
                }
                if (tok.text() == "=" || tok.text() == "," || tok.text() == ")")
                {
                    break;
                }
                if (!param.type().empty())
                {
                    param.type() += " ";
                }
                param.type() += last;
                last = tok.text();
            }
            if (last.empty())
            {
                if (tok.text() != ")")
                {
                    oper._error("strange::parser::parse_parameters() expected ')', but got text: " + tok.text());
                }
                return;
            }
            param.name() = last;
            if (tok.text() == ")")
            {
                oper.parameters().push_back(param);
                return;
            }
            if (tok.text() == ",")
            {
                oper.parameters().push_back(param);
                continue;
            }
            if (tok.text() != "=")
            {
                oper._error("strange::parser::parse_parameters() expected '=', ',' or ')', but got punctuation: " + tok.text());
                return;
            }
            parse_argument(tok, param.argument());
            if (tok.classification() == cls::mistake)
            {
                oper._error(tok.text());
                return;
            }
            oper.parameters().push_back(param);
            if (tok.text() == ")")
            {
                return;
            }
            if (tok.text() != ",")
            {
                oper._error("strange::parser::parse_parameters() expected ',' or ')', but got punctuation: " + tok.text());
                return;
            }
        }
    }

    void parse_name(strange::token & tok)
    {
        while (!toke.end)
        {
            tok = toke.increment();
            switch (tok.classification())
            {
                case strange::comprehension::cls::character:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_name() got character: " + tok.text();
                    return;
                case strange::comprehension::cls::comment:
                    std::cout << "comment: " << tok.text() << std::endl;
                    break;
                case strange::comprehension::cls::mistake:
                    return;
                case strange::comprehension::cls::name:
                    return;
                case strange::comprehension::cls::number:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_name() got number: " + tok.text();
                    return;
                case strange::comprehension::cls::punctuation:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_name() got punctuation: " + tok.text();
                    return;
                case strange::comprehension::cls::string:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_name() got string: " + tok.text();
                    return;
                default:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_name() got token: " + tok.text();
                    return;
            }
        }
        tok.classification() = cls::mistake;
        tok.text() = "strange::parser::parse_name() reached end of tokens";
    }

    void parse_punctuation(strange::token & tok)
    {
        while (!toke.end)
        {
            tok = toke.increment();
            switch (tok.classification())
            {
                case strange::comprehension::cls::character:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_punctuation() got character: " + tok.text();
                    return;
                case strange::comprehension::cls::comment:
                    std::cout << "comment: " << tok.text() << std::endl;
                    break;
                case strange::comprehension::cls::mistake:
                    return;
                case strange::comprehension::cls::name:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_punctuation() got name: " + tok.text();
                    return;
                case strange::comprehension::cls::number:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_punctuation() got number: " + tok.text();
                    return;
                case strange::comprehension::cls::punctuation:
                    return;
                case strange::comprehension::cls::string:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_punctuation() got string: " + tok.text();
                    return;
                default:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_punctuation() got token: " + tok.text();
                    return;
            }
        }
        tok.classification() = cls::mistake;
        tok.text() = "strange::parser::parse_punctuation() reached end of tokens";
    }

    void parse_string(strange::token & tok)
    {
        while (!toke.end)
        {
            tok = toke.increment();
            switch (tok.classification())
            {
                case strange::comprehension::cls::character:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_string() got character: " + tok.text();
                    return;
                case strange::comprehension::cls::comment:
                    std::cout << "comment: " << tok.text() << std::endl;
                    break;
                case strange::comprehension::cls::mistake:
                    return;
                case strange::comprehension::cls::name:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_string() got name: " + tok.text();
                    return;
                case strange::comprehension::cls::number:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_string() got number: " + tok.text();
                    return;
                case strange::comprehension::cls::punctuation:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_string() got punctuation: " + tok.text();
                    return;
                case strange::comprehension::cls::string:
                    return;
                default:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_string() got token: " + tok.text();
                    return;
            }
        }
        tok.classification() = cls::mistake;
        tok.text() = "strange::parser::parse_string() reached end of tokens";
    }

    void parse_name_or_punctuation(strange::token & tok)
    {
        while (!toke.end)
        {
            tok = toke.increment();
            switch (tok.classification())
            {
                case strange::comprehension::cls::character:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_name_or_punctuation() got character: " + tok.text();
                    return;
                case strange::comprehension::cls::comment:
                    std::cout << "comment: " << tok.text() << std::endl;
                    break;
                case strange::comprehension::cls::mistake:
                    return;
                case strange::comprehension::cls::name:
                    return;
                case strange::comprehension::cls::number:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_name_or_punctuation() got number: " + tok.text();
                    return;
                case strange::comprehension::cls::punctuation:
                    return;
                case strange::comprehension::cls::string:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_name_or_punctuation() got string: " + tok.text();
                    return;
                default:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_name_or_punctuation() got token: " + tok.text();
                    return;
            }
        }
        tok.classification() = cls::mistake;
        tok.text() = "strange::parser::parse_name_or_punctuation() reached end of tokens";
    }
};
}
}
