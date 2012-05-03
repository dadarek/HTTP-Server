//#include "HttpConnectionHandler.h"
#include "stdio.h"
#include "cstdlib"
#include "string.h"
#include "cstring"
#include "unistd.h"
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
  printf("Creating objects ...\n");
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

  printf("Creating server...\n");
  Server server( receiver, connectionhandler );

  printf("Starting server (you won't see a Server Started message :) )...\n");
  server.start();
}

void ensureParameterCount( int argc )
{
  if( 5 != argc )
  {
    printf("Usage: ./main -p [port] -d [directory]\n\n");
    exit( -1 );
  }
}

void ensureDirectoryTrailingSlash( char* directory )
{
  int directoryLength = strlen( directory );
  char lastCharacter = directory[ directoryLength - 1 ];
  if( '/' !=  lastCharacter )
  {
    directory[ directoryLength ] = '/';
    directory[ directoryLength + 1 ] = '\0';
  }
}

int main( int argc, char** argv )
{
  ensureParameterCount( argc );

  int port = atoi( argv[2] );

  char directory[256];
  strcpy( directory, argv[4] );
  ensureDirectoryTrailingSlash( directory );

  try
  {
    go( port, directory );
  }
  catch( std::runtime_error e )
  {
    printf("Exception: %s\n\n", e.what());
  }
}
