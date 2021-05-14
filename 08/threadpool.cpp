#include "threadpool.hpp"

ThreadPool::ThreadPool(size_t size)
{
    pool_size = size;
    flag = false;
    for (size_t i = 0; i < pool_size; i++)
    {
        threads.emplace_back([this]() {
            while (!flag)
            {
                std::unique_lock<std::mutex> lock(mutex);
                condition.wait(lock, [this]() { return !tasks.empty() || flag; });
                if (!tasks.empty())
                {
                    auto next = std::move(tasks.front());
                    tasks.pop();
                    next();
                }
                else
                {
                    return;
                }
            }
        });
    }
}

ThreadPool::~ThreadPool()
{
    flag = true;
    condition.notify_all();
    for (auto &i : threads)
    {
        i.join();
    }
}