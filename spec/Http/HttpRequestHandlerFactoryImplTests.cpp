#include "gtest/gtest.h"
#include "MockFileApi.h"
#include "HttpRequestHandlerFactoryImpl.h"
#include "HttpRequest.h"

class HttpRequestHandlerFactoryImplTests
  : public ::testing::Test
{
  public:

};

TEST_F( HttpRequestHandlerFactoryImplTests, asksFileApiIfCorrectFileExists )
{
  MockFileApi fileApi;

  std::string basePath = "/some/base/";
  HttpRequest request( "some-url.html" );

  HttpRequestHandlerFactoryImpl factory( basePath, fileApi );

  factory.createHandler( request );

  ASSERT_EQ( "/some/base/some-url.html", fileApi.existsInput_ ); 
}


