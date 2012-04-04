#ifndef MOCK_THREAD_FACTORY_H
#define MOCK_THREAD_FACTORY_H

#include "ThreadFactory.h"

class MockThreadFactory
  : public ThreadFactory
{
  public:
    unsigned threadsCreated_;

    MockThreadFactory();
    virtual ~MockThreadFactory();

    Thread* create();
};

#endif
