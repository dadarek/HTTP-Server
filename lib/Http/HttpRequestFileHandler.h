#ifndef HTTP_REQUEST_FILE_HANDLER_H
#define HTTP_REQUEST_FILE_HANDLER_H

#include "HttpRequestHandler.h"

class HttpRequestFileHandler
  : public HttpRequestHandler
{
  public:
    HttpRequestFileHandler();
    virtual ~HttpRequestFileHandler();

    HttpResponse* handle( HttpRequest& request);

};
#endif
