#ifndef DATE_UTILITIES_H
#define DATE_UTILITIES_H

#include <string>
#include <ctime>

class DateUtilities
{
  private:
    DateUtilities();
    virtual ~DateUtilities();

  public:
    static struct tm parse( std::string );
    static bool equal( const struct tm& date1, const struct tm& date2 );
};

#endif
