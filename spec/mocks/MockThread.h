#ifndef MOCK_THREAD_H
#define MOCK_THREAD_H

#include "SlaveThread.h"

class MockSlaveThreadFactory;

class MockThread
  : public SlaveThread
{
  public:
    MockSlaveThreadFactory* factory_;
    bool goCalled_;

    MockThread();
    MockThread( MockSlaveThreadFactory* factory );
    virtual ~MockThread();

    void go();
    void start( MasterThread& );
};

#endif
