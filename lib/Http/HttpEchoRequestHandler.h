#ifndef HTTP_ECHO_REQUEST_HANDLER_H
#define HTTP_ECHO_REQUEST_HANDLER_H

#include "HttpRequestHandler.h"

class HttpEchoRequestHandler
  : public HttpRequestHandler
{
  public:
    HttpEchoRequestHandler();
    virtual ~HttpEchoRequestHandler();

    HttpResponse* handle( HttpRequest& request );
};

#endif
