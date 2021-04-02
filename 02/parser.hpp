
#ifndef HEADER
#define HEADER

#include <iostream>
#include <string>
#include <functional>
#include <cassert>

using TokenCallback = std::function<void(const std::string &token)>;
using BoundCallback = std::function<void()>;

class TokenParser
{
private:
    BoundCallback start_cb;
    BoundCallback end_cb;
    TokenCallback digit_cb;
    TokenCallback string_cb;

public:
    TokenParser();
    void SetStartCallback(BoundCallback start);
    void SetEndCallback(BoundCallback end);
    void SetDigitTokenCallback(TokenCallback digit);
    void SetStringTokenCallback(TokenCallback str);
    void Parse(const std::string &str);
};

#endif