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

void go( int portNumber, const char* directory )
{
  SystemThreadApi threadApi;

  RawSocketApi socketApi;
  HttpSocketReader socketReader( socketApi );
  HttpResponseSocketWriter socketWriter( socketApi );

  SystemDirectoryApi directoryApi;

  SystemFileFactory fileFactory;
  SystemFileApi fileApi( fileFactory );
  std::string basePath( directory );

  HttpRequestParserImpl requestParser;

  HttpRequestHandlerFactoryImpl requestHandlerFactory( basePath, fileApi, directoryApi );


  StlWorkItemQueue workItemQueue;
  unsigned numberOfThreads = 50;
  SystemSlaveThreadFactory slaveThreadFactory( threadApi );

  ThreadPool threadPool( threadApi, slaveThreadFactory, workItemQueue, numberOfThreads );

  ThreadedRequestHandler connectionhandler
    ( socketReader, requestParser, requestHandlerFactory, socketWriter, threadPool );

  SocketConnectionReceiver receiver( socketApi, portNumber );

  Server server( receiver, connectionhandler );

  server.start();
}

void ensureParameterCount( int argc )
{
  if( 3 != argc )
  {
    printf("Usage: ./main [port] [directory]\n\n");
    exit( -1 );
  }
}

void ensureDirectoryTrailingSlash( const char* directory )
{
  int directoryLength = strlen( directory );
  char lastCharacter = directory[ directoryLength - 1 ];
  if( '/' !=  lastCharacter )
  {
    printf("Help us protect the environment - please enter a trailing backslash on your directory.\n\n");
    exit( -1 );
  }
}

int main( int argc, char** argv )
{

  ensureParameterCount( argc );
  ensureDirectoryTrailingSlash( argv[2] );

  int port = atoi( argv[1] );
  const char* directory = argv[2];
  

  try
  {
    go( port, directory );
  }
  catch( std::runtime_error e )
  {
    printf("Exception: %s\n\n", e.what());
  }
}
