#include "HttpRequestParserImpl.h"
#include "HttpRequest.h"
#include "InvalidHttpRequestHeadersException.h"

HttpRequestParserImpl::HttpRequestParserImpl()
{ }

HttpRequestParserImpl::~HttpRequestParserImpl()
{ }

HttpRequest* HttpRequestParserImpl::parse( std::string headers )
{ 
  int firstSpaceIndex = headers.find(" ");
  int httpVersionIndex = headers.find(" HTTP/1.1\r\n");

  if ( firstSpaceIndex < 1 || httpVersionIndex < firstSpaceIndex )
    throw InvalidHttpRequestHeadersException();


  int urlStartIndex = firstSpaceIndex + 1;
  int urlEndIndex = httpVersionIndex;

  int urlLength = urlEndIndex - urlStartIndex;

  std::string url = headers.substr( urlStartIndex, urlLength );
  std::string method = headers.substr( 0, urlStartIndex-1 );

  return new HttpRequest( method, url );
}

