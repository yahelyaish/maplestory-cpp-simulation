#ifndef _THREAD_POOL
#define _THREAD_POOL


#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <utility>
#include <atomic>

// ======================================================
// ThreadPool
// ======================================================

class ThreadPool
{
private:
    std::vector<std::thread> workers;

    std::mutex mtx;
    std::condition_variable cv;
    bool stop = false;

    std::queue<std::packaged_task<void()>> jobs;
    std::atomic<size_t> activeJobs{0};

    void workerLoop();

public:
    ThreadPool(size_t numOfWorkers = 10);
    ~ThreadPool();

    template <typename F>
    std::future<void> submit(F&& f)
    {
        std::packaged_task<void()> task(forward<F>(f));
        std::future<void> fut = task.get_future();

        {
            std::lock_guard<std::mutex> lock(mtx);
            jobs.push(std::move(task));
        }

        cv.notify_one();
        return fut;
    }
};

#endif //_THREAD_POOL
