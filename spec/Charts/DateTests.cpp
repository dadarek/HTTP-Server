#include "gtest/gtest.h"
#include "Date.h"

class DateTests
  : public ::testing::Test
{
  public:
    DateTests(){ }

    time_t createDate(struct tm& date, int year, int month, int day)
    {
      memset( &date, 0, sizeof(date) );

      date.tm_year = year - 1900;
      date.tm_mon = month - 1;
      date.tm_mday = day;

      time_t result = mktime( &date );
      return result;
    }
};

TEST_F( DateTests, ParsesDateFromString )
{
  Date date("2011-04-18");
  ASSERT_EQ( 18, date.day() );
  ASSERT_EQ( 4, date.month() );
  ASSERT_EQ( 2011, date.year() );
}

TEST_F( DateTests, Compares2Dates )
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

TEST_F( DateTests, ComparesCorrectly )
{
  Date yesterday ("2012-05-05");
  Date today     ("2012-05-06");

  ASSERT_GT( today, yesterday );

  struct tm date;
  time_t t_may_5 = createDate(date, 2012, 5, 5);
  time_t t_may_6 = createDate(date, 2012, 5, 6);

  ASSERT_GT( (double) 0, difftime(t_may_5, t_may_6) );
  ASSERT_LT( (double) 0, difftime(t_may_6, t_may_5) );
  ASSERT_EQ( (double) 0, difftime(t_may_5, t_may_5) );
  ASSERT_EQ( (double) 0, difftime(t_may_6, t_may_6) );
}

