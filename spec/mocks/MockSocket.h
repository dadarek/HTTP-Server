#ifndef MOCK_SOCKET_H
#define MOCK_SOCKET_H

#include "Socket.h"

class MockSocket
  : public Socket
{
  public:
    int socketsCreated_;
    int socketReturnValue_;
    int acceptReturnValue_;
    int boundTo_;
    bool returnErrorOnSocket_;
    bool returnErrorOnBind_;
    bool returnErrorOnAccept_;
    bool* destructorCalled_;
    int socketClosed_;
    int listeningTo_;
    int boundToPort_;
    int socketFDPassedIntoAccept_; 

    MockSocket( int socketReturnValue, int acceptReturnValue );
    virtual ~MockSocket();

    int socket();
    int bind( int socketFD, int portNumber );
    void listen( int socketFD );
    int accept( int socketFD );
    void close( int socketFD );
};

#endif
