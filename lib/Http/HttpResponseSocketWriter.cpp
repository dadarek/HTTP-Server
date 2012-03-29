#include "HttpResponseSocketWriter.h"

HttpResponseSocketWriter::HttpResponseSocketWriter( SocketApi& socketApi )
  : socketApi_( socketApi )
{ }

HttpResponseSocketWriter::~HttpResponseSocketWriter()
{ }

void HttpResponseSocketWriter::write( HttpResponse& response )
{
  socketApi_.write( -1, response.body(), -1 );
}
