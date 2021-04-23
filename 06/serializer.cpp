#include "serializer.hpp"

Error Serializer::process(bool arg)
{
    if (arg == true)
    {
        out_ << "true" << Separator;
    }
    else if (arg == false)
    {
        out_ << "false" << Separator;
    }
    else
    {
        return Error::CorruptedArchive;
    }
    return Error::NoError;
}

Error Serializer::process(uint64_t arg)
{
    out_ << arg << Separator;
    return Error::NoError;
}

Error Deserializer::process(bool &value)
{
    std::string text;
    in_ >> text;
    if (text == "true")
    {
        value = true;
    }
    else if (text == "false")
    {
        value = false;
    }
    else
    {
        return Error::CorruptedArchive;
    }
    return Error::NoError;
}

Error Deserializer::process(uint64_t &value)
{
    std::string text;
    in_ >> text;
    try
    {
        value = stoull(text);
    }
    catch (const std::logic_error &)
    {
        return Error::CorruptedArchive;
    }
    return Error::NoError;
}