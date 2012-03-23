#ifndef SOCKET_WRITER_H
#define SOCKET_WRITER_H

#include <iostream>

class SocketApi;

class SocketWriter
{
  public:
    static const int READ_EXCEPTION = 1;

  private:
    SocketApi& socketApi_;

  public:
    SocketWriter( SocketApi& socketApi_ );
    virtual ~SocketWriter();
};

#endif
