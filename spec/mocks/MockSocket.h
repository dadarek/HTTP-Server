#ifndef MOCK_SOCKET_H
#define MOCK_SOCKET_H

#include "Socket.h"

struct MockSocketReturnValues
{
  int socket;
  int accept;
};

struct MockSocketInputValues
{
  int close;
  int listen;
  int bindFD;
  int bindPort;
};

struct MockSocketFlags
{
  bool destructorCalled;
};

class MockSocket
  : public Socket
{
  public:
    MockSocketReturnValues& returnValues_;
    MockSocketInputValues& inputValues_;
    MockSocketFlags& flags_;
    int socketsCreated_;
    bool returnErrorOnSocket_;
    bool returnErrorOnBind_;
    bool returnErrorOnAccept_;
    bool* destructorCalled_;
    int socketFDPassedIntoAccept_; 

    MockSocket( MockSocketReturnValues& returnValues, MockSocketInputValues& inputValues, MockSocketFlags& flags );
    virtual ~MockSocket();

    int socket();
    int bind( int socketFD, int portNumber );
    void listen( int socketFD );
    int accept( int socketFD );
    void close( int socketFD );
};

#endif
