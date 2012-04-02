#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

#include <stddef.h>

class HttpResponse
{
  private:
    char* body_;
    size_t bodyLength_;

  public:
    HttpResponse( const char* body, size_t bodyLength );
    virtual ~HttpResponse();

    const char* body();
    size_t bodyLength();
};

#endif
