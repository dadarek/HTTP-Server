#include "HttpRequestHandlerFactoryImpl.h"
#include "Http404RequestHandler.h"
#include "FileApi.h"
#include "HttpRequest.h"

HttpRequestHandlerFactoryImpl::HttpRequestHandlerFactoryImpl( std::string basePath, FileApi& fileApi )
  : basePath_( basePath )
  , fileApi_( fileApi )
{ }

HttpRequestHandlerFactoryImpl::~HttpRequestHandlerFactoryImpl()
{ }

HttpRequestHandler* HttpRequestHandlerFactoryImpl::createHandler( HttpRequest& request )
{ 
  fileApi_.exists( basePath_ + request.url() );
  return new Http404RequestHandler();
}

