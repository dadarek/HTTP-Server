#include <iostream>
#include "MockSocketApi.h"

MockSocketApi::MockSocketApi( MockSocketApiReturnValues& returnValues, MockSocketApiInputValues& inputValues, MockSocketApiFlags& flags )
  : lastReadPosition_( 0 )
  , returnValues_( returnValues )
  , inputValues_( inputValues )
  , flags_( flags )
{ }

MockSocketApi::~MockSocketApi()
{ } 

int MockSocketApi::socket()
{
  if( flags_.socketShouldError )
    return -1;

  flags_.socketCalled = true;
  return returnValues_.socket;
}

int MockSocketApi::bind( int socketFD, int portNumber )
{
  if( flags_.bindShouldError )
    return -1;

  inputValues_.bindFD = socketFD;
  inputValues_.bindPort = portNumber;
  return returnValues_.bind;
}

void MockSocketApi::listen( int socketFD )
{
  inputValues_.listen = socketFD;
}

int MockSocketApi::accept( int socketFD )
{
  if( flags_.acceptShouldError )
    return -1;

  inputValues_.accept = socketFD;
  return returnValues_.accept;
}

void MockSocketApi::close( int socketFD )
{
  inputValues_.close = socketFD;
}

int MockSocketApi::read( int socketFD, char* buffer, int bufferSize )
{
  int result = returnValues_.readReturns[ lastReadPosition_ ];
  const char* whatToCopy = returnValues_.readBuffer[ lastReadPosition_ ];
  int howMuchToCopy = returnValues_.howMuchToCopy[ lastReadPosition_ ];

  lastReadPosition_ ++;

  memcpy(buffer, whatToCopy, howMuchToCopy );
  return result;
}

