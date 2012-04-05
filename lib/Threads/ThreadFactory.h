#ifndef THREAD_FACTORY_H
#define THREAD_FACTORY_H

class SlaveThread;

class ThreadFactory
{
  public:
    virtual ~ThreadFactory(){ }

    virtual SlaveThread* create() = 0;
};

#endif
