#include "MockSocket.h"

int MockSocket::socket()
{
  socketsCreated_++;
  return socketFD_;
}

int MockSocket::bind( int socketFD, struct sockaddr* serverAddress, size_t serverAddressSize )
{
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
