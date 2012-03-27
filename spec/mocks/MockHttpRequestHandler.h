#ifndef MOCK_HTTP_REQUEST_HANDLER_H
#define MOCK_HTTP_REQUEST_HANDLER_H

#include "HttpRequestHandler.h"

class MockHttpRequestHandler
  : public HttpRequestHandler
{
  public:
    MockHttpRequestHandler();
    virtual ~MockHttpRequestHandler();

    HttpResponse* handle( HttpRequest& request);
};

#endif
