#include "gtest/gtest.h"
#include "MockFileApi.h"
#include "HttpRequestHandlerFactoryImpl.h"
#include "Http404RequestHandler.h"
#include "HttpRequestFileHandler.h"
#include "HttpRequest.h"

class HttpRequestHandlerFactoryImplTests
  : public ::testing::Test
{
  public:

};

TEST_F( HttpRequestHandlerFactoryImplTests, asksFileApiIfCorrectFileExists )
{
  MockFileApi fileApi;

  std::string basePath = "/some/base/";
  HttpRequest request( "some-url.html" );

  HttpRequestHandlerFactoryImpl factory( basePath, fileApi );

  factory.createHandler( request );

  ASSERT_EQ( "/some/base/some-url.html", fileApi.existsInput_ ); 
}


TEST_F( HttpRequestHandlerFactoryImplTests, returns404HandlerIfFileNotexists )
{
  MockFileApi fileApi;
  HttpRequest request( "" );
  HttpRequestHandlerFactoryImpl factory( "", fileApi );

  fileApi.existsReturnValue_ = false;
  HttpRequestHandler* handler = factory.createHandler( request );

  ASSERT_EQ( handler, dynamic_cast <Http404RequestHandler*> ( handler ) );
}

TEST_F( HttpRequestHandlerFactoryImplTests, returnsFileHandlerIfFileDoesExist )
{
  MockFileApi fileApi;
  HttpRequest request( "" );
  HttpRequestHandlerFactoryImpl factory( "", fileApi );

  fileApi.existsReturnValue_ = true;
  HttpRequestHandler* handler = factory.createHandler( request );

  ASSERT_EQ( handler, dynamic_cast <HttpRequestFileHandler*> ( handler ) );
}


