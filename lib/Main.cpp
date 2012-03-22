#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "RawSocket.h"
#include "InboundConnectionListener.h"

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

int main()
{
  a();
}

