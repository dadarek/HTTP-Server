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
  return 0;
}


