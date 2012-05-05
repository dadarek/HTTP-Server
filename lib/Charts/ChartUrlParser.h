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
    std::string urlDecode( std::string json );

  private:
    bool isEncoded( char );
    std::string decode( const char* );
};

#endif
