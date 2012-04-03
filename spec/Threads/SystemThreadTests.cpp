#include "gtest/gtest.h"
#include "MockThreadApi.h"
#include "SystemThread.h"
#include "ThreadLauncher.h"
#include "ThreadStartException.h"

class SystemThreadTests
  : public ::testing::Test
{
  public:
    MockThreadApi threadApi_;
    SystemThread thread_;
    
    SystemThreadTests()
      : threadApi_()
      , thread_( threadApi_ )
    { }

};

TEST_F( SystemThreadTests, PassesTheThreadLauncherStaticMethod )
{
  thread_.start();
  void* (*expected)(void*) = ThreadLauncher::launch;
  ASSERT_EQ( expected, threadApi_.callBackFunctionPassedIn_ );
}

TEST_F( SystemThreadTests, PassesItselfAsCallbackParameter )
{
  thread_.start();
  void* expected = &thread_;
  ASSERT_EQ( expected, threadApi_.callBackParameterPassedIn_ );
}

TEST_F( SystemThreadTests, ThrowsExceptionIf_pthread_create_returnsError )
{
  threadApi_.createReturnValue_ = 1;
  EXPECT_THROW( thread_.start(), ThreadStartException );
}
