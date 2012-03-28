#include "SocketConnectionReceiver.h"
#include "SocketApi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

SocketConnectionReceiver::SocketConnectionReceiver( SocketApi& socketApi, int portToBindTo )
  : socketApi_( socketApi )
  , fd_( -1 )
{ 
  createSocket();
  bindToSocket( portToBindTo );
  socketApi_.listen( fd_ );
}

void SocketConnectionReceiver::createSocket()
{
  fd_ = socketApi_.socket();
  if( fd_ < 0 )
    throw SocketApi::SOCKET_EXCEPTION;
}

void SocketConnectionReceiver::bindToSocket( int portToBindTo )
{
  struct sockaddr_in serverAddress = createBindAddress( portToBindTo );
  struct sockaddr* serverAddressReference = (struct sockaddr*) &serverAddress;
  size_t serverAddressSize = sizeof( serverAddress );

  int bindResult = socketApi_.bind( fd_, serverAddressReference, serverAddressSize );
  if( bindResult < 0 )
  {
    closeSocket();
    throw SocketApi::BIND_EXCEPTION;
  }
}

struct sockaddr_in SocketConnectionReceiver::createBindAddress( int portToBindTo )
{
  struct sockaddr_in result;
  bzero((char *) &result, sizeof( result ));
  result.sin_family = AF_INET;
  result.sin_addr.s_addr = INADDR_ANY;
  result.sin_port = htons( portToBindTo );

  return result;
}

SocketConnectionReceiver::~SocketConnectionReceiver()
{
  closeSocket();
}  

int SocketConnectionReceiver::nextConnection()
{
  struct sockaddr_in clientAddress;
  struct sockaddr* clientAddressIn = (struct sockaddr*) &clientAddress;

  socklen_t clientAddressSize = sizeof( clientAddress );
  
  int result = socketApi_.accept( this->fd_, clientAddressIn, &clientAddressSize );
  if( result < 0 )
    throw SocketApi::ACCEPT_EXCEPTION;

  return result;
}

void SocketConnectionReceiver::closeSocket()
{
  socketApi_.close( fd_ );
}

