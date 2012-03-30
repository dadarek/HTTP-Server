#include "HttpRequestHandlerFactoryImpl.h"
#include "FileApi.h"

HttpRequestHandlerFactoryImpl::HttpRequestHandlerFactoryImpl( FileApi& fileApi )
  : fileApi_( fileApi )
{ }

HttpRequestHandlerFactoryImpl::~HttpRequestHandlerFactoryImpl()
{ }

HttpRequestHandler* HttpRequestHandlerFactoryImpl::createHandler( HttpRequest& request )
{ 
  throw 0;
}

