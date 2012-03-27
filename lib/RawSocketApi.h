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
    int bind( int socketFD, int portNumber );
    void listen( int socketFD );
    int accept( int socketFD );
    void close( int socketFD );

    int read( int socketFD, char* buffer, unsigned bufferSize );
    int write( int socketFD, char* buffer, unsigned length );
};

#endif
