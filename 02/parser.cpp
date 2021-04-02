#include "parser.hpp"

TokenParser::TokenParser()
{
    start_cb = []() {};
    end_cb = []() {};
    digit_cb = [](const std::string &token) {};
    string_cb = [](const std::string &token) {};
}

void TokenParser::SetStartCallback(BoundCallback start)
{
    start_cb = start;
}

void TokenParser::SetEndCallback(BoundCallback end)
{
    end_cb = end;
}

void TokenParser::SetDigitTokenCallback(TokenCallback digit)
{
    digit_cb = digit;
}

void TokenParser::SetStringTokenCallback(TokenCallback str)
{
    string_cb = str;
}

void TokenParser::Parse(const std::string &str)
{
    start_cb();
    std::string token;
    auto iterator = str.begin();
    char c;
    bool digit_flag = true;
    while (iterator != str.end())
    {
        c = *iterator;
        if (!isspace(c))
        {
            token.push_back(c);
            digit_flag = !isdigit(c) ? false : digit_flag;
        }
        else if (token.size() != 0)
        {

            digit_flag ? digit_cb(token) : string_cb(token);
            digit_flag = true;
            token.clear();
        }
        iterator++;
    }
    if (token.size() != 0)
    {
        digit_flag ? digit_cb(token) : string_cb(token);
        digit_flag = true;
        token.clear();
    }
    end_cb();
}