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
    MockFileApi fileApi_;
    std::string basePath_;
    HttpRequest request_;
    HttpRequestHandlerFactoryImpl factory_;

    HttpRequestHandlerFactoryImplTests()
      : basePath_( "/some/base/" )
      , request_( "some/url.html" )
      , factory_( basePath_, fileApi_ )
    { }

    HttpRequestHandler* getHandler()
    {
      return factory_.createHandler( request_ );

    }

};

TEST_F( HttpRequestHandlerFactoryImplTests, asksFileApiIfCorrectFileExists )
{
  getHandler();
  ASSERT_EQ( basePath_ + request_.url(), fileApi_.existsInput_ ); 
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


