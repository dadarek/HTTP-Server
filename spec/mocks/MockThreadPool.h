#ifndef MOCK_THREAD_POOL_H
#define MOCK_THREAD_POOL_H

#include "ThreadPool.h"
#include "MockThreadApi.h"

class MockThreadPool
  : public ThreadPool
{
  private:
    MockThreadApi& api_;

  public:
    MockThreadPool( MockThreadApi& api, ThreadFactory& factory, unsigned numberOfThreads );
    virtual ~MockThreadPool();

  protected:
    WorkItem* popWorkItem();
};

#endif
