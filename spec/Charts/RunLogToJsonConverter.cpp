#include "RunLogToJsonConverter.h"
#include "UrlUtilities.h"

std::string RunLogToJsonConverter::convert( const RunLog& log )
{
  char json[100];
  sprintf( json, "[{\"date_ran\":\"%d-%02d-%02d\",\"time_ran\":\"%d\"}]", log.dateRan().year(), log.dateRan().month(), log.dateRan().day(), log.timeRan() );

  return UrlUtilities::encode( json );
}

std::string RunLogToJsonConverter::convert( const std::vector<RunLog>& logs )
{
  std::string json;

  std::vector<RunLog>::const_iterator start = logs.end();
  std::vector<RunLog>::const_iterator end = logs.end();

  while( start != end )
  {
    json += convert( *start );
    ++start;
  }

  return json;
}
