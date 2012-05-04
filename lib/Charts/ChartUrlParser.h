#ifndef CHART_URL_PARSER_H
#define CHART_URL_PARSER_H

#include <string>

class ChartUrlParser
{
  public:
    ChartUrlParser();
    virtual ~ChartUrlParser();

    std::string parseDate( std::string json );
};

#endif
