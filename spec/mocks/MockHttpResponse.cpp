#include "MockHttpResponse.h"
#include "HttpConnectionHandlerInspector.h"

MockHttpResponse::MockHttpResponse( HttpConnectionHandlerInspector& inspector )
  : HttpResponse( "" )
  , inspector_( inspector )
{ }

MockHttpResponse::~MockHttpResponse()
{
  inspector_.responseDestroyed = true;
}
