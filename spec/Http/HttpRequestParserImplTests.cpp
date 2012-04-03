#include "gtest/gtest.h"
#include "HttpRequestParserImpl.h"
#include "HttpRequest.h"
#include "InvalidHttpRequestHeadersException.h"

class HttpRequestParserImplTests
  : public testing::Test
{
  protected:
    HttpRequestParserImpl parser_;

    std::string parseOutUrl( std::string headers )
    {
      HttpRequest* request = parser_.parse( headers );
      std::string url = request->url();
      delete request;
      
      return url;
    }

    void assertMethod( const char* headers, const char* expectedMethod ) 
    {
      HttpRequest* request = parser_.parse( std::string(headers) );
      ASSERT_EQ( std::string(expectedMethod), request->method() );
      delete request;
    }

    void expectInvalidHeaderException( const char* headers )
    {
      EXPECT_THROW( parser_.parse( std::string(headers) ), InvalidHttpRequestHeadersException );
    }
};

TEST_F( HttpRequestParserImplTests, ParsesHeaders )
{
  std::string headers( "GET /someUrl.ext HTTP/1.1\r\nSomeOtherHeaders\r\nMoreHeaders" );
  ASSERT_STREQ( "/someUrl.ext", parseOutUrl( headers ).c_str() );
}

TEST_F( HttpRequestParserImplTests, ParsesHeaders2 )
{
  std::string headers( "GET /AnotherUrl.html HTTP/1.1\r\nOtherHeaers");
  ASSERT_STREQ( "/AnotherUrl.html", parseOutUrl( headers ).c_str() );
}

TEST_F( HttpRequestParserImplTests, HandlesSpaces )
{
  std::string headers( "GET /Some Url with spaces.html HTTP/1.1\r\nOther Headers" );
  ASSERT_STREQ( "/Some Url with spaces.html", parseOutUrl( headers ).c_str() );
}

TEST_F( HttpRequestParserImplTests, HandlesEncodings )
{
  std::string headers( "GET /Look%20Space HTTP/1.1\r\nOther Headers" );
  ASSERT_STREQ( "/Look%20Space", parseOutUrl( headers ).c_str() );
}

TEST_F( HttpRequestParserImplTests, ParsesMethod )
{
  assertMethod( "POST /some-url HTTP/1.1\r\n", "POST" );
}

TEST_F( HttpRequestParserImplTests, ParsesDifferentMethods )
{
  assertMethod( "PUT /some-url HTTP/1.1\r\n", "PUT" );
}

TEST_F( HttpRequestParserImplTests, ParsesOutBody )
{
  std::string headers( "PUT / HTTP/1.1" );
  std::string body( "Some body\r\n here\r\n\r\nand here" );
  HttpRequest* request = parser_.parse( headers + "\r\n\r\n" + body );

  //int diff = memcmp( body.c_str(), request->body(), body.length() );
  ASSERT_EQ( body.length(), request->bodyLength() );
}

TEST_F( HttpRequestParserImplTests, ThrowsExceptionOnInvalidHeaders )
{
  expectInvalidHeaderException( "HTTP/1.1\r\n" );
  expectInvalidHeaderException( "Some Invalid Header" );
  expectInvalidHeaderException( "GET IncompleteHeader" );
  expectInvalidHeaderException( "GET BuggyHeaderHTTP/1.1\r\nOtherHeaders: Well Formatted\r\n" );
}

