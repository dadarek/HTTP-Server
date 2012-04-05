#ifndef WORK_ITEM_H
#define WORK_ITEM_H

class WorkItem
{
  public:
    virtual ~WorkItem() { }

    virtual void execute() = 0;
};

#endif
