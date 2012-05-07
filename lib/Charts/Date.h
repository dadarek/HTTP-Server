#ifndef DATE_H
#define DATE_H

#include <ctime>

class Date
{
  private:
    struct tm date_;

  public:
    Date( const char* );
    virtual ~Date();

    bool operator==( const Date& ) const;
    bool operator!=( const Date& ) const;

    int year() const;
    int month() const;
    int day() const;
};

#endif
