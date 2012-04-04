#include "ThreadPool.h"
#include "ThreadFactory.h"
#include "Thread.h"

ThreadPool::ThreadPool( ThreadApi& api, ThreadFactory& factory, unsigned numberOfThreads )
  : api_( api )
  , factory_( factory )
  , numberOfThreads_( numberOfThreads )
{
  api_.pthread_mutex_init( &mutex_, 0 );
  api_.pthread_cond_init( &condition_, 0 );

  for(unsigned i = 0; i < numberOfThreads_; i++ )
  {
    delete (factory_.create());
  }
}

ThreadPool::~ThreadPool()
{ 
  api_.pthread_mutex_destroy( &mutex_ );
  api_.pthread_cond_destroy( &condition_ );
}

