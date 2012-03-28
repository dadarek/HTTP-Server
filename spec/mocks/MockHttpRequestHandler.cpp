#include "MockHttpRequestHandler.h"
#include "HttpConnectionHandlerInspector.h"

MockHttpRequestHandler::MockHttpRequestHandler( HttpConnectionHandlerInspector& inspector )
  : inspector_( inspector )
  , requestReceived_( 0 )
{ }

MockHttpRequestHandler::~MockHttpRequestHandler()
{ 
  inspector_.handlerDestroyed = true;
}

HttpResponse* MockHttpRequestHandler::handle( HttpRequest& request )
{
  requestReceived_ = &request;
  return handleReturnValue_;
}


