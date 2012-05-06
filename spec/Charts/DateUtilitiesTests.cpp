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

TEST( DateUtilitiesTests, ComparesCorrectly )
{
  struct tm may_5;
  memset( &may_5, 0, sizeof(may_5) );
  may_5.tm_year = 2012 - 1900;
  may_5.tm_mon = 5 - 1;
  may_5.tm_mday = 5;
  time_t t_may_5 = mktime( &may_5 );

  struct tm may_6;
  memset( &may_6, 0, sizeof(may_6) );
  may_6.tm_year = 2012 - 1900;
  may_6.tm_mon = 5 - 1;
  may_6.tm_mday = 6;
  time_t t_may_6 = mktime( &may_6 );

  ASSERT_GT( (double) 0, difftime(t_may_5, t_may_6) );
  ASSERT_LT( (double) 0, difftime(t_may_6, t_may_5) );
  ASSERT_EQ( (double) 0, difftime(t_may_5, t_may_5) );
  ASSERT_EQ( (double) 0, difftime(t_may_6, t_may_6) );
}

