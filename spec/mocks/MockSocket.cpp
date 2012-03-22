#include "MockSocket.h"

MockSocket::MockSocket( MockSocketReturnValues& returnValues, MockSocketInputValues& inputValues, MockSocketFlags& flags )
  : returnValues_( returnValues )
  , inputValues_( inputValues )
  , flags_( flags )
{ }

MockSocket::~MockSocket()
{ 
  flags_.destructorCalled = true;
}

int MockSocket::socket()
{
  if( flags_.socketShouldError )
    return -1;

  flags_.socketCalled = true;
  return returnValues_.socket;
}

int MockSocket::bind( int socketFD, int portNumber )
{
  if( flags_.bindShouldError )
    return -1;

  inputValues_.bindFD = socketFD;
  inputValues_.bindPort = portNumber;
  return returnValues_.bind;
}

void MockSocket::listen( int socketFD )
{
  inputValues_.listen = socketFD;
}

int MockSocket::accept( int socketFD )
{
  if( flags_.acceptShouldError )
    return -1;

  inputValues_.accept = socketFD;
  return returnValues_.accept;
}

void MockSocket::close( int socketFD )
{
  inputValues_.close = socketFD;
}
