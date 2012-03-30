#include "HttpRequestHandlerFactoryImpl.h"
#include "Http404RequestHandler.h"
#include "HttpRequestFileHandler.h"
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
  bool fileExists = fileApi_.exists( basePath_ + request.url() );
  if( fileExists )
  {
    return new HttpRequestFileHandler( basePath_, fileApi_ );
  }
  else
  {
    return new Http404RequestHandler();
  }
}

