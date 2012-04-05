#include "HttpConnectionHandlerWorkItem.h"

HttpConnectionHandlerWorkItem::HttpConnectionHandlerWorkItem( SocketReader& socketReader, HttpRequestParser& parser, HttpRequestHandlerFactory& factory, HttpResponseWriter& writer, int socketFD )
  : HttpConnectionHandler( socketReader, parser, factory, writer )
  , socketFD_( socketFD )
{ 
}

HttpConnectionHandlerWorkItem::~HttpConnectionHandlerWorkItem()
{
}  

void HttpConnectionHandlerWorkItem::execute()
{ 
  HttpConnectionHandler::handle( socketFD_ );
}
