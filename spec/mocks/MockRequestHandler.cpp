#include "MockRequestHandler.h"

MockRequestHandler::MockRequestHandler()
  : index_( 0 )
{ }

MockRequestHandler::~MockRequestHandler()
{ } 

void MockRequestHandler::handle( int connection )
{
  connectionsHandled_[ index_++ ] = connection;
}

