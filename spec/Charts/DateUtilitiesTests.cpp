#include "gtest/gtest.h"
#include "DateUtilities.h"

TEST( DateUtilitiesTests, SetsDayOfWeekCorrectly )
{
  struct tm expected;
  memset( &expected, 0, sizeof(expected) );

  expected.tm_year = 2012 - 1900;
  expected.tm_mon = 5 - 1;
  expected.tm_mday = 5;

  mktime( &expected );

  ASSERT_EQ( 6, expected.tm_wday );
}

TEST( DateUtilitiesTests, SubtractsDaysCorrectly )
{
  struct tm expected;
  memset( &expected, 0, sizeof(expected) );

  expected.tm_year = 2012 - 1900;
  expected.tm_mon = 5 - 1;
  expected.tm_mday = 5 - 15;

  mktime( &expected );

  ASSERT_EQ( 5, expected.tm_wday );
  ASSERT_EQ( 20, expected.tm_mday );
  ASSERT_EQ( 4-1, expected.tm_mon );
  ASSERT_EQ( 2012-1900, expected.tm_year );
}
