#ifndef THREAD_H
#define THREAD_H

class Runnable;

class Thread
{
  public:
    virtual ~Thread() { }

    virtual void start( Runnable* runnable ) = 0;
    virtual void go() = 0;
};

#endif
