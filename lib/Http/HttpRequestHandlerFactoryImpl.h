#ifndef HTTP_REQUEST_HANDLER_FACTORY_IMPL
#define HTTP_REQUEST_HANDLER_FACTORY_IMPL

#include "HttpRequestHandlerFactory.h"

class HttpRequestHandlerFactoryImpl
  : public HttpRequestHandlerFactory
{
  public:
    HttpRequestHandlerFactoryImpl();
    virtual ~HttpRequestHandlerFactoryImpl();

    HttpRequestHandler* createHandler( HttpRequest& request );
};

#endif
