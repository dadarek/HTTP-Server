#ifndef ECHO_REQUEST_HANDLER_H
#define ECHO_REQUEST_HANDLER_H

#include "RequestHandler.h"

class SocketApi;

class EchoRequestHandler
  : public RequestHandler
{
  private:
    SocketApi* socketApi_;

  public:
    EchoRequestHandler( SocketApi* socketApi );
    ~EchoRequestHandler();

    void handle( int connection );
};

#endif

