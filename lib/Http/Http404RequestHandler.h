#ifndef HTTP_404_REQUEST_HANDLER_H
#define HTTP_404_REQUEST_HANDLER_H

#include "HttpRequestHandler.h"

class Http404RequestHandler
  : public HttpRequestHandler
{
  public:
    Http404RequestHandler();
    virtual ~Http404RequestHandler();

    HttpResponse* handle( HttpRequest& request );
};
#endif
