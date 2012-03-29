#ifndef MOCK_SOCKET_READ_API_H
#define MOCK_SOCKET_READ_API_H

#include "SocketApi.h"

class MockSocketReadApi
  : public SocketApi
{
  public:
    const char* sourceBuffer_;
    int lastReadPosition_;
    bool returnErrorOnRead_;
    int socketReadOn_;

    MockSocketReadApi();
    virtual ~MockSocketReadApi();

    int socket();
    int bind( int socketFD, struct sockaddr* serverAddress, size_t serverAddressSize );
    void listen( int socketFD );
    int accept( int socketFD, struct sockaddr* clientAddress, socklen_t* clientAddressSize );
    void close( int socketFD );

    int read( int socketFD, char* buffer, unsigned bufferSize );
    int write( int socketFD, const char* buffer, unsigned length );
};

#endif
