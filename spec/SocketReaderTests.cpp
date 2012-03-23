#include "gtest/gtest.h"
#include "SocketReader.h"
#include "mocks/MockSocketReadApi.h"

class SocketReaderTests
  : public ::testing::Test
{
  private:
    std::string setAndGet( const char* input )
    {
      MockSocketReadApi socketApi;
      SocketReader reader( &socketApi );

      socketApi.sourceBuffer_ = input;
      std::string result = reader.readToEnd( -1 );

      return result;
    }

  protected:
    void testWithNBytes( int numberOfBytes )
    {
      std::string expected = std::string( numberOfBytes, '.' );
      std::string actual = setAndGet( expected.c_str() );
      ASSERT_EQ( expected, actual );
    }
};

TEST_F( SocketReaderTests, ReadsCorrectValues )  
{
  testWithNBytes( 0 );
  testWithNBytes( 1 );
  testWithNBytes( 2 );
  testWithNBytes( 3 );
  testWithNBytes( 255 );
  testWithNBytes( 256 );
  testWithNBytes( 257 );
  testWithNBytes( 1000 * 1000 );
}

TEST_F( SocketReaderTests, ThrowsExceptionOnErrorRead )  
{
  MockSocketReadApi socketApi;
  socketApi.returnErrorOnRead_ = true;
  socketApi.sourceBuffer_ = "";

  SocketReader reader( &socketApi );

  ASSERT_THROW( reader.readToEnd( -1 ), int );
}

