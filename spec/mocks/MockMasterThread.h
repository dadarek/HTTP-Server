#ifndef MOCK_MASTER_THREAD_H
#define MOCK_MASTER_THREAD_H

#include "MasterThread.h"
#include <stdexcept>

class MockMasterThreadStopException
  : public std::runtime_error
{
  public:
    MockMasterThreadStopException()
      : std::runtime_error( "Time to stop.")
    { }
};

class MockMasterThread
  : public MasterThread
{
  public:
    WorkItem* workItem_;

    bool returnDummies_;
    unsigned throwAfter_;
    unsigned timesNextCalled_;

    MockMasterThread();
    virtual ~MockMasterThread();

    WorkItem* next();
};

#endif
