#ifndef MOCK_SOCKET_API_H
#define MOCK_SOCKET_API_H

#include "SocketApi.h"

struct MockSocketApiReturnValues
{
  int socket;
  int bind;
  int accept;
};

struct MockSocketApiInputValues
{
  int close;
  int listen;
  int bindFD;
  int bindPort;
  int accept;
};

struct MockSocketApiFlags
{
  bool socketShouldError;
  bool bindShouldError;
  bool acceptShouldError;
  bool socketCalled;
};

class MockSocketApi
  : public SocketApi
{
  public:
    MockSocketApiReturnValues& returnValues_;
    MockSocketApiInputValues& inputValues_;
    MockSocketApiFlags& flags_;

    MockSocketApi( MockSocketApiReturnValues& returnValues, MockSocketApiInputValues& inputValues, MockSocketApiFlags& flags );
    virtual ~MockSocketApi();

    int socket();
    int bind( int socketFD, int portNumber );
    void listen( int socketFD );
    int accept( int socketFD );
    void close( int socketFD );
};

#endif
