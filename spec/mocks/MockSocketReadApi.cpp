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
  int sourceSize = strlen( sourceBuffer_ );
  int result = ( sourceSize < bufferSize ) ? bufferSize : sourceSize;

  memcpy( buffer, sourceBuffer_, result );
}

