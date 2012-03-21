#include "InboundConnectionListener.h"
#include "Socket.h"


InboundConnectionListener::InboundConnectionListener(Socket* socket)
  : socket_( socket )
{ 
  int fd = socket_->socket();
  if( fd < 0 )
    throw Socket::SOCKET_EXCEPTION;
  
  int bindResult = socket_->bind( fd, 0, 0 );
  if( bindResult < 0 )
    throw Socket::BIND_EXCEPTION;
}

InboundConnectionListener::~InboundConnectionListener()
{
//  if( 0 != socket_ )
//  {
//    delete socket_;
//    socket_ = 0;
//  }
}  
