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

  DIR* directory = directoryApi_.opendir( directoryPath.c_str() );
  while( directoryApi_.readdir( directory ) ) ;

  return new HttpResponse( "", 0, "" );
}
