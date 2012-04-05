#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include "MasterThread.h"
#include "ThreadApi.h"
#include <vector>
#include <queue>

class Thread;
class ThreadFactory;

class ThreadPool
  : public MasterThread
{
  private:
    ThreadApi& api_;
    ThreadFactory& factory_;

    unsigned numberOfThreads_;
    std::vector< Thread* > threads_;

    pthread_mutex_t mutex_;
    pthread_cond_t condition_;

    std::queue< WorkItem* > workItems_;

  public:
    ThreadPool( ThreadApi& api, ThreadFactory& factory, unsigned numberOfThreads );
    virtual ~ThreadPool();

    void add( WorkItem* );
    WorkItem* next();

  private:
    void createThreads();
    void deleteThreads();

    WorkItem* popWorkItem();

};
#endif
