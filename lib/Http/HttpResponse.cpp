#include "HttpResponse.h"
#include <cstring>

HttpResponse::HttpResponse( const char* body, size_t bodyLength )
  : charBody_( new char[ bodyLength ] )
  , bodyLength_( bodyLength )
{
  memcpy( charBody_, body, bodyLength );
}

HttpResponse::~HttpResponse()
{
  delete[] charBody_;
}

const char* HttpResponse::charBody()
{
  return charBody_;
}

size_t HttpResponse::bodyLength()
{
  return bodyLength_;
}

