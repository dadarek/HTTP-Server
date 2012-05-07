#include "ChartUrlParser.h"
#include "UrlUtilities.h"
#include "RunLog.h"

ChartUrlParser::ChartUrlParser()
{ }

ChartUrlParser::~ChartUrlParser()
{ }

std::vector<RunLog> ChartUrlParser::parse( std::string json )
{
  std::vector<RunLog> result;

  const std::string& decodedJson = UrlUtilities::decode( json.c_str() );
  const char* nextBracket = strchr(decodedJson.c_str(), '{');

  while( 0 != nextBracket )
  {
    result.push_back( parseNextLog( nextBracket ) );
    nextBracket = strchr(nextBracket + 1, '{');
  }

  return result;
}

RunLog ChartUrlParser::parseNextLog( const char* bracket )
{
    char dateRan[11];
    int timeRan;
    memset(dateRan, 0, 11);

    const char* pattern = "{\"date_ran\":\"%10s\",\"time_ran\":\"%d\"}";
    sscanf(bracket, pattern, dateRan, &timeRan);

    RunLog log( dateRan, timeRan );
    return log;
}

