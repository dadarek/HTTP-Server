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
  char buffer[10];
  memset( buffer, 0, 10 );

  socketApi_->read( -1, buffer, 9 );
  return std::string( buffer );
}

