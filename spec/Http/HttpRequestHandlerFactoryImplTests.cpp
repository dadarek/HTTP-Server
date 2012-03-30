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
  fileApi_.existsReturnValue_ = false;
  HttpRequestHandler* handler = getHandler();
  ASSERT_EQ( handler, dynamic_cast <Http404RequestHandler*> ( handler ) );
}

TEST_F( HttpRequestHandlerFactoryImplTests, returnsFileHandlerIfFileDoesExist )
{
  fileApi_.existsReturnValue_ = true;
  HttpRequestHandler* handler = getHandler();
  ASSERT_EQ( handler, dynamic_cast <HttpRequestFileHandler*> ( handler ) );
}

TEST_F( HttpRequestHandlerFactoryImplTests, fileHandlerHasCorrectBasePath)
{
  fileApi_.existsReturnValue_ = true;
  getHandler()->handle( request_ );
  ASSERT_EQ( basePath_ + request_.url(), fileApi_.readToEndInput_ );
}

