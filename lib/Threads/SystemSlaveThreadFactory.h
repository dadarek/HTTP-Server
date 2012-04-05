#ifndef SYSTEM_THREAD_FACTORY
#define SYSTEM_THREAD_FACTORY

#include "SlaveThreadFactory.h"

class ThreadApi;

class SystemSlaveThreadFactory
  : public SlaveThreadFactory
{
  private:
    ThreadApi& api_;

  public:
    SystemSlaveThreadFactory( ThreadApi& api );
    virtual ~SystemSlaveThreadFactory();

    SlaveThread* create();
};

#endif
