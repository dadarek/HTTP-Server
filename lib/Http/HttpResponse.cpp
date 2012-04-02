#include "HttpResponse.h"
#include <cstring>

HttpResponse::HttpResponse( const char* body, size_t bodyLength )
  : body_( new char[ bodyLength ] )
  , bodyLength_( bodyLength )
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

