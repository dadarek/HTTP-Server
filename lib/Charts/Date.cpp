#include "Date.h"

Date::Date( const char* date )
{
  memset( &date_, 0, sizeof(date_) );

  int year, month, day;
  sscanf( date, "%d-%d-%d", &year, &month, &day );

  date_.tm_year = year - 1900;
  date_.tm_mon = month - 1;
  date_.tm_mday = day;

  mktime( &date_ );
}

Date::~Date()
{ }

int Date::year()
{
  return date_.tm_year + 1900;
}

int Date::month()
{
  return date_.tm_mon + 1;
}

int Date::day()
{
  return date_.tm_mday;
}

struct tm Date::parse( std::string dateString )
{
  struct tm result;
  memset( &result, 0, sizeof(result) );

  int year, month, day;
  sscanf( dateString.c_str(), "%d-%d-%d", &year, &month, &day );

  result.tm_year = year - 1900;
  result.tm_mon = month - 1;
  result.tm_mday = day;

  mktime( &result );
  return result;
}

bool Date::equal(const struct tm& date1, const struct tm& date2 )
{
  return date1.tm_year == date2.tm_year
    && date1.tm_mon == date2.tm_mon
    && date1.tm_mday == date2.tm_mday;
}
