//#include "HttpConnectionHandler.h"
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
#include "SystemThreadApi.h"

#include "ThreadedRequestHandler.h"

#include <string>
#include <stdexcept>

#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t condition;

void* threadFunction( void* )
{
  printf("Subthread locking mutex.\n");
  pthread_mutex_lock( &mutex );

  printf("Subthread waiting on signal.\n");
  pthread_cond_wait( &condition, &mutex );

  printf("Subthrea unlocking mutex.\n");
  pthread_mutex_unlock( &mutex );

  pthread_exit( 0 );
}
void go()
{
  /* Initialize mutex and condition variable objects */
  pthread_mutex_init( &mutex, NULL );
  pthread_cond_init( &condition, NULL );

  long threadId;
  pthread_t thread;

  printf("About to create thread.\n");
  pthread_create( &thread, 0, &threadFunction, (void*) &threadId );
  printf("Thread created.\n");
  printf("sleeping for 2.\n");
  sleep( 2 );
 
  printf("loking mutex.\n");
  pthread_mutex_lock( &mutex );
  printf("sleeping for 2.\n");
  sleep( 2 );

  printf("signalling condition.\n");
  pthread_cond_signal( &condition );
  printf("sleeping for 2.\n");
  sleep( 2 );

  printf("Unlocking mutex.");
  pthread_mutex_unlock( &mutex );
  printf("sleeping for 2.\n");
  sleep( 2 );

  printf("Joining thread.\n");
  pthread_join( thread, 0 );
  printf("Thread joined.\n");

  pthread_mutex_destroy( &mutex );
  pthread_cond_destroy( &condition );

  pthread_exit( 0 );
}

void G()
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

  //HttpConnectionHandler connectionhandler
  ThreadedRequestHandler connectionhandler
    ( socketReader, requestParser, requestHandlerFactory, socketWriter, threadApi );

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
