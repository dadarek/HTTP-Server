#include "gtest/gtest.h"
#include "HttpRequestFileHandler.h"
#include "MockFileReader.h"
#include "HttpRequest.h"
#include "HttpResponse.h"


class HttpRequestFileHandlerTests
  : public ::testing::Test
{
  public:
    MockFileReader reader_;
    HttpRequest request_;
    std::string basePath_;
    HttpRequestFileHandler handler_;

    HttpRequestFileHandlerTests()
      : reader_()
      , request_( "some/url" )
      , basePath_( "/some/base/path/" )
      , handler_( basePath_, reader_ )
    { }

    virtual ~HttpRequestFileHandlerTests()
    { }
};

TEST_F( HttpRequestFileHandlerTests, ReadsTheCorrectFile )
{
  handler_.handle( request_ );
  ASSERT_EQ( "/some/base/path/some/url", reader_.readToEndInput_ );
}

TEST_F( HttpRequestFileHandlerTests, SetsTheResponseBodyToFileContents )
{
  reader_.readToEndReturnValue_ = "Some file contents.";
  HttpResponse* response = handler_.handle( request_ );
  ASSERT_EQ( "Some file contents.", response->body() );
}
