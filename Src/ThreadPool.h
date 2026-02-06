#ifndef _THREAD_POOL
#define _THREAD_POOL

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <utility>
class ThreadPool
{
    private:
    vector<thread> workers;
    mutex mtx;
    condition_variable cv;
    bool stop=false;
    queue<packaged_task<void()>> jobs;
    atomic<size_t> activeJobs{0};
   // condition_variable doneCv;

    void workerLoop();
    

    public:
    ThreadPool(size_t numOfWorkers=10);
    ~ThreadPool();
    
    template<typename F>
    future<void> submit(F&& f) 
    {
    packaged_task<void()> task(forward<F>(f));
    future<void> fut = task.get_future();
    {
        lock_guard<std::mutex> lock(mtx);
        jobs.push(std::move(task));
    }

    cv.notify_one();
    return fut;
    }

  //  void waitAll();

};



#endif //_THREAD_POOL

