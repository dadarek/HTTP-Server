#include "ChartUrlParser.h"
#include "RunLog.h"

ChartUrlParser::ChartUrlParser()
{ }

ChartUrlParser::~ChartUrlParser()
{ }

RunLog ChartUrlParser::parse( std::string )
{
  RunLog result;
  result.dateRan = "2012-04-15";
  result.timeRan = "30";

  return result;
}

std::string ChartUrlParser::parseDate( std::string )
{
  return "2012-04-15";
}

std::string ChartUrlParser::parseTime( std::string )
{
  return "30";
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
