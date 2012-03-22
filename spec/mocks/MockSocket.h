#ifndef MOCK_SOCKET_H
#define MOCK_SOCKET_H

#include "Socket.h"

struct MockSocketReturnValues
{
  int socket;
  int accept;
};

class MockSocket
  : public Socket
{
  public:
    MockSocketReturnValues& returnValues_;
    int socketsCreated_;
    int boundTo_;
    bool returnErrorOnSocket_;
    bool returnErrorOnBind_;
    bool returnErrorOnAccept_;
    bool* destructorCalled_;
    int socketClosed_;
    int listeningTo_;
    int boundToPort_;
    int socketFDPassedIntoAccept_; 

    MockSocket( MockSocketReturnValues& returnValues );
    virtual ~MockSocket();

    int socket();
    int bind( int socketFD, int portNumber );
    void listen( int socketFD );
    int accept( int socketFD );
    void close( int socketFD );
};

#endif
