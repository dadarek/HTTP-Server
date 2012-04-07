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

    void assertResponseContains( HttpResponse* response, const char* value )
    {
      char* index = strstr( response->body(), value );
      ASSERT_NE( (char*) 0, index );
    }
};

TEST_F( HttpQueryStringRequestHandlerTests, BodyContainsOneQueryString )
{
  HttpResponse* response = getResponse( "/some-script?x=1" );
  assertResponseContains( response, "x = 1" );
  delete response;
}

TEST_F( HttpQueryStringRequestHandlerTests, BodyContainsTwoQueryStrings )
{
  HttpResponse* response = getResponse( "/another-script?x=4&y=7" );
  assertResponseContains( response, "x = 4" );
  assertResponseContains( response, "y = 7" );
  delete response;
}

TEST_F( HttpQueryStringRequestHandlerTests, BodyContainsThreeQueryStrings )
{
  HttpResponse* response = getResponse( "/z?name=Darek&id=77&remember=false" );
  assertResponseContains( response, "name = Darek" );
  assertResponseContains( response, "id = 77" );
  assertResponseContains( response, "remember = false" );
  delete response;
}
