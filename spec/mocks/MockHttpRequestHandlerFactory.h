#ifndef MOCK_HTTP_REQUEST_HANDLER_FACTORY_H
#define MOCK_HTTP_REQUEST_HANDLER_FACTORY_H

#include "HttpRequestHandlerFactory.h"

class MockHttpRequestHandlerFactory
  : public HttpRequestHandlerFactory
{
  public:
    HttpRequest* requestReceived_;
    HttpRequestHandler* createHandlerReturnValue_;

    MockHttpRequestHandlerFactory();
    virtual ~MockHttpRequestHandlerFactory();

    HttpRequestHandler* createHandler( HttpRequest& request );
};

#endif
