#ifndef HTTP_REQUEST_PARSER_IMPL_H
#define HTTP_REQUEST_PARSER_IMPL_H

#include "HttpRequestParser.h"

class HttpRequestParserImpl
  : public HttpRequestParser
{
  public:
    HttpRequestParserImpl();
    virtual ~HttpRequestParserImpl();

    HttpRequest* parse( std::string request );
};
#endif
