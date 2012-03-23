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

// TODO: change int to unsigned in SocketApi::read
//
// TODO: Do you really need to re-declare inherited
// pure virtual functions that you're overriding?
//
