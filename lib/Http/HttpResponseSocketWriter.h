#ifndef HTTP_RESPONSE_SOCKET_WRITER
#define HTTP_RESPONSE_SOCKET_WRITER

#include "HttpResponseWriter.h"

class SocketApi;
class HttpResponse;

class HttpResponseSocketWriter
  : public HttpResponseWriter
{
  private:
    SocketApi& socketApi_;

  public:
    HttpResponseSocketWriter( SocketApi& socketApi );
    virtual ~HttpResponseSocketWriter();

    void write( int socketFD, HttpResponse& response );
};

#endif
