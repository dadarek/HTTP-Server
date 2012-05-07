#include "Date.h"
#include <cstring>
#include <cstdio>

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
  return !(this == &other);
}

bool Date::operator>( const Date& other ) const
{
  return this->day() > other.day();
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
