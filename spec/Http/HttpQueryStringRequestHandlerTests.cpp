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
  HttpRequest request( url, "" );

  HttpResponse* response = handler_.handle( request );

  char* index = strstr( response->body(), "x = 1" );
  ASSERT_NE( (char*) 0, index );
  
  delete response;
}
