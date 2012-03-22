#include "MockSocketReadApi.h"

MockSocketReadApi::MockSocketReadApi()
  : lastReadPosition_( 0 )
{ }

MockSocketReadApi::~MockSocketReadApi()
{ }

int MockSocketReadApi::socket()
{ throw 0; }

int MockSocketReadApi::bind( int, int )
{ throw 0; }

void MockSocketReadApi::listen( int )
{ throw 0; }

int MockSocketReadApi::accept( int )
{ throw 0; }

void MockSocketReadApi::close( int )
{ throw 0; }

int MockSocketReadApi::read( int socketFD, char* buffer, int bufferSize )
{
  int result = readReturns_[ lastReadPosition_ ];
  const char* whatToCopy = readBuffer_[ lastReadPosition_ ];
  int howMuchToCopy = howMuchToCopy_[ lastReadPosition_ ];

  lastReadPosition_ ++;

  memcpy(buffer, whatToCopy, howMuchToCopy );
  return result;
}

