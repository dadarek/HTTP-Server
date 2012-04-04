#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include "ThreadApi.h"
#include <vector>

class Thread;
class ThreadFactory;

class ThreadPool
{
  private:
    ThreadApi& api_;
    ThreadFactory& factory_;

    unsigned numberOfThreads_;
    std::vector< Thread* > threads_;

    pthread_mutex_t mutex_;
    pthread_cond_t condition_;

  public:
    ThreadPool( ThreadApi& api, ThreadFactory& factory, unsigned numberOfThreads );
    virtual ~ThreadPool();

    void add( void* );

  private:
    void createThreads();
    void deleteThreads();

};
#endif
