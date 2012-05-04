#include "ChartUrlParser.h"

ChartUrlParser::ChartUrlParser()
{ }

ChartUrlParser::~ChartUrlParser()
{ }

std::string ChartUrlParser::parseDate( std::string json )
{
  return "2012-04-15";
}

std::string ChartUrlParser::parseTime( std::string json )
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
      std::string nextChar(cJson, i, 3);
      if(nextChar == "%7B") result += "{";
      if(nextChar == "%7D") result += "}";
      if(nextChar == "%22") result += "\"";

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

std::string decode( const char* encoded )
{
  std::string nextChar(encoded, 3);
  if(nextChar == "%7B") return "{";
  if(nextChar == "%7D") return "}";
  if(nextChar == "%22") return "\"";
  throw 0;
}
