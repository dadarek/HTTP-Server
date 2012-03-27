#ifndef HTTP_REQUEST_HANDLER_H
#define HTTP_REQUEST_HANDLER_H

class HttpResponse;
class HttpRequest;

class HttpRequestHandler
{
  public:
    virtual ~HttpRequestHandler() { }

    virtual HttpResponse* handle( HttpRequest& request ) = 0;
};

#endif
