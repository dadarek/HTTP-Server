#ifndef SLAVE_THREAD_FACTORY_H
#define SLAVE_THREAD_FACTORY_H

class SlaveThread;

class SlaveThreadFactory
{
  public:
    virtual ~SlaveThreadFactory(){ }

    virtual SlaveThread* create() = 0;
};

#endif
