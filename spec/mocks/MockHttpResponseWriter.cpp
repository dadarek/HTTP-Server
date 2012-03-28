#include "MockHttpResponseWriter.h"

MockHttpResponseWriter::MockHttpResponseWriter()
  : responseReceived_( 0 )
{ }

MockHttpResponseWriter::~MockHttpResponseWriter()
{ }

void MockHttpResponseWriter::write( HttpResponse& response )
{
  responseReceived_ = &response;
}
