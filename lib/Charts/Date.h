#ifndef DATE_H
#define DATE_H

#include <string>
#include <ctime>

class Date
{
  private:
    struct tm date_;

  public:
    Date( const char* );
    virtual ~Date();

    int year();
    int month();
    int day();

    static struct tm parse( std::string );
    static bool equal( const struct tm& date1, const struct tm& date2 );
};

#endif
