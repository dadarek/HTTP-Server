#include "HttpConnectionHandler.h"
#include "SocketReader.h"
#include "HttpRequest.h"
#include "HttpRequestParser.h"
#include "HttpRequestHandler.h"
#include "HttpRequestHandlerFactory.h"

HttpConnectionHandler::HttpConnectionHandler( SocketReader& socketReader, HttpRequestParser& parser, HttpRequestHandlerFactory& factory )
  : socketReader_( socketReader )
  , parser_( parser )
  , factory_( factory )
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
  delete request;

  handler->handle( *request );
}
