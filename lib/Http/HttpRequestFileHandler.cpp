#include "HttpRequestFileHandler.h"
#include "HttpRequest.h"
#include "HttpResponse.H"

HttpRequestFileHandler::HttpRequestFileHandler( std::string basePath, FileReader& reader )
  : basePath_( basePath )
  , reader_( reader )
{ }

HttpRequestFileHandler::~HttpRequestFileHandler()
{ }

HttpResponse* HttpRequestFileHandler::handle( HttpRequest& request )
{
  std::string path( basePath_ + request.url() );
  std::string fileContents = reader_.readToEnd( path );

  HttpResponse* response = new HttpResponse( fileContents );
  return response;
}


