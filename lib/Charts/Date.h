#ifndef DATE_H
#define DATE_H

#include <string>
#include <ctime>

class Date
{
  private:
    Date();
    virtual ~Date();

  public:
    static struct tm parse( std::string );
    static bool equal( const struct tm& date1, const struct tm& date2 );
};

#endif
