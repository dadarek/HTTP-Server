#include "gtest/gtest.h"
#include "MockFileApi.h"
#include "MockDirectoryApi.h"
#include "HttpRequestHandlerFactoryImpl.h"
#include "Http404RequestHandler.h"
#include "HttpRequestFileHandler.h"
#include "HttpDirectoryListRequestHandler.h"
#include "HttpEchoRequestHandler.h"
#include "HttpRequest.h"

#include <dirent.h>

class HttpRequestHandlerFactoryImplTests
  : public ::testing::Test
{
  public:
    MockFileApi fileApi_;
    MockDirectoryApi directoryApi_;
    std::string basePath_;
    HttpRequest request_;
    HttpRequestHandlerFactoryImpl factory_;

    HttpRequestHandlerFactoryImplTests()
      : basePath_( "/some/base/" )
      , request_( "", "some/url.html" )
      , factory_( basePath_, fileApi_, directoryApi_ )
    { }

    HttpRequestHandler* getHandler()
    {
      return factory_.createHandler( request_ );
    }

    template <class ExpectedType>
    void assertHandlerType()
    {
      HttpRequestHandler* handler = getHandler();
      ASSERT_EQ( handler, dynamic_cast <ExpectedType*> ( handler ) );
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
  assertHandlerType< Http404RequestHandler >();
}

TEST_F( HttpRequestHandlerFactoryImplTests, returnsFileHandlerIfFileDoesExist )
{
  fileApi_.existsReturnValue_ = true;
  assertHandlerType< HttpRequestFileHandler >();
}

TEST_F( HttpRequestHandlerFactoryImplTests, returnsFolderHandlerIfFolderExists )
{
  directoryApi_.opendir_returnValue_ = (DIR*) 10;
  assertHandlerType< HttpDirectoryListRequestHandler >();
}

TEST_F( HttpRequestHandlerFactoryImplTests, returnsEchoHandlerOnPutRequests )
{
  HttpRequest request( "PUT", "" );
  HttpRequestHandler* handler = factory_.createHandler( request );
  ASSERT_EQ( handler, dynamic_cast < HttpEchoRequestHandler* > ( handler ) );
}

TEST_F( HttpRequestHandlerFactoryImplTests, returnsEchoHandlerOnPostRequests )
{
  HttpRequest request( "POST", "" );
  HttpRequestHandler* handler = factory_.createHandler( request );
  ASSERT_EQ( handler, dynamic_cast < HttpEchoRequestHandler* > ( handler ) );
}

TEST_F( HttpRequestHandlerFactoryImplTests, fileHandlerHasCorrectBasePath)
{
  fileApi_.existsReturnValue_ = true;
  getHandler()->handle( request_ );
  ASSERT_EQ( basePath_ + request_.url(), fileApi_.readToEndInput_ );
}

