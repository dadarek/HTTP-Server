#include "gtest/gtest.h"
#include "HttpRequestHandlerFactoryImpl.h"
#include "HttpRequest.h"

class HttpRequestHandlerFactoryImplTests
  : public ::testing::Test
{
  public:

};

TEST_F( HttpRequestHandlerFactoryImplTests, Compiles )
{
  HttpRequestHandlerFactoryImpl factory;
}


