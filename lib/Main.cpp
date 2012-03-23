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

    std::string request = reader.readToEnd( nextConnection );

    printf("Message: %s\n\n", request.c_str() );

    write(nextConnection, "I got your stuffing...", 22);

    socketApi.close(nextConnection);
  }

  return 0;
}

int main()
{
  a();
}

