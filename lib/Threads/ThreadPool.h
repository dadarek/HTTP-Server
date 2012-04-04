#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include "ThreadApi.h"

class ThreadPool
{
  private:
    ThreadApi& api_;
    pthread_mutex_t mutex_;
    pthread_cond_t condition_;

  public:
    ThreadPool( ThreadApi& api );
    virtual ~ThreadPool();

};
#endif
