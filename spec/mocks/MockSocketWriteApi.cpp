#include "MockSocketWriteApi.h"

#include <iostream>

MockSocketWriteApi::MockSocketWriteApi()
  : socketWrittenTo_( -1 )
  , whatToReturn_( 0 )
  , returnError_( false )
  , socketClosed_( -1 )
{ }

MockSocketWriteApi::~MockSocketWriteApi()
{ }

int MockSocketWriteApi::socket()
{ throw 0; }

int MockSocketWriteApi::bind( int , struct sockaddr* , size_t )
{ throw 0; }

void MockSocketWriteApi::listen( int )
{ throw 0; }

int MockSocketWriteApi::accept( int, struct sockaddr*, socklen_t* )
{ throw 0; }

void MockSocketWriteApi::close( int socketFD )
{
  socketClosed_ = socketFD;
}

int MockSocketWriteApi::read( int, char*, unsigned )
{ throw 0; }

int MockSocketWriteApi::write( int socketFD, const char* content, unsigned contentSize )
{
  if( returnError_ )
    return -1;

  socketWrittenTo_ = socketFD;
  whatWasWritten_ << content;
  howMuchWasClaimedToBeWritten_ = contentSize;

  return whatToReturn_;
}
