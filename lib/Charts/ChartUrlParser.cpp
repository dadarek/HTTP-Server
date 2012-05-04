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

  for(size_t i = 0; i < json.length(); i += 3)
  {
    std::string nextChar = json.substr(i, 3);

    if(nextChar == "%7B") result += "{";
    if(nextChar == "%7D") result += "}";
    if(nextChar == "%22") result += "\"";
  }
  return result;
}
