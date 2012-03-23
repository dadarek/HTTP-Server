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
    ~MockSocketReadApi();

    int socket();
    int bind( int socketFD, int portNumber );
    void listen( int socketFD );
    int accept( int socketFD );
    void close( int socketFD );

    int read( int socketFD, char* buffer, int bufferSize );
    int write( int socketFD, char* buffer, unsigned length );
};

#endif
