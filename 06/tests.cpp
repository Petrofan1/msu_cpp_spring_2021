#include "serializer.hpp"
#include <limits.h>

void SimpleTest()
{
    Data x{1, true, 2};

    std::stringstream stream;

    Serializer serializer(stream);
    serializer.save(x);

    Data y{0, false, 0};

    Deserializer deserializer(stream);
    const Error err = deserializer.load(y);

    assert(err == Error::NoError);

    assert(x.a == y.a);
    assert(x.b == y.b);
    assert(x.c == y.c);
}

void ErrorIntTest()
{
    std::stringstream stream;

    Data y{0, false, 0};

    stream << "text true 1";

    Deserializer deserializer(stream);
    const Error err = deserializer.load(y);

    assert(err == Error::CorruptedArchive);
}

void ErrorBoolTest()
{
    std::stringstream stream;

    Data y{0, false, 0};

    stream << "1 text 1";

    Deserializer deserializer(stream);
    const Error err = deserializer.load(y);

    assert(err == Error::CorruptedArchive);
}

void LongIntTest()
{
    Data x{ULLONG_MAX, true, 1};
    std::stringstream stream;

    Serializer serializer(stream);
    const Error err_1 = serializer.save(x);

    assert(err_1 == Error::NoError);

    Data y{0, false, 0};

    Deserializer deserializer(stream);
    const Error err_2 = deserializer.load(y);

    assert(err_2 == Error::NoError);

    assert(x.a == y.a);
    assert(x.b == y.b);
    assert(x.c == y.c);
}

int main()
{
    SimpleTest();
    ErrorBoolTest();
    ErrorIntTest();
    LongIntTest();

    std::cout << "Success!" << std::endl;
    return 0;
}