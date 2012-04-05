#ifndef SYSTEM_THREAD_H
#define SYSTEM_THREAD_H

#include "Thread.h"

class ThreadApi;
class Runnable;

class SystemThread
  : public Thread
{
  private:
    MasterThread* master_;
    ThreadApi& threadApi_;
    Runnable* runnable_;


  public:
    SystemThread( ThreadApi& threadApi );
    virtual ~SystemThread();

    void start( MasterThread& );
    void start( Runnable* runnable );
    void go();
};
#endif
