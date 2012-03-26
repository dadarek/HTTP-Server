#include "gtest/gtest.h"
#include "Http/HttpRequestParser.h"
#include "Http/HttpRequest.h"

class HttpRequestParserTests
  : public testing::Test
{

};

TEST( HttpRequestParserTests, ParsesHeaders )
{
  std::string requestString( "GET /someUrl.ext HTTP/1.1\r\nSomeOtherHeaders\r\nMoreHeaders" );
  HttpRequestParser parser;
  HttpRequest* request = parser.parse( requestString );

  ASSERT_EQ( "/someUrl.ext", request->url() );

  delete request;
}

// TODO: Throw parse exceptions
//
