#include "gtest/gtest.h"
#include "ThreadPool.h"
#include "MockThreadApi.h"

TEST( ThreadPoolTests, InitsAValidMutex )
{
  MockThreadApi api;
  ThreadPool pool( api );

  ASSERT_NE( (void*) 0, api.mutexInit_mutex_input_ );
}
