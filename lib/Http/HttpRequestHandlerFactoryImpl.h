#ifndef HTTP_REQUEST_HANDLER_FACTORY_IMPL
#define HTTP_REQUEST_HANDLER_FACTORY_IMPL

#include <string>
#include "HttpRequestHandlerFactory.h"

class FileApi;

class HttpRequestHandlerFactoryImpl
  : public HttpRequestHandlerFactory
{
  private:
    std::string basePath_;
    FileApi& fileApi_;

  public:
    HttpRequestHandlerFactoryImpl( std::string basePath, FileApi& fileApi );
    virtual ~HttpRequestHandlerFactoryImpl();

    HttpRequestHandler* createHandler( HttpRequest& request );

  private:
    HttpRequestHandler* createFileHandler();
    HttpRequestHandler* create404Handler();
};

#endif
