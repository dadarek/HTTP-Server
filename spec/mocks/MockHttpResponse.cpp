#include "MockHttpResponse.h"

MockHttpResponse::MockHttpResponse( HttpResponseInspector& inspector )
  : HttpResponse( "" )
  , inspector_( inspector )
{ }

MockHttpResponse::~MockHttpResponse()
{
  inspector_.destroyed = true;
}
