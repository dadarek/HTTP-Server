#include "SocketAcceptException.h"

SocketAcceptException::SocketAcceptException()
  : std::runtime_error( "Error accepting next incoming connection on socket." )
{ }

SocketAcceptException::~SocketAcceptException() throw()
{ }
