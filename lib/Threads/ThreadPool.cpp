#include "ThreadPool.h"
#include "ThreadFactory.h"
#include "Thread.h"

ThreadPool::ThreadPool( ThreadApi& api, ThreadFactory& factory, unsigned numberOfThreads )
  : api_( api )
  , factory_( factory )
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

void ThreadPool::add( void* )
{
  api_.pthread_mutex_lock( &mutex_ );
  api_.pthread_cond_signal( &condition_ );
  api_.pthread_mutex_unlock( &mutex_ );
}

void* ThreadPool::remove()
{
  api_.pthread_mutex_lock( &mutex_ );
  api_.pthread_mutex_unlock( &mutex_ );
  return 0;
}

WorkItem* ThreadPool::next()
{
  throw 0;
}
