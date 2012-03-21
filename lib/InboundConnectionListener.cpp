#include "InboundConnectionListener.h"
#include "Socket.h"
#include <iostream>

InboundConnectionListener::InboundConnectionListener( Socket* socket, int portToListenOn )
  : socket_( socket )
{ 
  int fd = socket_->socket();
  if( fd < 0 )
    throw Socket::SOCKET_EXCEPTION;
  
  int bindResult = socket_->bind( fd, portToListenOn );
  if( bindResult < 0 )
  {
    socket_->close( fd );
    throw Socket::BIND_EXCEPTION;
  }

  socket_->listen( fd );
}

InboundConnectionListener::~InboundConnectionListener()
{
  if( 0 != socket_ )
  {
    delete socket_;
    socket_ = 0;
  }
}  
