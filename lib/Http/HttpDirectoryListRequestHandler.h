#ifndef HTTP_DIRECTORY_LIST_REQUEST_HANDLER_H
#define HTTP_DIRECTORY_LIST_REQUEST_HANDLER_H

#include "HttpRequestHandler.h"

class FileApi;

class HttpDirectoryListRequestHandler
  : public HttpRequestHandler
{
  private:
    FileApi& fileApi_;

  public:
    HttpDirectoryListRequestHandler( FileApi& fileApi_ );
    virtual ~HttpDirectoryListRequestHandler();

    HttpResponse* handle( HttpRequest& request );
};

#endif
