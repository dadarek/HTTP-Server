#ifndef MOCK_HTTP_RESPONSE_H
#define MOCK_HTTP_RESPONSE_H

#include "HttpResponse.h"

class HttpConnectionHandlerInspector;

class MockHttpResponse
  : public HttpResponse
{
  private:
    HttpConnectionHandlerInspector& inspector_;

  public:
    MockHttpResponse( HttpConnectionHandlerInspector& inspector );
    virtual ~MockHttpResponse();

};

#endif
