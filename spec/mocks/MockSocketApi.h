#ifndef MOCK_SOCKET_API_H
#define MOCK_SOCKET_API_H

#include <iostream>
#include "SocketApi.h"
#include <netinet/in.h>

struct MockSocketApiReturnValues
{
  int socket;
  int bind;
  int accept;

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
  struct sockaddr bindAddress;
  size_t bindSize;
  int accept;

  MockSocketApiInputValues()
  {
    close = listen = bindFD = accept = -1;
    bindSize = 0;
    memset( &bindAddress, 0, sizeof( bindAddress ) );
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
  public:
    MockSocketApiReturnValues& returnValues_;
    MockSocketApiInputValues& inputValues_;
    MockSocketApiFlags& flags_;

    MockSocketApi( MockSocketApiReturnValues& returnValues, MockSocketApiInputValues& inputValues, MockSocketApiFlags& flags );
    virtual ~MockSocketApi();

    int socket();
    int bind( int socketFD, struct sockaddr* serverAddress, size_t serverAddressSize );
    void listen( int socketFD );
    int accept( int socketFD );
    void close( int socketFD );

    int read( int socketFD, char* buffer, unsigned bufferSize );
    int write( int socketFD, char* buffer, unsigned length );
};

#endif
