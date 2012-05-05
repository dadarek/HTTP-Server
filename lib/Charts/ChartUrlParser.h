#ifndef CHART_URL_PARSER_H
#define CHART_URL_PARSER_H

#include <string>
#include <vector>

class RunLog;

class ChartUrlParser
{
  public:
    ChartUrlParser();
    virtual ~ChartUrlParser();

    std::vector<RunLog> parse( std::string json );

  private:
    RunLog parseNextLog( const char* );
};

#endif
