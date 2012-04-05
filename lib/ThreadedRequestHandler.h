#ifndef THREADED_REQUEST_HANDLER_H
#define THREADED_REQUEST_HANDLER_H

#include "RequestHandler.h"

class SocketReader;
class HttpRequestParser;
class HttpRequestHandlerFactory;
class HttpResponseWriter;
class ThreadPool;

class ThreadedRequestHandler
  : public RequestHandler
{
  private:
    SocketReader& socketReader_;
    HttpRequestParser& parser_;
    HttpRequestHandlerFactory& factory_;
    HttpResponseWriter& writer_;
    ThreadPool& threadPool_;

  public:
    ThreadedRequestHandler( SocketReader& socketReader, HttpRequestParser& parser, HttpRequestHandlerFactory& factory, HttpResponseWriter& writer, ThreadPool& threadPool );
    virtual ~ThreadedRequestHandler();

    void handle( int socketFD );
};

#endif
