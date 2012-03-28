#include "gtest/gtest.h"
#include "HttpRequestParserImpl.h"
#include "HttpRequest.h"
#include "InvalidHttpRequestHeadersException.h"

class HttpRequestParserImplTests
  : public testing::Test
{
  protected:
    std::string parse( std::string headers )
    {
      HttpRequestParserImpl parser;
      
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

TEST_F( HttpRequestParserImplTests, ParsesHeaders )
{
  std::string headers( "GET /someUrl.ext HTTP/1.1\r\nSomeOtherHeaders\r\nMoreHeaders" );
  parseAndAssert( headers, "/someUrl.ext" );
}

TEST_F( HttpRequestParserImplTests, ParsesHeaders2 )
{
  std::string headers( "GET /AnotherUrl.html HTTP/1.1\r\nOtherHeaers");
  parseAndAssert( headers, "/AnotherUrl.html" );
}

TEST_F( HttpRequestParserImplTests, ThrowsException )
{
  EXPECT_THROW( parse( "Some Invalid Header" ), InvalidHttpRequestHeadersException );
  EXPECT_THROW( parse( "GET IncompleteHeader" ), InvalidHttpRequestHeadersException );
  EXPECT_THROW( parse( "GET BuggyHeaderHTTP/1.1\r\nOtherHeaders: Well Formatted\r\n" ), InvalidHttpRequestHeadersException );
}

TEST_F( HttpRequestParserImplTests, HandlesSpaces )
{
  std::string headers( "GET /Some Url with spaces.html HTTP/1.1\r\nOther Headers" );
  parseAndAssert( headers, "/Some Url with spaces.html" );
}

TEST_F( HttpRequestParserImplTests, HandlesEncodings )
{
  std::string headers( "GET /Look%20Space HTTP/1.1\r\nOther Headers" );
  parseAndAssert( headers, "/Look%20Space" );
}
