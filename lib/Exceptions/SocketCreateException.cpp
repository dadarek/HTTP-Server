#include "SocketCreateException.h"

SocketCreateException::SocketCreateException()
  : std::runtime_error( "Error creating socket." )
{ }

SocketCreateException::~SocketCreateException() throw()
{ }
