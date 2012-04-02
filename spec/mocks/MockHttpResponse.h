#ifndef MOCK_HTTP_RESPONSE_H
#define MOCK_HTTP_RESPONSE_H

#include "HttpResponse.h"

struct HttpConnectionHandlerInspector;

class MockHttpResponse
  : public HttpResponse
{
  private:
    HttpConnectionHandlerInspector& inspector_;

  public:
    MockHttpResponse( HttpConnectionHandlerInspector& inspector );
    MockHttpResponse( HttpConnectionHandlerInspector& inspector, const char* body, size_t bodyLength );
    virtual ~MockHttpResponse();

};

#endif
