#ifndef MOCK_RUNNABLE_H
#define MOCK_RUNNABLE_H

#include "Runnable.h"

struct MockRunnableInspector
{
  bool ran;
  bool deleted;
  MockRunnableInspector()
    : ran( false )
    , deleted( false )
  { }
};

class MockRunnable
  : public Runnable
{
  public:
    MockRunnableInspector& inspector_;

    MockRunnable( MockRunnableInspector& inspector );
    virtual ~MockRunnable();

    void run();
};

#endif
