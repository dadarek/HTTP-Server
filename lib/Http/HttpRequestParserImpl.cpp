#include "HttpRequestParserImpl.h"
#include "HttpRequest.h"
#include "InvalidHttpRequestHeadersException.h"

HttpRequestParserImpl::HttpRequestParserImpl()
{ }

HttpRequestParserImpl::~HttpRequestParserImpl()
{ }

HttpRequest* HttpRequestParserImpl::parse( std::string headers )
{ 
  size_t httpVersionIndex = getHttpVersionIndex( headers );

  const char* firstLine = headers.substr( 0, httpVersionIndex ).c_str();

  char method[5];
  char url[1024];

  int variablesFilled = sscanf( firstLine, "%s %[^\r]", method, url );
  if( 2 != variablesFilled )
    throw InvalidHttpRequestHeadersException();

  HttpRequest* result = new HttpRequest( std::string(method), std::string(url) );
  setBody( headers, result );

  return result;
}

void HttpRequestParserImpl::setBody( std::string headers, HttpRequest* request )
{
  size_t bodyStartIndex = headers.find("\r\n\r\n") + 4;
  size_t bodyEndIndex = headers.length();

  if( bodyStartIndex != std::string::npos 
      && bodyStartIndex < bodyEndIndex )
  {
    size_t bodyLength = bodyEndIndex - bodyStartIndex;
    const char* body = headers.c_str() + bodyStartIndex;
    request->setBody( body, bodyLength );
  }
}

size_t HttpRequestParserImpl::getHttpVersionIndex( std::string headers )
{
  const char* httpVersion = " HTTP/1.1\r\n";
  size_t result = headers.find( httpVersion );

  if( std::string::npos == result )
    throw InvalidHttpRequestHeadersException();

  return result;
}
