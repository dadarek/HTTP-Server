#ifndef MOCK_THREAD_POOL_H
#define MOCK_THREAD_POOL_H

#include "ThreadPool.h"

class MockThreadPool
  : public ThreadPool
{
  public:
    MockThreadPool( ThreadApi& api, ThreadFactory& factory, unsigned numberOfThreads );
    virtual ~MockThreadPool();

  protected:
    WorkItem* popWorkItem();
};

#endif
