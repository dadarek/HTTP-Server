#ifndef HTTP_REQUEST_PARSER_H
#define HTTP_REQUEST_PARSER_H

#include <iostream>

class HttpRequest;

class HttpRequestParser
{
  public:
    const static int INVALID_HEADERS_EXCEPTION = 1;

    HttpRequestParser();
    ~HttpRequestParser();

    HttpRequest* parse( std::string );
};

#endif

