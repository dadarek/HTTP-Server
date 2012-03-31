#ifndef SOCKET_ACCEPT_EXCEPTION_H
#define SOCKET_ACCEPT_EXCEPTION_H

#include <stdexcept>

class SocketAcceptException
  : public std::runtime_error
{
  public:
    SocketAcceptException();
    virtual ~SocketAcceptException() throw();
};

#endif
