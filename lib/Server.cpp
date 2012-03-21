#include "Server.h"
#include "RequestHandler.h"
#include "PortListener.h"

Server::Server( PortListener* listener, RequestHandler* handler )
  : handler_( handler )
  , listener_( listener )
{ }

void Server::start()
{
  while( listener_->listen() )
  {
    handler_->handle();
  }
}

Server::~Server()
{ }

