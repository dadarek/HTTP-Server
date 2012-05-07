#ifndef RUN_LOG_H
#define RUN_LOG_H

#include "Date.h"

class RunLog
{
  private:
    Date dateRan_;
    int timeRan_;

  public:
    RunLog( const Date& dateRan, int timeRan );
    RunLog( const char* dateRan, int timeRan );
    virtual ~RunLog();

    bool operator==( const RunLog& other ) const;

    const Date& dateRan() const;
    int timeRan() const;
};

#endif
