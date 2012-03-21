#include "MockSocket.h"
#include <iostream>

MockSocket::MockSocket()
  : socketsCreated_( 0 )
  , socketFD_( 0 )
  , returnErrorOnSocket_( false )
  , returnErrorOnBind_( false )
{ }

MockSocket::~MockSocket()
{ }

int MockSocket::socket()
{
  if( returnErrorOnSocket_ )
    return -1;

  socketsCreated_++;
  return socketFD_;
}

int MockSocket::bind( int socketFD, struct sockaddr* serverAddress, size_t serverAddressSize )
{
  if( returnErrorOnBind_ )
    return -1;

  boundTo_ = socketFD;
  return 0;
}

void MockSocket::listen( int socketFD )
{
}

int MockSocket::accept( int socketFD, struct sockaddr* clientAddress, socklen_t* clientAddressSize )
{
  return 0;
}

void MockSocket::close( int socketFD )
{
}
