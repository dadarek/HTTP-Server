#ifndef RAW_SOCKET_API_H
#define RAW_SOCKET_API_H

#include "SocketApi.h"

class RawSocketApi
  : public SocketApi
{
  public:
    RawSocketApi();
    virtual ~RawSocketApi();

    int socket();
    int bind( int socketFD, struct sockaddr* serverAddress, size_t serverAddressSize );
    void listen( int socketFD );
    int accept( int socketFD, struct sockaddr* clientAddress, socklen_t* clientAddressSize );
    void close( int socketFD );

    int read( int socketFD, char* buffer, unsigned bufferSize );
    int write( int socketFD, const char* buffer, unsigned length );
};

#endif
