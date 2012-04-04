#ifndef SYSTEM_THREAD_H
#define SYSTEM_THREAD_H

#include "Thread.h"

class ThreadApi;
class Runnable;

class SystemThread
  : public Thread
{
  private:
    ThreadApi& threadApi_;
    Runnable* runnable_;


  public:
    SystemThread( ThreadApi& threadApi );
    virtual ~SystemThread();

    void start( Runnable* runnable );
    void go();
};
#endif
