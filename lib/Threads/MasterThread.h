#ifndef MASTER_THREAD_H
#define MASTER_THREAD_H

class WorkItem;

class MasterThread
{
  public:
   virtual ~MasterThread() { }

   virtual WorkItem* next() = 0;
};

#endif
