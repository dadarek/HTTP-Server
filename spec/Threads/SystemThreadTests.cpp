#include "gtest/gtest.h"
#include "MockThreadApi.h"
#include "SystemThread.h"
#include "ThreadLauncher.h"

TEST( SystemThreadTests, PassesTheThreadLauncherStaticMethod )
{
  MockThreadApi threadApi;
  SystemThread thread( threadApi );

  thread.start();

  void* (*expected)(void*) = ThreadLauncher::launch;

  ASSERT_EQ( expected, threadApi.callBackFunctionPassedIn_ );
}

TEST( SystemThreadTests, PassesItselfAsCallbackParameter )
{
  MockThreadApi threadApi;
  SystemThread thread( threadApi );

  thread.start();

  void* expected = &thread;

  ASSERT_EQ( expected, threadApi.callBackParameterPassedIn_ );
}
