#include "ChartRequestHandler.h"
#include "HttpResponse.h"
#include "HttpRequest.h"
#include <sstream>

ChartRequestHandler::ChartRequestHandler()
{ }

ChartRequestHandler::~ChartRequestHandler()
{ }

HttpResponse* ChartRequestHandler::handle( HttpRequest& )
{
  HttpResponse* response = new HttpResponse( "", 0, "200 OK" );
  return response;
}
