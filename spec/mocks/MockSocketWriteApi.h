#ifndef MOCK_SOCKET_WRITE_API_H
#define MOCK_SOCKET_WRITE_API_H

#include "SocketApi.h"

class MockSocketWriteApi
  : public SocketApi
{
  public:
    MockSocketWriteApi();
    ~MockSocketWriteApi();

    int socket();
    int bind( int socketFD, int portNumber );
    void listen( int socketFD );
    int accept( int socketFD );
    void close( int socketFD );

    int read( int socketFD, char* buffer, int bufferSize );
    int write( int socketFD, char* buffer, unsigned length );
};

#endif
