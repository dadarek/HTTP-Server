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

  std::string nextChunk;
  do
  {
    nextChunk = getNextChunk( socketFD );
    result += nextChunk;
  }
  while( nextChunk != "" );

  return result;
}

std::string SocketReader::getNextChunk( int socketFD )
{
  char buffer[ 256 ] ;
  size_t bufferSize = sizeof( buffer );

  memset( buffer, 0, bufferSize );

  size_t charSize = sizeof( char );
  size_t bytesToRead = bufferSize - charSize;
  
  int bytesRead = socketApi_->read( socketFD, buffer, bytesToRead );
  if( bytesRead < 0 )
    throw SocketReader::READ_EXCEPTION;

  return std::string( buffer );
}
