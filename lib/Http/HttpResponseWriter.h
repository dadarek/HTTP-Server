#ifndef HTTP_RESPONSE_WRITER_H
#define HTTP_RESPONSE_WRITER_H

class HttpResponse;

class HttpResponseWriter
{
  public:
    virtual ~HttpResponseWriter(){ }

    virtual void write( HttpResponse& response ) = 0;
};
#endif
