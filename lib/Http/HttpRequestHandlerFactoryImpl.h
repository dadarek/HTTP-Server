#ifndef HTTP_REQUEST_HANDLER_FACTORY_IMPL
#define HTTP_REQUEST_HANDLER_FACTORY_IMPL

#include <string>
#include "HttpRequestHandlerFactory.h"

class FileApi;
class DirectoryApi;

class HttpRequestHandlerFactoryImpl
  : public HttpRequestHandlerFactory
{
  private:
    std::string basePath_;
    FileApi& fileApi_;
    DirectoryApi& directoryApi_;

  public:
    HttpRequestHandlerFactoryImpl( std::string basePath, FileApi& fileApi, DirectoryApi& directoryApi );
    virtual ~HttpRequestHandlerFactoryImpl();

    HttpRequestHandler* createHandler( HttpRequest& request );

  private:
    bool directoryExists( std::string path );
    bool requiresEcho( HttpRequest& request );
    bool containsQueryString( HttpRequest& request );
};

#endif
