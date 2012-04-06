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

TEST_F( HttpQueryStringRequestHandlerTests, Compiles )
{
  ASSERT_EQ( true, true );
}
