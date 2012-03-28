#ifndef MOCK_HTTP_REQUEST_HANDLER_H
#define MOCK_HTTP_REQUEST_HANDLER_H

#include "HttpRequestHandler.h"

struct HttpConnectionHandlerInspector;

class MockHttpRequestHandler
  : public HttpRequestHandler
{
  private:
    HttpConnectionHandlerInspector& inspector_;

  public:
    HttpRequest* requestReceived_;
    HttpResponse* handleReturnValue_;

    MockHttpRequestHandler( HttpConnectionHandlerInspector& inspector );
    virtual ~MockHttpRequestHandler();

    HttpResponse* handle( HttpRequest& request);
};

#endif
