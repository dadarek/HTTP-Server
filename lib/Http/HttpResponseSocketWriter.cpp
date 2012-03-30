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
  const char* body = response.body().c_str();
  unsigned length = strlen( body );

  int written = socketApi_.write( socketFD, body, length );
  if( written < 0 )
    throw SocketWriteException();

  socketApi_.close( socketFD );
}
