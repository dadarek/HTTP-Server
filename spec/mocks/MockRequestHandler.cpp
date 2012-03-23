#include "MockRequestHandler.h"

MockRequestHandler::MockRequestHandler()
{ }

MockRequestHandler::~MockRequestHandler()
{ } 

void MockRequestHandler::handle( int connection )
{
  throw 0;
}

