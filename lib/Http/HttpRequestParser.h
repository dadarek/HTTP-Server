#ifndef HTTP_REQUEST_PARSER_H
#define HTTP_REQUEST_PARSER_H

#include <string>

class HttpRequest;

class HttpRequestParser
{
  public:
    virtual ~HttpRequestParser() { }

    virtual HttpRequest* parse( std::string ) = 0;
};

#endif

