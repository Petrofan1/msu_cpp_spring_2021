#include "header.hpp"

Allocator::Allocator()
{
    ptr = nullptr;
    curSize = 0;
    offset = 0;
}

void Allocator::makeAllocator(size_t maxSize)
{
    if (curSize)
        delete[] ptr;
    curSize = maxSize;
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
    if (curSize)
        delete[] ptr;
}
