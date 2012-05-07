#include "gtest/gtest.h"
#include "DateUtilities.h"

class DateUtilitiesTests
  : public ::testing::Test
{
  public:
    DateUtilitiesTests(){ }

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

TEST_F( DateUtilitiesTests, ParsesDateFromString )
{
  std::string dateString("2011-04-18");
  const struct tm& result = DateUtilities::parse(dateString);

  ASSERT_EQ( 18, result.tm_mday );
  ASSERT_EQ( 4-1, result.tm_mon );
  ASSERT_EQ( 2011-1900, result.tm_year );
}

TEST_F( DateUtilitiesTests, Compares2Dates )
{
  struct tm date, sameDate, diffYear, diffMonth, diffDay;
  createDate( date, 2008, 9, 21 );
  createDate( sameDate, 2008, 9, 21 );
  createDate( diffYear, 2007, 9, 21 );
  createDate( diffMonth, 2008, 8, 21 );
  createDate( diffDay, 2008, 9, 22 );
  ASSERT_EQ( true, DateUtilities::equal( date, sameDate ) );
  ASSERT_EQ( false, DateUtilities::equal( date, diffYear) );
  ASSERT_EQ( false, DateUtilities::equal( date, diffMonth ) );
  ASSERT_EQ( false, DateUtilities::equal( date, diffDay ) );
}

TEST_F( DateUtilitiesTests, SetsDayOfWeekCorrectly )
{
  struct tm expected;
  createDate(expected, 2012, 5, 4);
  ASSERT_EQ( 5, expected.tm_wday );
}

TEST_F( DateUtilitiesTests, SubtractsDaysCorrectly )
{
  struct tm expected;
  createDate(expected, 2012, 5, 5-15);

  ASSERT_EQ( 5, expected.tm_wday );
  ASSERT_EQ( 20, expected.tm_mday );
  ASSERT_EQ( 4-1, expected.tm_mon );
  ASSERT_EQ( 2012-1900, expected.tm_year );
}

TEST_F( DateUtilitiesTests, ComparesCorrectly )
{
  struct tm date;
  time_t t_may_5 = createDate(date, 2012, 5, 5);
  time_t t_may_6 = createDate(date, 2012, 5, 6);

  ASSERT_GT( (double) 0, difftime(t_may_5, t_may_6) );
  ASSERT_LT( (double) 0, difftime(t_may_6, t_may_5) );
  ASSERT_EQ( (double) 0, difftime(t_may_5, t_may_5) );
  ASSERT_EQ( (double) 0, difftime(t_may_6, t_may_6) );
}

