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
  HttpEchoRequestHandler handler;

}

