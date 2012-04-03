#include "HttpConnectionHandler.h"
#include "HttpRequestHandlerFactoryImpl.h"
#include "HttpRequestParserImpl.h"
#include "HttpResponseSocketWriter.h"
#include "HttpSocketReader.h"

#include "RawSocketApi.h"

#include "Server.h"
#include "SocketConnectionReceiver.h"
#include "SystemDirectoryApi.h"
#include "SystemFileFactory.h"
#include "SystemFileApi.h"

#include <string>
#include <stdexcept>

void go()
{
  RawSocketApi socketApi;
  HttpSocketReader socketReader( socketApi );
  HttpResponseSocketWriter socketWriter( socketApi );

  SystemDirectoryApi directoryApi;

  SystemFileFactory fileFactory;
  SystemFileApi fileApi( fileFactory );
  std::string basePath( "/Users/dariusz/Projects/HttpServer/public/" );

  HttpRequestParserImpl requestParser;

  HttpRequestHandlerFactoryImpl requestHandlerFactory( basePath, fileApi, directoryApi );

  HttpConnectionHandler connectionhandler
    ( socketReader, requestParser, requestHandlerFactory, socketWriter );

  SocketConnectionReceiver receiver( socketApi, 5000 );

  Server server( receiver, connectionhandler );

  server.start();
}


int main()
{
  try
  {
    go();
  }
  catch( std::runtime_error e )
  {
    printf("Exception: %s\n\n", e.what());
  }
}
