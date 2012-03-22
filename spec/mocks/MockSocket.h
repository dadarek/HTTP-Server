#ifndef MOCK_SOCKET_H
#define MOCK_SOCKET_H

#include "Socket.h"

struct MockSocketReturnValues
{
  int socket;
  int bind;
  int accept;
};

struct MockSocketInputValues
{
  int close;
  int listen;
  int bindFD;
  int bindPort;
  int accept;
};

struct MockSocketFlags
{
  bool socketShouldError;
  bool bindShouldError;
  bool acceptShouldError;
  bool destructorCalled;
  bool socketCalled;
};

class MockSocket
  : public Socket
{
  public:
    MockSocketReturnValues& returnValues_;
    MockSocketInputValues& inputValues_;
    MockSocketFlags& flags_;

    MockSocket( MockSocketReturnValues& returnValues, MockSocketInputValues& inputValues, MockSocketFlags& flags );
    virtual ~MockSocket();

    int socket();
    int bind( int socketFD, int portNumber );
    void listen( int socketFD );
    int accept( int socketFD );
    void close( int socketFD );
};

#endif
