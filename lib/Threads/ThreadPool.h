#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include "MasterThread.h"
#include "ThreadApi.h"
#include <vector>

class SlaveThread;
class ThreadFactory;
class WorkItemQueue;

class ThreadPool
  : public MasterThread
{
  private:
    ThreadApi& api_;
    ThreadFactory& factory_;

    WorkItemQueue& workItems_;

    unsigned numberOfThreads_;
    std::vector< SlaveThread* > threads_;


    pthread_mutex_t mutex_;
    pthread_cond_t condition_;

  public:
    ThreadPool( ThreadApi& api, ThreadFactory& factory, WorkItemQueue& workItem, unsigned numberOfThreads );
    virtual ~ThreadPool();

    void add( WorkItem* );
    WorkItem* next();

  private:
    void createThreads();
    void deleteThreads();

    WorkItem* getWorkItem();
};
#endif
