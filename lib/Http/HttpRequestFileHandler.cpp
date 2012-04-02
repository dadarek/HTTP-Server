#include "HttpRequestFileHandler.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "FileApi.h"

const char* const HttpRequestFileHandler::STATUS_200 = "200 OK";

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

  HttpResponse* response = new HttpResponse( contents, size, STATUS_200 );

  delete[] contents;
  return response;
}

