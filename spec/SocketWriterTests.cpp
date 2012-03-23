#include "gtest/gtest.h"
#include "SocketWriter.h"
#include "mocks/MockSocketWriteApi.h"

class SocketWriterTests
  : public ::testing::Test
{
  protected:
};

TEST_F( SocketWriterTests, Compiles )  
{
  MockSocketWriteApi socketApi;
  SocketWriter writer( socketApi );

}

