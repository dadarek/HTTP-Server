#include "HttpQueryStringRequestHandler.h"
#include "HttpResponse.h"
#include "HttpRequest.h"

HttpQueryStringRequestHandler::HttpQueryStringRequestHandler()
{ }

HttpQueryStringRequestHandler::~HttpQueryStringRequestHandler()
{ }

HttpResponse* HttpQueryStringRequestHandler::handle( HttpRequest& request )
{
  HttpResponse* result = new HttpResponse( "x = 1", 5, "" );
  return result;
}
