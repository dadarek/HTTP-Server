#include "RawPortListener.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

RawPortListener::RawPortListener( int portNumber )
  : portNumber_( portNumber )
{ }

bool RawPortListener::listen()
{
  return false;
}

