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

int RawSocket::bind( int socketFD )
{
  return 0;
}

void RawSocket::listen( int socketFD )
{
}

int RawSocket::accept( int socketFD )
{
  return 0;
}

void RawSocket::close( int socketFD )
{
  ::close( socketFD );
}

