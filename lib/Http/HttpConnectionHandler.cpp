#include "HttpConnectionHandler.h"
#include "SocketReader.h"
#include "HttpRequestHandlerFactory.h"

HttpConnectionHandler::HttpConnectionHandler( SocketReader& socketReader, HttpRequestHandlerFactory& factory )
  : socketReader_( socketReader )
  , factory_( factory )
{ 
}

HttpConnectionHandler::~HttpConnectionHandler()
{
}  

void HttpConnectionHandler::handle( int )
{ }
