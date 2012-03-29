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
  reader_.readToEnd( path );
  return 0;
}


