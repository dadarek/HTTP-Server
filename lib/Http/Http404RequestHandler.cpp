#include "Http404RequestHandler.h"


const char* const Http404RequestHandler::HTML_404 = "<h1>Page Not Found</h1>";
Http404RequestHandler::Http404RequestHandler()
{ }

Http404RequestHandler::~Http404RequestHandler()
{ }

HttpResponse* Http404RequestHandler::handle( HttpRequest& request )
{
  throw 0;
}
