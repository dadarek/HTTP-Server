#ifndef MOCK_THREAD_H
#define MOCK_THREAD_H

#include "SlaveThread.h"

class MockThreadFactory;

class MockThread
  : public SlaveThread
{
  public:
    MockThreadFactory* factory_;
    bool goCalled_;

    MockThread();
    MockThread( MockThreadFactory* factory );
    virtual ~MockThread();

    void go();
    void start( MasterThread& );
};

#endif
