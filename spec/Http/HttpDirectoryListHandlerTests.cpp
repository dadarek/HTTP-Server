#include "gtest/gtest.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "MockDirectoryApi.h"
#include "HttpDirectoryListRequestHandler.h"

class HttpDirectoryListRequestHandlerTests
  : public ::testing::Test
{
  public:
    MockDirectoryApi directoryApi_;
    std::string basePath_;
    std::string url_;
    HttpRequest request_;
    HttpDirectoryListRequestHandler handler_;

    HttpDirectoryListRequestHandlerTests()
      : directoryApi_()
      , basePath_( "/some/base/" )
      , url_( "some/folder/ ")
      , request_( url_ )
      , handler_( basePath_, directoryApi_)
    { }
    

};

TEST_F( HttpDirectoryListRequestHandlerTests, OpensCorrectFolder )
{
  handler_.handle(request_);
  ASSERT_EQ( basePath_ + url_, directoryApi_.directoryOpened_ );
}

TEST_F( HttpDirectoryListRequestHandlerTests, CallsReadDirWithCorrectDIRPointer )
{
  directoryApi_.opendir_returnValue_ = (DIR*) 77;
  handler_.handle( request_ );
  ASSERT_EQ( (DIR*) 77, directoryApi_.readdir_input_ );
}
