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
  ASSERT_NE( (void*) 0, api_.in_mutexInit_ );
}

TEST_F( ThreadPoolTests, DestroysItsMutexInDestructor )
{
  ASSERT_EQ( (void*) 0, api_.in_mutexDestroy_ );
  destroy(); 
  ASSERT_EQ( api_.in_mutexInit_, api_.in_mutexDestroy_ );
}

TEST_F( ThreadPoolTests, InitsAValidConditionVariable )
{
  ASSERT_NE( (void*) 0, api_.in_condInit_ );
}

TEST_F( ThreadPoolTests, DestroysItsConditionVariableInDestructor )
{
  ASSERT_EQ( (void*) 0, api_.in_condDestroy_ );
  destroy();
  ASSERT_EQ( api_.in_condInit_, api_.in_condDestroy_ );
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

TEST_F( ThreadPoolTests, LocksMutexWhenAddingWorkItems )
{
  pool_->add( 0 );
  ASSERT_EQ( api_.in_mutexInit_, api_.in_mutexLock_ );
}

TEST_F( ThreadPoolTests, UnlocksMutexAfterAddingWorkItems )
{
  pool_->add( 0 );
  ASSERT_EQ( api_.in_mutexInit_, api_.in_mutexUnlock_ );
}

TEST_F( ThreadPoolTests, SignalsConditionVariableWhenAddingItems )
{
  pool_->add( 0 );
  ASSERT_EQ( api_.in_condInit_, api_.in_condSignal_ );
}
