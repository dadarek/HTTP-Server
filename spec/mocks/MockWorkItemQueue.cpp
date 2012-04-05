#include "MockWorkItemQueue.h"
#include "MockThreadApi.h"

MockWorkItemQueue::MockWorkItemQueue( MockThreadApi& threadApi )
  : threadApi_( threadApi )
{ }

MockWorkItemQueue::~MockWorkItemQueue()
{ }

void MockWorkItemQueue::push( WorkItem* item )
{
  queue_.push( item );
}

void MockWorkItemQueue::pop()
{
  queue_.pop();
}

WorkItem* MockWorkItemQueue::front()
{
  return queue_.front();
}

bool MockWorkItemQueue::empty()
{
  return queue_.empty();
}
