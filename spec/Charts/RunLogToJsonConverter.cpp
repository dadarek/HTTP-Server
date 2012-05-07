#include "RunLogToJsonConverter.h"
#include "UrlUtilities.h"

std::string RunLogToJsonConverter::convert( const RunLog& log )
{
  std::string json;
  json += toJson( log );
  json = "[" + json + "]";

  return UrlUtilities::encode( json.c_str() );
}

std::string RunLogToJsonConverter::convert( const std::vector<RunLog>& logs )
{
  std::string json;

  std::vector<RunLog>::const_iterator start = logs.begin();
  std::vector<RunLog>::const_iterator end = logs.end();

  while( start != end )
  {
    json += toJson( *start );
    ++start;
    if( start != end )
      json += ",";
  }

  json = "[" + json + "]";

  return UrlUtilities::encode( json.c_str() );
}

std::string RunLogToJsonConverter::toJson( const RunLog& log )
{
  char json[100];
  sprintf( json, "{\"date_ran\":\"%d-%02d-%02d\",\"time_ran\":%d}", log.dateRan().year(), log.dateRan().month(), log.dateRan().day(), log.timeRan() );

  return std::string( json );
}
