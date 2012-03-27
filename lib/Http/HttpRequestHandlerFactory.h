#ifndef HTTP_REQUEST_HANDLER_FACTORY_H
#define HTTP_REQUEST_HANDLER_FACTORY_H

class HttpRequest;
class HttpRequestHandler;

class HttpRequestHandlerFactory
{
  public:
    virtual ~HttpRequestHandlerFactory() { }

    HttpRequestHandler* createHandler( HttpRequest& request );
};

#endif
