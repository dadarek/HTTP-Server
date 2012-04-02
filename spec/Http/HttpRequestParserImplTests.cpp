#include "gtest/gtest.h"
#include "HttpRequestParserImpl.h"
#include "HttpRequest.h"
#include "InvalidHttpRequestHeadersException.h"

class HttpRequestParserImplTests
  : public testing::Test
{
  protected:
    std::string parseOutUrl( std::string headers )
    {
      HttpRequestParserImpl parser;
      
      HttpRequest* request = parser.parse( headers );
      std::string url = request->url();
      delete request;
      
      return url;
    }

    void assertUrl( std::string headers, std::string expectedUrl )
    {
      ASSERT_EQ( expectedUrl, parseOutUrl( headers ) );
    }

    void assertMethod( const char* headers, const char* expectedMethod ) 
    {
      HttpRequestParserImpl parser;
      HttpRequest* request = parser.parse( std::string(headers) );
      ASSERT_EQ( std::string(expectedMethod), request->method() );
      delete request;
    }
};

TEST_F( HttpRequestParserImplTests, ParsesHeaders )
{
  std::string headers( "GET /someUrl.ext HTTP/1.1\r\nSomeOtherHeaders\r\nMoreHeaders" );
  assertUrl( headers, "/someUrl.ext" );
}

TEST_F( HttpRequestParserImplTests, ParsesHeaders2 )
{
  std::string headers( "GET /AnotherUrl.html HTTP/1.1\r\nOtherHeaers");
  assertUrl( headers, "/AnotherUrl.html" );
}

TEST_F( HttpRequestParserImplTests, ThrowsException )
{
  EXPECT_THROW( parseOutUrl( "Some Invalid Header" ), InvalidHttpRequestHeadersException );
  EXPECT_THROW( parseOutUrl( "GET IncompleteHeader" ), InvalidHttpRequestHeadersException );
  EXPECT_THROW( parseOutUrl( "GET BuggyHeaderHTTP/1.1\r\nOtherHeaders: Well Formatted\r\n" ), InvalidHttpRequestHeadersException );
}

TEST_F( HttpRequestParserImplTests, HandlesSpaces )
{
  std::string headers( "GET /Some Url with spaces.html HTTP/1.1\r\nOther Headers" );
  assertUrl( headers, "/Some Url with spaces.html" );
}

TEST_F( HttpRequestParserImplTests, HandlesEncodings )
{
  std::string headers( "GET /Look%20Space HTTP/1.1\r\nOther Headers" );
  assertUrl( headers, "/Look%20Space" );
}

TEST_F( HttpRequestParserImplTests, ParsesMethod )
{
  assertMethod( "POST /some-url HTTP/1.1\r\n", "POST" );
}

TEST_F( HttpRequestParserImplTests, ParsesDifferentMethods )
{
  assertMethod( "PUT /some-url HTTP/1.1\r\n", "PUT" );
}
