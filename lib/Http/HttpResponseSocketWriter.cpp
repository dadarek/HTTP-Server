#include "HttpResponseSocketWriter.h"
#include "SocketApi.h"
#include "HttpResponse.h"

HttpResponseSocketWriter::HttpResponseSocketWriter( SocketApi& socketApi )
  : socketApi_( socketApi )
{ }

HttpResponseSocketWriter::~HttpResponseSocketWriter()
{ }

void HttpResponseSocketWriter::write( int socketFD, HttpResponse& response )
{
  const char* body = response.body().c_str();
  unsigned length = strlen( body );
  socketApi_.write( socketFD, body, length );
}
