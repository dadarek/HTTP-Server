#include "EchoRequestHandler.h"
#include "SocketApi.h"

EchoRequestHandler::EchoRequestHandler( SocketApi* socketApi )
  : socketApi_( socketApi )
{ 
}

EchoRequestHandler::~EchoRequestHandler()
{
}  

void EchoRequestHandler::handle( int connection )
{ }
