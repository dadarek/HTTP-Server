#include "stdio.h"
#include "cstdlib"
#include "string.h"
#include "cstring"
#include "unistd.h"
#include "HttpRequestParserImpl.h"
#include "HttpResponseSocketWriter.h"
#include "HttpSocketReader.h"

#include "RawSocketApi.h"

#include "Server.h"
#include "SocketConnectionReceiver.h"

#include "StlWorkItemQueue.h"

#include "SystemSlaveThreadFactory.h"
#include "SystemThreadApi.h"
#include "ThreadPool.h"
#include "ThreadedRequestHandler.h"

#include "ChartRequestHandlerFactory.h"

#include <stdexcept>

void go( int portNumber, unsigned threads, const char* )
{
  printf("Creating objects ...\n");
  SystemThreadApi threadApi;

  RawSocketApi socketApi;
  HttpSocketReader socketReader( socketApi );
  HttpResponseSocketWriter socketWriter( socketApi );

  HttpRequestParserImpl requestParser;

  ChartRequestHandlerFactory requestHandlerFactory;

  StlWorkItemQueue workItemQueue;
  SystemSlaveThreadFactory slaveThreadFactory( threadApi );

  ThreadPool threadPool( threadApi, slaveThreadFactory, workItemQueue, threads );

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
  if( 7 != argc )
  {
    printf("Usage: ./main -p [port] -t [threads] -d [directory]\n\n");
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

  unsigned threads = atoi( argv[4] );

  char directory[256];
  strcpy( directory, argv[6] );
  ensureDirectoryTrailingSlash( directory );

  try
  {
    go( port, threads, directory );
  }
  catch( std::runtime_error e )
  {
    printf("Exception: %s\n\n", e.what());
  }
}
