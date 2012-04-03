#ifndef THREAD_H
#define THREAD_H

class Thread
{
  public:
    virtual ~Thread() { }

    virtual void start() = 0;
    virtual void go() = 0;
};

#endif
