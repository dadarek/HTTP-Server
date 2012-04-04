#ifndef SYSTEM_THREAD_FACTORY
#define SYSTEM_THREAD_FACTORY

#include "ThreadFactory.h"

class ThreadApi;

class SystemThreadFactory
  : public ThreadFactory
{
  private:
    ThreadApi& api_;

  public:
    SystemThreadFactory( ThreadApi& api );
    virtual ~SystemThreadFactory();

    Thread* create();
};

#endif
