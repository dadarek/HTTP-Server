#include "HttpRequestParserImpl.h"
#include "HttpRequest.h"
#include "InvalidHttpRequestHeadersException.h"

HttpRequestParserImpl::HttpRequestParserImpl()
{ }

HttpRequestParserImpl::~HttpRequestParserImpl()
{ }

HttpRequest* HttpRequestParserImpl::parse( std::string headers )
{ 
  const char* httpVersion = " HTTP/1.1\r\n";
  size_t firstSpaceIndex = headers.find(" ");
  size_t httpVersionIndex = headers.find( httpVersion );

  if( std::string::npos == httpVersionIndex )
    throw InvalidHttpRequestHeadersException();

  //if ( firstSpaceIndex < 1 || httpVersionIndex < firstSpaceIndex )
  //  throw InvalidHttpRequestHeadersException();


  size_t urlStartIndex = firstSpaceIndex + 1;
  size_t urlEndIndex = httpVersionIndex;

  size_t urlLength = urlEndIndex - urlStartIndex;

  std::string url = headers.substr( urlStartIndex, urlLength );
  std::string method = headers.substr( 0, urlStartIndex-1 );


  size_t bodyStartIndex = headers.find("\r\n\r\n") + 4;
  size_t bodyEndIndex = headers.length();

  HttpRequest* result = new HttpRequest( method, url );

  if( bodyStartIndex != std::string::npos 
      && bodyStartIndex < bodyEndIndex )
  {
    size_t bodyLength = bodyEndIndex - bodyStartIndex;
    const char* body = headers.c_str() + bodyStartIndex;
    result->setBody( body, bodyLength );
  }

  return result;
}

