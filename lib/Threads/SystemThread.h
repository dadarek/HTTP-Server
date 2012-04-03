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
    SystemThread( ThreadApi& threadApi, Runnable* runnable );
    virtual ~SystemThread();

    void start();
    void go();
};
#endif
