#include "RawSocket.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

RawSocket::RawSocket()
{ }

RawSocket::~RawSocket()
{ }

int RawSocket::socket()
{
  return ::socket( AF_INET, SOCK_STREAM, 0 );
}

int RawSocket::bind( int socketFD, struct sockaddr* serverAddress, size_t serverAddressSize )
{
  return ::bind( socketFD, serverAddress, serverAddressSize ); 
}

void RawSocket::listen( int socketFD )
{
  ::listen( socketFD, 5 );
}

int RawSocket::accept( int socketFD, struct sockaddr* clientAddress, socklen_t* clientAddressSize )
{
  return ::accept( socketFD, clientAddress, clientAddressSize );
}

void RawSocket::close( int socketFD )
{
  ::close( socketFD );
}

