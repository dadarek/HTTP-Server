#include "SocketApi.h"
#include "HttpSocketReader.h"

HttpSocketReader::HttpSocketReader( SocketApi& socketApi )
  : socketApi_( socketApi )
{ }

HttpSocketReader::~HttpSocketReader()
{ }

std::string HttpSocketReader::readToEnd( int socketFD, const char* terminator )
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

std::string HttpSocketReader::getNextChunk( int socketFD )
{
  char buffer[ 256 ] ;
  size_t bufferSize = sizeof( buffer );

  memset( buffer, 0, bufferSize );

  size_t charSize = sizeof( char );
  size_t bytesToRead = bufferSize - charSize;
  
  int bytesRead = socketApi_.read( socketFD, buffer, bytesToRead );
  if( bytesRead < 0 )
    throw HttpSocketReader::READ_EXCEPTION;

  return std::string( buffer );
}
