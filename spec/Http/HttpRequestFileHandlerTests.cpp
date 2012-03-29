#include "gtest/gtest.h"
#include "HttpRequestFileHandler.h"
#include "MockFileReader.h"
#include "HttpRequest.h"
#include "HttpResponse.h"


class HttpRequestFileHandlerTests
  : public ::testing::Test
{
  public:
    HttpRequestFileHandlerTests()
    { }

    virtual ~HttpRequestFileHandlerTests()
    { }
};

TEST_F( HttpRequestFileHandlerTests, ReadsTheCorrectFile )
{
  std::string basePath = "/some/base/";
  MockFileReader reader;

  HttpRequestFileHandler handler( basePath, reader );
  HttpRequest request( "someUrl" );

  HttpResponse* response = handler.handle( request );
  

  ASSERT_EQ( "/some/base/someUrl", reader.fileRead_ );
}

TEST_F( HttpRequestFileHandlerTests, SetsTheResponseBodyToFileContents )
{
  MockFileReader reader;

  HttpRequestFileHandler handler( "", reader );
  HttpRequest request( "" );

  reader.returnValue_ = "Some file contents.";

  HttpResponse* response = handler.handle( request );

  ASSERT_EQ( "Some file contents.", response->body() );
}
