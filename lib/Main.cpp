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

#include <pthread.h>

#define NUM_THREADS 5

void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;
   printf("Hello World! It's me, thread #%ld!\n", tid);
   pthread_exit(NULL);
}

void go()
{
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;
  for(t=0; t<NUM_THREADS; t++){
    printf("In main: creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
    if (rc){
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }

  /* Last thing that main() should do */
  /* It waits until ALL threads exit */
  pthread_exit(NULL);
}

void G()
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
