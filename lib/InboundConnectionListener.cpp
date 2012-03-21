#include "InboundConnectionListener.h"
#include "Socket.h"


InboundConnectionListener::InboundConnectionListener(Socket* socket)
  : socket_( socket )
{ 
  int fd = socket_->socket();
  socket_->bind( fd, 0, 0 );
}

InboundConnectionListener::~InboundConnectionListener()
{
//  if( 0 != socket_ )
//  {
//    delete socket_;
//    socket_ = 0;
//  }
}  
