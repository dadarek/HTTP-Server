#include "HttpRequestParser.h"
#include "HttpRequest.h"

HttpRequestParser::HttpRequestParser()
{ }

HttpRequestParser::~HttpRequestParser()
{ }

HttpRequest* HttpRequestParser::parse( std::string )
{ 
  return new HttpRequest( "/someUrl.ext" );
}

