#include "HttpConnectionHandler.h"
#include "SocketReader.h"
#include "HttpRequestParser.h"
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
  socketReader_.readToEnd( socketFD );
}
