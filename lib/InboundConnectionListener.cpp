#include "InboundConnectionListener.h"
#include "Socket.h"
#include <iostream>

InboundConnectionListener::InboundConnectionListener( Socket* socket, int portToListenOn )
  : socket_( socket )
  , fd_( -1 )
{ 
  fd_ = socket_->socket();
  if( fd_ < 0 )
    throw Socket::SOCKET_EXCEPTION;
  
  int bindResult = socket_->bind( fd_, portToListenOn );
  if( bindResult < 0 )
  {
    socket_->close( fd_ );
    throw Socket::BIND_EXCEPTION;
  }

  socket_->listen( fd_ );
}

InboundConnectionListener::~InboundConnectionListener()
{
  if( 0 != socket_ )
  {
    delete socket_;
    socket_ = 0;
  }
}  

int InboundConnectionListener::nextConnection()
{
  int result = socket_->accept( this->fd_ );
  if( result < 0 )
  {
    socket_->close( fd_ );
    throw Socket::ACCEPT_EXCEPTION;
  }

  return result;
}
