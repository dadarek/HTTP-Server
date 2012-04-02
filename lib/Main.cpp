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
#include <stdexcept>

#include <vector>
#include <dirent.h>
void go()
{
  std::vector< std::string > directories;

  DIR* directory = opendir(".");

  struct dirent* entry;
  if( directory ) 
  {
    printf("YES!!!\n");
   while( 0 != ( entry = readdir( directory ) ) )
   {
     if( DT_DIR == entry->d_type )
     {
       printf("DIRECTORY!!!\n");
     }
     printf("etnry: %u!\n", entry->d_type);
     directories.push_back( entry->d_name );
   } 
  }


  for(size_t i = 0; i < directories.size(); i++ )
  {
    std::cout << directories[i];
    std::cout << std::endl;
  }
  


}

void g()
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
