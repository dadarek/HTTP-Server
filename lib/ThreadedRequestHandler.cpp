#include "ThreadedRequestHandler.h"
#include "RunnableHttpConnectionHandler.h"
#include "SystemThread.h"

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
  RunnableHttpConnectionHandler* runnable = new RunnableHttpConnectionHandler( 
      socketReader_, parser_, factory_, writer_, socketFD );

  SystemThread* thread = new SystemThread( threadApi_, *runnable );
  thread->start();
}
