#include "StlWorkItemQueue.h"

StlWorkItemQueue::StlWorkItemQueue()
{ }

StlWorkItemQueue::~StlWorkItemQueue()
{ }

void StlWorkItemQueue::push( WorkItem* item )
{
  queue_.push( item );
}

void StlWorkItemQueue::pop()
{
  queue_.pop();
}

WorkItem* StlWorkItemQueue::front()
{
  return queue_.front();
}

bool StlWorkItemQueue::empty()
{
  return queue_.empty();
}
