#include "MockSocketApi.h"

MockSocketApi::MockSocketApi( MockSocketApiReturnValues& returnValues, MockSocketApiInputValues& inputValues, MockSocketApiFlags& flags )
  : returnValues_( returnValues )
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

int MockSocketApi::bind( int socketFD, struct sockaddr* address, size_t )
{
  if( flags_.bindShouldError )
    return -1;

  inputValues_.bindFD = socketFD;

  size_t addressSize = sizeof( inputValues_.bindAddress );
  memcpy( &inputValues_.bindAddress, address, addressSize );

  return returnValues_.bind;
}

void MockSocketApi::listen( int socketFD )
{
  inputValues_.listen = socketFD;
}

int MockSocketApi::accept( int socketFD, struct sockaddr* clientAddress, socklen_t* clientAddressSize )
{ 
  if( flags_.acceptShouldError )
    return -1;

  inputValues_.accept = socketFD;
  inputValues_.acceptSockAddressSize = *clientAddressSize;

  struct sockaddr_in* clientAddressIn = (struct sockaddr_in*) clientAddress;

  //Try to write random stuff, make sure address is not bogus
  clientAddressIn->sin_family = AF_INET;
  clientAddressIn->sin_port = 22;

  return returnValues_.accept;
}

void MockSocketApi::close( int socketFD )
{
  inputValues_.close = socketFD;
}

int MockSocketApi::read( int, char*, unsigned )
{ throw 0; }

int MockSocketApi::write( int, char*, unsigned )
{ throw 0; }
