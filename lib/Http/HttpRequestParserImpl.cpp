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
  size_t httpVersionIndex = headers.find( httpVersion );

  if( std::string::npos == httpVersionIndex )
    throw InvalidHttpRequestHeadersException();

  const char* firstLine = headers.substr( 0, httpVersionIndex ).c_str();

  char method[5];
  char url[1024];

  int variablesFilled = sscanf( firstLine, "%s %[^\r]", method, url );
  printf("Variables filed: %d\n", variablesFilled );
  if( 2 != variablesFilled )
    throw InvalidHttpRequestHeadersException();

  size_t bodyStartIndex = headers.find("\r\n\r\n") + 4;
  size_t bodyEndIndex = headers.length();

  HttpRequest* result = new HttpRequest( std::string(method), std::string(url) );

  if( bodyStartIndex != std::string::npos 
      && bodyStartIndex < bodyEndIndex )
  {
    size_t bodyLength = bodyEndIndex - bodyStartIndex;
    const char* body = headers.c_str() + bodyStartIndex;
    result->setBody( body, bodyLength );
  }

  return result;
}
