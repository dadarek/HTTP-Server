#ifndef HTTP_DIRECTORY_LIST_REQUEST_HANDLER_H
#define HTTP_DIRECTORY_LIST_REQUEST_HANDLER_H

#include "HttpRequestHandler.h"

class DirectoryApi;

class HttpDirectoryListRequestHandler
  : public HttpRequestHandler
{
  private:
    DirectoryApi& directoryApi_;

  public:
    HttpDirectoryListRequestHandler( DirectoryApi& directoryApi_ );
    virtual ~HttpDirectoryListRequestHandler();

    HttpResponse* handle( HttpRequest& request );
};

#endif
