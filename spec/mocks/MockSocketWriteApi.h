#ifndef MOCK_SOCKET_WRITE_API_H
#define MOCK_SOCKET_WRITE_API_H

#include <sstream>
#include "SocketApi.h"

class MockSocketWriteApi
  : public SocketApi
{
  public:
    int socketWrittenTo_;
    char* whatWasWritten_;
    unsigned howMuchWasClaimedToBeWritten_;
    int whatToReturn_;
    bool returnError_;
    int socketClosed_;

    MockSocketWriteApi();
    virtual ~MockSocketWriteApi();

    int socket();
    int bind( int socketFD, struct sockaddr* serverAddress, size_t serverAddressSize );
    void listen( int socketFD );
    int accept( int socketFD, struct sockaddr* clientAddress, socklen_t* clientAddressSize );
    void close( int socketFD );

    int read( int socketFD, char* buffer, unsigned bufferSize );
    int write( int socketFD, const char* buffer, unsigned length );
};

#endif
