// A character-level tokenizer for the strange prototype DSL. Reads characters
// from an istreambuf_iterator and produces strange::token objects classified as:
// name, number, character, string, comment, punctuation, whitespace, or mistake.
// Handles escape sequences in strings, multi-character operators (::, ->, ==,
// <=, ++, ...), block/line comments, and scientific notation in numbers.

#pragma once
#include <string>
#include <cstdint>
#include <istream>
#include <iterator>

namespace strange
{
namespace comprehension
{
enum class cls
{
    name,
    number,
    character,
    string,
    comment,
    punctuation,
    whitespace,
    mistake,
};

struct toker
{
    inline auto filename() const -> std::string const & { return _filename; }
    inline auto end() const -> bool { return _end; }

    toker(std::istreambuf_iterator<char> sit, std::string const & fname = std::string{})
    :_filename{fname}
    ,_end{sit == std::istreambuf_iterator<char>{}}
    ,_it{sit}
    ,_start_line{1}
    ,_start_position{0}
    ,_line{1}
    ,_position{0}
    ,_dot{false}
    ,_use{'\0'}
    {
    }

    inline auto increment() -> strange::token
    {
        if (!_end)
        {
            if ((!_dot) && (!_use) && (_it == std::istreambuf_iterator<char>{}))
            {
                _end = true;
                return make_token(cls::comment, "");
            }
            else
            {
                auto token = next();
                if ((!_dot) && (!_use) && (_it == std::istreambuf_iterator<char>{}))
                {
                    _end = true;
                }
                return token;
            }
        }
        return make_token(cls::mistake, "beyond end of stream");
    }

private:
    std::string _filename;
    bool _end;
    std::istreambuf_iterator<char> _it;
    int64_t _start_line;
    int64_t _start_position;
    int64_t _line;
    int64_t _position;
    bool _dot;
    char _use;

    static inline auto alpha_char(char c) -> bool
    {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_';
    }

    static inline auto numeric_char(char c) -> bool
    {
        return c >= '0' && c <= '9';
    }

    inline auto make_token(cls classification, std::string text) const -> strange::token
    {
        return strange::token::_make(strange::implementation::token{.filename_ = _filename, .line_ = _start_line, .position_ = _start_position, .classification_ = classification, .text_ = text});
    }

