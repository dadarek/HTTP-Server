#ifndef SOCKET_BIND_EXCEPTION_H
#define SOCKET_BIND_EXCEPTION_H

#include <stdexcept>

class SocketBindException
  : public std::runtime_error
{
  public:
    SocketBindException();
    virtual ~SocketBindException() throw();
};

#endif
