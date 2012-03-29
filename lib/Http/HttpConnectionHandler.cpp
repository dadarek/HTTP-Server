#include "HttpConnectionHandler.h"
#include "SocketReader.h"
#include "HttpResponse.h"
#include "HttpResponseWriter.h"
#include "HttpRequest.h"
#include "HttpRequestParser.h"
#include "HttpRequestHandler.h"
#include "HttpRequestHandlerFactory.h"

HttpConnectionHandler::HttpConnectionHandler( SocketReader& socketReader, HttpRequestParser& parser, HttpRequestHandlerFactory& factory, HttpResponseWriter& writer )
  : socketReader_( socketReader )
  , parser_( parser )
  , factory_( factory )
  , writer_( writer )
{ 
}

HttpConnectionHandler::~HttpConnectionHandler()
{
}  

void HttpConnectionHandler::handle( int socketFD )
{ 
  std::string requestString = socketReader_.readToEnd( socketFD );
  HttpRequest* request =  parser_.parse( requestString );

  HttpRequestHandler* handler = factory_.createHandler( *request );
  HttpResponse* response = handler->handle( *request );
  delete request;

  writer_.write( socketFD, *response );
  delete response;
  delete handler;
}
