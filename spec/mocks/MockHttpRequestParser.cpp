#include "MockHttpRequestParser.h"

MockHttpRequestParser::MockHttpRequestParser()
  : parseReturnValue_( 0 )
{ }

MockHttpRequestParser::~MockHttpRequestParser()
{ }

HttpRequest* MockHttpRequestParser::parse( std::string request )
{
  stringToParse_ = request;
  return parseReturnValue_;
}
