#include "ChartRequestHandlerFactory.h"
#include "ChartRequestHandler.h"

ChartRequestHandlerFactory::ChartRequestHandlerFactory()
{ }

ChartRequestHandlerFactory::~ChartRequestHandlerFactory()
{ }

HttpRequestHandler* ChartRequestHandlerFactory::createHandler( HttpRequest& )
{ 
  return new ChartRequestHandler();
}

