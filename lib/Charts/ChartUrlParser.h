#ifndef CHART_URL_PARSER_H
#define CHART_URL_PARSER_H

#include <string>

class ChartUrlParser
{
  public:
    ChartUrlParser();
    virtual ~ChartUrlParser();

    std::string parseDate( std::string json );
    std::string parseTime( std::string json );

    std::string urlDecode( std::string json );

  private:
    bool isEncoded( char );
    std::string decode( const char* );
};

#endif
