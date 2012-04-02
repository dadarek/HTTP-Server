#include "MockHttpResponse.h"
#include "HttpConnectionHandlerInspector.h"

MockHttpResponse::MockHttpResponse( HttpConnectionHandlerInspector& inspector )
  : HttpResponse( "", 0, "" )
  , inspector_( inspector )
{ }

MockHttpResponse::MockHttpResponse( HttpConnectionHandlerInspector& inspector, const char* body, size_t bodyLength )
  : HttpResponse( body, bodyLength, "" )
  , inspector_( inspector )
{ }

MockHttpResponse::~MockHttpResponse()
{
  inspector_.responseDestroyed = true;
}
