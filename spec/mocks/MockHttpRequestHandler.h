#ifndef MOCK_HTTP_REQUEST_HANDLER_H
#define MOCK_HTTP_REQUEST_HANDLER_H

#include "HttpRequestHandler.h"

class MockHttpRequestHandler
  : public HttpRequestHandler
{
  public:
    HttpRequest* requestReceived_;
    HttpResponse* handleReturnValue_;

    MockHttpRequestHandler();
    virtual ~MockHttpRequestHandler();

    HttpResponse* handle( HttpRequest& request);
};

#endif
