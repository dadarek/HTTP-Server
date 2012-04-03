#include "SocketApi.h"
#include "HttpSocketReader.h"
#include "SocketReadException.h"

const char* const HttpSocketReader::STREAM_TERMINATOR = "\r\n\r\n";

HttpSocketReader::HttpSocketReader( SocketApi& socketApi )
  : socketApi_( socketApi )
{ }

HttpSocketReader::~HttpSocketReader()
{ }

std::string HttpSocketReader::readToEnd( int socketFD )
{
  std::string result;

  size_t terminatorIndex;
  std::string bufferData;
  do
  {
    bufferData += getNextChunk( socketFD );
    terminatorIndex = bufferData.find( STREAM_TERMINATOR );
  }while( std::string::npos == terminatorIndex );

  result = bufferData.substr( 0, terminatorIndex );

  return result;
}

std::string HttpSocketReader::getNextChunk( int socketFD )
{
  char buffer[ 1024 ] ;
  size_t bufferSize = sizeof( buffer );

  memset( buffer, 0, bufferSize );

  size_t charSize = sizeof( char );
  size_t bytesToRead = bufferSize - charSize;
  
  int bytesRead = socketApi_.read( socketFD, buffer, bytesToRead );
  if( bytesRead < 0 )
    throw SocketReadException();

  return std::string( buffer );
}
