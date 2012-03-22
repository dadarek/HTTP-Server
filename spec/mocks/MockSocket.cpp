#include "MockSocket.h"

MockSocket::MockSocket( MockSocketReturnValues& returnValues, MockSocketInputValues& inputValues, MockSocketFlags& flags )
  : returnValues_( returnValues )
  , inputValues_( inputValues )
  , flags_( flags )
  , socketsCreated_( 0 )
  , returnErrorOnSocket_( false )
  , returnErrorOnBind_( false )
  , returnErrorOnAccept_( false )
  , destructorCalled_( 0 )
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

  inputValues_.bindFD = socketFD;
  inputValues_.bindPort = portNumber;
  return 0;
}

void MockSocket::listen( int socketFD )
{
  inputValues_.listen = socketFD;
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
  inputValues_.close = socketFD;
}
