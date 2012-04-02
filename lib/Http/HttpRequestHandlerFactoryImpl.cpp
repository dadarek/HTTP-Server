#include "HttpRequestHandlerFactoryImpl.h"
#include "Http404RequestHandler.h"
#include "HttpRequestFileHandler.h"
#include "HttpDirectoryListRequestHandler.h"
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
  DIR* directory = directoryApi_.opendir( path.c_str() );
  bool directoryExists = ((DIR*) 0) != directory;
  if( directoryExists )
    return new HttpDirectoryListRequestHandler( basePath_, directoryApi_ );
  

  bool fileExists = fileApi_.exists( path );
  if( fileExists )
    return createFileHandler();

  return create404Handler();
}

HttpRequestHandler* HttpRequestHandlerFactoryImpl::createFileHandler()
{
  return new HttpRequestFileHandler( basePath_, fileApi_ );
}

HttpRequestHandler* HttpRequestHandlerFactoryImpl::create404Handler()
{
  return new Http404RequestHandler();
}

