#include "header.hpp"
#define testsCount 7

size_t tests(size_t num)
{
    Allocator A;
    A.makeAllocator(500);
    char *ptr, *ptr_1, *ptr_2;

    switch (num)
    {
    case 0:
        std::cout << "default usage" << std::endl;
        ptr = A.alloc(500);
        if (ptr == nullptr)
        {
            std::cout << "Cannot allocate memory!" << std::endl;
            return -1;
        }
        return 0;

    case 1:
        std::cout << "default sequential allocation" << std::endl;
        ptr_1 = A.alloc(250);
        ptr_2 = A.alloc(250);
        if (ptr_1 == nullptr or ptr_2 == nullptr)
        {
            std::cout << "Cannot allocate memory!" << std::endl;
            return -1;
        }
        if (ptr_2 != ptr_1 + 250)
        {
            std::cout << "Incorrect difference!" << std::endl;
            return -1;
        }
        return 0;

    case 2:
        std::cout << "default reallocation" << std::endl;
        ptr_1 = A.alloc(500);
        A.reset();
        ptr_2 = A.alloc(500);
        if (ptr_1 == nullptr or ptr_2 == nullptr)
        {
            std::cout << "Cannot allocate memory!" << std::endl;
            return -1;
        }
        if (ptr_1 != ptr_2)
        {
            std::cout << "Different pointers!" << std::endl;
            return -1;
        }
        return 0;

    case 3:
        std::cout << "overfull allocation" << std::endl;
        ptr = A.alloc(600);
        if (ptr != nullptr)
        {
            std::cout << "Incorrect behavior!" << std::endl;
            return -1;
        }
        return 0;

    case 4:
        std::cout << "overfull sequential allocation" << std::endl;
        ptr_1 = A.alloc(300);
        ptr_2 = A.alloc(300);
        if (ptr_2 != nullptr)
        {
            std::cout << "Incorrect behavior!" << std::endl;
            return -1;
        }
        return 0;

    case 5:
        std::cout << "overfull reallocation" << std::endl;
        ptr_1 = A.alloc(500);
        A.reset();
        ptr_2 = A.alloc(600);
        if (ptr_2 != nullptr)
        {
            std::cout << "Incorrect behavior!" << std::endl;
            return -1;
        }
        return 0;

    case 6:
        std::cout << "makeAllocator recall" << std::endl;
        A.makeAllocator(600);
        ptr = A.alloc(600);
        if (ptr == nullptr)
        {
            std::cout << "Cannot allocate memory!" << std::endl;
            return -1;
        }
        return 0;

    default:
        return 0;
    }
}

int main()
{
    for (int i = 0; i < testsCount; i++)
    {
        std::cout << "Starting the test number " << i + 1 << ": ";
        if (!tests(i))
            std::cout << "PASSED" << std::endl;
        else
            std::cout << "NOT PASSED" << std::endl;
        std::cout << "\n";
    }
    return 0;
}