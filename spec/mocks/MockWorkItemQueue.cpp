#include "MockWorkItemQueue.h"
#include "MockThreadApi.h"
#include <stdexcept>

MockWorkItemQueue::MockWorkItemQueue( MockThreadApi& threadApi )
  : threadApi_( threadApi )
  , addFakeItemAfterNCalls_( 0 )
  , times_empty_called_( 0 )
{ }

MockWorkItemQueue::~MockWorkItemQueue()
{ }

void MockWorkItemQueue::push( WorkItem* item )
{
  if( !threadApi_.isLocked_ )
    throw std::runtime_error( "Cannot push work item without locking." );

  if( threadApi_.isSignaled_ )
    throw std::runtime_error( "Don't signal before adding work items." );

  queue_.push( item );
}

void MockWorkItemQueue::pop()
{
  if( !threadApi_.isLocked_ )
    throw std::runtime_error( "Cannot pop work item without locking." );

  queue_.pop();
}

WorkItem* MockWorkItemQueue::front()
{
  if( !threadApi_.isLocked_ )
    throw std::runtime_error( "Cannot call front without locking." );

  return queue_.front();
}

bool MockWorkItemQueue::empty()
{
  if( !threadApi_.isLocked_ )
    throw std::runtime_error( "Cannot call empty without locking." );

  if( times_empty_called_ == addFakeItemAfterNCalls_ )
    queue_.push( (WorkItem*) 77 );

  times_empty_called_ ++;

  return queue_.empty();
}
