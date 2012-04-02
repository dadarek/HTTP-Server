#include "HttpRequest.h"

HttpRequest::HttpRequest( std::string method, std::string url )
  : method_( method )
  , url_( url )
{ }

HttpRequest::~HttpRequest()
{ }

std::string HttpRequest::url()
{
  return url_;
}

std::string HttpRequest::method()
{
  return method_;
}

