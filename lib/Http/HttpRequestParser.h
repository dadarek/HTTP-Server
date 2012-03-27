#ifndef HTTP_REQUEST_PARSER_H
#define HTTP_REQUEST_PARSER_H

#include <iostream>

class HttpRequest;

class HttpRequestParser
{
  public:
    HttpRequestParser();
    ~HttpRequestParser();

    HttpRequest* parse( std::string );
};

#endif

