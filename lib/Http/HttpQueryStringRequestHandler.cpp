#include "HttpQueryStringRequestHandler.h"
#include "HttpResponse.h"
#include "HttpRequest.h"

HttpQueryStringRequestHandler::HttpQueryStringRequestHandler()
{ }

HttpQueryStringRequestHandler::~HttpQueryStringRequestHandler()
{ }

HttpResponse* HttpQueryStringRequestHandler::handle( HttpRequest& request )
{
  std::string copy = request.url();

  size_t equalsSign = copy.find('=');
  while( std::string::npos !=  equalsSign )
  {
    copy.replace( equalsSign, 1, " = " );
    equalsSign = copy.find( '=', equalsSign + 2 );
  }

  HttpResponse* result = new HttpResponse( copy.c_str(), copy.length(), "200 OK" );
  return result;
}
