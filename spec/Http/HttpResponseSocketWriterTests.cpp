#include "gtest/gtest.h"
#include "HttpResponseSocketWriter.h"
#include "MockSocketWriteApi.h"
#include "MockHttpResponse.h"
#include "HttpConnectionHandlerInspector.h"

class HttpResponseSocketWriterTests
  : public ::testing::Test
{
  protected:
};

TEST_F( HttpResponseSocketWriterTests, writesTheCorrectContent )
{
  HttpConnectionHandlerInspector inspector;
  MockSocketWriteApi socketApi;
  MockHttpResponse response( inspector, "Some text" );
  HttpResponseSocketWriter writer( socketApi );

  writer.write( response );

  ASSERT_EQ( socketApi.whatWasWritten_.str(), response.body() );
}

// Changed unsigneds to size_t's (in MockSocketRead/WriteApi )
// take care of situation when write returns -1
//
//
// SPEED UP THAT BUILD PROCESS!!!!
