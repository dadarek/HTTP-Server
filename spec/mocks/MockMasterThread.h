#ifndef MOCK_MASTER_THREAD_H
#define MOCK_MASTER_THREAD_H

#include "MasterThread.h"

class MockMasterThread
  : public MasterThread
{
  public:
    MockMasterThread();
    virtual ~MockMasterThread();

    WorkItem* next();
};

#endif
