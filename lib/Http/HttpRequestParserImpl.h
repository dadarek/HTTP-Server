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

  private:
    size_t getHttpVersionIndex( std::string request );
    void setBody( std::string request, HttpRequest* request );
};
#endif
