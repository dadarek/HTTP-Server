#ifndef THREAD_FACTORY_H
#define THREAD_FACTORY_H

class Thread;

class ThreadFactory
{
  public:
    virtual ~ThreadFactory(){ }

    virtual Thread* create() = 0;
};

#endif
