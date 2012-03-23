#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "RawSocketApi.h"
#include "SocketReader.h"
#include "InboundConnectionListener.h"

int a()
{
  RawSocketApi socketApi;
  InboundConnectionListener listener( &socketApi, 8083 );
  SocketReader reader( &socketApi );

  for(;;)
  {
    int nextConnection = listener.nextConnection();

    printf("Received connection: %d\n\n", nextConnection );

    char buffer[1024];
    memset( buffer, 0, 1024 );
    read( nextConnection, buffer, 1023 );
    
   // std::string request = reader.readToEnd( nextConnection );

    //printf("Message: %s\n\n", request.c_str() );
    printf(" Message:\n%s", buffer );

    write(nextConnection, "I got your stuffing...", 22);

    socketApi.close(nextConnection);
  }

  return 0;
}

int main()
{
  a();
}

