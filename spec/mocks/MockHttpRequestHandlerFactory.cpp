#include "MockHttpRequestHandlerFactory.h"

MockHttpRequestHandlerFactory::MockHttpRequestHandlerFactory()
  : requestReceived_( 0 )
  , createHandlerReturnValue_( 0 )
{ }

MockHttpRequestHandlerFactory::~MockHttpRequestHandlerFactory()
{ }

HttpRequestHandler* MockHttpRequestHandlerFactory::createHandler( HttpRequest& request )
{
  requestReceived_ = &request;
  return createHandlerReturnValue_;
}
