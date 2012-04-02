#ifndef HTTP_DIRECTORY_LIST_REQUEST_HANDLER_H
#define HTTP_DIRECTORY_LIST_REQUEST_HANDLER_H

#include "HttpRequestHandler.h"

class HttpDirectoryListRequestHandler
  : public HttpRequestHandler
{
  public:
    HttpDirectoryListRequestHandler();
    virtual ~HttpDirectoryListRequestHandler();

    HttpResponse* handle( HttpRequest& request );
};

#endif
