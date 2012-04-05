#include "gtest/gtest.h"
#include "MockThreadApi.h"
#include "SystemSlaveThread.h"
#include "ThreadLauncher.h"
#include "ThreadStartException.h"
#include "MockMasterThread.h"
#include "MockWorkItem.h"

class SystemSlaveThreadTests
  : public ::testing::Test
{
  public:
    MockThreadApi threadApi_;
    MockMasterThread master_;
    MockWorkItem* workItem_;
    SystemSlaveThread thread_;
    
    SystemSlaveThreadTests()
      : threadApi_()
      , master_()
      , workItem_( new MockWorkItem() )
      , thread_( threadApi_ )
    { }

    void start()
    {
      master_.workItem_ = workItem_;
      try
      {
        thread_.start( master_ );
      }
      catch( MockMasterThreadStopException& e )
      { 
      }
    }
};

TEST_F( SystemSlaveThreadTests, PassesTheThreadLauncherStaticMethod )
{
  start();
  void* (*expected)(void*) = ThreadLauncher::launch;
  ASSERT_EQ( expected, threadApi_.callBackFunctionPassedIn_ );
}

TEST_F( SystemSlaveThreadTests, PassesItselfAsCallbackParameter )
{
  start();
  void* expected = &thread_;
  ASSERT_EQ( expected, threadApi_.callBackParameterPassedIn_ );
}

TEST_F( SystemSlaveThreadTests, ThrowsExceptionIf_pthread_create_returnsError )
{
  threadApi_.createReturnValue_ = 1;
  EXPECT_THROW( start(), ThreadStartException );
}

TEST_F( SystemSlaveThreadTests, RunsWorkItemFromMaster )
{
  bool executed = false;
  workItem_->executed_ = &executed;
  start();
  EXPECT_EQ( true, executed );
}

TEST_F( SystemSlaveThreadTests, DeletesWorkItemAfterRun )
{
  bool deleted = false;
  workItem_->deleted_ = &deleted;
  start();
  EXPECT_EQ( true, deleted );
}

TEST_F( SystemSlaveThreadTests, PollsMasterIndefinitely )
{
  master_.returnDummies_ = true;
  master_.throwAfter_ = 5;
  start();
  EXPECT_EQ( 5U, master_.timesNextCalled_ );
}
