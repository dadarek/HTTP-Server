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
    int bind( int socketFD, struct sockaddr* serverAddress, size_t serverAddressSize );
    void listen( int socketFD );
    int accept( int socketFD, struct sockaddr* clientAddress, socklen_t* clientAddressSize );
    void close( int socketFD );
};

#endif
