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

    virtual ~HttpQueryStringRequestHandlerTests()
    { }

};

TEST_F( HttpQueryStringRequestHandlerTests, BodyContainsOneQueryString )
{
  const char* url = "/some-script?x=1";
  HttpRequest request( "", url );

  HttpResponse* response = handler_.handle( request );

  char* index = strstr( response->body(), "x = 1" );
  ASSERT_NE( (char*) 0, index );
  
  delete response;
}

TEST_F( HttpQueryStringRequestHandlerTests, BodyContainsTwoQueryStrings )
{
  const char* url = "/another-script?x=4&y=7";
  HttpRequest request( "", url );

  HttpResponse* response = handler_.handle( request );

  char* index = strstr( response->body(), "x = 4" );
  ASSERT_NE( (char*) 0, index );
  
  index = strstr( response->body(), "y = 7" );
  ASSERT_NE( (char*) 0, index );
  
  delete response;
}
