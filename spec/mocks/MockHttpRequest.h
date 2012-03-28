#ifndef MOCK_HTTP_REQUEST_H
#define MOCK_HTTP_REQUEST_H

#include "HttpRequest.h"

struct HttpConnectionHandlerInspector;

class MockHttpRequest
  : public HttpRequest
{
  private:
    HttpConnectionHandlerInspector& inspector_;

  public:
    MockHttpRequest( HttpConnectionHandlerInspector& inspector );
    virtual ~MockHttpRequest();

};

#endif
