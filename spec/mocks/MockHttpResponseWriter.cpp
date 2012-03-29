#include "MockHttpResponseWriter.h"
#include "HttpConnectionHandlerInspector.h"
#include "stdexcept"

MockHttpResponseWriter::MockHttpResponseWriter( HttpConnectionHandlerInspector& inspector )
  : inspector_( inspector )
  , responseReceived_( 0 )
  , socketFDReceived_( -1 )
{ }

MockHttpResponseWriter::~MockHttpResponseWriter()
{ }

void MockHttpResponseWriter::write( int socketFD, HttpResponse& response )
{
  if( inspector_.responseDestroyed )
    throw std::runtime_error(" Cannot write a destroyed response. ");

  socketFDReceived_ = socketFD;
  responseReceived_ = &response;
}
