#include "ThreadPool.h"

ThreadPool::ThreadPool(size_t numOfWorkers)
{
    for(size_t i=0;i<numOfWorkers;i++){
      workers.emplace_back(&ThreadPool::workerLoop,this);
    }
}


ThreadPool::~ThreadPool(){
    {
        unique_lock<mutex>lock(mtx);
        stop=true;
    }
    cv.notify_all();
    for(auto& t:workers){
        if(t.joinable())
        t.join();
    }

}

void ThreadPool::workerLoop(){
    
    while(true){
    packaged_task<void()> jobToExecute;
    {  
            unique_lock<mutex> lock(mtx);
            cv.wait(lock,[this]{
                return stop || !jobs.empty();
            });
            if(stop && jobs.empty())
            return;
        jobToExecute=std::move(jobs.front());
        jobs.pop();

    }
    jobToExecute();
    }
}
   