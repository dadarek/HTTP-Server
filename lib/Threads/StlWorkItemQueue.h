#ifndef STL_WORK_ITEM_QUEUE_H
#define STL_WORK_ITEM_QUEUE_H

#include "WorkItemQueue.h"
#include <queue>

class WorkItem;

class StlWorkItemQueue
  : public WorkItemQueue
{
  private:
    std::queue< WorkItem* > queue_;

  public:
    StlWorkItemQueue();
    virtual ~StlWorkItemQueue();

    void push( WorkItem* );
    void pop();

    WorkItem* front();
    bool empty();
};

#endif
