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
    mistake,
};

struct token
{
    std::string filename;
    int64_t line;
    int64_t position;
    cls classification;
    std::string text;
};

struct tokenization
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

    tokenization(std::istreambuf_iterator<char> sit)
    :it{sit}
    ,end{it == std::istreambuf_iterator<char>{}}
    ,filename{}
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

    inline auto make_token(cls classification, std::string text) const -> token
    {
        return {.filename = filename, .line = start_line, .position = start_position, .classification = classification, .text = text};
    }

    inline auto increment() -> token
    {
        if (!end)
        {
            if ((!dot) && (!use) && (it == std::istreambuf_iterator<char>{}))
            {
                end = true;
            }
            else
            {
                auto token = next();
                if ((!dot) && (!use) && (it == std::istreambuf_iterator<char>{}) &&
                    (token.classification == cls::punctuation) && token.text.empty())
                {
                    end = true;
                }
                return token;
            }
        }
        return make_token(cls::mistake, "end of stream");
    }

    inline auto next() -> token
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
            //TODO ...
        }
        if (commentline || text.empty())
        {
            return make_token(cls::punctuation, "");
        }
        return make_token(cls::mistake, "end of next()");
    }
};
}
}
