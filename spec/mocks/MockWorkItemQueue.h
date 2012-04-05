#ifndef MOCk_WORK_ITEM_QUEUE_H
#define MOCK_WORK_ITEM_QUEUE_H

#include "WorkItemQueue.h"
#include <queue>

class WorkItem;

class MockWorkItemQueue
  : public WorkItemQueue
{
  private:
    std::queue< WorkItem* > queue_;

  public:
    MockWorkItemQueue();
    virtual ~MockWorkItemQueue();

    void push( WorkItem* );
    void pop();

    WorkItem* front();
    bool empty();
};

#endif
