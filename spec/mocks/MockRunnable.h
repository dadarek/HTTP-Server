#ifndef MOCK_RUNNABLE_H
#define MOCK_RUNNABLE_H

#include "Runnable.h"

class MockRunnable
  : public Runnable
{
  public:
    bool ran_;

    MockRunnable();
    virtual ~MockRunnable();

    void run();
};

#endif
