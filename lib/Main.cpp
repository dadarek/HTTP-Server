#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "RawSocketApi.h"
#include "HttpSocketReader.h"
#include "SocketConnectionReceiver.h"
#include "HttpRequestParserImpl.h"
#include "HttpRequest.h"

#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <sstream>

int a()
{

  RawSocketApi socketApi;
  SocketConnectionReceiver receiver( socketApi, 5000 );
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


    std::string newLine = "\r\n";

    std::string body = "<html><head><title></title><head><body><a href=\"file1\">file1</a><br><a href=\"file2\">file2</a><br></body></html>";
    std::stringstream ss;
    ss << (body.length() + 1);

    std::string bodyLength = ss.str();

    std::string headers;
    headers += "HTTP/1.1 200 OK" + newLine;
    headers += "Status: 200 OK" + newLine;
    headers += "Date: Wed, 28 Mar 2012 11:03:32 GMT" + newLine;
    headers += "Connection: close" + newLine;
    headers += "Server: cplus/0.3" + newLine;
    headers += "Content-Type: text/html" + newLine;
    headers += "Last-Modified: Tue, 06 Mar 2012 16:11:25 GMT" + newLine;
    headers += "Content-Length: " + bodyLength + newLine;

    std::string toSend = headers + newLine + body;
    write(nextConnection, toSend.c_str(), toSend.length());

    socketApi.close(nextConnection);
  }

  return 0;
}

int main()
{
  a();
}

