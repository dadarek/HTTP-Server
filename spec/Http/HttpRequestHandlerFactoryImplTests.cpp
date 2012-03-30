#include "gtest/gtest.h"
#include "MockFileApi.h"
#include "HttpRequestHandlerFactoryImpl.h"
#include "HttpRequest.h"

class HttpRequestHandlerFactoryImplTests
  : public ::testing::Test
{
  public:

};

TEST_F( HttpRequestHandlerFactoryImplTests, returnsFileHandlerIfFileIsValid )
{
  std::string basePath = "/some/base/";
  MockFileApi fileApi;
  HttpRequestHandlerFactoryImpl factory( basePath, fileApi );
}


