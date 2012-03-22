#include "InboundConnectionListener.h"
#include "Socket.h"
#include <iostream>

InboundConnectionListener::InboundConnectionListener( Socket* socket, int portToBindTo )
  : socket_( socket )
  , fd_( -1 )
{ 
  createSocket();
  bindToSocket( portToBindTo );
  socket_->listen( fd_ );
}
void InboundConnectionListener::createSocket()
{
  fd_ = socket_->socket();
  if( fd_ < 0 )
    throw Socket::SOCKET_EXCEPTION;
}

void InboundConnectionListener::bindToSocket( int portToBindTo )
{
  int bindResult = socket_->bind( fd_, portToBindTo );
  if( bindResult < 0 )
  {
    closeSocket();
    throw Socket::BIND_EXCEPTION;
  }
}

InboundConnectionListener::~InboundConnectionListener()
{
  closeSocket();
}  

int InboundConnectionListener::nextConnection()
{
  printf("About to listen ...\n");
  int result = socket_->accept( this->fd_ );
  printf("Done listening: %d\n", result );
  if( result < 0 )
    throw Socket::ACCEPT_EXCEPTION;

  return result;
}

void InboundConnectionListener::closeSocket()
{
  socket_->close( fd_ );
  fd_ = -1;
}

