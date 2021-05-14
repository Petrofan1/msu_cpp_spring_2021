
#ifndef HEADER
#define HEADER
#include <mutex>
#include <condition_variable>
#include <future>
#include <thread>
#include <vector>
#include <atomic>
#include <queue>
#include <functional>
#include <cassert>
#include <iostream>

class ThreadPool
{
    std::vector<std::thread> threads;
    std::queue<std::function<void()>> tasks;
    size_t pool_size;
    std::mutex mutex;
    std::condition_variable condition;
    bool flag;

public:
    explicit ThreadPool(size_t size);
    template <class Func, class... Args>
    auto exec(Func func, Args... args) -> std::future<decltype(func(args...))>
    {
        auto task = std::make_shared<std::packaged_task<decltype(func(args...))()>>([func, args...]() {
            return func(args...);
        });
        std::future<decltype(func(args...))> result = task->get_future();
        {
            std::lock_guard<std::mutex> lock(mutex);
            tasks.emplace([task]() { (*task)(); });
        }
        condition.notify_one();
        return result;
    }
    ~ThreadPool();
};
#endif