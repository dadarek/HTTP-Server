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

    bool responseContains( HttpResponse* response, const char* value )
    {
      char* index = strstr( response->body(), value );
      return index != 0;
    }
};

TEST_F( HttpQueryStringRequestHandlerTests, BodyContainsOneQueryString )
{
  HttpResponse* response = getResponse( "/some-script?x=1" );
  ASSERT_EQ( true, responseContains( response, "x = 1" ) );
  delete response;
}

TEST_F( HttpQueryStringRequestHandlerTests, BodyContainsTwoQueryStrings )
{
  HttpResponse* response = getResponse( "/another-script?x=4&y=7" );
  ASSERT_EQ( true, responseContains( response, "x = 4" ) );
  ASSERT_EQ( true, responseContains( response, "y = 7" ) );
  delete response;
}

TEST_F( HttpQueryStringRequestHandlerTests, BodyContainsThreeQueryStrings )
{
  HttpResponse* response = getResponse( "/z?name=Darek&id=77&remember=false" );
  ASSERT_EQ( true, responseContains( response, "name = Darek" ) );
  ASSERT_EQ( true, responseContains( response, "id = 77" ) );
  ASSERT_EQ( true, responseContains( response, "remember = false" ) );
  delete response;
}

