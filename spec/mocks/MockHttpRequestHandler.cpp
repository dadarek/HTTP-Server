#include "MockHttpRequestHandler.h"
#include "HttpConnectionHandlerInspector.h"
#include "stdexcept"

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
  if( inspector_.requestDestroyed )
    throw std::runtime_error(" Cannot handle a destroyed request. ");

  requestReceived_ = &request;
  return handleReturnValue_;
}


