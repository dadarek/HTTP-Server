#include "DateUtilities.h"

struct tm DateUtilities::parse( std::string dateString )
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

bool DateUtilities::equal(const struct tm& date1, const struct tm& date2 )
{
  return date1.tm_year == date2.tm_year
    && date1.tm_mon == date2.tm_mon
    && date1.tm_mday == date2.tm_mday;
}
