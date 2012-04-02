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
    
    char* appendNullTerminator( const char* string, size_t length )
    {
      char* result = new char[ length + 1 ];
      memcpy( result, string, length );
      result[ length ] = '\0';
      return result;
    }

    void assertBodyContains( HttpResponse* response, const char* expectedText )
    {
      char* body = appendNullTerminator( response->body(), response->bodyLength() );
      ASSERT_NE( (char*) 0 , strstr( body, expectedText ) );
      delete[] body;
    }
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

TEST_F( HttpDirectoryListRequestHandlerTests, CallsReadDirUntilNull )
{
  struct dirent* directories[4];
  directories[0] = (struct dirent*) 5;
  directories[1] = (struct dirent*) 6;
  directories[2] = (struct dirent*) 7;
  directories[3] = 0;
  directoryApi_.readdir_returnValues_ = directories;

  handler_.handle( request_ );

  ASSERT_EQ( 4, directoryApi_.timesReaddirCalled_ );
}

TEST_F( HttpDirectoryListRequestHandlerTests, IncludesResultsInResponse )
{
  struct dirent* directories[3];
  struct dirent someFolder;
  strcpy( someFolder.d_name, "Some Folder Name" );

  struct dirent someFile;
  strcpy( someFile.d_name, "Some FileName.txt" );

  directories[0] = &someFolder;
  directories[1] = &someFile;
  directories[2] = 0;
  directoryApi_.readdir_returnValues_ = directories;

  HttpResponse* response = handler_.handle( request_ );

  assertBodyContains( response, someFolder.d_name );
  assertBodyContains( response, someFile.d_name );

}
