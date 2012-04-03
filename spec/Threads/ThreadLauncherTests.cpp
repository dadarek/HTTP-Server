#include "gtest/gtest.h"
#include "ThreadLauncher.h"
#include "MockThread.h"

TEST( ThreadLauncherTests, CallsGoOnThread )
{
  MockThread thread;
  ThreadLauncher::launch( &thread );
  ASSERT_EQ( true, thread.goCalled_ );
}
