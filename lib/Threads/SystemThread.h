#ifndef SYSTEM_THREAD_H
#define SYSTEM_THREAD_H

#include "Thread.h"

class ThreadApi;

class SystemThread
  : public Thread
{
  private:
    MasterThread* master_;
    ThreadApi& threadApi_;


  public:
    SystemThread( ThreadApi& threadApi );
    virtual ~SystemThread();

    void start( MasterThread& );
    void go();
};
#endif
