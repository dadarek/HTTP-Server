//#include "HttpConnectionHandler.h"
#include "HttpRequestHandlerFactoryImpl.h"
#include "HttpRequestParserImpl.h"
#include "HttpResponseSocketWriter.h"
#include "HttpSocketReader.h"

#include "RawSocketApi.h"

#include "Server.h"
#include "SocketConnectionReceiver.h"

#include "StlWorkItemQueue.h"

#include "SystemDirectoryApi.h"
#include "SystemFileFactory.h"
#include "SystemFileApi.h"

#include "SystemSlaveThreadFactory.h"
#include "SystemThreadApi.h"
#include "ThreadPool.h"
#include "ThreadedRequestHandler.h"

#include <stdexcept>

void go()
{
  SystemThreadApi threadApi;

  RawSocketApi socketApi;
  HttpSocketReader socketReader( socketApi );
  HttpResponseSocketWriter socketWriter( socketApi );

  SystemDirectoryApi directoryApi;

  SystemFileFactory fileFactory;
  SystemFileApi fileApi( fileFactory );
  std::string basePath( "/Users/dariusz/Projects/HttpServer/public/" );

  HttpRequestParserImpl requestParser;

  HttpRequestHandlerFactoryImpl requestHandlerFactory( basePath, fileApi, directoryApi );


  StlWorkItemQueue workItemQueue;
  unsigned numberOfThreads = 50;
  SystemSlaveThreadFactory slaveThreadFactory( threadApi );

  ThreadPool threadPool( threadApi, slaveThreadFactory, workItemQueue, numberOfThreads );

  ThreadedRequestHandler connectionhandler
    ( socketReader, requestParser, requestHandlerFactory, socketWriter, threadPool );

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
