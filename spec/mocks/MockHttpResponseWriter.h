#ifndef MOCK_HTTP_RESPONSE_WRITER_H
#define MOCK_HTTP_RESPONSE_WRITER_H

#include "HttpResponseWriter.h"

class HttpResponse;

class MockHttpResponseWriter
  : HttpResponseWriter
{
  public:
    HttpResponse* responseReceived_;

    MockHttpResponseWriter();
    virtual ~MockHttpResponseWriter();

    void write( HttpResponse& response );
};

#endif
