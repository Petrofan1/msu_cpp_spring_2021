#ifndef HEADER
#define HEADER

#include <iostream>
#include <sstream>
#include <cassert>
#include <string>

enum class Error
{
    NoError,
    CorruptedArchive
};

class Serializer
{
    static constexpr char Separator = ' ';
    std::ostream &out_;

public:
    explicit Serializer(std::ostream &out) : out_(out)
    {
    }

    template <class T>
    Error save(T &object)
    {
        return object.serialize(*this);
    }

    template <class... ArgsT>
    Error operator()(ArgsT &...args)
    {
        return process(args...);
    }

    template <class T, class... ArgsT>
    Error process(T &x, ArgsT &...args)
    {
        if (process(x) == Error::CorruptedArchive)
        {
            return Error::CorruptedArchive;
        }
        return process(args...);
    }
    Error process(bool arg);
    Error process(uint64_t arg);
};

class Deserializer
{
    static constexpr char Separator = ' ';
    std::istream &in_;

public:
    explicit Deserializer(std::istream &in) : in_(in)
    {
    }

    template <class T>
    Error load(T &object)
    {
        return object.deserialize(*this);
    }

    template <class... ArgsT>
    Error operator()(ArgsT &...args)
    {
        return process(args...);
    }

    template <class T, class... ArgsT>
    Error process(T &x, ArgsT &...args)
    {
        if (process(x) == Error::CorruptedArchive)
        {
            return Error::CorruptedArchive;
        }
        return process(args...);
    }

    Error process(bool &arg);
    Error process(uint64_t &arg);
};

struct Data
{
    uint64_t a;
    bool b;
    uint64_t c;

    template <class Serializer>
    Error serialize(Serializer &serializer)
    {
        return serializer(a, b, c);
    }

    template <class Deserializer>
    Error deserialize(Deserializer &deserializer)
    {
        return deserializer(a, b, c);
    }
};

#endif