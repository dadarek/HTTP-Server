#ifndef RUNNABLE_HTTP_CONNECTION_HANDLER_H
#define RUNNABLE_HTTP_CONNECTION_HANDLER_H

#include "HttpConnectionHandler.h"
#include "Runnable.h"

class RunnableHttpConnectionHandler
  : public HttpConnectionHandler
  , public Runnable
{
  private:
    int socketFD_;

  public:
    RunnableHttpConnectionHandler( SocketReader& socketReader, HttpRequestParser& parser, HttpRequestHandlerFactory& factory, HttpResponseWriter& writer, int socketFD );
    virtual ~RunnableHttpConnectionHandler();

    void run(); 
};

#endif

