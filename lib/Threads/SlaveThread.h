#ifndef SLAVE_THREAD_H
#define SLAVE_THREAD_H

class MasterThread;

class SlaveThread
{
  public:
    virtual ~SlaveThread() { }

    virtual void start( MasterThread& ) = 0;
    virtual void go() = 0;
};

#endif
