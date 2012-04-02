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
};

TEST_F( HttpRequestFileHandlerTests, ReadsTheCorrectFile )
{
  handler_.handle( request_ );
  ASSERT_EQ( "/some/base/path/some/url", fileApi_.readToEndInput_ );
}

TEST_F( HttpRequestFileHandlerTests, SetsTheResponseBodyToFileContents )
{
  const char* contents = "Some file contents.";
  size_t length = strlen( contents );
  fileApi_.fileContents_ = contents;
  fileApi_.fileSize_ = length;

  HttpResponse* response = handler_.handle( request_ );

  int diff = memcmp( response->charBody(), contents, length ); 
  ASSERT_EQ( 0, diff );


  delete response;
}
