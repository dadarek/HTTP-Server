#include "HttpRequest.h"

HttpRequest::HttpRequest( std::string url )
  : url_( url )
{ }

HttpRequest::~HttpRequest()
{ }

std::string HttpRequest::url()
{
  return url_;
}

