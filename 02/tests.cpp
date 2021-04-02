#include "parser.hpp"
void StartEndCallbacksTest()
{
    TokenParser P;
    bool start = false;
    bool end = false;
    std::string str = "some simple text";
    P.SetStartCallback([&start]() { start = true; });
    P.SetEndCallback([&end]() { end = true; });
    P.Parse(str);
    assert(start & end);
}

void CountersCallbacksTest()
{
    TokenParser P;
    int strings_counter = 0;
    int digits_counter = 0;
    std::string str = "string 1 other 2 123notadigit321";
    P.SetStringTokenCallback([&strings_counter](const std::string &token) { strings_counter++; });
    P.SetDigitTokenCallback([&digits_counter](const std::string &token) { digits_counter++; });
    P.Parse(str);
    assert((strings_counter == 3) & (digits_counter == 2));
}

void SingleSizeCallbacksTest()
{
    TokenParser P;
    int strings_counter = 0;
    int digits_counter = 0;
    std::string str = "a b c 1 2 3 d e f";
    P.SetStringTokenCallback([&strings_counter](const std::string &token) { strings_counter++; });
    P.SetDigitTokenCallback([&digits_counter](const std::string &token) { digits_counter++; });
    P.Parse(str);
    assert((strings_counter == 6) & (digits_counter == 3));
}

void LengthCallbacksTest()
{
    TokenParser P;
    int strings_length = 0;
    int digits_length = 0;
    std::string str = "one two three 1 12 123";
    P.SetStringTokenCallback([&strings_length](const std::string &token) { strings_length += token.size(); });
    P.SetDigitTokenCallback([&digits_length](const std::string &token) { digits_length += token.size(); });
    P.Parse(str);
    assert((strings_length == 11) & (digits_length == 6));
}

int main()
{
    StartEndCallbacksTest();
    CountersCallbacksTest();
    LengthCallbacksTest();
    SingleSizeCallbacksTest();
    std::cout << "Success!" << std::endl;
    return 0;
}