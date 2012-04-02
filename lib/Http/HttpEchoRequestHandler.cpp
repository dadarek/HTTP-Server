#include "HttpEchoRequestHandler.h"
#include "HttpRequest.h"
#include "HttpResponse.h"

HttpEchoRequestHandler::HttpEchoRequestHandler()
{ }

HttpEchoRequestHandler::~HttpEchoRequestHandler()
{ }

HttpResponse* HttpEchoRequestHandler::handle( HttpRequest& request )
{
  HttpResponse* response = new HttpResponse( request.body(), request.bodyLength(), "" );
  return response;
}
