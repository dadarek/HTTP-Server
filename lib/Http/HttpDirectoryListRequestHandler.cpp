#include "HttpDirectoryListRequestHandler.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "DirectoryApi.h"

HttpDirectoryListRequestHandler::HttpDirectoryListRequestHandler( std::string basePath, DirectoryApi& directoryApi )
  : basePath_( basePath )
  , directoryApi_( directoryApi )
{ }

HttpDirectoryListRequestHandler::~HttpDirectoryListRequestHandler()
{ }

HttpResponse* HttpDirectoryListRequestHandler::handle( HttpRequest& request )
{
  std::string directoryPath = basePath_ + request.url();
  directoryApi_.opendir( directoryPath.c_str() );
}
