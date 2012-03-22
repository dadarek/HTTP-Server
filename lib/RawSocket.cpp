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

int RawSocket::bind( int socketFD, int portNumber )
{
  struct sockaddr_in serverAddress;
  bzero((char *) &serverAddress, sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  serverAddress.sin_port = htons( portNumber );

  struct sockaddr* serverAddressReference = (struct sockaddr*) &serverAddress;

  size_t serverAddressSize = sizeof( serverAddress );

  return ::bind( socketFD, serverAddressReference, serverAddressSize ); 
}

void RawSocket::listen( int socketFD )
{
  ::listen( socketFD, 5 );
}

int RawSocket::accept( int socketFD )
{
  struct sockaddr_in clientAddress;
  socklen_t clientAddressSize = sizeof(clientAddress);
  struct sockaddr* clientAddressReference = (struct sockaddr*) &clientAddress;
  return ::accept( socketFD, clientAddressReference, &clientAddressSize );
}

void RawSocket::close( int socketFD )
{
  ::close( socketFD );
}

