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

  int written = socketApi_.write( socketFD, header.c_str(), header.length() );
  if( written < 0 )
    throw SocketWriteException();

  written = socketApi_.write( socketFD, response.status().c_str(), response.status().length() );
  if( written < 0 )
    throw SocketWriteException();

  written = socketApi_.write( socketFD, "\r\n\r\n", 4 );
  if( written < 0 )
    throw SocketWriteException();

  written = socketApi_.write( socketFD, response.body(), response.bodyLength() );
  if( written < 0 )
    throw SocketWriteException();

  socketApi_.close( socketFD );
}
