#include "ThreadPool.h"

ThreadPool::ThreadPool( ThreadApi& api )
  : api_( api )
{
  api_.pthread_mutex_init( &mutex_, 0 );
  api_.pthread_cond_init( &condition_, 0 );
  api_.pthread_cond_destroy( &condition_ );
}

ThreadPool::~ThreadPool()
{ 
  api_.pthread_mutex_destroy( &mutex_ );
}

