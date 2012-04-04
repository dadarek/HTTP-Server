#ifndef MOCK_THREAD_H
#define MOCK_THREAD_H

#include "Thread.h"

class MockThread
  : public Thread
{
  public:
    bool goCalled_;

    MockThread();
    virtual ~MockThread();

    void go();
    void start( Runnable* runnable );
};

#endif
