#include "HttpRequestHandlerFactoryImpl.h"
#include "Http404RequestHandler.h"
#include "HttpRequestFileHandler.h"
#include "FileApi.h"
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
  bool fileExists = fileApi_.exists( basePath_ + request.url() );
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

