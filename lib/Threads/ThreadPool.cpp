#include "ThreadPool.h"

ThreadPool::ThreadPool( ThreadApi& api, ThreadFactory& factory )
  : api_( api )
  , factory_( factory )
{
  api_.pthread_mutex_init( &mutex_, 0 );
  api_.pthread_cond_init( &condition_, 0 );
}

ThreadPool::~ThreadPool()
{ 
  api_.pthread_mutex_destroy( &mutex_ );
  api_.pthread_cond_destroy( &condition_ );
}

