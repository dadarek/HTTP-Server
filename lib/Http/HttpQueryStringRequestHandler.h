#ifndef HTTP_QUERY_STRING_REQUEST_HANDLER_H
#define HTTP_QUERY_STRING_REQUEST_HANDLER_H

#include "HttpRequestHandler.h"

class HttpQueryStringRequestHandler
  : public HttpRequestHandler
{
  public:
    HttpQueryStringRequestHandler();
    virtual ~HttpQueryStringRequestHandler();

    HttpResponse* handle( HttpRequest& request );

};

#endif
