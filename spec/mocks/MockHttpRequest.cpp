#include "MockHttpRequest.h"
#include "HttpConnectionHandlerInspector.h"

MockHttpRequest::MockHttpRequest( HttpConnectionHandlerInspector& inspector )
  : HttpRequest( "" )
  , inspector_( inspector )
{ }

MockHttpRequest::~MockHttpRequest()
{
  inspector_.requestDestroyed = true;
}
