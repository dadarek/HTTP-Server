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

    const unsigned THREADS_TO_CREATE;

    ThreadPoolTests()
      : THREADS_TO_CREATE( 5 )
    {
      create();
    }

    virtual ~ThreadPoolTests()
    {
      destroy();
    }

    void create()
    {
      pool_ = new ThreadPool( api_, factory_, THREADS_TO_CREATE );
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

TEST_F( ThreadPoolTests, DestroysItsConditionVariableInDestructor )
{
  ASSERT_EQ( (void*) 0, api_.condDestroy_cond_input_ );
  destroy();
  ASSERT_EQ( api_.condInit_cond_input_, api_.condDestroy_cond_input_ );
}

TEST_F( ThreadPoolTests, CreatesSpecifiedNumberOfThreads )
{
  ASSERT_EQ( THREADS_TO_CREATE, factory_.threadsCreated_ );
}

TEST_F( ThreadPoolTests, DeletesTheThreadsItCreatedInDestructor )
{
  ASSERT_EQ( 0U, factory_.threadsDeleted_ );
  destroy();
  ASSERT_EQ( THREADS_TO_CREATE, factory_.threadsDeleted_ );
}
