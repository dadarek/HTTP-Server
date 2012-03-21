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

int RawPortListener::getNewSocketFD()
{
  int socketFD = this->socket_.socket();
  if( socketFD < 0 )
    perror("ERROR on bind");
  return socketFD;
}

void RawPortListener::bindToSocket( int socketFD, int portNumber )
{
  bzero((char *) &this->serverAddress, sizeof(this->serverAddress));
  this->serverAddress.sin_family = AF_INET;
  this->serverAddress.sin_addr.s_addr = INADDR_ANY;
  this->serverAddress.sin_port = htons( portNumber );

  int bindResult = this->socket_.bind( socketFD, (struct sockaddr *) &this->serverAddress, sizeof(this->serverAddress) ); 
  if( bindResult < 0 )
    perror("ERROR on bind");
}

void RawPortListener::listenOnSocket( int socketFD )
{
  this->socket_.listen( socketFD );
}

int RawPortListener::getSocketFDForNextIncomingConnection( int socketFD )
{
  struct sockaddr_in cli_addr;
  socklen_t clilen = sizeof(cli_addr);
  printf("Accepting on socket: %d\n", socketFD );
  int incomingSocketFD = this->socket_.accept( socketFD, 
              (struct sockaddr *) &cli_addr, 
              &clilen);
  if( incomingSocketFD < 0 )
    perror("ERROR on accept");

  printf("Incoming socketfd: %d\n", incomingSocketFD);
  return incomingSocketFD;
}
bool RawPortListener::listen()
{
  int socketFD = getNewSocketFD();
  bindToSocket( socketFD, this->portNumber_ );
  listenOnSocket( socketFD );
  int incomingSocketFD = getSocketFDForNextIncomingConnection( socketFD );

  this->socket_.close( incomingSocketFD );
  this->socket_.close( socketFD );
  
  return true;
}

