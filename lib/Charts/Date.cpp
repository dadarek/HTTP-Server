#include "Date.h"
#include <cstring>
#include <cstdio>

Date::Date()
{
  time_t t = time(0);
  struct tm* now = localtime( &t );

  init( now->tm_year + 1900, now->tm_mon + 1, now->tm_mday );
}

Date::Date( const char* date )
{
  int year, month, day;
  sscanf( date, "%d-%d-%d", &year, &month, &day );

  init( year, month, day );
}

Date::Date( int year, int month, int day )
{
  init( year, month, day );
}

Date::~Date()
{ }

bool Date::operator==( const Date& other ) const
{
  const struct tm& date1 = this->date_;
  const struct tm& date2 = other.date_;

  return date1.tm_year == date2.tm_year
    && date1.tm_mon == date2.tm_mon
    && date1.tm_mday == date2.tm_mday;
}

bool Date::operator!=( const Date& other ) const
{
  return !(*this == other);
}

int Date::year() const
{
  return date_.tm_year + 1900;
}

int Date::month() const
{
  return date_.tm_mon + 1;
}

int Date::day() const
{
  return date_.tm_mday;
}

void Date::addDays( int days )
{
  date_.tm_mday += days;
  mktime( &date_ );
}

void Date::init( int year, int month, int day )
{
  memset( &date_, 0, sizeof(date_) );

  date_.tm_year = year - 1900;
  date_.tm_mon = month - 1;
  date_.tm_mday = day;

  mktime( &date_ );
}