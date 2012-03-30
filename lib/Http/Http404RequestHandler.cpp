#include "Http404RequestHandler.h"
#include "HttpResponse.h"
#include "HttpRequest.h"
#include <sstream>

const char* const Http404RequestHandler::HTML_404 = "<h1>Page Not Found</h1>";
Http404RequestHandler::Http404RequestHandler()
{ }

Http404RequestHandler::~Http404RequestHandler()
{ }

HttpResponse* Http404RequestHandler::handle( HttpRequest& request )
{
  std::stringstream message;
  message << "The requested url: ";
  message << request.url();
  message << " was not found.";
  HttpResponse* result = new HttpResponse( message.str() );
  return result;
}
