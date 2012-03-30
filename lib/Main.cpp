#include "HttpConnectionHandler.h"
#include "HttpRequestHandlerFactoryImpl.h"
#include "HttpRequestParserImpl.h"
#include "HttpResponseSocketWriter.h"
#include "HttpSocketReader.h"

#include "RawSocketApi.h"

#include "Server.h"
#include "SocketConnectionReceiver.h"
#include "SystemFileFactory.h"
#include "SystemFileApi.h"

#include <string>

int main()
{
  RawSocketApi socketApi;
  HttpSocketReader socketReader( socketApi );
  HttpResponseSocketWriter socketWriter( socketApi );

  SystemFileFactory fileFactory;
  SystemFileApi fileApi( fileFactory );
  std::string basePath( "/Users/dariusz/Projects/HttpServer/public/" );

  HttpRequestParserImpl requestParser;

  HttpRequestHandlerFactoryImpl requestHandlerFactory( basePath, fileApi ); 

  HttpConnectionHandler connectionhandler
    ( socketReader, requestParser, requestHandlerFactory, socketWriter );

  SocketConnectionReceiver receiver( socketApi, 5000 );

  Server server( receiver, connectionhandler );

  server.start();
}

