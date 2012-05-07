#ifndef RUN_LOG_TO_JSON_CONVERTER_H
#define RUN_LOG_TO_JSON_CONVERTER_H

#include "RunLog.h"
#include <string>
#include <vector>

class RunLogToJsonConverter
{
  public:
    static std::string convert( const RunLog& );
    static std::string convert( const std::vector<RunLog>& );

  private:
    static std::string toJson( const RunLog& );
};

#endif
