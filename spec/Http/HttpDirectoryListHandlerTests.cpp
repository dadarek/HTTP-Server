#include "gtest/gtest.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "MockFileApi.h"
#include "HttpDirectoryListRequestHandler.h"

class HttpDirectoryListRequestHandlerTests
  : public ::testing::Test
{

};

TEST_F( HttpDirectoryListRequestHandlerTests, Compiles )
{
  MockFileApi fileApi;
  HttpDirectoryListRequestHandler handler( fileApi );
}
