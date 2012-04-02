#include "gtest/gtest.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "HttpEchoRequestHandler.h"

class HttpEchoRequestHandlerTests
  : public ::testing::Test
{
  public:
};

TEST_F( HttpEchoRequestHandlerTests, Compiles )
{
  const char* body = "abcdef";
  size_t length = strlen( body );

  HttpRequest request( "", "" );
  request.setBody( body, length );

  HttpEchoRequestHandler handler;

  HttpResponse* response = handler.handle( request );

  ASSERT_EQ( length, response->bodyLength() );

  delete response;
}

