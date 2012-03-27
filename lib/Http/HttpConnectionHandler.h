#ifndef HTTP_CONNECTION_HANDLER_H
#define HTTP_CONNECTION_HANDLER_H

#include "RequestHandler.h"

class SocketReader;
class HttpRequestParser;
class HttpRequestHandlerFactory;

class HttpConnectionHandler
  : public RequestHandler
{
  private:
    SocketReader& socketReader_;
    HttpRequestParser& parser_;
    HttpRequestHandlerFactory& factory_;

  public:
    HttpConnectionHandler( SocketReader& socketReader, HttpRequestParser& parser, HttpRequestHandlerFactory& factory );
    virtual ~HttpConnectionHandler();

    void handle( int connection );
};

#endif

