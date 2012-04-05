#include "ThreadedRequestHandler.h"
#include "HttpConnectionHandlerWorkItem.h"
#include "SystemSlaveThread.h"
#include "ThreadPool.h"

ThreadedRequestHandler::ThreadedRequestHandler( SocketReader& socketReader, HttpRequestParser& parser, HttpRequestHandlerFactory& factory, HttpResponseWriter& writer, ThreadPool& threadPool )
  : socketReader_( socketReader )
  , parser_( parser )
  , factory_( factory )
  , writer_( writer )
  , threadPool_( threadPool )
{ }

ThreadedRequestHandler::~ThreadedRequestHandler()
{ }

void ThreadedRequestHandler::handle( int socketFD )
{
  HttpConnectionHandlerWorkItem* workItem = new HttpConnectionHandlerWorkItem( 
      socketReader_, parser_, factory_, writer_, socketFD );

  threadPool_.add( workItem );
}
