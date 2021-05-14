#include "threadpool.hpp"

size_t product(size_t x, size_t y)
{
    return x * y;
}

size_t sum(size_t x, size_t y)
{
    return x + y;
}

void DefaultTest()
{
    ThreadPool pool(8);
    auto task = pool.exec([]() { return 1; });
    assert(task.get() == 1);
    return;
}

void SimpleFunctionsTest()
{
    ThreadPool pool(8);
    size_t pool_size = 8;
    for (size_t i = 0; i < pool_size; i++)
    {
        auto task = pool.exec(product, i, i);
        assert(task.get() == i * i);
    }
    for (size_t i = 0; i < pool_size; i++)
    {
        auto task = pool.exec(sum, i, i);
        assert(task.get() == i + i);
    }
    return;
}

int main()
{
    DefaultTest();
    SimpleFunctionsTest();
    std::cout << "Success!" << std::endl;
    return 0;
}