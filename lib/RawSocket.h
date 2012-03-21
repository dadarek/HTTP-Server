#ifndef RAW_SOCKET_H
#define RAW_SOCKET_H

#include "Socket.h"

class RawSocket
  : public Socket
{
  public:
    RawSocket();
    virtual ~RawSocket();

    int socket();
    int bind( int socketFD, int portNumber );
    void listen( int socketFD );
    int accept( int socketFD );
    void close( int socketFD );
};

#endif
