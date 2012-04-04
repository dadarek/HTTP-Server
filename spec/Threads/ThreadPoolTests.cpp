#include "gtest/gtest.h"
#include "ThreadPool.h"
#include "MockThreadApi.h"

TEST( ThreadPoolTests, InitsAValidMutex )
{
  MockThreadApi api;
  ThreadPool pool( api );

  ASSERT_NE( (void*) 0, api.mutexInit_mutex_input_ );
}

TEST( ThreadPoolTests, DestroysItsMutexInDestructor )
{
  MockThreadApi api;
  {
    ThreadPool pool( api );
    ASSERT_EQ( (void*) 0, api.mutexDestroy_mutex_input_ );
  }

  ASSERT_EQ( api.mutexInit_mutex_input_, api.mutexDestroy_mutex_input_ );
}

TEST( ThreadPoolTests, InitsAValidConditionVariable )
{
  MockThreadApi api;
  ThreadPool pool( api );
  ASSERT_NE( (void*) 0, api.condInit_cond_input_ );
}

TEST( ThreadPoolTests, DestroysItsConditionVariable )
{
  MockThreadApi api;
  {
    ThreadPool pool( api );
    ASSERT_EQ( (void*) 0, api.condDestroy_cond_input_ );
  }
  ASSERT_EQ( api.condInit_cond_input_, api.condDestroy_cond_input_ );
}
