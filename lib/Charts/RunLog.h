#ifndef RUN_LOG_H
#define RUN_LOG_H

#include "Date.h"

struct RunLog
{
  Date dateRan;
  int timeRan;

  RunLog( const char* dateRan, int timeRan )
    : dateRan( dateRan )
    , timeRan( timeRan )
  { }
};

#endif
