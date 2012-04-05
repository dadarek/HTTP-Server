#include "MockWorkItemQueue.h"
#include "MockThreadApi.h"
#include <stdexcept>

MockWorkItemQueue::MockWorkItemQueue( MockThreadApi& threadApi )
  : threadApi_( threadApi )
{ }

MockWorkItemQueue::~MockWorkItemQueue()
{ }

void MockWorkItemQueue::push( WorkItem* item )
{
  if( !threadApi_.isLocked_ )
    throw std::runtime_error( "Cannot push work item without locking." );

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
