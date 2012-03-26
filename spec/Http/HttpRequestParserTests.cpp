#include "gtest/gtest.h"
#include "Http/HttpRequestParser.h"
#include "Http/HttpRequest.h"

class HttpRequestParserTests
  : public testing::Test
{
  protected:
    std::string parse( std::string headers )
    {
      HttpRequestParser parser;
      
      HttpRequest* request = parser.parse( headers );
      std::string url = request->url();
      delete request;
      
      return url;
    }

    void parseAndAssert( std::string headers, std::string expectedUrl )
    {
      ASSERT_EQ( expectedUrl, parse( headers ) );
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
  EXPECT_THROW( parse( headers ), int );
}

// TODO: Throw parse exceptions
//
// TODO: Handle encodings? maybe?
//    At least handle spaces ...
//
