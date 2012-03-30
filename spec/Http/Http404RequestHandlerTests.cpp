#include "gtest/gtest.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "Http404RequestHandler.h"
#include <string>

class Http404RequestHandlerTests
  : public ::testing::Test
{
  public:

};

TEST_F( Http404RequestHandlerTests, bodyContainsUrlRequested )
{
  HttpRequest request( "invalid-url.html" );
  Http404RequestHandler handler;

  HttpResponse* response = handler.handle( request );
  std::string body = response->body();
  
  ASSERT_LE( (size_t) 0 , body.find( "invalid-url.html" ) );
  ASSERT_GT( body.length() , body.find( "invalid-url.html" ) );
}

TEST_F( Http404RequestHandlerTests, bodyContainsNotFoundLiteral )
{
  HttpRequest request( "" );
  Http404RequestHandler handler;

  HttpResponse* response = handler.handle( request );
  std::string body = response->body();
  
  ASSERT_LE( (size_t) 0 , body.find( "not found" ) );
  ASSERT_GT( body.length() , body.find( "not found" ) );
}
