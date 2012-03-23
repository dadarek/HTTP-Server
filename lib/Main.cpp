#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "RawSocketApi.h"
#include "SocketReader.h"
#include "SocketConnectionReceiver.h"

int a()
{
  RawSocketApi socketApi;
  SocketConnectionReceiver receiver( &socketApi, 8083 );
  SocketReader reader( &socketApi );

  for(;;)
  {
    int nextConnection = receiver.nextConnection();

    printf("Received connection: %d\n\n", nextConnection );

    std::string request = reader.readToEnd( nextConnection, "\r\n\r\n" );
    printf("Request message: %s\n", request.c_str() );

    write(nextConnection, "I got your stuffing...", 22);

    socketApi.close(nextConnection);
  }

  return 0;
}

int main()
{
  a();
}

