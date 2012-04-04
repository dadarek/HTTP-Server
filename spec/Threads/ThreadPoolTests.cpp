#include "gtest/gtest.h"
#include "ThreadPool.h"
#include "MockThreadApi.h"
#include "MockThreadFactory.h"

class ThreadPoolTests
  : public ::testing::Test
{
  public:
    MockThreadApi api_;
    MockThreadFactory factory_;
};

TEST_F( ThreadPoolTests, InitsAValidMutex )
{
  ThreadPool pool( api_, factory_ );
  ASSERT_NE( (void*) 0, api_.mutexInit_mutex_input_ );
}

TEST_F( ThreadPoolTests, DestroysItsMutexInDestructor )
{
  {
    ThreadPool pool( api_, factory_ );
    ASSERT_EQ( (void*) 0, api_.mutexDestroy_mutex_input_ );
  }

  ASSERT_EQ( api_.mutexInit_mutex_input_, api_.mutexDestroy_mutex_input_ );
}

TEST_F( ThreadPoolTests, InitsAValidConditionVariable )
{
  ThreadPool pool( api_, factory_ );
  ASSERT_NE( (void*) 0, api_.condInit_cond_input_ );
}

TEST_F( ThreadPoolTests, DestroysItsConditionVariable )
{
  {
    ThreadPool pool( api_, factory_ );
    ASSERT_EQ( (void*) 0, api_.condDestroy_cond_input_ );
  }
  ASSERT_EQ( api_.condInit_cond_input_, api_.condDestroy_cond_input_ );
}
