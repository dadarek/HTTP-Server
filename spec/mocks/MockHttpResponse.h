#ifndef MOCK_HTTP_RESPONSE_H
#define MOCK_HTTP_RESPONSE_H

#include "HttpResponse.h"

struct HttpResponseInspector
{
  bool destroyed;
  HttpResponseInspector()
    : destroyed( false )
  { }
};

class MockHttpResponse
  : public HttpResponse
{
  private:
    HttpResponseInspector& inspector_;

  public:
    MockHttpResponse( HttpResponseInspector& inspector );
    virtual ~MockHttpResponse();

};

#endif
