#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#include <string>

class HttpRequest
{
  private:
    std::string method_;
    std::string url_;

  public:
    HttpRequest( std::string method, std::string url );
    virtual ~HttpRequest();

    std::string method();
    std::string url();
};

#endif
