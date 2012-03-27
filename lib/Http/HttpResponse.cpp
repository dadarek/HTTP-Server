#include "HttpResponse.h"

HttpResponse::HttpResponse( std::string body )
  : body_( body )
{ }

HttpResponse::~HttpResponse()
{ }


std::string HttpResponse::body()
{
  return body_;
}

