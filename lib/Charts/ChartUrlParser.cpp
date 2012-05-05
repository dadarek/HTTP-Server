#include "ChartUrlParser.h"
#include "RunLog.h"

ChartUrlParser::ChartUrlParser()
{ }

ChartUrlParser::~ChartUrlParser()
{ }

std::vector<RunLog> ChartUrlParser::parse( std::string )
{
  RunLog log;
  log.dateRan = "2012-04-15";
  log.timeRan = "30";

  std::vector<RunLog> result;
  result.push_back(log);

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
