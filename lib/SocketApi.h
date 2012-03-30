#ifndef SOCKET_API_H
#define SOCKET_API_H

#include <netinet/in.h>

class SocketApi
{
  public:
    static const int SOCKET_EXCEPTION = 1;
    static const int BIND_EXCEPTION = 2;
    static const int ACCEPT_EXCEPTION = 3;

  public:
    virtual ~SocketApi() { }

    virtual int socket() = 0;
    virtual int bind( int socketFD, struct sockaddr* serverAddress, size_t serverAddressSize ) = 0;
    virtual void listen( int socketFD ) = 0;
    virtual int accept( int socketFD, struct sockaddr* clientAddress, socklen_t* clientAddressSize ) = 0;
    virtual void close( int socketFD ) = 0;

    virtual int read( int socketFD, char* buffer, unsigned bufferSize ) = 0;
    virtual int write( int socketFD, const char* buffer, unsigned length ) = 0;
};

#endif
