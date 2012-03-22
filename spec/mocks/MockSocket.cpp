#include "MockSocket.h"

MockSocket::MockSocket( MockSocketReturnValues& returnValues, MockSocketFlags& flags )
  : returnValues_( returnValues )
  , flags_( flags )
  , socketsCreated_( 0 )
  , boundTo_( -1 )
  , returnErrorOnSocket_( false )
  , returnErrorOnBind_( false )
  , returnErrorOnAccept_( false )
  , destructorCalled_( 0 )
  , socketClosed_( -1 )
  , listeningTo_( -1 )
  , boundToPort_( -1 )
  , socketFDPassedIntoAccept_( -1 )
{ }

MockSocket::~MockSocket()
{ 
  flags_.destructorCalled = true;
}

int MockSocket::socket()
{
  if( returnErrorOnSocket_ )
    return -1;

  socketsCreated_++;
  return returnValues_.socket;
}

int MockSocket::bind( int socketFD, int portNumber )
{
  if( returnErrorOnBind_ )
    return -1;

  boundTo_ = socketFD;
  boundToPort_ = portNumber;
  return 0;
}

void MockSocket::listen( int socketFD )
{
  listeningTo_ = socketFD;
}

int MockSocket::accept( int socketFD )
{
  if( returnErrorOnAccept_ )
    return -1;

  socketFDPassedIntoAccept_ = socketFD;
  return returnValues_.accept;
}

void MockSocket::close( int socketFD )
{
  socketClosed_ = socketFD;
}
