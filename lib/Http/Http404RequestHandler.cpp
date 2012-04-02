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
  std::stringstream buffer;
  buffer << "The requested url: ";
  buffer << request.url();
  buffer << " was not found.";

  std::string message = buffer.str();
  size_t length = message.length();

  HttpResponse* result = new HttpResponse( message.c_str(), length );
  return result;
}
