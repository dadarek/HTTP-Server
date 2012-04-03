#include "Server.h"
#include "RequestHandler.h"
#include "ConnectionReceiver.h"

#include <iostream>

Server::Server( ConnectionReceiver& receiver, RequestHandler& handler )
  : handler_( handler )
  , receiver_( receiver )
{ }

void Server::start()
{
  for(;;)
  {
    int connectionId = receiver_.nextConnection();
    handler_.handle( connectionId );
  }
}

Server::~Server()
{ }

