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
  if(json == "%7B") return "{";
  if(json == "%7D") return "}";
  if(json == "%22") return "\"";
  throw 0;
}
