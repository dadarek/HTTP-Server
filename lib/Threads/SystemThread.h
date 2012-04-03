#ifndef SYSTEM_THREAD_H
#define SYSTEM_THREAD_H

#include "Thread.h"

class ThreadApi;

class SystemThread
  : public Thread
{
  private:
    ThreadApi& threadApi_;

  public:
    SystemThread( ThreadApi& threadApi );
    virtual ~SystemThread();

    void go();
};
#endif
