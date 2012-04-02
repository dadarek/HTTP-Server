#include "gtest/gtest.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "MockDirectoryApi.h"
#include "HttpDirectoryListRequestHandler.h"

class HttpDirectoryListRequestHandlerTests
  : public ::testing::Test
{

};

TEST_F( HttpDirectoryListRequestHandlerTests, OpensCorrectFolder )
{
  MockDirectoryApi directoryApi;
  std::string basePath( "/some/base/" );
  std::string url( "/some/folder/" );
  HttpDirectoryListRequestHandler handler( basePath, directoryApi );

  HttpRequest request( url );
  handler.handle(request);

  ASSERT_EQ( basePath + url, directoryApi.directoryOpened_ );
}

TEST_F( HttpDirectoryListRequestHandlerTests, CallsReadDirWithCorrectDIRPointer )
{
  MockDirectoryApi directoryApi;
  HttpDirectoryListRequestHandler handler( "", directoryApi );
  HttpRequest request( "" );

  directoryApi.opendir_returnValue_ = (DIR*) 77;
  handler.handle( request );

  ASSERT_EQ( (DIR*) 77, directoryApi.readdir_input_ );
}
