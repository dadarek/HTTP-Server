#ifndef MOCk_WORK_ITEM_QUEUE_H
#define MOCK_WORK_ITEM_QUEUE_H

#include "WorkItemQueue.h"
#include <queue>

class WorkItem;
class MockThreadApi;

class MockWorkItemQueue
  : public WorkItemQueue
{
  private:
    std::queue< WorkItem* > queue_;
    MockThreadApi& threadApi_;

  public:
    unsigned addFakeItemAfterNCalls_;
    unsigned times_empty_called_;

  public:
    MockWorkItemQueue( MockThreadApi& );
    virtual ~MockWorkItemQueue();

    void push( WorkItem* );
    void pop();

    WorkItem* front();
    bool empty();
};

#endif
