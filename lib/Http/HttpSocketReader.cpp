#include "SocketApi.h"
#include "HttpSocketReader.h"
#include "SocketReadException.h"
#include <cstring>

const char* const HttpSocketReader::STREAM_TERMINATOR = "\r\n\r\n";

HttpSocketReader::HttpSocketReader( SocketApi& socketApi )
  : socketApi_( socketApi )
{ }

HttpSocketReader::~HttpSocketReader()
{ }

std::string HttpSocketReader::readToEnd( int socketFD )
{
  return getNextChunk( socketFD );
}

std::string HttpSocketReader::getNextChunk( int socketFD )
{
  char buffer[ 2048 ] ;
  size_t bufferSize = sizeof( buffer );

  memset( buffer, 0, bufferSize );

  size_t charSize = sizeof( char );
  size_t bytesToRead = bufferSize - charSize;
  
  int bytesRead = socketApi_.read( socketFD, buffer, bytesToRead );
  if( bytesRead < 0 )
    throw SocketReadException();

  return std::string( buffer );
}
