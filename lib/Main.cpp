/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include "Socket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#include "RawPortListener.h"
#include "RawSocket.h"
#include "InboundConnectionListener.h"

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int a()
{
  RawSocket socket;
  InboundConnectionListener listener( &socket, 8083 );

  for(;;)
  {
    int nextConnection = listener.nextConnection();
    char buffer[256];
    bzero(buffer,256);

    read(nextConnection, buffer, 255);
    printf("Message: %s\n\n", buffer );
    write(nextConnection, "I got your stuffing...", 22);
    socket.close(nextConnection);
  }

  return 0;
}

int b()
{
     int sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     
     struct sockaddr_in serv_addr; 
     bzero((char *) &serv_addr, sizeof(serv_addr));
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons( 8080 );

     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     listen(sockfd,5);

     struct sockaddr_in cli_addr;
     socklen_t clilen = sizeof(cli_addr);

     printf("ACCEPT on socket: %d \n", sockfd);
     int newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
     if (newsockfd < 0) 
          error("ERROR on accept");

     char buffer[256];
     bzero(buffer,256);

     printf("Waiting for read.... \n");
     int n = read(newsockfd,buffer,255);
     if (n < 0) error("ERROR reading from socket");
     printf("Here is the message: %s\n",buffer);
     n = write(newsockfd,"I got your message",18);
     if (n < 0) error("ERROR writing to socket");
     close(newsockfd);
     close(sockfd);
     return 0; 
}

int main()
{
  a();
  //b();
}

