#include "SocketReadException.h"

SocketReadException::SocketReadException()
  : std::runtime_error( "Error reading socket." )
{ }

SocketReadException::~SocketReadException() throw()
{ }
