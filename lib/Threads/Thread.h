#ifndef THREAD_H
#define THREAD_H

class Thread
{
  public:
    virtual ~Thread() { }

    virtual void go() = 0;
};

#endif
