#include "SocketWriteException.h"

SocketWriteException::SocketWriteException()
  : std::runtime_error( "Error writing to socket." )
{ }

SocketWriteException::~SocketWriteException() throw()
{ }
