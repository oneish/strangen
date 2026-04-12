// A recursive descent parser for the strange prototype DSL. Reads tokens from
// a toker and produces a strange::space containing abstractions with their
// operations, parameters, template parameters, parent types, using declarations,
// and attributes. Supports #include directives for composing spaces from
// multiple files.

#pragma once
#include "../strange.h"
#include "strange__comprehension__toker.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <filesystem>

namespace strange
{
namespace comprehension
{
struct parser
{
    parser(toker tokenizer)
    :_toke{tokenizer}
    ,_tok{}
    ,_err{}
    {
    }

    auto parse() -> space
    {
        auto spc = space::_make();
        _err.clear();
        while (_err.empty())
        {
            parse_name_or_punctuation();
            if (!_err.empty())
            {
                _err = "parse() " + _err;
            }
            else if (_tok.text() == "#")
            {
                parse_name();
                if (!_err.empty())
                {
                    _err = "parse() " + _err;
                }
                else if (_tok.text() != "include")
                {
                    _err = "parse() expected 'include', but got name";
                }
                else
                {
                    parse_include(spc);
                    if (!_err.empty())
                    {
                        _err = "parse() " + _err;
                    }
                }
            }
            else if (_tok.text() != "namespace")
            {
                _err = "parse() expected '#' or 'namespace', but got text";
            }
            else
            {
                break;
            }
        }
        if (_err.empty())
        {
            parse_space(spc);
        }
        if (!_err.empty())
        {
            std::stringstream str;
            str << "strange::comprehension::parser::" << _err << " - " << _tok;
            spc._error(str.str());
        }
        return spc;
    }

    static inline auto rtrim(std::string & s) -> void
    {
        s.erase(std::find_if(s.rbegin(), s.rend(),
            [](unsigned char ch)
            {
                return !std::isspace(ch);
            }).base(), s.end());
    }

private:
    toker _toke;

    strange::token _tok;

    std::string _err;

