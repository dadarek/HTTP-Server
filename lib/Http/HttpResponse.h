#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

#include <string>

class HttpResponse
{
  private:
    std::string body_;

  public:
    HttpResponse( std::string body );
    virtual ~HttpResponse();

    std::string body();
};

#endif
