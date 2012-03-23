#include <iostream>
#include "SocketApi.h"
#include "SocketReader.h"

SocketReader::SocketReader( SocketApi* socketApi )
  : socketApi_( socketApi )
{ }

SocketReader::~SocketReader()
{ }

std::string SocketReader::readToEnd( int socketFD )
{
  std::string result;

  int bytesRead;
  do
  {
    char buffer[ 256 ] ;
    size_t bufferSize = sizeof( buffer );

    memset( buffer, 0, bufferSize );

    size_t charSize = sizeof( char );
    size_t bytesToRead = bufferSize - charSize;
    
    bytesRead = socketApi_->read( -1, buffer, bytesToRead );

    result += buffer;
  }
  while( bytesRead > 0 );

  return result;
}

