#include "HttpRequest.h"

HttpRequest::HttpRequest( std::string method, std::string url )
  : method_( method )
  , url_( url )
  , body_( 0 )
  , bodyLength_( 0 )
{ }

HttpRequest::~HttpRequest()
{ 
  if( 0 != body_ )
    delete[] body_;
}

std::string HttpRequest::url()
{
  return url_;
}

std::string HttpRequest::method()
{
  return method_;
}

void HttpRequest::setBody( const char* body, size_t length )
{
  body_ = new char[ length ];
  memcpy( body_, body, length );

  bodyLength_ = length;
}

const char* HttpRequest::body()
{
  return body_;
}

size_t HttpRequest::bodyLength()
{
  return bodyLength_;
}
