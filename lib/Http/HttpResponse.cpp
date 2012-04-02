#include "HttpResponse.h"
#include <cstring>

HttpResponse::HttpResponse( const char* body, size_t bodyLength, std::string status )
  : body_( new char[ bodyLength ] )
  , bodyLength_( bodyLength )
  , status_( status )
{
  memcpy( body_, body, bodyLength );
}

HttpResponse::~HttpResponse()
{
  delete[] body_;
}

const char* HttpResponse::body()
{
  return body_;
}

size_t HttpResponse::bodyLength()
{
  return bodyLength_;
}

std::string HttpResponse::status()
{
  return status_;
}
