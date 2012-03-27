#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "RawSocketApi.h"
#include "HttpSocketReader.h"
#include "SocketConnectionReceiver.h"
#include "HttpRequestParserImpl.h"
#include "HttpRequest.h"

int a()
{

  RawSocketApi socketApi;
  SocketConnectionReceiver receiver( socketApi, 8083 );
  HttpSocketReader reader( socketApi );

  for(;;)
  {
    int nextConnection = receiver.nextConnection();

    printf("Received connection: %d\n\n", nextConnection );

    std::string requestHeaders = reader.readToEnd( nextConnection );
    HttpRequestParserImpl parser;
    HttpRequest* request = parser.parse( requestHeaders );
    std::string url = request->url();
    delete request;


    printf("Url: %s\n", url.c_str() );
    printf("ALL HEADERS\n--------\n%s\n", requestHeaders.c_str() );

    write(nextConnection, "I got your stuffing...", 22);

    socketApi.close(nextConnection);
  }

  return 0;
}

int main()
{
  a();
}

