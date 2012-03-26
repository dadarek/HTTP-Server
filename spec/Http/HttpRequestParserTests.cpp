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

TEST( HttpRequestParserTests, ParsesHeaders2 )
{
  std::string requestString( "GET /AnotherUrl.html HTTP/1.1\r\nOtherHeaers");
  HttpRequestParser parser;
  HttpRequest* request = parser.parse( requestString );

  ASSERT_EQ( "/AnotherUrl.html", request->url() );

  delete request;
}

// TODO: Throw parse exceptions
//
// TODO: Handle encodings? maybe?
//    At least handle spaces ...
//
