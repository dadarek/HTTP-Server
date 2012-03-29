#include "Server.h"
#include "SocketConnectionReceiver.h"
#include "HttpConnectionHandler.h"
#include "SocketReader.h"
#include "HttpRequestHandlerFactory.h"
#include "HttpResponseSocketWriter.h"
#include "HttpRequestFileHandler.h"
#include "SystemFileFactory.h"
#include "SystemFileReader.h"
#include "HttpSocketReader.h"
#include "HttpRequestParserImpl.h"
#include "RawSocketApi.h"

class DummyFactory
  : public HttpRequestHandlerFactory
{
  public:
    DummyFactory()
    { }
    virtual ~DummyFactory()
    { }

    HttpRequestHandler* createHandler( HttpRequest& )
    {
      // MEMORY LEAK!!
      SystemFileFactory* fileFactory = new SystemFileFactory();
      FileReader* fileReader = new SystemFileReader( *fileFactory );
      return new HttpRequestFileHandler("/Users/dariusz/Projects/HttpServer/public/", *fileReader );
    }
};

int main()
{
  RawSocketApi socketApi;
  HttpSocketReader socketReader( socketApi );
  HttpRequestParserImpl requestParser;
  DummyFactory factory;
  HttpResponseSocketWriter socketWriter( socketApi );

  HttpConnectionHandler connectionhandler
    ( socketReader, requestParser, factory, socketWriter );

  SocketConnectionReceiver receiver( socketApi, 8585 );

  Server server( receiver, connectionhandler );

  server.start();
}

