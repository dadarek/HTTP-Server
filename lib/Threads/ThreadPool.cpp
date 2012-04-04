#include "ThreadPool.h"

ThreadPool::ThreadPool( ThreadApi& api )
  : api_( api )
{
  api_.pthread_mutex_init( &mutex_, 0 );
}

ThreadPool::~ThreadPool()
{ }

