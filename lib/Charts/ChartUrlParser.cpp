#include "ChartUrlParser.h"
#include "RunLog.h"

ChartUrlParser::ChartUrlParser()
{ }

ChartUrlParser::~ChartUrlParser()
{ }

std::vector<RunLog> ChartUrlParser::parse( std::string json )
{
  std::vector<RunLog> result;

  char dateRan[11];
  int timeRan;
  memset(dateRan, 0, 11);

  const std::string& decodedJson = urlDecode( json );
  const char* nextBracket = strchr(decodedJson.c_str(), '{');

  while( 0 != nextBracket )
  {
    const char* pattern = "{\"date_ran\":\"%10s\",\"time_ran\":\"%d\"}";
    sscanf(nextBracket, pattern, dateRan, &timeRan);

    RunLog log;
    log.dateRan = std::string(dateRan);
    log.timeRan = timeRan;

    result.push_back(log);

    nextBracket = strchr(nextBracket + 1, '{');
  }

  return result;
}

std::string ChartUrlParser::urlDecode( std::string json )
{
  std::string result;

  const char* cJson = json.c_str();

  for(size_t i = 0; i < json.length(); )
  {
    if( isEncoded( cJson[i] ) )
    {
      result += decode(cJson + i);
      i += 3;
    }
    else
    {
      result += cJson[i];
      i++;
    }
  }
  return result;
}

bool ChartUrlParser::isEncoded( char c )
{
  return c == '%';
}

std::string ChartUrlParser::decode( const char* encoded )
{
  std::string nextChar(encoded, 3);
  if(nextChar == "%7B") return "{";
  if(nextChar == "%7D") return "}";
  if(nextChar == "%22") return "\"";
  throw 0;
}
