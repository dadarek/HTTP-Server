#ifndef THREAD_H
#define THREAD_H

class MasterThread;

class Thread
{
  public:
    virtual ~Thread() { }

    virtual void start( MasterThread& ) = 0;
    virtual void go() = 0;
};

#endif