    inline auto next() -> strange::token
    {
        _start_line = _line;
        _start_position = _position;
        if ((!_dot) && !_use)
        {
            ++_start_position;
        }
        bool alphanumeric = false;
        bool numeric = false;
        bool point = false;
        bool exponent = false;
        bool second = false;
        bool singlequote = false;
        bool doublequote = false;
        bool escape = false;
        bool commentblock = false;
        bool commentline = false;
        std::string text;

        for (bool first = true;;)
        {
            char char1;
            char char2;
            if (_dot)
            {
                char1 = '.';
                _dot = false;
            }
            else if (_use)
            {
                char1 = _use;
                _use = '\0';
            }
            else if (_it == std::istreambuf_iterator<char>{})
            {
                break;
            }
            else
            {
                char1 = *_it;
                ++_it;
                ++_position;
            }
            char2 = (_it != std::istreambuf_iterator<char>{}) ? (*_it) : '\0';

            if (char1 == '\n')
            {
                _position = 0;
                ++_line;
            }
            else if (char1 == '\t')
            {
                // round to next 4-space tab stop
                _position = ((_position + 3) / 4) * 4;
            }

            if (commentblock)
            {
                if (second)
                {
                    return make_token(cls::comment, text + char1);
                }
                second = ((char1 == '*') && (char2 == '/'));
                text += char1;
                continue;
            }
            else if (commentline)
            {
                if (char1 == '\n')
                {
                    return make_token(cls::comment, text);
                }
                text += char1;
                continue;
            }
            else if (escape)
            {
                switch (char1)
                {
                case 'a':
                    text += '\a';
                    break;
                case 'b':
                    text += '\b';
                    break;
                case 'f':
                    text += '\f';
                    break;
                case 'n':
                    text += '\n';
                    break;
                case 'r':
                    text += '\r';
                    break;
                case 't':
                    text += '\t';
                    break;
                case 'v':
                    text += '\v';
                    break;
                default:
                    text += char1;
                }
                escape = false;
            }
            else if (second)
            {
                if (char1 == '.' && char1 == char2 && text.length() == 1)
                {
                    text += char1;
                    continue;
                }
                return make_token(cls::punctuation, text + char1);
            }
            else if (singlequote && char1 == '\'')
            {
                return make_token(cls::character, text);
            }
            else if (doublequote && char1 == '\"')
            {
                return make_token(cls::string, text);
            }
            else if (singlequote || doublequote)
            {
                if (char1 == '\\')
                {
                    escape = true;
                }
                else
                {
                    text += char1;
                }
            }
            else
            {
                bool const num2 = numeric_char(char2);
                if (first)
                {
                    if (((char1 == '-') && num2) || numeric_char(char1))
                    {
                        numeric = true;
                    }
                    else if (alpha_char(char1))
                    {
                        alphanumeric = true;
                    }
                }
                if (numeric)
                {
                    text += char1;
                    bool const exp1 = ((char1 == 'E') || (char1 == 'e'));
                    bool const exp2 = ((char2 == 'E') || (char2 == 'e'));
                    bool const pnt1 = (char1 == '.');
                    bool const pnt2 = (char2 == '.');
                    bool sig2 = ((char2 == '+') || (char2 == '-'));
                    if (exp1)
                    {
                        exponent = true;
                        point = true;
                    }
                    else if (pnt1)
                    {
                        point = true;
                    }
                    if ((!num2) &&
                        ((!pnt2) || (pnt2 && point)) &&
                        ((!exp2) || (exp2 && exponent)) &&
                        ((!sig2) || (sig2 && !exp1)))
                    {
                        // end of numeric token
                        if (point || exponent)
                        {
                            if (pnt1)
                            {
                                _dot = true;
                                return make_token(cls::number, text.substr(0, text.size() - 1));
                            }
                            if (exp1)
                            {
                                _use = char1;
                                if (point)
                                {
                                    if (text.size() >= 2 && text[text.size() - 2] == '.')
                                    {
                                        // int
                                        _dot = true;
                                        return make_token(cls::number, text.substr(0, text.size() - 2));
                                    }
                                    // float
                                    return make_token(cls::number, text.substr(0, text.size() - 1));
                                }
                                // int
                                return make_token(cls::number, text.substr(0, text.size() - 1));
                            }
                            // float
                            return make_token(cls::number, text);
                        }
                        // int
                        return make_token(cls::number, text);
                    }
                }
                else if (alphanumeric)
                {
                    text += char1;
                    if ((!num2) && !alpha_char(char2))
                    {
                        // end of alphanumeric token
                        return make_token(cls::name, text);
                    }
                }
                else if ((char1 == ' ') || (char1 == '\n') || (char1 == '\t') || (char1 == '\r'))
                {
                    // whitespace
                    text += char1;
                    if ((char2 != ' ') && (char2 != '\n') && (char2 != '\t') && (char2 != '\r'))
                    {
                        // end of whitespace
                        return make_token(cls::whitespace, text);
                    }
                    continue;
                }
                else switch (char1)
                {
                case '\'':
                    singlequote = true;
                    break;
                case '\"':
                    doublequote = true;
                    break;
                case '+':
                case '-':
                    text = char1;
                    if ((char1 == char2) || (char2 == '=') || (char1 == '-' && char2 == '>'))
                    {
                        second = true;
                        break;
                    }
                    return make_token(cls::punctuation, text);
                case '*':
                case '%':
                case '!':
                    text = char1;
                    if (char2 == '=')
                    {
                        second = true;
                        break;
                    }
                    return make_token(cls::punctuation, text);
                case '<':
                    text = char1;
                    if (char2 == '=')
                    {
                        second = true;
                        break;
                    }
                    return make_token(cls::punctuation, text);
                case '>':
                    text = char1;
                    if (char2 == '=')
                    {
                        second = true;
                        break;
                    }
                    return make_token(cls::punctuation, text);
                case ':':
                case '.':
                case '&':
                case '|':
                case '=':
                case '[':
                case ']':
                    text = char1;
                    if (char1 == char2)
                    {
                        second = true;
                        break;
                    }
                    return make_token(cls::punctuation, text);
                case '/':
                    text = char1;
                    if (char2 == '=')
                    {
                        second = true;
                        break;
                    }
                    if (char2 == '*')
                    {
                        commentblock = true;
                        break;
                    }
                    if (char2 == '/')
                    {
                        commentline = true;
                        break;
                    }
                    return make_token(cls::punctuation, text);
                default:
                    // single character punctuation
                    return make_token(cls::punctuation, std::string(&char1, 1));
                }
            }
            if ((!commentblock) && !commentline)
            {
                first = false;
            }
        }
        if (commentline || text.empty())
        {
            return make_token(cls::comment, text);
        }
        return make_token(cls::mistake, text);
    }
};

inline auto operator<<(std::ostream & str, cls classification) -> std::ostream &
{
    switch (classification)
    {
        case strange::comprehension::cls::name:
            str << "name";
            break;
        case strange::comprehension::cls::number:
            str << "number";
            break;
        case strange::comprehension::cls::character:
            str << "character";
            break;
        case strange::comprehension::cls::string:
            str << "string";
            break;
        case strange::comprehension::cls::comment:
            str << "comment";
            break;
        case strange::comprehension::cls::punctuation:
            str << "punctuation";
            break;
        case strange::comprehension::cls::whitespace:
            str << "whitespace";
            break;
        case strange::comprehension::cls::mistake:
            str << "mistake";
            break;
        default:
            str << "unknown";
            break;
    }
    return str;
}

inline auto operator<<(std::ostream & str, token const & tok) -> std::ostream &
{
    str << "file: " << tok.filename()
        << " line: " << tok.line()
        << " pos: " << tok.position()
        << " cls: " << tok.classification()
        << " text: " << tok.text();
    return str;
}

}
}
