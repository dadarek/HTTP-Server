#include "MockHttpRequest.h"

MockHttpRequest::MockHttpRequest( HttpRequestInspector& inspector )
  : HttpRequest( "" )
  , inspector_( inspector )
{ }

MockHttpRequest::~MockHttpRequest()
{
  inspector_.destroyed = true;
}
