#ifndef SOCKET_WRITE_EXCEPTION_H
#define SOCKET_WRITE_EXCEPTION_H

#include <stdexcept>

class SocketWriteException
  : public std::runtime_error
{
  public:
    SocketWriteException();
    virtual ~SocketWriteException() throw();
};

#endif
