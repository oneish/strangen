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
    std::istreambuf_iterator<char> it;
    bool end;
    std::string filename;
    int64_t start_line;
    int64_t start_position;
    int64_t line;
    int64_t position;
    bool dot;
    char use;

    toker(std::istreambuf_iterator<char> sit, std::string const & fname = std::string{})
    :it{sit}
    ,end{it == std::istreambuf_iterator<char>{}}
    ,filename{fname}
    ,start_line{1}
    ,start_position{0}
    ,line{1}
    ,position{0}
    ,dot{false}
    ,use{'\0'}
    {
    }

    inline static auto alpha_char(char c) -> bool
    {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_';
	}

    inline static auto numeric_char(char c) -> bool
    {
        return c >= '0' && c <= '9';
    }

    inline auto make_token(cls classification, std::string text) const -> strange::token
    {
        return strange::token::_make(strange::implementation::token{.filename_ = filename, .line_ = start_line, .position_ = start_position, .classification_ = classification, .text_ = text});
    }

    inline auto increment() -> strange::token
    {
        if (!end)
        {
            if ((!dot) && (!use) && (it == std::istreambuf_iterator<char>{}))
            {
                end = true;
                return make_token(cls::comment, "");
            }
            else
            {
                auto token = next();
                if ((!dot) && (!use) && (it == std::istreambuf_iterator<char>{}))
                {
                    end = true;
                }
                return token;
            }
        }
        return make_token(cls::mistake, "beyond end of stream");
    }

    inline auto next() -> strange::token
    {
        start_line = line;
        start_position = position;
        if ((!dot) && !use)
        {
            ++start_position;
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
            if (dot)
            {
                char1 = '.';
                dot = false;
            }
            else if (use)
            {
                char1 = use;
                use = '\0';
            }
            else if (it == std::istreambuf_iterator<char>{})
            {
                break;
            }
            else
            {
                char1 = *it;
                ++it;
                ++position;
            }
            char2 = (it != std::istreambuf_iterator<char>{}) ? (*it) : '\0';

            if (char1 == '\n')
            {
                position = 0;
                ++line;
            }
            else if (char1 == '\t')
            {
                position = ((position + 3) / 4) * 4;
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
                                dot = true;
                                return make_token(cls::number, text.substr(0, text.size() - 1));
                            }
                            if (exp1)
                            {
                                use = char1;
                                if (point)
                                {
                                    if (text[text.size() - 2] == '.')
                                    {
                                        // int
                                        dot = true;
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

auto operator<<(std::ostream & str, cls classification) -> std::ostream &
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
    };
    return str;
}

auto operator<<(std::ostream & str, token const & tok) -> std::ostream &
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
