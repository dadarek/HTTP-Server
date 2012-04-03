#include "gtest/gtest.h"
#include "MockThreadApi.h"
#include "SystemThread.h"
#include "ThreadLauncher.h"

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
