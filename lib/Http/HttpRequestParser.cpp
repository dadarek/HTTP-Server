#include "HttpRequestParser.h"
#include "HttpRequest.h"

HttpRequestParser::HttpRequestParser()
{ }

HttpRequestParser::~HttpRequestParser()
{ }

HttpRequest* HttpRequestParser::parse( std::string headers )
{ 
  int urlStartIndex = headers.find(" ") + 1;
  int urlEndIndex = headers.find(" HTTP/1.1\r\n");

  int urlLength = urlEndIndex - urlStartIndex;

  std::string url = headers.substr( urlStartIndex, urlLength );
  return new HttpRequest( url );
}

