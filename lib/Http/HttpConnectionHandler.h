#ifndef HTTP_CONNECTION_HANDLER_H
#define HTTP_CONNECTION_HANDLER_H

#include "RequestHandler.h"

class SocketApi;

class HttpConnectionHandler
  : public RequestHandler
{
  private:

  public:
    HttpConnectionHandler( );
    ~HttpConnectionHandler();

    void handle( int connection );
};

#endif

