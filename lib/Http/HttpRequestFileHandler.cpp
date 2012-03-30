#include "HttpRequestFileHandler.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "FileApi.h"

HttpRequestFileHandler::HttpRequestFileHandler( std::string basePath, FileApi& fileApi )
  : basePath_( basePath )
  , fileApi_( fileApi )
{ }

HttpRequestFileHandler::~HttpRequestFileHandler()
{ }

HttpResponse* HttpRequestFileHandler::handle( HttpRequest& request )
{
  std::string path( basePath_ + request.url() );
  std::string fileContents = fileApi_.readToEnd( path );

  HttpResponse* response = new HttpResponse( fileContents );
  return response;
}

