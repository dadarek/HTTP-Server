#include "ChartRequestHandlerFactory.h"
#include "Http404RequestHandler.h"
#include "HttpRequestFileHandler.h"
#include "HttpDirectoryListRequestHandler.h"
#include "HttpEchoRequestHandler.h"
#include "HttpQueryStringRequestHandler.h"
#include "FileApi.h"
#include "DirectoryApi.h"
#include "HttpRequest.h"

ChartRequestHandlerFactory::ChartRequestHandlerFactory()
{ }

ChartRequestHandlerFactory::~ChartRequestHandlerFactory()
{ }

HttpRequestHandler* ChartRequestHandlerFactory::createHandler( HttpRequest& request )
{ 
  return 0;
}

