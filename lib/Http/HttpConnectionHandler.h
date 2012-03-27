#ifndef HTTP_CONNECTION_HANDLER_H
#define HTTP_CONNECTION_HANDLER_H

#include "RequestHandler.h"

class SocketReader;
class HttpRequestHandlerFactory;

class HttpConnectionHandler
  : public RequestHandler
{
  private:
    SocketReader& socketReader_;
    HttpRequestHandlerFactory& factory_;

  public:
    HttpConnectionHandler( SocketReader& socketReader, HttpRequestHandlerFactory& factory );
    virtual ~HttpConnectionHandler();

    void handle( int connection );
};

#endif

