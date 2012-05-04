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
  throw 0;
}
