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

TEST( HttpRequestFileHandlerTests, Compiles )
{
  std::string basePath = "/some/base/";
  MockFileReader reader;

  HttpRequestFileHandler handler( basePath, reader );
  HttpRequest request( "someUrl" );

  HttpResponse* response = handler.handle( request );
  

  ASSERT_EQ( "/some/base/someUrl", reader.fileRead_ );
}
