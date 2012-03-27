#include "MockSocketReader.h"

MockSocketReader::MockSocketReader()
  : readToEnd_( false )
  , socketFDRead_( -1 )
{ }

MockSocketReader::~MockSocketReader()
{ }

std::string MockSocketReader::readToEnd( int socketFD )
{
  readToEnd_ = true;
  socketFDRead_ = socketFD;

  return readToEndReturnValue_;
}
