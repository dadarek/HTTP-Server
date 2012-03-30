#ifndef HTTP_REQUEST_HANDLER_FACTORY_IMPL
#define HTTP_REQUEST_HANDLER_FACTORY_IMPL

#include "HttpRequestHandlerFactory.h"

class FileApi;

class HttpRequestHandlerFactoryImpl
  : public HttpRequestHandlerFactory
{
  private:
    FileApi& fileApi_;

  public:
    HttpRequestHandlerFactoryImpl( FileApi& fileApi );
    virtual ~HttpRequestHandlerFactoryImpl();

    HttpRequestHandler* createHandler( HttpRequest& request );
};

#endif
