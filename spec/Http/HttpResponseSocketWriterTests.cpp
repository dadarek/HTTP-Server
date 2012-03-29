#include "gtest/gtest.h"
#include "HttpResponseSocketWriter.h"
#include "MockSocketWriteApi.h"
#include "MockHttpResponse.h"
#include "HttpConnectionHandlerInspector.h"

class HttpResponseSocketWriterTests
  : public ::testing::Test
{
  protected:
    static const std::string RESPONSE_BODY;
    static const int PORT;
    
    HttpConnectionHandlerInspector inspector_;
    MockSocketWriteApi socketApi_;
    MockHttpResponse response_;
    HttpResponseSocketWriter writer_;

    HttpResponseSocketWriterTests()
      : inspector_()
      , socketApi_()
      , response_( inspector_, HttpResponseSocketWriterTests::RESPONSE_BODY.c_str() )
      , writer_( socketApi_ )
    { }

    void write()
    {
      writer_.write( HttpResponseSocketWriterTests::PORT, response_ );
    }
};

const std::string HttpResponseSocketWriterTests::RESPONSE_BODY("Some body");
const int HttpResponseSocketWriterTests::PORT = 77;

TEST_F( HttpResponseSocketWriterTests, writesTheCorrectContent )
{
  write();
  ASSERT_EQ( HttpResponseSocketWriterTests::RESPONSE_BODY, socketApi_.whatWasWritten_.str() );
}

TEST_F( HttpResponseSocketWriterTests, writesToTheCorrectSocket )
{
  write();
  ASSERT_EQ( HttpResponseSocketWriterTests::PORT, socketApi_.socketWrittenTo_ );
}

TEST_F( HttpResponseSocketWriterTests, passesInCorrectBufferSize )
{
  write();
  const char* body = HttpResponseSocketWriterTests::RESPONSE_BODY.c_str();
  unsigned bodyLength = (unsigned) strlen( body );
  ASSERT_EQ( bodyLength, socketApi_.howMuchWasClaimedToBeWritten_ );
}

TEST_F( HttpResponseSocketWriterTests, throwsExceptionIfWriteFails )
{
  socketApi_.returnError_ = true;
  ASSERT_THROW( write(), int );
}

// Take care of situation when write returns -1
//
//
// SPEED UP THAT BUILD PROCESS!!!!
