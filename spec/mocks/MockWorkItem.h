#ifndef MOCK_WORK_ITEM_H
#define MOCK_WORK_ITEM_H

#include "WorkItem.h"

class MockWorkItem
  : public WorkItem
{
  public:
    bool* executed_;
    bool* deleted_;

    MockWorkItem();
    virtual ~MockWorkItem();

    void execute();
};

#endif
