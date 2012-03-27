#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#include <string>

class HttpRequest
{
  private:
    std::string url_;

  public:
    HttpRequest( std::string url );
    virtual ~HttpRequest();

    std::string url();

};

#endif
