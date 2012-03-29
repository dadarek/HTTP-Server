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
  socketApi_.write( socketFD, response.body().c_str(), -1 );
}
