#include "SocketBindException.h"

SocketBindException::SocketBindException()
  : std::runtime_error( "Error binding to socket." )
{ }

SocketBindException::~SocketBindException() throw()
{ }
