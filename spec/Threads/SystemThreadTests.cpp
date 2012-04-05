#include "gtest/gtest.h"
#include "MockThreadApi.h"
#include "SystemThread.h"
#include "ThreadLauncher.h"
#include "ThreadStartException.h"
#include "MockMasterThread.h"
#include "MockWorkItem.h"

class SystemThreadTests
  : public ::testing::Test
{
  public:
    MockThreadApi threadApi_;
    MockMasterThread master_;
    MockWorkItem* workItem_;
    SystemThread thread_;
    
    SystemThreadTests()
      : threadApi_()
      , master_()
      , workItem_( new MockWorkItem() )
      , thread_( threadApi_ )
    { }

    void start()
    {
      master_.workItem_ = workItem_;
      thread_.start( master_ );
    }
};

TEST_F( SystemThreadTests, PassesTheThreadLauncherStaticMethod )
{
  start();
  void* (*expected)(void*) = ThreadLauncher::launch;
  ASSERT_EQ( expected, threadApi_.callBackFunctionPassedIn_ );
}

TEST_F( SystemThreadTests, PassesItselfAsCallbackParameter )
{
  start();
  void* expected = &thread_;
  ASSERT_EQ( expected, threadApi_.callBackParameterPassedIn_ );
}

TEST_F( SystemThreadTests, ThrowsExceptionIf_pthread_create_returnsError )
{
  threadApi_.createReturnValue_ = 1;
  EXPECT_THROW( start(), ThreadStartException );
}

TEST_F( SystemThreadTests, RunsWorkItemFromMaster )
{
  bool executed = false;
  workItem_->executed_ = &executed;
  start();
  EXPECT_EQ( true, executed );
}

TEST_F( SystemThreadTests, DeletesWorkItemAfterRun )
{
  bool deleted = false;
  workItem_->deleted_ = &deleted;
  start();
  EXPECT_EQ( true, deleted );
}
