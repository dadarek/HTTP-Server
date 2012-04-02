#ifndef HTTP_DIRECTORY_LIST_REQUEST_HANDLER_H
#define HTTP_DIRECTORY_LIST_REQUEST_HANDLER_H

#include <string>
#include "HttpRequestHandler.h"

class DirectoryApi;

class HttpDirectoryListRequestHandler
  : public HttpRequestHandler
{
  private:
    std::string basePath_;
    DirectoryApi& directoryApi_;

  public:
    HttpDirectoryListRequestHandler( std::string basePath, DirectoryApi& directoryApi_ );
    virtual ~HttpDirectoryListRequestHandler();

    HttpResponse* handle( HttpRequest& request );

  private:
    std::string getBody( const char* folder );
};

#endif
