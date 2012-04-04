#include "gtest/gtest.h"
#include "MockThreadApi.h"
#include "SystemThread.h"
#include "ThreadLauncher.h"
#include "ThreadStartException.h"
#include "MockRunnable.h"

class SystemThreadTests
  : public ::testing::Test
{
  public:
    MockRunnableInspector inspector_;
    MockRunnable* runnable_;
    MockThreadApi threadApi_;
    SystemThread thread_;
    
    SystemThreadTests()
      : inspector_()
      , runnable_( new MockRunnable( inspector_ ) )
      , threadApi_()
      , thread_( threadApi_ )
    { }

    void start()
    {
      thread_.start( runnable_ );
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

TEST_F( SystemThreadTests, RunsTheRunnable )
{
  start();
  EXPECT_EQ( true, inspector_.ran );
}

TEST_F( SystemThreadTests, DeletesRunnableAfterRun )
{
  start();
  EXPECT_EQ( true, inspector_.deleted );
}
