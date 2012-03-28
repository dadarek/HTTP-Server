#ifndef MOCK_HTTP_REQUEST_H
#define MOCK_HTTP_REQUEST_H

#include "HttpRequest.h"

struct HttpRequestInspector
{
  bool destroyed;
  HttpRequestInspector()
    : destroyed( false )
  { }
};

class MockHttpRequest
  : public HttpRequest
{
  private:
    HttpRequestInspector& inspector_;

  public:
    MockHttpRequest( HttpRequestInspector& inspector );
    virtual ~MockHttpRequest();

};

#endif
