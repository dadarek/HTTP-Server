#include "ThreadPool.h"
#include "SlaveThreadFactory.h"
#include "SlaveThread.h"
#include "WorkItemQueue.h"

ThreadPool::ThreadPool( ThreadApi& api, SlaveThreadFactory& factory, WorkItemQueue& workItems, unsigned numberOfThreads )
  : api_( api )
  , factory_( factory )
  , workItems_( workItems )
  , numberOfThreads_( numberOfThreads )
  , threads_( numberOfThreads_ )
{
  api_.pthread_mutex_init( &mutex_, 0 );
  api_.pthread_cond_init( &condition_, 0 );

  createThreads();
}

ThreadPool::~ThreadPool()
{ 
  api_.pthread_mutex_destroy( &mutex_ );
  api_.pthread_cond_destroy( &condition_ );

  deleteThreads();
}

void ThreadPool::createThreads()
{
  for(unsigned i = 0; i < numberOfThreads_; i++ )
  {
    threads_[ i ] = factory_.create();
  }
}

void ThreadPool::deleteThreads()
{
  for(unsigned i = 0; i < numberOfThreads_; i++ )
  {
    delete threads_[ i ];
  }
}

void ThreadPool::add( WorkItem* item )
{
  api_.pthread_mutex_lock( &mutex_ );
  workItems_.push( item );
  api_.pthread_cond_signal( &condition_ );
  api_.pthread_mutex_unlock( &mutex_ );
}

WorkItem* ThreadPool::next()
{
  api_.pthread_mutex_lock( &mutex_ );
  WorkItem* result = getWorkItem();
  api_.pthread_mutex_unlock( &mutex_ );

  return result;
}

WorkItem* ThreadPool::getWorkItem()
{
  while( workItems_.empty() )
  {
    api_.pthread_cond_wait( &condition_, &mutex_ );
  }

  WorkItem* result = workItems_.front();
  workItems_.pop();

  return result;
}
