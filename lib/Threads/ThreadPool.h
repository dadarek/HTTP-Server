#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include "ThreadApi.h"

class ThreadFactory;

class ThreadPool
{
  private:
    ThreadApi& api_;
    ThreadFactory& factory_;

    pthread_mutex_t mutex_;
    pthread_cond_t condition_;

  public:
    ThreadPool( ThreadApi& api, ThreadFactory& factory );
    virtual ~ThreadPool();

};
#endif
