#pragma once
#include "../strange.h"
#include <iostream>
#include <algorithm>

namespace strange
{
namespace comprehension
{
struct parser
{
    static inline auto rtrim(std::string & s) -> void
    {
        s.erase(std::find_if(s.rbegin(), s.rend(),
            [](unsigned char ch)
            {
                return !std::isspace(ch);
            }).base(), s.end());
    }

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
            if (oper.data())
            {
                if (!oper.constness())
                {
                    auto result = oper.result();
                    oper.result() += " const &";
                    oper.constness() = true;
                    abs.operations().push_back(oper);
                    oper.result() = result;
                    oper.constness() = false;
                }
                oper.result() += " &";
            }
            abs.operations().push_back(oper);
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
            switch (tok.classification())
            {
                case cls::character:
                    arg += "'" + tok.text() + "'";
                    break;
                case cls::comment:
                    break;
                case cls::mistake:
                    return;
                case cls::name:
                    arg += tok.text();
                    break;
                case cls::number:
                    arg += tok.text();
                    break;
                case cls::punctuation:
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
                            rtrim(arg);
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
                        else
                        {
                            rtrim(arg);
                        }
                        return;
                    }
                    break;
                case cls::string:
                    arg += "\"" + tok.text() + "\"";
                    break;
                case cls::whitespace:
                    if (!arg.empty())
                    {
                        arg += " ";
                    }
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
        parse_string(tok, abs.thing());
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
                break;
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
                parse_name_or_punctuation(tok, true);
                if (tok.classification() == cls::mistake)
                {
                    oper._error(tok.text());
                    return;
                }
                if (tok.classification() == cls::whitespace)
                {
                    if (!oper.name().empty())
                    {
                        oper.name() += " ";
                    }
                    continue;
                }
                if (tok.text() == "(")
                {
                    rtrim(oper.name());
                    break;
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
                parse_name_or_punctuation(tok, true);
                if (tok.classification() == cls::mistake)
                {
                    oper._error(tok.text());
                    return;
                }
                if (tok.text() == "{" || tok.text() == ";")
                {
                    rtrim(oper.result());
                    break;
                }
                if (ignore)
                {
                    continue;
                }
                if (tok.classification() == cls::whitespace)
                {
                    if (!oper.result().empty())
                    {
                        oper.result() += " ";
                    }
                    continue;
                }
                oper.result() += tok.text();
            }
        }
        else
        {
            oper.data() = true;
            oper.result() = tok.text();
            for (;;)
            {
                parse_name_or_punctuation(tok, true);
                if (tok.classification() == cls::mistake)
                {
                    oper._error(tok.text());
                    return;
                }
                if (tok.text() == "{" || tok.text() == ";")
                {
                    rtrim(oper.result());
                    oper.result() = oper.result().substr(0, oper.result().length() - oper.name().length());
                    rtrim(oper.result());
                    break;
                }
                oper.result() += tok.text();
                if (tok.classification() == cls::name)
                {
                    oper.name() = tok.text();
                }
            }
            if (oper.result().length() > 5 && oper.result().substr(oper.result().length() - 5) == "const")
            {
                oper.constness() = true;
            }
        }
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
        std::string text;
        parse_string(tok, text);
        if (tok.classification() == cls::mistake)
        {
            oper._error(tok.text());
            return;
        }
        if (result)
        {
            oper.result() = text;
        }
        else if (modification)
        {
            oper.modification() = text;
        }
        else
        {
            oper.customisation() = text;
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
            for (;;)
            {
                parse_name_or_punctuation(tok, true);
                if (tok.classification() == cls::mistake)
                {
                    oper._error(tok.text());
                    return;
                }
                if (tok.text() == "=" || tok.text() == "," || tok.text() == ")")
                {
                    rtrim(param.type());
                    param.type() = param.type().substr(0, param.type().length() - param.name().length());
                    rtrim(param.type());
                    break;
                }
                if (param.type().empty())
                {
                    param.type() = tok.text();
                    rtrim(param.type());
                }
                else
                {
                    param.type() += tok.text();
                }
                if (tok.classification() == cls::name)
                {
                    param.name() = tok.text();
                }
            }
            if (param.name().empty())
            {
                if (tok.text() != ")")
                {
                    oper._error("strange::parser::parse_parameters() expected ')', but got punctuation: " + tok.text());
                }
                return;
            }
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
                case cls::character:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_name() got character: " + tok.text();
                    return;
                case cls::comment:
                    break;
                case cls::mistake:
                    return;
                case cls::name:
                    return;
                case cls::number:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_name() got number: " + tok.text();
                    return;
                case cls::punctuation:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_name() got punctuation: " + tok.text();
                    return;
                case cls::string:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_name() got string: " + tok.text();
                    return;
                case cls::whitespace:
                    break;
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
                case cls::character:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_punctuation() got character: " + tok.text();
                    return;
                case cls::comment:
                    break;
                case cls::mistake:
                    return;
                case cls::name:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_punctuation() got name: " + tok.text();
                    return;
                case cls::number:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_punctuation() got number: " + tok.text();
                    return;
                case cls::punctuation:
                    return;
                case cls::string:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_punctuation() got string: " + tok.text();
                    return;
                case cls::whitespace:
                    break;
                default:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_punctuation() got token: " + tok.text();
                    return;
            }
        }
        tok.classification() = cls::mistake;
        tok.text() = "strange::parser::parse_punctuation() reached end of tokens";
    }

    void parse_string(strange::token & tok, std::string & text)
    {
        while (!toke.end)
        {
            tok = toke.increment();
            switch (tok.classification())
            {
                case cls::character:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_string() got character: " + tok.text();
                    return;
                case cls::comment:
                    break;
                case cls::mistake:
                    return;
                case cls::name:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_string() got name: " + tok.text();
                    return;
                case cls::number:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_string() got number: " + tok.text();
                    return;
                case cls::punctuation:
                    return;
                case cls::string:
                    if (!text.empty())
                    {
                        text += R"#(
)#";
                    }
                    text += tok.text();
                    break;
                case cls::whitespace:
                    break;
                default:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_string() got token: " + tok.text();
                    return;
            }
        }
        tok.classification() = cls::mistake;
        tok.text() = "strange::parser::parse_string() reached end of tokens";
    }

    void parse_name_or_punctuation(strange::token & tok, bool whitespace = false)
    {
        while (!toke.end)
        {
            tok = toke.increment();
            switch (tok.classification())
            {
                case cls::character:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_name_or_punctuation() got character: " + tok.text();
                    return;
                case cls::comment:
                    break;
                case cls::mistake:
                    return;
                case cls::name:
                    return;
                case cls::number:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_name_or_punctuation() got number: " + tok.text();
                    return;
                case cls::punctuation:
                    return;
                case cls::string:
                    tok.classification() = cls::mistake;
                    tok.text() = "strange::parser::parse_name_or_punctuation() got string: " + tok.text();
                    return;
                case cls::whitespace:
                    if (whitespace)
                    {
                        return;
                    }
                    break;
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
