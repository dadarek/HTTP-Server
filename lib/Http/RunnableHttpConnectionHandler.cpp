#include "RunnableHttpConnectionHandler.h"

RunnableHttpConnectionHandler::RunnableHttpConnectionHandler( SocketReader& socketReader, HttpRequestParser& parser, HttpRequestHandlerFactory& factory, HttpResponseWriter& writer, int socketFD )
  : HttpConnectionHandler( socketReader, parser, factory, writer )
  , socketFD_( socketFD )
{ 
}

RunnableHttpConnectionHandler::~RunnableHttpConnectionHandler()
{
}  

void RunnableHttpConnectionHandler::run()
{ 
  HttpConnectionHandler::handle( socketFD_ );
}
