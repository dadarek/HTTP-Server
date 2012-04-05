#ifndef SYSTEM_THREAD_H
#define SYSTEM_THREAD_H

#include "SlaveThread.h"

class ThreadApi;

class SystemThread
  : public SlaveThread
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
