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

    ThreadPoolTests()
    {
      create();
    }

    virtual ~ThreadPoolTests()
    {
      destroy();
    }

    void create()
    {
      pool_ = new ThreadPool( api_, factory_, 5 );
    }

    void destroy()
    {
      if( pool_ != 0 )
      {
        delete pool_;
        pool_ = 0;
      }
    }
};

TEST_F( ThreadPoolTests, InitsAValidMutex )
{
  ASSERT_NE( (void*) 0, api_.mutexInit_mutex_input_ );
}

TEST_F( ThreadPoolTests, DestroysItsMutexInDestructor )
{
  ASSERT_EQ( (void*) 0, api_.mutexDestroy_mutex_input_ );
  destroy(); 
  ASSERT_EQ( api_.mutexInit_mutex_input_, api_.mutexDestroy_mutex_input_ );
}

TEST_F( ThreadPoolTests, InitsAValidConditionVariable )
{
  ASSERT_NE( (void*) 0, api_.condInit_cond_input_ );
}

TEST_F( ThreadPoolTests, DestroysItsConditionVariable )
{
  ASSERT_EQ( (void*) 0, api_.condDestroy_cond_input_ );
  destroy();
  ASSERT_EQ( api_.condInit_cond_input_, api_.condDestroy_cond_input_ );
}
