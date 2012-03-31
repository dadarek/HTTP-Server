#ifndef SOCKET_CREATE_EXCEPTION_H
#define SOCKET_CREATE_EXCEPTION_H

#include <stdexcept>

class SocketCreateException
  : public std::runtime_error
{
  public:
    SocketCreateException();
    virtual ~SocketCreateException() throw();
};

#endif
