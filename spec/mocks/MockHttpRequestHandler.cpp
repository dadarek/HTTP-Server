#include "MockHttpRequestHandler.h"

MockHttpRequestHandler::MockHttpRequestHandler()
  : requestReceived_( 0 )
{ }

MockHttpRequestHandler::~MockHttpRequestHandler()
{ }

HttpResponse* MockHttpRequestHandler::handle( HttpRequest& request )
{
  requestReceived_ = &request;
  return handleReturnValue_;
}


