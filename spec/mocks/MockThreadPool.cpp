#include "MockThreadPool.h"
#include "MockThreadApi.h"
#include <stdexcept>

MockThreadPool::MockThreadPool( MockThreadApi& api, ThreadFactory& factory, unsigned numberOfThreads )
  : ThreadPool( api, factory, numberOfThreads )
  , api_( api )
{ }

MockThreadPool::~MockThreadPool()
{ }

WorkItem* MockThreadPool::popWorkItem()
{
  if( !api_.isLocked_)
    throw std::runtime_error( "Can't pop a work item without a locked mutex" );

  return ThreadPool::popWorkItem();
}

