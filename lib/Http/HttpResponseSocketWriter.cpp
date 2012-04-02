#include "HttpResponseSocketWriter.h"
#include "SocketApi.h"
#include "HttpResponse.h"
#include "SocketWriteException.h"

HttpResponseSocketWriter::HttpResponseSocketWriter( SocketApi& socketApi )
  : socketApi_( socketApi )
{ }

HttpResponseSocketWriter::~HttpResponseSocketWriter()
{ }

void HttpResponseSocketWriter::write( int socketFD, HttpResponse& response )
{
  int written = socketApi_.write( socketFD, response.body(), response.bodyLength() );
  if( written < 0 )
    throw SocketWriteException();

  socketApi_.close( socketFD );
}
