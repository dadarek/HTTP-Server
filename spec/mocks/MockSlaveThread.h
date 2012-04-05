#ifndef MOCK_SLAVE_THREAD_H
#define MOCK_SLAVE_THREAD_H

#include "SlaveThread.h"

class MockSlaveThreadFactory;

class MockSlaveThread
  : public SlaveThread
{
  public:
    MockSlaveThreadFactory* factory_;
    bool goCalled_;

    MockSlaveThread();
    MockSlaveThread( MockSlaveThreadFactory* factory );
    virtual ~MockSlaveThread();

    void go();
    void start( MasterThread& );
};

#endif
