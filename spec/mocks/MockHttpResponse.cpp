#include "MockHttpResponse.h"
#include "HttpConnectionHandlerInspector.h"

MockHttpResponse::MockHttpResponse( HttpConnectionHandlerInspector& inspector )
  : HttpResponse( "" )
  , inspector_( inspector )
{ }

MockHttpResponse::MockHttpResponse( HttpConnectionHandlerInspector& inspector, const char* body )
  : HttpResponse( body )
  , inspector_( inspector )
{ }

MockHttpResponse::~MockHttpResponse()
{
  inspector_.responseDestroyed = true;
}
