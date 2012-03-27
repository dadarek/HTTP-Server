#include "SocketConnectionReceiver.h"
#include "SocketApi.h"

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
  int bindResult = socketApi_.bind( fd_, portToBindTo );
  if( bindResult < 0 )
  {
    closeSocket();
    throw SocketApi::BIND_EXCEPTION;
  }
}

SocketConnectionReceiver::~SocketConnectionReceiver()
{
  closeSocket();
}  

int SocketConnectionReceiver::nextConnection()
{
  int result = socketApi_.accept( this->fd_ );
  if( result < 0 )
    throw SocketApi::ACCEPT_EXCEPTION;

  return result;
}

void SocketConnectionReceiver::closeSocket()
{
  socketApi_.close( fd_ );
  fd_ = -1;
}

