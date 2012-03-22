#ifndef MOCK_SOCKET_API_H
#define MOCK_SOCKET_API_H

#include <iostream>
#include "SocketApi.h"

struct MockSocketApiReturnValues
{
  int socket;
  int bind;
  int accept;
  const char* readBuffer[10];
  int readReturns[10];
  int howMuchToCopy[10];

  MockSocketApiReturnValues()
    : socket( -1 )
    , bind( -1 )
    , accept( -1 )
  { }

  MockSocketApiReturnValues( int socket, int bind, int accept )
    : socket( socket )
    , bind( bind )
    , accept( accept )
  { }
};

struct MockSocketApiInputValues
{
  int close;
  int listen;
  int bindFD;
  int bindPort;
  int accept;

  MockSocketApiInputValues()
  {
    close = listen = bindFD = bindPort = accept = -1;
  }
};

struct MockSocketApiFlags
{
  bool socketShouldError;
  bool bindShouldError;
  bool acceptShouldError;
  bool socketCalled;

  MockSocketApiFlags()
  {
    socketShouldError = bindShouldError = acceptShouldError = socketCalled = false;
  }
};

class MockSocketApi
  : public SocketApi
{
  private:
    int lastReadPosition_;

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

    int read( int socketFD, char* buffer, int bufferSize );
};

#endif
