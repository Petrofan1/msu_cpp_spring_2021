#ifndef HEADER
#define HEADER

#include <iostream>

class Allocator
{
private:
    char *ptr;
    size_t curSize;
    size_t offset;

public:
    Allocator();
    void makeAllocator(size_t maxSize);
    char *alloc(size_t size);
    void reset();
    ~Allocator();
};

#endif