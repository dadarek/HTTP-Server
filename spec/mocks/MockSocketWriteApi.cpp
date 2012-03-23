#include "MockSocketWriteApi.h"

#include <iostream>

MockSocketWriteApi::MockSocketWriteApi()
{ }

MockSocketWriteApi::~MockSocketWriteApi()
{ }

int MockSocketWriteApi::socket()
{ throw 0; }

int MockSocketWriteApi::bind( int, int )
{ throw 0; }

void MockSocketWriteApi::listen( int )
{ throw 0; }

int MockSocketWriteApi::accept( int )
{ throw 0; }

void MockSocketWriteApi::close( int )
{ throw 0; }

int MockSocketWriteApi::read( int, char*, unsigned)
{ throw 0; }

int MockSocketWriteApi::write( int , char* , unsigned )
{ 
  throw 0;
}
