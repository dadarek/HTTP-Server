#include "gtest/gtest.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "HttpQueryStringRequestHandler.h"

class HttpQueryStringRequestHandlerTests
  : public ::testing::Test
{
  public:
    HttpQueryStringRequestHandler handler_;

    HttpQueryStringRequestHandlerTests()
      : handler_()
    { }

    HttpResponse* getResponse( const char* url )
    {
      HttpRequest request( "", url );
      return handler_.handle( request );
    }
    void assertResponseContains( const char* value )
    {

    }

};

TEST_F( HttpQueryStringRequestHandlerTests, BodyContainsOneQueryString )
{
  HttpResponse* response = getResponse( "/some-script?x=1" );
  char* index = strstr( response->body(), "x = 1" );
  ASSERT_NE( (char*) 0, index );
  
  delete response;
}

TEST_F( HttpQueryStringRequestHandlerTests, BodyContainsTwoQueryStrings )
{
  HttpResponse* response = getResponse( "/another-script?x=4&y=7" );

  char* index = strstr( response->body(), "x = 4" );
  ASSERT_NE( (char*) 0, index );
  
  index = strstr( response->body(), "y = 7" );
  ASSERT_NE( (char*) 0, index );
  
  delete response;
}
