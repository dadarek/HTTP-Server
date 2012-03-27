#include "MockHttpRequestHandler.h"

MockHttpRequestHandler::MockHttpRequestHandler()
{ }

MockHttpRequestHandler::~MockHttpRequestHandler()
{ }

HttpResponse* MockHttpRequestHandler::handle( HttpRequest& request )
{
  throw 0;
}


