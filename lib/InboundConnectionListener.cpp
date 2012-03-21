#include "InboundConnectionListener.h"
#include "Socket.h"


InboundConnectionListener::InboundConnectionListener(Socket* socket)
  : socket_( socket )
{ 
  socket_->socket();
}

InboundConnectionListener::~InboundConnectionListener()
{
  if( 0 != socket_ )
  {
    delete socket_;
    socket_ = 0;
  }
}  
