#include "ThreadedRequestHandler.h"
#include "HttpConnectionHandlerWorkItem.h"
#include "SystemSlaveThread.h"

ThreadedRequestHandler::ThreadedRequestHandler( SocketReader& socketReader, HttpRequestParser& parser, HttpRequestHandlerFactory& factory, HttpResponseWriter& writer, ThreadApi& threadApi )
  : socketReader_( socketReader )
  , parser_( parser )
  , factory_( factory )
  , writer_( writer )
  , threadApi_( threadApi )
{ }

ThreadedRequestHandler::~ThreadedRequestHandler()
{ }

void ThreadedRequestHandler::handle( int socketFD )
{
//HttpConnectionHandlerWorkItem* runnable = new HttpConnectionHandlerWorkItem( 
 //     socketReader_, parser_, factory_, writer_, socketFD );

 // SystemSlaveThread* thread = new SystemSlaveThread( threadApi_ );
 // thread->start( runnable );
}
