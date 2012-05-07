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
};

#endif
