#ifndef MOCK_HTTP_REQUEST_PARSER_H
#define MOCK_HTTP_REQUEST_PARSER_H

#include "HttpRequestParser.h"

class MockHttpRequestParser
  : public HttpRequestParser
{
  public:
    std::string stringToParse_;
    HttpRequest* parseReturnValue_;

    MockHttpRequestParser();
    virtual ~MockHttpRequestParser();

    HttpRequest* parse( std::string );
};

#endif
