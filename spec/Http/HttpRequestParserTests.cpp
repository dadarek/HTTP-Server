#include "gtest/gtest.h"
#include "Http/HttpRequestParser.h"
#include "Http/HttpRequest.h"

class HttpRequestParserTests
  : public testing::Test
{
  protected:
    void parseAndAssert( std::string headers, std::string expectedUrl )
    {
      HttpRequestParser parser;
      HttpRequest* request = parser.parse( headers );

      ASSERT_EQ( expectedUrl, request->url() );

      delete request;
    }
};

TEST_F( HttpRequestParserTests, ParsesHeaders )
{
  std::string headers( "GET /someUrl.ext HTTP/1.1\r\nSomeOtherHeaders\r\nMoreHeaders" );
  parseAndAssert( headers, "/someUrl.ext" );
}

TEST_F( HttpRequestParserTests, ParsesHeaders2 )
{
  std::string headers( "GET /AnotherUrl.html HTTP/1.1\r\nOtherHeaers");
  parseAndAssert( headers, "/AnotherUrl.html" );
}

TEST_F( HttpRequestParserTests, ThrowsException )
{
  std::string headers( "Some invalid headers" );
  HttpRequestParser parser;

  EXPECT_THROW( parser.parse( headers ), int );
}

// TODO: Throw parse exceptions
//
// TODO: Handle encodings? maybe?
//    At least handle spaces ...
//
