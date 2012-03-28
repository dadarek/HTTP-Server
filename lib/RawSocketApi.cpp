#include "RawSocketApi.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

RawSocketApi::RawSocketApi()
{ }

RawSocketApi::~RawSocketApi()
{ }

int RawSocketApi::socket()
{
  return ::socket( AF_INET, SOCK_STREAM, 0 );
}

int RawSocketApi::bind( int socketFD, struct sockaddr* serverAddress, size_t serverAddressSize )
{
  return ::bind( socketFD, serverAddress, serverAddressSize ); 
}

void RawSocketApi::listen( int socketFD )
{
  ::listen( socketFD, 5 );
}

int RawSocketApi::accept( int socketFD, struct sockaddr* clientAddress, socklen_t* clientAddressSize )
{
  throw 0;
  //return ::accept( socketFD, clientAddress, clientAddressSize );
}

int RawSocketApi::accept( int socketFD )
{
  struct sockaddr_in clientAddress;
  socklen_t clientAddressSize = sizeof(clientAddress);
  struct sockaddr* clientAddressReference = (struct sockaddr*) &clientAddress;
  return ::accept( socketFD, clientAddressReference, &clientAddressSize );
}

void RawSocketApi::close( int socketFD )
{
  ::close( socketFD );
}

int RawSocketApi::read( int socketFD, char* buffer, unsigned bufferSize )
{
  return ::read( socketFD, buffer, bufferSize );
}

int RawSocketApi::write( int socketFD, char* buffer, unsigned length )
{
  return ::write( socketFD, buffer, length );
}

