#include "MockRequestHandler.h"

MockRequestHandler::MockRequestHandler()
  : connectionHandled_( -1 )
{ }

MockRequestHandler::~MockRequestHandler()
{ } 

void MockRequestHandler::handle( int connection )
{
  connectionHandled_ = connection;
}

