#include "HttpDirectoryListRequestHandler.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "DirectoryApi.h"

HttpDirectoryListRequestHandler::HttpDirectoryListRequestHandler( FileApi& directoryApi )
  : directoryApi_( directoryApi )
{ }

HttpDirectoryListRequestHandler::~HttpDirectoryListRequestHandler()
{ }

HttpResponse* HttpDirectoryListRequestHandler::handle( HttpRequest& request )
{
  throw 0;
}
