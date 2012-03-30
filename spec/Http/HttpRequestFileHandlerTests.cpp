#include "gtest/gtest.h"
#include "HttpRequestFileHandler.h"
#include "MockFileApi.h"
#include "HttpRequest.h"
#include "HttpResponse.h"


class HttpRequestFileHandlerTests
  : public ::testing::Test
{
  public:
    MockFileApi fileApi_;
    HttpRequest request_;
    std::string basePath_;
    HttpRequestFileHandler handler_;

    HttpRequestFileHandlerTests()
      : fileApi_()
      , request_( "some/url" )
      , basePath_( "/some/base/path/" )
      , handler_( basePath_, fileApi_ )
    { }

    virtual ~HttpRequestFileHandlerTests()
    { }
};

TEST_F( HttpRequestFileHandlerTests, ReadsTheCorrectFile )
{
  handler_.handle( request_ );
  ASSERT_EQ( "/some/base/path/some/url", fileApi_.readToEndInput_ );
}

TEST_F( HttpRequestFileHandlerTests, SetsTheResponseBodyToFileContents )
{
  fileApi_.readToEndReturnValue_ = "Some file contents.";
  HttpResponse* response = handler_.handle( request_ );
  ASSERT_EQ( "Some file contents.", response->body() );
}
