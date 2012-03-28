#ifndef MOCK_HTTP_RESPONSE_WRITER_H
#define MOCK_HTTP_RESPONSE_WRITER_H

class HttpResponse;

class MockHttpResponseWriter
{
  public:
    HttpResponse* responseReceived_;

    MockHttpResponseWriter();
    virtual ~MockHttpResponseWriter();

    void write( HttpResponse& response );
};

#endif
