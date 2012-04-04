#include "ThreadPool.h"

ThreadPool::ThreadPool( ThreadApi& api )
  : api_( api )
{ }

ThreadPool::~ThreadPool()
{ }

