#include "gtest/gtest.h"
#include "RunLog.h"

TEST( RunLogTests, ComparesDateTime )
{
  RunLog log1( "2012-04-01", 15 );
  RunLog log2( "2012-04-01", 15 );
  ASSERT_EQ( log1, log2 );
}
