#include "gtest/gtest.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "MockDirectoryApi.h"
#include "HttpDirectoryListRequestHandler.h"

class HttpDirectoryListRequestHandlerTests
  : public ::testing::Test
{

};

TEST_F( HttpDirectoryListRequestHandlerTests, Compiles )
{
  MockDirectoryApi directoryApi;
  std::string basePath( "/some/base/" );
  std::string url( "/some/folder/" );
  HttpDirectoryListRequestHandler handler( basePath, directoryApi );

  HttpRequest request( url );
  handler.handle(request);

  ASSERT_EQ( basePath + url, directoryApi.directoryOpened_ );

}
