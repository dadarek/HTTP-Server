#include "MockHttpResponseWriter.h"
#include "HttpConnectionHandlerInspector.h"
#include "stdexcept"

MockHttpResponseWriter::MockHttpResponseWriter( HttpConnectionHandlerInspector& inspector )
  : inspector_( inspector )
  , responseReceived_( 0 )
{ }

MockHttpResponseWriter::~MockHttpResponseWriter()
{ }

void MockHttpResponseWriter::write( HttpResponse& response )
{
  if( inspector_.responseDestroyed )
    throw std::runtime_error(" Cannot write a destroyed response. ");

  responseReceived_ = &response;
}
