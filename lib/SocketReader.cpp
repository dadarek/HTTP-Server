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
    char buffer[256];
    memset( buffer, 0, 256 );

    bytesRead = socketApi_->read( -1, buffer, 255 );

    result += buffer;
  }
  while( bytesRead == 255 );

  return result;
}