    void parse_include(space & spc)
    {
        while (!_toke.end())
        {
            _tok = _toke.increment();
            if (_tok.classification() == cls::whitespace || _tok.classification() == cls::comment)
            {
                continue;
            }
            break;
        }
        if (_toke.end() && _tok.classification() == cls::whitespace)
        {
            _err = "parse_include() reached end of tokens";
            return;
        }
        if (_tok.classification() == cls::string)
        {
            std::string prototype = _tok.text();
            std::filesystem::path dir = std::filesystem::path(_toke.filename()).parent_path();
            std::filesystem::path resolved = dir / prototype;
            std::ifstream ifs{resolved, std::ios::binary};
            std::istreambuf_iterator<char> it{ifs};
            auto previous = _toke;
            _toke = toker{it, resolved.string()};
            auto deep = parse();
            _toke = previous;
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
        else if (_tok.classification() == cls::punctuation && _tok.text() == "<")
        {
            std::string include;
            while (!_toke.end())
            {
                _tok = _toke.increment();
                if (_tok.classification() == cls::whitespace)
                {
                    continue;
                }
                if (_tok.classification() == cls::punctuation && _tok.text() == ">")
                {
                    spc.includes().push_back(include);
                    return;
                }
                include += _tok.text();
            }
            _err = "parse_include() expected '>', but reached end of tokens";
        }
        else
        {
            _err = "parse_include() expected string or '<', but got unexpected token";
        }
    }

    auto parse_space(space & spc) -> void
    {
        parse_name();
        if (!_err.empty())
        {
            _err = "parse_space() " + _err;
            return;
        }
        spc.name() = _tok.text();
        parse_punctuation();
        if (!_err.empty())
        {
            _err = "parse_space() " + _err;
            return;
        }
        if (_tok.text() != "{")
        {
            _err = "parse_space() expected '{', but got punctuation";
            return;
        }
        for (;;)
        {
            parse_name_or_punctuation();
            if (!_err.empty())
            {
                _err = "parse_space() " + _err;
                return;
            }
            if (_tok.classification() == cls::punctuation)
            {
                if (_tok.text() != "}")
                {
                    _err = "parse_space() expected name or '}', but got punctuation";
                    return;
                }
                break;
            }
            auto abs = abstraction::_make();
            parse_abstraction(abs);
            if (!_err.empty())
            {
                return;
            }
            spc.abstractions().push_back(abs);
        }
    }

    void parse_abstraction(abstraction & abs)
    {
        if (_tok.text() == "template")
        {
            parse_abstraction_template(abs);
            if (!_err.empty())
            {
                return;
            }
            parse_name();
            if (!_err.empty())
            {
                _err = "parse_abstraction() " + _err;
                return;
            }
        }
        if (_tok.text() != "struct")
        {
            _err = "parse_abstraction() expected 'struct', but got name";
            return;
        }
        parse_name_or_punctuation();
        if (!_err.empty())
        {
            _err = "parse_abstraction() " + _err;
            return;
        }
        while (_tok.classification() == cls::punctuation)
        {
            if (_tok.text() != "[[")
            {
                break;
            }
            parse_abstraction_attribute(abs);
            if (!_err.empty())
            {
                return;
            }
            parse_name_or_punctuation();
            if (!_err.empty())
            {
                _err = "parse_abstraction() " + _err;
                return;
            }
        }
        abs.name() = _tok.text();
        parse_punctuation();
        if (!_err.empty())
        {
            _err = "parse_abstraction() " + _err;
            return;
        }
        if (_tok.text() == ":")
        {
            parse_abstraction_parents(abs);
            if (!_err.empty())
            {
                return;
            }
        }
        if (_tok.text() != "{")
        {
            _err = "parse_abstraction() expected '{', but got punctuation";
            return;
        }
        for (;;)
        {
            parse_name_or_punctuation();
            if (!_err.empty())
            {
                _err = "parse_abstraction() " + _err;
                return;
            }
            if (_tok.text() == "}")
            {
                break;
            }
            if (_tok.text() == "using")
            {
                auto type = parameter::_make();
                parse_abstraction_type(type);
                if (!_err.empty())
                {
                    return;
                }
                abs.types().push_back(type);
                continue;
            }
            auto oper = operation::_make();
            parse_operation(oper);
            if (!_err.empty())
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
        if (!_err.empty())
        {
            _err = "parse_abstraction() " + _err;
            return;
        }
        if (_tok.text() != ";")
        {
            _err = "parse_abstraction() expected ';', but got punctuation";
        }
    }

    void parse_abstraction_template(abstraction & abs)
    {
        parse_punctuation();
        if (!_err.empty())
        {
            _err = "parse_abstraction_template() " + _err;
            return;
        }
        if (_tok.text() != "<")
        {
            _err = "parse_abstraction_template() expected '<', but got punctuation";
            return;
        }
        for (;;)
        {
            parse_name();
            if (!_err.empty())
            {
                _err = "parse_abstraction_template() " + _err;
                return;
            }
            if (_tok.text() != "typename")
            {
                _err = "parse_abstraction_template() expected 'typename', but got name";
                return;
            }
            auto param = strange::parameter::_make();
            param.type() = _tok.text();
            parse_name_or_punctuation();
            if (!_err.empty())
            {
                _err = "parse_abstraction_template() " + _err;
                return;
            }
            if (_tok.text() == "...")
            {
                param.variadic() = true;
                parse_name();
            }
            else if (_tok.classification() != cls::name)
            {
                _err = "parse_abstraction_template() expected name or '...', but got punctuation";
                return;
            }
            param.name() = _tok.text();
            parse_punctuation();
            if (!_err.empty())
            {
                _err = "parse_abstraction_template() " + _err;
                return;
            }
            if (_tok.text() == ">")
            {
                abs.parameters().push_back(param);
                return;
            }
            if (_tok.text() == ",")
            {
                abs.parameters().push_back(param);
                continue;
            }
            if (_tok.text() != "=")
            {
                _err = "parse_abstraction_template() expected '=', ',' or '>', but got punctuation";
                return;
            }
            parse_argument(param.argument());
            if (!_err.empty())
            {
                _err = "parse_abstraction_template() " + _err;
                return;
            }
            abs.parameters().push_back(param);
            if (_tok.text() == ">")
            {
                return;
            }
            if (_tok.text() != ",")
            {
                _err = "parse_abstraction_template() expected ',' or '>', but got punctuation";
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
            if (!_err.empty())
            {
                _err = "parse_abstraction_parents() " + _err;
                return;
            }
            abs.parents().push_back(parent);
            if (_tok.text() == "{")
            {
                break;
            }
            if (_tok.text() != ",")
            {
                _err = "parse_abstraction_parents() expected ',' or '{', but got punctuation";
                return;
            }
        }
    }

    void parse_abstraction_attribute(abstraction & abs)
    {
        parse_name();
        if (!_err.empty())
        {
            _err = "parse_abstraction_attribute() " + _err;
            return;
        }
        if (_tok.text() != "strange")
        {
            _err = "parse_abstraction_attribute() expected 'strange', but got name";
            return;
        }
        parse_punctuation();
        if (!_err.empty())
        {
            _err = "parse_abstraction_attribute() " + _err;
            return;
        }
        if (_tok.text() != "::")
        {
            _err = "parse_abstraction_attribute() expected '::', but got punctuation";
            return;
        }
        parse_name();
        if (!_err.empty())
        {
            _err = "parse_abstraction_attribute() " + _err;
            return;
        }
        bool thing = (_tok.text() == "thing");
        bool implementation = (_tok.text() == "implementation");
        bool hash = (_tok.text() == "hash");
        if (!thing && !implementation && !hash)
        {
            _err = "parse_abstraction_attribute() expected 'thing', 'implementation' or 'hash', but got name";
            return;
        }
        if (hash)
        {
            abs.hash() = true;
            parse_punctuation();
            if (!_err.empty())
            {
                _err = "parse_abstraction_attribute() " + _err;
                return;
            }
            if (_tok.text() != "]]")
            {
                _err = "parse_abstraction_attribute() expected ']]', but got punctuation";
            }
            return;
        }
        parse_punctuation();
        if (!_err.empty())
        {
            _err = "parse_abstraction_attribute() " + _err;
            return;
        }
        if (_tok.text() != "(")
        {
            _err = "parse_abstraction_attribute() expected '(', but got punctuation";
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
        if (!_err.empty())
        {
            _err = "parse_abstraction_attribute() " + _err;
            return;
        }
        if (_tok.text() != ")")
        {
            _err = "parse_abstraction_attribute() expected ')', but got punctuation";
            return;
        }
        parse_punctuation();
        if (!_err.empty())
        {
            _err = "parse_abstraction_attribute() " + _err;
            return;
        }
        if (_tok.text() != "]]")
        {
            _err = "parse_abstraction_attribute() expected ']]', but got punctuation";
            return;
        }
    }

    void parse_abstraction_type(parameter & type)
    {
        type.type() = "using";
        parse_name();
        if (!_err.empty())
        {
            _err = "parse_abstraction_type() " + _err;
            return;
        }
        type.name() = _tok.text();
        parse_punctuation();
        if (!_err.empty())
        {
            _err = "parse_abstraction_type() " + _err;
            return;
        }
        if (_tok.text() != "=")
        {
            _err = "parse_abstraction_type() expected '=', but got punctuation";
            return;
        }
        parse_argument(type.argument());
        if (!_err.empty())
        {
            _err = "parse_abstraction_type() " + _err;
            return;
        }
        if (_tok.text() != ";")
        {
            _err = "parse_abstraction_type() expected ';', but got punctuation";
            return;
        }
    }

    void parse_operation(operation & oper)
    {
        while (_tok.classification() == cls::punctuation)
        {
            if (_tok.text() != "[[")
            {
                break;
            }
            parse_operation_attribute(oper);
            if (!_err.empty())
            {
                return;
            }
            parse_name_or_punctuation();
            if (!_err.empty())
            {
                _err = "parse_operation() " + _err;
                return;
            }
        }
        if (_tok.text() == "auto")
        {
            for (;;)
            {
                parse_name_or_punctuation(true);
                if (!_err.empty())
                {
                    _err = "parse_operation() " + _err;
                    return;
                }
                if (_tok.classification() == cls::whitespace)
                {
                    if (!oper.name().empty())
                    {
                        oper.name() += " ";
                    }
                    continue;
                }
                if (_tok.text() == "(" && oper.name() != "operator")
                {
                    rtrim(oper.name());
                    break;
                }
                oper.name() += _tok.text();
            }
            parse_operation_parameters(oper);
            if (!_err.empty())
            {
                return;
            }
            parse_name_or_punctuation();
            if (!_err.empty())
            {
                _err = "parse_operation() " + _err;
                return;
            }
            if (_tok.text() == "const")
            {
                oper.constness() = true;
                parse_name_or_punctuation();
                if (!_err.empty())
                {
                    _err = "parse_operation() " + _err;
                    return;
                }
            }
            if (_tok.text() != "->")
            {
                _err = "parse_operation() expected 'const' or '->', but got text";
                return;
            }
            bool ignore = !oper.result().empty();
            for (;;)
            {
                parse_name_or_punctuation(true);
                if (!_err.empty())
                {
                    _err = "parse_operation() " + _err;
                    return;
                }
                if (_tok.text() == "{" || _tok.text() == ";")
                {
                    rtrim(oper.result());
                    break;
                }
                if (ignore)
                {
                    continue;
                }
                if (_tok.classification() == cls::whitespace)
                {
                    if (!oper.result().empty())
                    {
                        oper.result() += " ";
                    }
                    continue;
                }
                oper.result() += _tok.text();
            }
        }
        else
        {
            oper.data() = true;
            oper.result() = _tok.text();
            for (;;)
            {
                parse_name_or_punctuation(true);
                if (!_err.empty())
                {
                    _err = "parse_operation() " + _err;
                    return;
                }
                if (_tok.text() == "{" || _tok.text() == ";")
                {
                    rtrim(oper.result());
                    if (oper.result().length() >= oper.name().length())
                    {
                        oper.result() = oper.result().substr(0, oper.result().length() - oper.name().length());
                    }
                    rtrim(oper.result());
                    break;
                }
                oper.result() += _tok.text();
                if (_tok.classification() == cls::name)
                {
                    oper.name() = _tok.text();
                }
            }
            if (oper.result().length() > 5 && oper.result().substr(oper.result().length() - 5) == "const")
            {
                oper.constness() = true;
            }
        }
        if (_tok.text() != ";")
        {
            oper.implementation() = _tok.text();
            parse_argument(oper.implementation());
            if (!_err.empty())
            {
                _err = "parse_operation() " + _err;
                return;
            }
            if (_tok.text() != ";")
            {
                _err = "parse_operation() expected ';', but got punctuation";
                return;
            }
        }
    }

    void parse_operation_attribute(operation & oper)
    {
        parse_name();
        if (!_err.empty())
        {
            _err = "parse_operation_attribute() " + _err;
            return;
        }
        if (_tok.text() != "strange")
        {
            _err = "parse_operation_attribute() expected 'strange', but got name";
            return;
        }
        parse_punctuation();
        if (!_err.empty())
        {
            _err = "parse_operation_attribute() " + _err;
            return;
        }
        if (_tok.text() != "::")
        {
            _err = "parse_operation_attribute() expected '::', but got punctuation";
            return;
        }
        parse_name();
        if (!_err.empty())
        {
            _err = "parse_operation_attribute() " + _err;
            return;
        }
        bool result = false;
        bool closure = false;
        bool modification = false;
        if (_tok.text() == "result")
        {
            result = true;
        }
        else if (_tok.text() == "closure")
        {
            closure = true;
        }
        else if (_tok.text() == "modification")
        {
            modification = true;
        }
        else if (_tok.text() != "customisation")
        {
            _err = "parse_operation_attribute() expected 'result', 'closure', 'modification' or 'customisation', but got name";
            return;
        }
        parse_punctuation();
        if (!_err.empty())
        {
            _err = "parse_operation_attribute() " + _err;
            return;
        }
        if (_tok.text() != "(")
        {
            _err = "parse_operation_attribute() expected '(', but got punctuation";
            return;
        }
        std::string text;
        parse_string(text);
        if (!_err.empty())
        {
            _err = "parse_operation_attribute() " + _err;
            return;
        }
        if (_tok.text() != ")")
        {
            _err = "parse_operation_attribute() expected ')', but got punctuation";
            return;
        }
        if (result)
        {
            oper.result() = text;
        }
        else if (closure)
        {
            oper.closure() = text;
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
        if (!_err.empty())
        {
            _err = "parse_operation_attribute() " + _err;
            return;
        }
        if (_tok.text() != "]]")
        {
            _err = "parse_operation_attribute() expected ']]', but got punctuation";
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
                if (!_err.empty())
                {
                    _err = "parse_operation_parameters() " + _err;
                    return;
                }
                if (_tok.text() == "<")
                {
                    ++angle;
                }
                else if (_tok.text() == ">")
                {
                    --angle;
                    if (angle < 0)
                    {
                        _err = "parse_operation_parameters() mismatched '>'";
                        return;
                    }
                }
                else if (angle == 0 && _tok.text() == "...")
                {
                    param.variadic() = true;
                    continue;
                }
                else if (angle == 0 && (_tok.text() == "=" || _tok.text() == "," || _tok.text() == ")"))
                {
                    rtrim(param.type());
                    if (param.type().length() >= param.name().length())
                    {
                        param.type() = param.type().substr(0, param.type().length() - param.name().length());
                    }
                    rtrim(param.type());
                    break;
                }
                if (param.type().empty())
                {
                    param.type() = _tok.text();
                    rtrim(param.type());
                }
                else
                {
                    param.type() += _tok.text();
                }
                if (_tok.classification() == cls::name)
                {
                    param.name() = _tok.text();
                }
            }
            if (param.name().empty())
            {
                if (_tok.text() != ")")
                {
                    _err = "parse_operation_parameters() expected ')', but got punctuation";
                }
                return;
            }
            if (_tok.text() == ")")
            {
                oper.parameters().push_back(param);
                return;
            }
            if (_tok.text() == ",")
            {
                oper.parameters().push_back(param);
                continue;
            }
            if (_tok.text() != "=")
            {
                _err = "parse_operation_parameters() expected '=', ',' or ')', but got punctuation";
                return;
            }
            parse_argument(param.argument());
            if (!_err.empty())
            {
                _err = "parse_operation_parameters() " + _err;
                return;
            }
            oper.parameters().push_back(param);
            if (_tok.text() == ")")
            {
                return;
            }
            if (_tok.text() != ",")
            {
                _err = "parse_operation_parameters() expected ',' or ')', but got punctuation";
                return;
            }
        }
    }

    void parse_name()
    {
        while (!_toke.end())
        {
            _tok = _toke.increment();
            switch (_tok.classification())
            {
                case cls::character:
                    _err = "parse_name() got character";
                    return;
                case cls::comment:
                    break;
                case cls::mistake:
                    _err = "parse_name() got mistake";
                    return;
                case cls::name:
                    return;
                case cls::number:
                    _err = "parse_name() got number";
                    return;
                case cls::punctuation:
                    _err = "parse_name() got punctuation";
                    return;
                case cls::string:
                    _err = "parse_name() got string";
                    return;
                case cls::whitespace:
                    break;
                default:
                    _err = "parse_name() unexpected classification";
                    return;
            }
        }
        _err = "parse_name() reached end of tokens";
    }

    void parse_punctuation()
    {
        while (!_toke.end())
        {
            _tok = _toke.increment();
            switch (_tok.classification())
            {
                case cls::character:
                    _err = "parse_punctuation() got character";
                    return;
                case cls::comment:
                    break;
                case cls::mistake:
                    _err = "parse_punctuation() got mistake";
                    return;
                case cls::name:
                    _err = "parse_punctuation() got name";
                    return;
                case cls::number:
                    _err = "parse_punctuation() got number";
                    return;
                case cls::punctuation:
                    return;
                case cls::string:
                    _err = "parse_punctuation() got string";
                    return;
                case cls::whitespace:
                    break;
                default:
                    _err = "parse_punctuation() unexpected classification";
                    return;
            }
        }
        _err = "parse_punctuation() reached end of tokens";
    }

    void parse_string(std::string & text, bool single = false)
    {
        while (!_toke.end())
        {
            _tok = _toke.increment();
            switch (_tok.classification())
            {
                case cls::character:
                    _err = "parse_string() got character";
                    return;
                case cls::comment:
                    break;
                case cls::mistake:
                    _err = "parse_string() got mistake";
                    return;
                case cls::name:
                    _err = "parse_string() got name";
                    return;
                case cls::number:
                    _err = "parse_string() got number";
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
                    text += _tok.text();
                    if (single)
                    {
                        return;
                    }
                    break;
                case cls::whitespace:
                    break;
                default:
                    _err = "parse_string() unexpected classification";
                    return;
            }
        }
        _err = "parse_string() reached end of tokens";
    }

    void parse_name_or_punctuation(bool whitespace = false)
    {
        while (!_toke.end())
        {
            _tok = _toke.increment();
            switch (_tok.classification())
            {
                case cls::character:
                    _err = "parse_name_or_punctuation() got character";
                    return;
                case cls::comment:
                    break;
                case cls::mistake:
                    _err = "parse_name_or_punctuation() got mistake";
                    return;
                case cls::name:
                    return;
                case cls::number:
                    _err = "parse_name_or_punctuation() got number";
                    return;
                case cls::punctuation:
                    return;
                case cls::string:
                    _err = "parse_name_or_punctuation() got string";
                    return;
                case cls::whitespace:
                    if (whitespace)
                    {
                        return;
                    }
                    break;
                default:
                    _err = "parse_name_or_punctuation() unexpected classification";
                    return;
            }
        }
        _err = "parse_name_or_punctuation() reached end of tokens";
    }

    void parse_argument(std::string & arg, bool parent = false)
    {
        int64_t angle = arg == "<" ? 1 : 0;
        int64_t curly = arg == "{" ? 1 : 0;
        int64_t round = arg == "(" ? 1 : 0;
        int64_t square = arg == "[" ? 1 : 0;
        while (!_toke.end())
        {
            _tok = _toke.increment();
            switch (_tok.classification())
            {
                case cls::character:
                    arg += "'" + _tok.text() + "'";
                    break;
                case cls::comment:
                    break;
                case cls::mistake:
                    _err = "parse_argument() got mistake";
                    return;
                case cls::name:
                    arg += _tok.text();
                    break;
                case cls::number:
                    arg += _tok.text();
                    break;
                case cls::punctuation:
                    if (_tok.text() == "<")
                    {
                        ++angle;
                    }
                    else if (_tok.text() == ">")
                    {
                        --angle;
                    }
                    else if (_tok.text() == "{")
                    {
                        if (parent && angle == 0 && curly == 0 && round == 0 && square == 0)
                        {
                            rtrim(arg);
                            return;
                        }
                        ++curly;
                    }
                    else if (_tok.text() == "}")
                    {
                        --curly;
                    }
                    else if (_tok.text() == "(")
                    {
                        ++round;
                    }
                    else if (_tok.text() == ")")
                    {
                        --round;
                    }
                    else if (_tok.text() == "[")
                    {
                        ++square;
                    }
                    else if (_tok.text() == "]")
                    {
                        --square;
                    }
                    if (angle < 0 || curly < 0 || round < 0 || square < 0)
                    {
                        if (angle > 0)
                        {
                            _err = "parse_argument() mismatched '<'";
                        }
                        else if (curly > 0)
                        {
                            _err = "parse_argument() mismatched '{'";
                        }
                        else if (round > 0)
                        {
                            _err = "parse_argument() mismatched '('";
                        }
                        else if (square > 0)
                        {
                            _err = "parse_argument() mismatched '['";
                        }
                        else
                        {
                            rtrim(arg);
                        }
                        return;
                    }
                    if (angle == 0 && curly == 0 && round == 0 && square == 0 &&
                        (_tok.text() == "," || _tok.text() == ";"))
                    {
                        rtrim(arg);
                        return;
                    }
                    arg += _tok.text();
                    break;
                case cls::string:
                    arg += "\"" + _tok.text() + "\"";
                    break;
                case cls::whitespace:
                    if (!arg.empty())
                    {
                        arg += " ";
                    }
                    break;
                default:
                    _err = "parse_argument() unexpected classification";
                    return;
            }
        }
        _err = "parse_argument() reached end of tokens";
    }
};
}
}
