#include "allocator.hpp"

void DefaultUsageTest()
{
    Allocator A;
    A.makeAllocator(500);
    char *ptr;
    ptr = A.alloc(500);
    assert(ptr != nullptr);
}
void DefaultSeqAllocTest()
{
    Allocator A;
    A.makeAllocator(500);
    char *ptr_1, *ptr_2;
    ptr_1 = A.alloc(250);
    ptr_2 = A.alloc(250);
    assert(ptr_1 != nullptr and ptr_2 != nullptr);
    assert(ptr_2 == ptr_1 + 250);
}
void DefaultReallocTest()
{
    Allocator A;
    A.makeAllocator(500);
    char *ptr_1, *ptr_2;
    ptr_1 = A.alloc(500);
    A.reset();
    ptr_2 = A.alloc(500);
    assert(ptr_1 != nullptr and ptr_2 != nullptr);
    assert(ptr_1 == ptr_2);
}
void OverfullAllocTest()
{
    Allocator A;
    A.makeAllocator(500);
    char *ptr;
    ptr = A.alloc(600);
    assert(ptr == nullptr);
}
void OverfullSeqAllocTest()
{
    Allocator A;
    A.makeAllocator(500);
    char *ptr_1, *ptr_2;
    ptr_1 = A.alloc(300);
    assert(ptr_1 != nullptr);
    ptr_2 = A.alloc(300);
    assert(ptr_2 == nullptr);
}
void OverfullReallocTest()
{
    Allocator A;
    A.makeAllocator(500);
    char *ptr_1, *ptr_2;
    ptr_1 = A.alloc(500);
    assert(ptr_1 != nullptr);
    A.reset();
    ptr_2 = A.alloc(600);
    assert(ptr_2 == nullptr);
}
void MakeAllocatorRecallTest()
{
    Allocator A;
    char *ptr;
    A.makeAllocator(10);
    ptr = A.alloc(5);
    A.makeAllocator(20);
    ptr = A.alloc(16);
    assert(ptr != nullptr);
}

int main()
{
    DefaultUsageTest();
    DefaultSeqAllocTest();
    DefaultReallocTest();
    OverfullAllocTest();
    OverfullSeqAllocTest();
    OverfullReallocTest();
    MakeAllocatorRecallTest();
    std::cout << "Success!" << std::endl;
    return 0;
}