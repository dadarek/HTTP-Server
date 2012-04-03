#include "gtest/gtest.h"
#include "MockThreadApi.h"
#include "SystemThread.h"

TEST( SystemThreadTests, Compiles )
{
  MockThreadApi threadApi;
  SystemThread thread( threadApi );
}
