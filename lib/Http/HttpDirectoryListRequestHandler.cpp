#include "HttpDirectoryListRequestHandler.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "FileApi.h"

HttpDirectoryListRequestHandler::HttpDirectoryListRequestHandler( FileApi& fileApi )
  : fileApi_( fileApi )
{ }

HttpDirectoryListRequestHandler::~HttpDirectoryListRequestHandler()
{ }

HttpResponse* HttpDirectoryListRequestHandler::handle( HttpRequest& request )
{
  throw 0;
}
