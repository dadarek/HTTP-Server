#include "MockSocketWriteApi.h"

#include <iostream>

MockSocketWriteApi::MockSocketWriteApi()
  : socketWrittenTo_( -1 )
  , whatToReturn_( -1 )
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

void MockSocketWriteApi::close( int )
{ throw 0; }

int MockSocketWriteApi::read( int, char*, unsigned )
{ throw 0; }

int MockSocketWriteApi::write( int socketFD, char* content, unsigned contentSize )
{
  socketWrittenTo_ = socketFD;
  whatWasWritten_ << content;
  howMuchWasClaimedToBeWritten_ = contentSize;

  return whatToReturn_;
}
