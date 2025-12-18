#include "pch.h"
#include "Manager/ThreadManager/ManagerThread.h"

ManagerThread::~ManagerThread()
{
    stop_all_ = true;
    cv_job_queue_.notify_all();

    for (auto& t : worker_threads_)
    {
        t.join();
    }
}

void ManagerThread::Initialize(const ManagerDesc& _desc)
{
    size_t worker_thread_count{ thread::hardware_concurrency()/2 };
    worker_threads_.reserve(worker_thread_count);
    for (size_t i = 0; i < worker_thread_count; i++)
    {
        worker_threads_.emplace_back([this]() { this->WorkerThread(); });
    }
}

void ManagerThread::WorkerThread()
{
    CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    
    while (true)
    {
        std::unique_lock<std::mutex> lock(mutex_job_queue_);
        cv_job_queue_.wait(lock, [this]() { return !this->jobs_.empty() || stop_all_; });

        if (stop_all_ && this->jobs_.empty())
        {
            return;
        }

        std::function<void()> job = std::move(jobs_.front());
        jobs_.pop();
        lock.unlock();

        job();
    }
    
    CoUninitialize();
}
