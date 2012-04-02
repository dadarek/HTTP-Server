#include "HttpRequestParserImpl.h"
#include "HttpRequest.h"
#include "InvalidHttpRequestHeadersException.h"

HttpRequestParserImpl::HttpRequestParserImpl()
{ }

HttpRequestParserImpl::~HttpRequestParserImpl()
{ }

HttpRequest* HttpRequestParserImpl::parse( std::string headers )
{ 
  int urlStartIndex = headers.find(" ") + 1;
  int urlEndIndex = headers.find(" HTTP/1.1\r\n");

  if ( urlStartIndex < 1 || urlEndIndex < urlStartIndex )
    throw InvalidHttpRequestHeadersException();

  int urlLength = urlEndIndex - urlStartIndex;

  std::string url = headers.substr( urlStartIndex, urlLength );

  std::string method = headers.substr( 0, urlStartIndex-1 );
  return new HttpRequest( method, url );
}

