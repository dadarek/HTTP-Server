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

  char buffer[256];
  memset( buffer, 0, 256 );

  socketApi_->read( -1, buffer, 255 );

  result += buffer;

  return result;
}

