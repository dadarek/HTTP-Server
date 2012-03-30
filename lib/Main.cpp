#include "Server.h"
#include "SocketConnectionReceiver.h"
#include "HttpConnectionHandler.h"
#include "SocketReader.h"
#include "HttpRequestHandlerFactory.h"
#include "HttpResponseSocketWriter.h"
#include "HttpRequestFileHandler.h"
#include "SystemFileFactory.h"
#include "SystemFileApi.h"
#include "HttpSocketReader.h"
#include "HttpRequestParserImpl.h"
#include "RawSocketApi.h"

class DummyFactory
  : public HttpRequestHandlerFactory
{
  public:
    SystemFileFactory fileFactory_;
    SystemFileApi fileApi_;

    DummyFactory()
      : fileFactory_()
      , fileApi_( fileFactory_ )
    { }
    virtual ~DummyFactory()
    { }

    HttpRequestHandler* createHandler( HttpRequest& )
    {
      return new HttpRequestFileHandler("/Users/dariusz/Projects/HttpServer/public/", fileApi_ );
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

  SocketConnectionReceiver receiver( socketApi, 5000 );

  Server server( receiver, connectionhandler );

  server.start();
}

