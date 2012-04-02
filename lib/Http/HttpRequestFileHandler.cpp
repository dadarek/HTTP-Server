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

  char* contents;
  size_t size = fileApi_.readToEnd( path, &contents );

  HttpResponse* response = new HttpResponse( contents, size );

  delete[] contents;
  return response;
}

