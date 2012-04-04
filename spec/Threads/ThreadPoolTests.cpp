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
    ThreadPool* pool_;

    void create()
    {
      pool_ = new ThreadPool( api_, factory_, 5 );
    }

    void destroy()
    {
      delete pool_;
    }
};

TEST_F( ThreadPoolTests, InitsAValidMutex )
{
  create();
  ASSERT_NE( (void*) 0, api_.mutexInit_mutex_input_ );
  destroy();
}

TEST_F( ThreadPoolTests, DestroysItsMutexInDestructor )
{
  create();
  ASSERT_EQ( (void*) 0, api_.mutexDestroy_mutex_input_ );
  destroy(); 
  ASSERT_EQ( api_.mutexInit_mutex_input_, api_.mutexDestroy_mutex_input_ );
}

TEST_F( ThreadPoolTests, InitsAValidConditionVariable )
{
  create();
  ASSERT_NE( (void*) 0, api_.condInit_cond_input_ );
  destroy();
}

TEST_F( ThreadPoolTests, DestroysItsConditionVariable )
{
  create();
  ASSERT_EQ( (void*) 0, api_.condDestroy_cond_input_ );
  destroy();
  ASSERT_EQ( api_.condInit_cond_input_, api_.condDestroy_cond_input_ );
}
