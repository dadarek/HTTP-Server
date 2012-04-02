#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

#include <stddef.h>
#include <string>

class HttpResponse
{
  private:
    char* body_;
    size_t bodyLength_;
    std::string status_;

  public:
    HttpResponse( const char* body, size_t bodyLength, std::string status );
    virtual ~HttpResponse();

    const char* body();
    size_t bodyLength();

    std::string status();
};

#endif
