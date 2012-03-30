#ifndef SOCKET_READ_EXCEPTION_H
#define SOCKET_READ_EXCEPTION_H

#include <stdexcept>

class SocketReadException
  : public std::runtime_error
{
  public:
    SocketReadException();
    virtual ~SocketReadException() throw();
};

#endif
