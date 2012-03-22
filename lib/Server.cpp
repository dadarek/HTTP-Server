#include "Server.h"
#include "RequestHandler.h"
#include "InboundConnectionListener.h"

Server::Server( InboundConnectionListener* listener, RequestHandler* handler )
  : handler_( handler )
  , listener_( listener )
{ }

void Server::start()
{
}

Server::~Server()
{ }

