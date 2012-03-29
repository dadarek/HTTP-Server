#include "gtest/gtest.h"
#include "HttpResponseSocketWriter.h"
#include "MockSocketWriteApi.h"

class HttpResponseSocketWriterTests
  : public ::testing::Test
{
  protected:
};

TEST_F( HttpResponseSocketWriterTests, Compiles )
{
  MockSocketWriteApi socketApi;
  HttpResponseSocketWriter writer( socketApi );
}
