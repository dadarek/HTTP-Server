#ifndef MOCK_THREAD_H
#define MOCK_THREAD_H

#include "Thread.h"

class MockThreadFactory;

class MockThread
  : public Thread
{
  public:
    MockThreadFactory* factory_;
    bool goCalled_;

    MockThread();
    MockThread( MockThreadFactory* factory );
    virtual ~MockThread();

    void go();
    void start( Runnable* runnable );
    void start( MasterThread& );
};

#endif
