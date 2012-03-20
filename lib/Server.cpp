#include "Server.h"
#include "RequestHandler.h"

Server::Server( RequestHandler* handler )
  : handler_( handler )
{ }

void Server::start()
{
  handler_->handle();
}

Server::~Server()
{ }

