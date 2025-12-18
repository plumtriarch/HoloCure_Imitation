#pragma once

class ManagerThread : public IManager
{
public:
    ~ManagerThread() override;
    struct ManagerThreadDesc : public ManagerDesc
    {
        virtual ~ManagerThreadDesc() = default;
    };
public:
    void Initialize(const ManagerDesc& _desc) override;
    
private:
    void WorkerThread();
    template <class F, class... Args>
    std::future<std::invoke_result_t<F, Args...>> EnqueueJob(F&& f, Args&&... args);

private:
    condition_variable cv_job_queue_;
    mutex mutex_job_queue_;
    bool stop_all_{false};
    queue<function<void()>> jobs_;
    vector<thread> worker_threads_;
};
template <class F, class... Args>
future<invoke_result_t<F, Args...>> ManagerThread::EnqueueJob(F&& f, Args&&... args)
{
    if (stop_all_)
    {
        CRASH();
    }

    using return_type = std::invoke_result_t<F, Args...>;

    auto job = make_shared<packaged_task<return_type()>>(
        bind(forward<F>(f), forward<Args>(args)...));

    future<return_type> job_result_future = job->get_future();
    {
        lock_guard<mutex> lock(mutex_job_queue_);
        jobs_.push([job]() { (*job)(); });
    }
    cv_job_queue_.notify_one();

    return job_result_future;
}
