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
  std::string header("HTTP/1.1 ");

  write( socketFD, header.c_str(), header.length() );
  write( socketFD, response.status().c_str(), response.status().length() );
  write( socketFD, "\r\n\r\n", 4 );
  write( socketFD, response.body(), response.bodyLength() );

  socketApi_.close( socketFD );
}

void HttpResponseSocketWriter::write( int socketFD, const char* content, size_t length )
{
  int written = socketApi_.write( socketFD, content, length );
  if( written < 0 )
    throw SocketWriteException();
}
