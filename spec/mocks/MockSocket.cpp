#include "MockSocket.h"

MockSocket::MockSocket()
  : socketsCreated_( 0 )
  , socketFD_( 888 )
  , boundTo_( -1 )
  , returnErrorOnSocket_( false )
  , returnErrorOnBind_( false )
  , destructorCalled_( 0 )
  , socketClosed_( -1 )
  , listeningTo_( -1 )
{ }

MockSocket::~MockSocket()
{ 
  if( 0 != destructorCalled_ )
    (*destructorCalled_) = true;
}

int MockSocket::socket()
{
  if( returnErrorOnSocket_ )
    return -1;

  socketsCreated_++;
  return socketFD_;
}

int MockSocket::bind( int socketFD, int portNumber )
{
  if( returnErrorOnBind_ )
    return -1;

  boundTo_ = socketFD;
  return 0;
}

void MockSocket::listen( int socketFD )
{
  listeningTo_ = socketFD;
}

int MockSocket::accept( int socketFD )
{
  return 0;
}

void MockSocket::close( int socketFD )
{
  socketClosed_ = socketFD;
}
