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
  std::string body = getBody( directoryPath.c_str() );

  return new HttpResponse( body.c_str(), body.length(), "200 OK" );
}

std::string HttpDirectoryListRequestHandler::getBody( const char* folder )
{
  std::string result;

  DIR* directory = directoryApi_.opendir( folder );
  struct dirent* directoryEntry;
  while( 0 != (directoryEntry = directoryApi_.readdir( directory ) )  )
  {
    std::string name( directoryEntry->d_name );
    result += name;
  }
  if( 0 != directory )
    directoryApi_.closedir( directory );

  return result;
}
