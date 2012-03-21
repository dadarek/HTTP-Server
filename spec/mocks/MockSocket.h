#ifndef MOCK_SOCKET_H
#define MOCK_SOCKET_H

#include "Socket.h"

class MockSocket
  : public Socket
{
  public:
    int socketsCreated = 0;

    MockSocket() { }
    virtual ~MockSocket() { }

    int socket();
    int bind( int socketFD, struct sockaddr* serverAddress, size_t serverAddressSize );
    void listen( int socketFD );
    int accept( int socketFD, struct sockaddr* clientAddress, socklen_t* clientAddressSize );
    void close( int socketFD );
};

#endif
