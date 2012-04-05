#ifndef SYSTEM_SLAVE_THREAD_H
#define SYSTEM_SLAVE_THREAD_H

#include "SlaveThread.h"

class ThreadApi;

class SystemSlaveThread
  : public SlaveThread
{
  private:
    MasterThread* master_;
    ThreadApi& threadApi_;


  public:
    SystemSlaveThread( ThreadApi& threadApi );
    virtual ~SystemSlaveThread();

    void start( MasterThread& );
    void go();
};
#endif
