#ifndef MOCK_SLAVE_THREAD_FACTORY_H
#define MOCK_SLAVE_THREAD_FACTORY_H

#include "SlaveThreadFactory.h"

class MockSlaveThreadFactory
  : public SlaveThreadFactory
{
  public:
    unsigned threadsCreated_;
    unsigned threadsDeleted_;
    unsigned threadsStarted_;

    MockSlaveThreadFactory();
    virtual ~MockSlaveThreadFactory();

    SlaveThread* create();
};

#endif
