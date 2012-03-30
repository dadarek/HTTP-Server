#include "gtest/gtest.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "Http404RequestHandler.h"
#include <string>

class Http404RequestHandlerTests
  : public ::testing::Test
{
  public:
    std::string getBody( const char* url )
    {
      HttpRequest request( url );
      Http404RequestHandler handler;
      return handler.handle( request )->body();
    }
};

TEST_F( Http404RequestHandlerTests, bodyContainsUrlRequested )
{
  const char* url = "invalid-url.html";
  std::string body = getBody( url );
  
  ASSERT_LE( (size_t) 0 , body.find( url ) );
  ASSERT_GT( body.length() , body.find( url ) );
}

TEST_F( Http404RequestHandlerTests, bodyContainsNotFoundLiteral )
{
  std::string body = getBody( "" );
  
  ASSERT_LE( (size_t) 0 , body.find( "not found" ) );
  ASSERT_GT( body.length() , body.find( "not found" ) );
}
