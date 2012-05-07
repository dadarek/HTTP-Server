#ifndef DATE_H
#define DATE_H

#include <ctime>

class Date
{
  private:
    struct tm date_;

  public:
    Date();
    Date( const char* );
    Date( int year, int month, int day );
    virtual ~Date();

    bool operator==( const Date& ) const;
    bool operator!=( const Date& ) const;

    int year() const;
    int month() const;
    int day() const;

    void addDays( int );

  private:
    void init( int year, int month, int day );
};

#endif