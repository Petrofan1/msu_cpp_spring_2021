#include "allocator.hpp"

Allocator::Allocator()
{
    ptr = nullptr;
    curSize = 0;
    offset = 0;
}

void Allocator::makeAllocator(size_t maxSize)
{
    if (ptr != nullptr)
        delete[] ptr;
    curSize = maxSize;
    offset = 0;
    ptr = new char[curSize];
}

char *Allocator::alloc(size_t size)
{
    if (offset + size > curSize)
        return nullptr;
    offset += size;
    return ptr + offset - size;
}

void Allocator::reset()
{
    offset = 0;
}

Allocator::~Allocator()
{
    if (ptr != nullptr)
        delete[] ptr;
}
