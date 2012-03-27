#include "MockHttpRequestHandlerFactory.h"

MockHttpRequestHandlerFactory::MockHttpRequestHandlerFactory()
{ }

MockHttpRequestHandlerFactory::~MockHttpRequestHandlerFactory()
{ }

HttpRequestHandler* MockHttpRequestHandlerFactory::createHandler( HttpRequest& )
{
  throw 0;
}
