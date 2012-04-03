#include "gtest/gtest.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "HttpEchoRequestHandler.h"

class HttpEchoRequestHandlerTests
  : public ::testing::Test
{
  public:
    HttpRequest request_;
    HttpEchoRequestHandler handler_;

    HttpEchoRequestHandlerTests()
      : request_( "", "" )
      , handler_()
    { }

    void setRequestBody( const char* body )
    {
      size_t length = strlen( body );
      request_.setBody( body, length );
    }

    HttpResponse* getResponse()
    {
      return handler_.handle( request_ );
    }
};

TEST_F( HttpEchoRequestHandlerTests, EchoseBody )
{
  const char* body = "abcdef";
  setRequestBody( body );

  HttpResponse* response = getResponse();

  int diff = memcmp( response->body(), body, strlen(body) );
  ASSERT_EQ( 0, diff );

  delete response;
}

TEST_F( HttpEchoRequestHandlerTests, SetsCorrectBodyLength )
{
  const char* body = "abcdef";
  setRequestBody( body );

  HttpResponse* response = getResponse();

  ASSERT_EQ( strlen(body), response->bodyLength() );

  delete response;
}

TEST_F( HttpEchoRequestHandlerTests, Sets200Status )
{
  HttpResponse* response = getResponse();
  ASSERT_EQ( "200 OK", response->status() );
  delete response;
}
