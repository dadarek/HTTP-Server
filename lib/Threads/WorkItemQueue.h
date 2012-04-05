#ifndef WORK_ITEM_QUEUE_H
#define WORK_ITEM_QUEUE_H

class WorkItem;

class WorkItemQueue
{
  public:
    virtual ~WorkItemQueue() { }

    virtual void push( WorkItem* ) = 0;
    virtual void pop() = 0;

    virtual WorkItem* front() = 0;
    virtual bool empty() = 0;
};

#endif
