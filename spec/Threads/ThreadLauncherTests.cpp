#include "gtest/gtest.h"
#include "ThreadLauncher.h"
#include "MockSlaveThread.h"

TEST( ThreadLauncherTests, CallsGoOnThread )
{
  MockSlaveThread thread;
  ThreadLauncher::launch( &thread );
  ASSERT_EQ( true, thread.goCalled_ );
}
