#ifndef HTTP_RESPONSE_SOCKET_WRITER
#define HTTP_RESPONSE_SOCKET_WRITER

#include "HttpResponseWriter.h"
#include <stddef.h>

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

  private:
    void write( int socketFD, const char* content, size_t length );
};

#endif
