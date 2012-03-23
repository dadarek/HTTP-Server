#include "Server.h"
#include "RequestHandler.h"
#include "InboundConnectionListener.h"

Server::Server( ConnectionReceiver& receiver, RequestHandler& handler )
  : handler_( handler )
  , receiver_( receiver )
{ }

void Server::start()
{
}

Server::~Server()
{ }

