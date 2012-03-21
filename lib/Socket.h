#ifndef SOCKET_H
#define SOCKET_H

#include <sys/socket.h>

class Socket
{
  private:
    struct sockaddr a;

  public:
    Socket() { }
    virtual ~Socket() { }

    virtual int socket() = 0;
    virtual int bind( int socketFD, struct sockaddr* serverAddress, size_t serverAddressSize ) = 0;
    virtual void listen( int socketFD ) = 0;
    virtual int accept( int socketFD, struct sockaddr* clientAddress, socklen_t* clientAddressSize ) = 0;
    virtual void close( int socketFD ) = 0;
};

#endif
