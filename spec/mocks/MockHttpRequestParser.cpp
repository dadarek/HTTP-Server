#include "MockHttpRequestParser.h"

MockHttpRequestParser::MockHttpRequestParser()
{ }

MockHttpRequestParser::~MockHttpRequestParser()
{ }

HttpRequest* MockHttpRequestParser::parse( std::string request )
{
  stringToParse_ = request;
  return 0;
}
