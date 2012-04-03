#include "HttpRequestHandlerFactoryImpl.h"
#include "Http404RequestHandler.h"
#include "HttpRequestFileHandler.h"
#include "HttpDirectoryListRequestHandler.h"
#include "HttpEchoRequestHandler.h"
#include "FileApi.h"
#include "DirectoryApi.h"
#include "HttpRequest.h"

HttpRequestHandlerFactoryImpl::HttpRequestHandlerFactoryImpl( std::string basePath, FileApi& fileApi, DirectoryApi& directoryApi )
  : basePath_( basePath )
  , fileApi_( fileApi )
  , directoryApi_( directoryApi )
{ }

HttpRequestHandlerFactoryImpl::~HttpRequestHandlerFactoryImpl()
{ }

HttpRequestHandler* HttpRequestHandlerFactoryImpl::createHandler( HttpRequest& request )
{ 
  std::string path( basePath_ + request.url() );

  if( requiresEcho( request ) )
    return new HttpEchoRequestHandler();

  if( directoryExists( path ) )
    return new HttpDirectoryListRequestHandler( basePath_, directoryApi_ );

  if( fileApi_.exists( path ) )
    return new HttpRequestFileHandler( basePath_, fileApi_ );

  return new Http404RequestHandler();
}

bool HttpRequestHandlerFactoryImpl::directoryExists( std::string path )
{
  DIR* directory = directoryApi_.opendir( path.c_str() );
  bool result = (DIR*) 0 != directory;
  if( result )
    directoryApi_.closedir( directory );
  return result;
}

bool HttpRequestHandlerFactoryImpl::requiresEcho( HttpRequest& request )
{
  return request.method() == std::string("PUT")
    || request.method() == std::string("POST");
}
