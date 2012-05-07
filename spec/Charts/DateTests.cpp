#include "gtest/gtest.h"
#include "Date.h"

TEST( DateTests, ParsesDateFromString )
{
  Date date("2011-04-18");
  ASSERT_EQ( 18, date.day() );
  ASSERT_EQ( 4, date.month() );
  ASSERT_EQ( 2011, date.year() );
}

TEST( DateTests, Compares2Dates )
{
  Date date("2008-04-18");
  Date sameDate("2008-04-18");
  Date diffYear("1999-04-18");
  Date diffMonth("2008-01-18");
  Date diffDay("2008-04-19");

  ASSERT_EQ( date, sameDate );
  ASSERT_NE( date, diffYear );
  ASSERT_NE( date, diffMonth );
  ASSERT_NE( date, diffDay );
}


