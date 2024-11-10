#pragma once
#include "../strange.h"
#include "strange__comprehension__toker.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>

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

    strange::token tok;

    std::string err;

    parser(toker tokenizer)
    :toke{tokenizer}
    ,tok{}
    ,err{}
    {
    }

    auto parse() -> space
    {
        auto spc = space::_make();
        err.clear();
        while (err.empty())
        {
            parse_name_or_punctuation();
            if (!err.empty())
            {
                err = "parse() " + err;
            }
            else if (tok.text() == "#")
            {
                parse_name();
                if (!err.empty())
                {
                    err = "parse() " + err;
                }
                else if (tok.text() != "include")
                {
                    err = "parse() expected 'include', but got name";
                }
                else
                {
                    std::string prototype;
                    parse_string(prototype, true);
                    if (!err.empty())
                    {
                        err = "parse() " + err;
                    }
                    else
                    {
                        std::ifstream ifs{prototype, std::ios::binary};
                        std::istreambuf_iterator<char> it{ifs};
                        auto previous = toke;
                        toke = toker{it, prototype};
                        auto deep = parse();
                        toke = previous;
                        for (auto abstraction : deep.inclusions())
                        {
                            spc.inclusions().push_back(abstraction);
                        }
                        for (auto abstraction : deep.abstractions())
                        {
                            abstraction.name() = deep.name() + "::" + abstraction.name();
                            spc.inclusions().push_back(abstraction);
                        }
                    }
                }
            }
            else if (tok.text() != "namespace")
            {
                err = "parse() expected '#' or 'namespace', but got text";
            }
            else
            {
                break;
            }
        }
        if (err.empty())
        {
            parse_space(spc);
        }
        if (!err.empty())
        {
            std::stringstream str;
            str << "strange::comprehension::parser::" << err << " - " << tok;
            spc._error(str.str());
        }
        return spc;
    }

    auto parse_space(space & spc) -> void
    {
        parse_name();
        if (!err.empty())
        {
            err = "parse_space() " + err;
            return;
        }
        spc.name() = tok.text();
        parse_punctuation();
        if (!err.empty())
        {
            err = "parse_space() " + err;
            return;
        }
        if (tok.text() != "{")
        {
            err = "parse_space() expected '{', but got punctuation";
            return;
        }
        for (;;)
        {
            parse_name_or_punctuation();
            if (!err.empty())
            {
                err = "parse_space() " + err;
                return;
            }
            if (tok.classification() == cls::punctuation)
            {
                if (tok.text() != "}")
                {
                    err = "parse_space() expected name or '}', but got punctuation";
                    return;
                }
                break;
            }
            auto abs = abstraction::_make();
            parse_abstraction(abs);
            if (!err.empty())
            {
                return;
            }
            spc.abstractions().push_back(abs);
        }
    }

    void parse_abstraction(abstraction & abs)
    {
        if (tok.text() == "template")
        {
            parse_abstraction_template(abs);
            if (!err.empty())
            {
                return;
            }
            parse_name();
            if (!err.empty())
            {
                err = "parse_abstraction() " + err;
                return;
            }
        }
        if (tok.text() != "struct")
        {
            err = "parse_abstraction() expected 'struct', but got name";
            return;
        }
        parse_name_or_punctuation();
        if (!err.empty())
        {
            err = "parse_abstraction() " + err;
            return;
        }
        while (tok.classification() == cls::punctuation)
        {
            if (tok.text() != "[[")
            {
                break;
            }
            parse_abstraction_attribute(abs);
            if (!err.empty())
            {
                return;
            }
            parse_name_or_punctuation();
            if (!err.empty())
            {
                err = "parse_abstraction() " + err;
                return;
            }
        }
        abs.name() = tok.text();
        parse_punctuation();
        if (!err.empty())
        {
            err = "parse_abstraction() " + err;
            return;
        }
        if (tok.text() == ":")
        {
            parse_abstraction_parents(abs);
            if (!err.empty())
            {
                return;
            }
        }
        if (tok.text() != "{")
        {
            err = "parse_abstraction() expected '{', but got punctuation";
            return;
        }
        for (;;)
        {
            parse_name_or_punctuation();
            if (!err.empty())
            {
                err = "parse_abstraction() " + err;
                return;
            }
            if (tok.text() == "}")
            {
                break;
            }
            if (tok.text() == "using")
            {
                auto type = parameter::_make();
                parse_abstraction_type(type);
                if (!err.empty())
                {
                    return;
                }
                abs.types().push_back(type);
                continue;
            }
            auto oper = operation::_make();
            parse_operation(oper);
            if (!err.empty())
            {
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
            if (abs.implementation().empty() && !oper.implementation().empty())
            {
                abs.implementation() = abs.thing();
            }
        }
        parse_punctuation();
        if (!err.empty())
        {
            err = "parse_abstraction() " + err;
            return;
        }
        if (tok.text() != ";")
        {
            err = "parse_abstraction() expected ';', but got punctuation";
        }
    }

    void parse_abstraction_template(abstraction & abs)
    {
        parse_punctuation();
        if (!err.empty())
        {
            err = "parse_abstraction_template() " + err;
            return;
        }
        if (tok.text() != "<")
        {
            err = "parse_abstraction_template() expected '<', but got punctuation";
            return;
        }
        for (;;)
        {
            parse_name();
            if (!err.empty())
            {
                err = "parse_abstraction_template() " + err;
                return;
            }
            if (tok.text() != "typename")
            {
                err = "parse_abstraction_template() expected 'typename', but got name";
                return;
            }
            auto param = strange::parameter::_make();
            param.type() = tok.text();
            parse_name();
            if (!err.empty())
            {
                err = "parse_abstraction_template() " + err;
                return;
            }
            param.name() = tok.text();
            parse_punctuation();
            if (!err.empty())
            {
                err = "parse_abstraction_template() " + err;
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
                err = "parse_abstraction_template() expected '=', ',' or '>', but got punctuation";
                return;
            }
            parse_argument(param.argument());
            if (!err.empty())
            {
                err = "parse_abstraction_template() " + err;
                return;
            }
            abs.parameters().push_back(param);
            if (tok.text() == ">")
            {
                return;
            }
            if (tok.text() != ",")
            {
                err = "parse_abstraction_template() expected ',' or '>', but got punctuation";
                return;
            }
        }
    }

    void parse_abstraction_parents(abstraction & abs)
    {
        for (;;)
        {
            std::string parent;
            parse_argument(parent, true);
            if (!err.empty())
            {
                err = "parse_abstraction_parents() " + err;
                return;
            }
            abs.parents().push_back(parent);
            if (tok.text() == "{")
            {
                break;
            }
            if (tok.text() != ",")
            {
                err = "parse_abstraction_parents() expected ',' or '{', but got punctuation";
                return;
            }
        }
    }

    void parse_abstraction_attribute(abstraction & abs)
    {
        parse_name();
        if (!err.empty())
        {
            err = "parse_abstraction_attribute() " + err;
            return;
        }
        if (tok.text() != "strange")
        {
            err = "parse_abstraction_attribute() expected 'strange', but got name";
            return;
        }
        parse_punctuation();
        if (!err.empty())
        {
            err = "parse_abstraction_attribute() " + err;
            return;
        }
        if (tok.text() != "::")
        {
            err = "parse_abstraction_attribute() expected '::', but got punctuation";
            return;
        }
        parse_name();
        if (!err.empty())
        {
            err = "parse_abstraction_attribute() " + err;
            return;
        }
        bool thing = (tok.text() == "thing");
        bool implementation = (tok.text() == "implementation");
        if (!thing && !implementation)
        {
            err = "parse_abstraction_attribute() expected 'thing' or 'implementation', but got name";
            return;
        }
        parse_punctuation();
        if (!err.empty())
        {
            err = "parse_abstraction_attribute() " + err;
            return;
        }
        if (tok.text() != "(")
        {
            err = "parse_abstraction_attribute() expected '(', but got punctuation";
            return;
        }
        if (thing)
        {
            parse_string(abs.thing());
        }
        else if (implementation)
        {
            parse_string(abs.implementation());
        }
        if (!err.empty())
        {
            err = "parse_abstraction_attribute() " + err;
            return;
        }
        if (tok.text() != ")")
        {
            err = "parse_abstraction_attribute() expected ')', but got punctuation";
            return;
        }
        parse_punctuation();
        if (!err.empty())
        {
            err = "parse_abstraction_attribute() " + err;
            return;
        }
        if (tok.text() != "]]")
        {
            err = "parse_abstraction_attribute() expected ']]', but got punctuation";
            return;
        }
    }

    void parse_abstraction_type(parameter & type)
    {
        type.type() = "using";
        parse_name();
        if (!err.empty())
        {
            err = "parse_abstraction_type() " + err;
            return;
        }
        type.name() = tok.text();
        parse_punctuation();
        if (!err.empty())
        {
            err = "parse_abstraction_type() " + err;
            return;
        }
        if (tok.text() != "=")
        {
            err = "parse_abstraction_type() expected '=', but got punctuation";
            return;
        }
        parse_argument(type.argument());
        if (!err.empty())
        {
            err = "parse_abstraction_type() " + err;
            return;
        }
        if (tok.text() != ";")
        {
            err = "parse_abstraction_type() expected ';', but got punctuation";
            return;
        }
    }

    void parse_operation(operation & oper)
    {
        while (tok.classification() == cls::punctuation)
        {
            if (tok.text() != "[[")
            {
                break;
            }
            parse_operation_attribute(oper);
            if (!err.empty())
            {
                return;
            }
            parse_name_or_punctuation();
            if (!err.empty())
            {
                err = "parse_operation() " + err;
                return;
            }
        }
        if (tok.text() == "auto")
        {
            for (;;)
            {
                parse_name_or_punctuation(true);
                if (!err.empty())
                {
                    err = "parse_operation() " + err;
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
                if (tok.text() == "(" && oper.name() != "operator")
                {
                    rtrim(oper.name());
                    break;
                }
                oper.name() += tok.text();
            }
            parse_operation_parameters(oper);
            if (!err.empty())
            {
                return;
            }
            parse_name_or_punctuation();
            if (!err.empty())
            {
                err = "parse_operation() " + err;
                return;
            }
            if (tok.text() == "const")
            {
                oper.constness() = true;
                parse_name_or_punctuation();
                if (!err.empty())
                {
                    err = "parse_operation() " + err;
                    return;
                }
            }
            if (tok.text() != "->")
            {
                err = "parse_operation() expected 'const' or '->', but got text";
                return;
            }
            bool ignore = !oper.result().empty();
            for (;;)
            {
                parse_name_or_punctuation(true);
                if (!err.empty())
                {
                    err = "parse_operation() " + err;
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
                parse_name_or_punctuation(true);
                if (!err.empty())
                {
                    err = "parse_operation() " + err;
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
            parse_argument(oper.implementation());
            if (!err.empty())
            {
                err = "parse_operation() " + err;
                return;
            }
            if (tok.text() != ";")
            {
                err = "parse_operation() expected ';', but got punctuation";
                return;
            }
        }
    }

    void parse_operation_attribute(operation & oper)
    {
        parse_name();
        if (!err.empty())
        {
            err = "parse_operation_attribute() " + err;
            return;
        }
        if (tok.text() != "strange")
        {
            err = "parse_operation_attribute() expected 'strange', but got name";
            return;
        }
        parse_punctuation();
        if (!err.empty())
        {
            err = "parse_operation_attribute() " + err;
            return;
        }
        if (tok.text() != "::")
        {
            err = "parse_operation_attribute() expected '::', but got punctuation";
            return;
        }
        parse_name();
        if (!err.empty())
        {
            err = "parse_operation_attribute() " + err;
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
            err = "parse_operation_attribute() expected 'result', 'modification' or 'customisation', but got name";
            return;
        }
        parse_punctuation();
        if (!err.empty())
        {
            err = "parse_operation_attribute() " + err;
            return;
        }
        if (tok.text() != "(")
        {
            err = "parse_operation_attribute() expected '(', but got punctuation";
            return;
        }
        std::string text;
        parse_string(text);
        if (!err.empty())
        {
            err = "parse_operation_attribute() " + err;
            return;
        }
        if (tok.text() != ")")
        {
            err = "parse_operation_attribute() expected ')', but got punctuation";
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
        parse_punctuation();
        if (!err.empty())
        {
            err = "parse_operation_attribute() " + err;
            return;
        }
        if (tok.text() != "]]")
        {
            err = "parse_operation_attribute() expected ']]', but got punctuation";
            return;
        }
    }

    void parse_operation_parameters(operation & oper)
    {
        for (;;)
        {
            auto param = strange::parameter::_make();
            int64_t angle = 0;
            for (;;)
            {
                parse_name_or_punctuation(true);
                if (!err.empty())
                {
                    err = "parse_operation_parameters() " + err;
                    return;
                }
                if (tok.text() == "<")
                {
                    ++angle;
                }
                else if (tok.text() == ">")
                {
                    --angle;
                    if (angle < 0)
                    {
                        err = "parse_operation_parameters() mismatched '>'";
                        return;
                    }
                }
                else if (angle == 0 && (tok.text() == "=" || tok.text() == "," || tok.text() == ")"))
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
                    err = "parse_operation_parameters() expected ')', but got punctuation";
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
                err = "parse_operation_parameters() expected '=', ',' or ')', but got punctuation";
                return;
            }
            parse_argument(param.argument());
            if (!err.empty())
            {
                err = "parse_operation_parameters() " + err;
                return;
            }
            oper.parameters().push_back(param);
            if (tok.text() == ")")
            {
                return;
            }
            if (tok.text() != ",")
            {
                err = "parse_operation_parameters() expected ',' or ')', but got punctuation";
                return;
            }
        }
    }

    void parse_name()
    {
        while (!toke.end)
        {
            tok = toke.increment();
            switch (tok.classification())
            {
                case cls::character:
                    err = "parse_name() got character";
                    return;
                case cls::comment:
                    break;
                case cls::mistake:
                    err = "parse_name() got mistake";
                    return;
                case cls::name:
                    return;
                case cls::number:
                    err = "parse_name() got number";
                    return;
                case cls::punctuation:
                    err = "parse_name() got punctuation";
                    return;
                case cls::string:
                    err = "parse_name() got string";
                    return;
                case cls::whitespace:
                    break;
                default:
                    err = "parse_name() unexpected classification";
                    return;
            }
        }
        err = "parse_name() reached end of tokens";
    }

    void parse_punctuation()
    {
        while (!toke.end)
        {
            tok = toke.increment();
            switch (tok.classification())
            {
                case cls::character:
                    err = "parse_punctuation() got character";
                    return;
                case cls::comment:
                    break;
                case cls::mistake:
                    err = "parse_punctuation() got mistake";
                    return;
                case cls::name:
                    err = "parse_punctuation() got name";
                    return;
                case cls::number:
                    err = "parse_punctuation() got number";
                    return;
                case cls::punctuation:
                    return;
                case cls::string:
                    err = "parse_punctuation() got string";
                    return;
                case cls::whitespace:
                    break;
                default:
                    err = "parse_punctuation() unexpected classification";
                    return;
            }
        }
        err = "parse_punctuation() reached end of tokens";
    }

    void parse_string(std::string & text, bool single = false)
    {
        while (!toke.end)
        {
            tok = toke.increment();
            switch (tok.classification())
            {
                case cls::character:
                    err = "parse_string() got character";
                    return;
                case cls::comment:
                    break;
                case cls::mistake:
                    err = "parse_string() got mistake";
                    return;
                case cls::name:
                    err = "parse_string() got name";
                    return;
                case cls::number:
                    err = "parse_string() got number";
                    return;
                case cls::punctuation:
                    // expected
                    return;
                case cls::string:
                    if (!text.empty())
                    {
                        text += R"#(
)#";
                    }
                    text += tok.text();
                    if (single)
                    {
                        return;
                    }
                    break;
                case cls::whitespace:
                    break;
                default:
                    err = "parse_string() unexpected classification";
                    return;
            }
        }
        err = "parse_string() reached end of tokens";
    }

    void parse_name_or_punctuation(bool whitespace = false)
    {
        while (!toke.end)
        {
            tok = toke.increment();
            switch (tok.classification())
            {
                case cls::character:
                    err = "parse_name_or_punctuation() got character";
                    return;
                case cls::comment:
                    break;
                case cls::mistake:
                    err = "parse_name_or_punctuation() got mistake";
                    return;
                case cls::name:
                    return;
                case cls::number:
                    err = "parse_name_or_punctuation() got number";
                    return;
                case cls::punctuation:
                    return;
                case cls::string:
                    err = "parse_name_or_punctuation() got string";
                    return;
                case cls::whitespace:
                    if (whitespace)
                    {
                        return;
                    }
                    break;
                default:
                    err = "parse_name_or_punctuation() unexpected classification";
                    return;
            }
        }
        err = "parse_name_or_punctuation() reached end of tokens";
    }

    void parse_argument(std::string & arg, bool parent = false)
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
                    err = "parse_argument() got mistake";
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
                    if (angle < 0 || curly < 0 || round < 0 || square < 0)
                    {
                        if (angle > 0)
                        {
                            err = "parse_argument() mismatched '<'";
                        }
                        else if (curly > 0)
                        {
                            err = "parse_argument() mismatched '{'";
                        }
                        else if (round > 0)
                        {
                            err = "parse_argument() mismatched '('";
                        }
                        else if (square > 0)
                        {
                            err = "parse_argument() mismatched '['";
                        }
                        else
                        {
                            rtrim(arg);
                        }
                        return;
                    }
                    if (angle == 0 && curly == 0 && round == 0 && square == 0 &&
                        (tok.text() == "," || tok.text() == ";"))
                    {
                        rtrim(arg);
                        return;
                    }
                    arg += tok.text();
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
                    err = "parse_argument() unexpected classification";
                    return;
            }
        }
        err = "parse_argument() reached end of tokens";
    }
};
}
}
