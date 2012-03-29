#ifndef MOCK_HTTP_RESPONSE_WRITER_H
#define MOCK_HTTP_RESPONSE_WRITER_H

#include "HttpResponseWriter.h"

class HttpResponse;
class HttpConnectionHandlerInspector;

class MockHttpResponseWriter
  : public HttpResponseWriter
{
  public:
    HttpConnectionHandlerInspector& inspector_;
    HttpResponse* responseReceived_;
    int socketFDReceived_;

    MockHttpResponseWriter( HttpConnectionHandlerInspector& inspector );
    virtual ~MockHttpResponseWriter();

    void write( int socketFD, HttpResponse& response );
};

#endif
