#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "RawSocketApi.h"
#include "InboundConnectionListener.h"

int a()
{
  RawSocketApi socketApi;
  InboundConnectionListener listener( &socketApi, 8083 );

  for(;;)
  {
    int nextConnection = listener.nextConnection();
    char buffer[256];
    bzero(buffer,256);

    read(nextConnection, buffer, 255);
    printf("Message: %s\n\n", buffer );
    write(nextConnection, "I got your stuffing...", 22);
    socketApi.close(nextConnection);
  }

  return 0;
}

int main()
{
  a();
}

