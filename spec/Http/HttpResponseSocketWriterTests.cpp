#include "gtest/gtest.h"
#include "HttpResponseSocketWriter.h"
#include "MockSocketWriteApi.h"
#include "HttpResponse.h"
#include "HttpConnectionHandlerInspector.h"
#include "SocketWriteException.h"

class HttpResponseSocketWriterTests
  : public ::testing::Test
{
  protected:
    static const char* const STATUS_CODE;
    static const char* const RESPONSE_BODY;
    static const char* const LINE_BREAK;
    static const int PORT;
    
    MockSocketWriteApi socketApi_;
    HttpResponse response_;
    HttpResponseSocketWriter writer_;

    HttpResponseSocketWriterTests()
      : socketApi_()
      , response_( RESPONSE_BODY, strlen( RESPONSE_BODY ), STATUS_CODE )
      , writer_( socketApi_ )
    { }

    void write()
    {
      writer_.write( PORT, response_ );
    }

    std::string getExpectedBody()
    {
      std::string result("HTTP/1.1 ");
      result += STATUS_CODE;
      result += LINE_BREAK;
      result += LINE_BREAK;
      result += RESPONSE_BODY;

      return result;
    }
};

const char* const HttpResponseSocketWriterTests::RESPONSE_BODY = "Some body";
const char* const HttpResponseSocketWriterTests::STATUS_CODE = "999 Some Code";
const char* const HttpResponseSocketWriterTests::LINE_BREAK = "\r\n";
const int HttpResponseSocketWriterTests::PORT = 77;

TEST_F( HttpResponseSocketWriterTests, writesTheCorrectContent )
{
  write();
  std::string body = getExpectedBody();
  int diff = memcmp( body.c_str(), socketApi_.whatWasWritten_, socketApi_.howMuchWasWritten_ );

  ASSERT_EQ( 0, diff );
}

TEST_F( HttpResponseSocketWriterTests, writesToTheCorrectSocket )
{
  write();
  ASSERT_EQ( PORT, socketApi_.socketWrittenTo_ );
}

TEST_F( HttpResponseSocketWriterTests, passesInCorrectLength )
{
  write();
  ASSERT_EQ( getExpectedBody().length(), socketApi_.howMuchWasWritten_ );
}

TEST_F( HttpResponseSocketWriterTests, throwsExceptionIfWriteFails )
{
  socketApi_.returnError_ = true;
  ASSERT_THROW( write(), SocketWriteException );
}

TEST_F( HttpResponseSocketWriterTests, closesSocketWhenDone )
{
  write();
  ASSERT_EQ( PORT, socketApi_.socketClosed_ );
}

