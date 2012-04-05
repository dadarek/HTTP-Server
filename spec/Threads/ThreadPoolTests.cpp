#include "gtest/gtest.h"
#include "ThreadPool.h"
#include "MockThreadApi.h"
#include "MockSlaveThreadFactory.h"
#include "MockWorkItemQueue.h"

class ThreadPoolTests
  : public ::testing::Test
{
  public:
    MockThreadApi api_;
    MockSlaveThreadFactory factory_;
    MockWorkItemQueue queue_;
    ThreadPool* pool_;

    const unsigned THREADS_TO_CREATE;

    ThreadPoolTests()
      : queue_( api_ )
      , THREADS_TO_CREATE( 5 )
    {
      create();
    }

    virtual ~ThreadPoolTests()
    {
      destroy();
    }

    void create()
    {
      pool_ = new ThreadPool( api_, factory_, queue_, THREADS_TO_CREATE );
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

TEST_F( ThreadPoolTests, StartsEachThread )
{
  ASSERT_EQ( THREADS_TO_CREATE, factory_.threadsStarted_ );
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

TEST_F( ThreadPoolTests, LocksMutexWhenRemovingItems )
{
  pool_->add( (WorkItem*) 77 );
  pool_->next();
  ASSERT_EQ( api_.in_mutexInit_, api_.in_mutexLock_ );
}

TEST_F( ThreadPoolTests, UnlocksMutexWhenRemovingItems )
{
  pool_->add( (WorkItem*) 77 );
  pool_->next();
  ASSERT_EQ( api_.in_mutexInit_, api_.in_mutexUnlock_ );
}

TEST_F( ThreadPoolTests, RemembersWorkItems )
{
  WorkItem* expected = (WorkItem*) 55;
  pool_->add( expected );
  WorkItem* actual = pool_->next();
  ASSERT_EQ( expected, actual );
}

TEST_F( ThreadPoolTests, WaitsOnConditionVariableIfQueueIsEmpty )
{
  queue_.addFakeItemAfterNCalls_ = 1;
  pool_->next();
  ASSERT_EQ( api_.in_condInit_, api_.in_condWait_ );
}

TEST_F( ThreadPoolTests, WaitsOnConditionVariableWithCorrectMutex )
{
  queue_.addFakeItemAfterNCalls_ = 1;
  pool_->next();
  ASSERT_EQ( api_.in_mutexInit_, api_.in_condWait_mutex_ );
}

TEST_F( ThreadPoolTests, DoesNotWaitOnConditionVariableIfQueueIsEmpty )
{
  pool_->add( (WorkItem*) 77 );
  pool_->next();
  ASSERT_EQ( (void*) 0, api_.in_condWait_ );
}

TEST_F( ThreadPoolTests, WaitsOnConditionUntilNewWorkItemsAreAdded )
{
  queue_.addFakeItemAfterNCalls_ = 4;
  pool_->next();
  ASSERT_EQ( 4U, api_.times_condWait_called_ );
}

