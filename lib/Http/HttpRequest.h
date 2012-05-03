#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#include <string>
#include <cstring>

class HttpRequest
{
  private:
    std::string method_;
    std::string url_;

    char* body_;
    size_t bodyLength_;

  public:
    HttpRequest( std::string method, std::string url );
    virtual ~HttpRequest();

    void setBody( const char* body, size_t length );

    std::string method();
    std::string url();

    const char* body();
    size_t bodyLength();
};

#endif
