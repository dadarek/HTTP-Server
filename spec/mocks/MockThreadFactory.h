#ifndef MOCK_THREAD_FACTORY_H
#define MOCK_THREAD_FACTORY_H

#include "ThreadFactory.h"

class MockThreadFactory
  : public ThreadFactory
{
  public:
    unsigned threadsCreated_;
    unsigned threadsDeleted_;

    MockThreadFactory();
    virtual ~MockThreadFactory();

    SlaveThread* create();
};

#endif
