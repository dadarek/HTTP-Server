#include "MockSocketReadApi.h"

#include <iostream>

MockSocketReadApi::MockSocketReadApi()
  : sourceBuffer_( 0 )
  , lastReadPosition_( 0 )
  , returnErrorOnRead_( false )
  , socketReadOn_( -1 )
{ }

MockSocketReadApi::~MockSocketReadApi()
{ }

int MockSocketReadApi::socket()
{ throw 0; }

int MockSocketReadApi::bind( int , struct sockaddr* , size_t )
{ throw 0; }

void MockSocketReadApi::listen( int )
{ throw 0; }

int MockSocketReadApi::accept( int, struct sockaddr*, socklen_t* )
{ throw 0; }

void MockSocketReadApi::close( int )
{ throw 0; }

int MockSocketReadApi::read( int socketFD, char* buffer, unsigned bufferSize )
{
  if( returnErrorOnRead_ )
    return -1;

  socketReadOn_ = socketFD;

  const char* source = sourceBuffer_ + lastReadPosition_;
  
  unsigned sourceSize = strlen( source );
  int result = ( sourceSize > bufferSize ) ? bufferSize : sourceSize;

  memcpy( buffer, source, result );

  lastReadPosition_ += result;

  return result;
}

int MockSocketReadApi::write( int, char*, unsigned )
{ throw 0; }

