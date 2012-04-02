#include "gtest/gtest.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "Http404RequestHandler.h"

class Http404RequestHandlerTests
  : public ::testing::Test
{
  public:
    HttpResponse* getResponse( const char* url )
    {
      HttpRequest request( url );
      Http404RequestHandler handler;
      return handler.handle( request );
    }

    char* appendNullTerminator( const char* string, size_t length )
    {
      char* result = new char[ length + 1 ];
      memcpy( result, string, length );
      result[ length ] = '\0';
      return result;
    }

    void assertBodyContains( HttpResponse* response, const char* expectedText )
    {
      char* body = appendNullTerminator( response->body(), response->bodyLength() );
      ASSERT_NE( (char*) 0 , strstr( body, expectedText ) );
      delete[] body;
    }
};

TEST_F( Http404RequestHandlerTests, bodyContainsUrlRequested )
{
  const char* url = "invalid-url.html";
  HttpResponse* response = getResponse( url );
  assertBodyContains( response, url );

  delete response;
}

TEST_F( Http404RequestHandlerTests, bodyContainsNotFoundLiteral )
{
  HttpResponse* response = getResponse( "" );
  assertBodyContains( response, "not found" );

  delete response;
}

TEST_F( Http404RequestHandlerTests, setsCorrect404StatusCode )
{
  HttpResponse* response = getResponse( "" );

  ASSERT_EQ( std::string("404 Not Found"), response->status() );

  delete response;
}
