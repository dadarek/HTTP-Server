#include "MockHttpRequestParser.h"

MockHttpRequestParser::MockHttpRequestParser()
{ }

MockHttpRequestParser::~MockHttpRequestParser()
{ }

HttpRequest* MockHttpRequestParser::parse( std::string )
{
  throw 0;
}
