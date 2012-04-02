#include "gtest/gtest.h"
#include "HttpResponseSocketWriter.h"
#include "MockSocketWriteApi.h"
#include "MockHttpResponse.h"
#include "HttpConnectionHandlerInspector.h"
#include "SocketWriteException.h"

class HttpResponseSocketWriterTests
  : public ::testing::Test
{
  protected:
    static const char* const RESPONSE_BODY;
    static const size_t RESPONSE_BODY_SIZE;
    static const int PORT;
    
    HttpConnectionHandlerInspector inspector_;
    MockSocketWriteApi socketApi_;
    MockHttpResponse response_;
    HttpResponseSocketWriter writer_;

    HttpResponseSocketWriterTests()
      : inspector_()
      , socketApi_()
      , response_( inspector_, HttpResponseSocketWriterTests::RESPONSE_BODY, HttpResponseSocketWriterTests::RESPONSE_BODY_SIZE )
      , writer_( socketApi_ )
    { }

    void write()
    {
      writer_.write( HttpResponseSocketWriterTests::PORT, response_ );
    }
};

const char* const HttpResponseSocketWriterTests::RESPONSE_BODY = "Some body";
const size_t HttpResponseSocketWriterTests::RESPONSE_BODY_SIZE = strlen( RESPONSE_BODY ) + 1;
const int HttpResponseSocketWriterTests::PORT = 77;

TEST_F( HttpResponseSocketWriterTests, writesTheCorrectContent )
{
  write();
  ASSERT_STREQ( HttpResponseSocketWriterTests::RESPONSE_BODY, socketApi_.whatWasWritten_.str().c_str() );
}

TEST_F( HttpResponseSocketWriterTests, writesToTheCorrectSocket )
{
  write();
  ASSERT_EQ( HttpResponseSocketWriterTests::PORT, socketApi_.socketWrittenTo_ );
}

TEST_F( HttpResponseSocketWriterTests, passesInCorrectBufferSize )
{
  write();
  ASSERT_EQ( HttpResponseSocketWriterTests::RESPONSE_BODY_SIZE, socketApi_.howMuchWasClaimedToBeWritten_ );
}

TEST_F( HttpResponseSocketWriterTests, throwsExceptionIfWriteFails )
{
  socketApi_.returnError_ = true;
  ASSERT_THROW( write(), SocketWriteException );
}

TEST_F( HttpResponseSocketWriterTests, closesSocketWhenDone )
{
  write();
  ASSERT_EQ( HttpResponseSocketWriterTests::PORT, socketApi_.socketClosed_ );
}

