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
  std::string body;
  std::string directoryPath = basePath_ + request.url();

  DIR* directory = directoryApi_.opendir( directoryPath.c_str() );
  struct dirent* directoryEntry;
  while( 0 != (directoryEntry = directoryApi_.readdir( directory ) )  )
  {
    body += directoryEntry->d_name;
  }

  return new HttpResponse( body.c_str(), body.length(), "" );
}
