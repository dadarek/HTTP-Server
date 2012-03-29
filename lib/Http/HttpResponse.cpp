#include "HttpResponse.h"

HttpResponse::HttpResponse( std::string body )
  : body_( body )
  , charBody_( 0 )
{ }

HttpResponse::HttpResponse( const char* body, size_t bodyLength )
  : charBody_( new char[ bodyLength ] )
{
  memcpy( charBody_, body, bodyLength );
}

HttpResponse::~HttpResponse()
{
  if( 0 != charBody_ )
    delete[] charBody_;
}

const char* HttpResponse::charBody()
{
  return charBody_;
}

std::string HttpResponse::body()
{
  return body_;
}

