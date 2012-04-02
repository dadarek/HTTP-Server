#include "gtest/gtest.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "MockDirectoryApi.h"
#include "HttpDirectoryListRequestHandler.h"

class HttpDirectoryListRequestHandlerTests
  : public ::testing::Test
{
  public:
    struct dirent* directories_[4];
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
    { 
      setupDirectoryEntries();
    }
    
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

    struct dirent* createEntry( const char* name )
    {
      struct dirent* result = new struct dirent();
      strcpy( result->d_name, name );
      return result;
    }
    void setupDirectoryEntries()
    {
      directories_[0] = createEntry("Some Folder Name");
      directories_[1] = createEntry("Some file Name.txt");
      directories_[2] = createEntry("AnotherFile.asp");
      directories_[3] = 0;
      directoryApi_.readdir_returnValues_ = directories_;
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
  handler_.handle( request_ );
  ASSERT_EQ( 4, directoryApi_.timesReaddirCalled_ );
}

TEST_F( HttpDirectoryListRequestHandlerTests, IncludesResultsInResponse )
{
  HttpResponse* response = handler_.handle( request_ );

  assertBodyContains( response, directories_[0]->d_name );
  assertBodyContains( response, directories_[1]->d_name );
  assertBodyContains( response, directories_[2]->d_name );

}

TEST_F( HttpDirectoryListRequestHandlerTests, createsResponseWithAppropriateLength )
{
  HttpResponse* response = handler_.handle( request_ );
  size_t totalLength = 0;
  totalLength += strlen( directories_[0]->d_name );
  totalLength += strlen( directories_[1]->d_name );
  totalLength += strlen( directories_[2]->d_name );

  ASSERT_EQ( totalLength, response->bodyLength() );
}

TEST_F( HttpDirectoryListRequestHandlerTests, Sets200Status )
{
  HttpResponse* response = handler_.handle( request_ );
  ASSERT_EQ( std::string("200 OK"), response->status() );
}
