#include "RunLog.h"

RunLog::RunLog( const Date& dateRan, int timeRan )
  : dateRan_( dateRan )
  , timeRan_( timeRan )
{ }

RunLog::RunLog( const char* dateRan, int timeRan )
  : dateRan_( dateRan )
  , timeRan_( timeRan )
{ }

RunLog::~RunLog()
{ }

bool RunLog::operator==( const RunLog& other ) const
{
  return dateRan_ == other.dateRan_
    && timeRan_ == other.timeRan_;
}

const Date& RunLog::dateRan() const
{
  return dateRan_;
}

int RunLog::timeRan() const
{
  return timeRan_;
}

