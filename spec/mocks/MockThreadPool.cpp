#include "MockThreadPool.h"

MockThreadPool::MockThreadPool( ThreadApi& api, ThreadFactory& factory, unsigned numberOfThreads )
  : ThreadPool( api, factory, numberOfThreads )
{ }

MockThreadPool::~MockThreadPool()
{ }


