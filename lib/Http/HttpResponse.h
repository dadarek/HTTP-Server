#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

#include <string>

class HttpResponse
{
  private:
    std::string body_;
    char* charBody_;

  public:
    HttpResponse( std::string body );
    HttpResponse( const char* body, size_t bodyLength );
    virtual ~HttpResponse();

    std::string body();
    const char* charBody();
};

#endif
