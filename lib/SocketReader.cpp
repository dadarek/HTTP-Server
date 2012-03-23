#include "SocketApi.h"
#include "SocketReader.h"

SocketReader::SocketReader( SocketApi* socketApi )
  : socketApi_( socketApi )
{ }

SocketReader::~SocketReader()
{ }

std::string SocketReader::readToEnd( int socketFD, const char* terminator )
{
  std::string result;

  bool keepReading = true;
  while( keepReading )
  {
    result += getNextChunk( socketFD );

    int terminatorIndex = result.find( terminator );
    if( terminatorIndex >= 0 )
    {
      result = result.substr( 0, terminatorIndex );
      keepReading = false;
    }
  }

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
