#include "gtest/gtest.h"
#include "SocketReader.h"
#include "mocks/MockSocketReadApi.h"

class SocketReaderTests
  : public ::testing::Test
{
  protected:
    static const char* const STREAM_TERMINATOR;

    std::string setAndGet( MockSocketReadApi& socketApi, const char* input )
    {
      SocketReader reader( socketApi );

      socketApi.sourceBuffer_ = input;
      std::string result = reader.readToEnd( -1, STREAM_TERMINATOR );

      return result;
    }
    std::string setAndGet( const char* input )
    {
      MockSocketReadApi socketApi;
      return setAndGet( socketApi, input );
    }

    void testWithNBytes( int numberOfBytes )
    {
      std::string expected = std::string( numberOfBytes, '.' );
      
      std::string input = expected + STREAM_TERMINATOR + "Some Extra Stuff"; 
      std::string actual = setAndGet( input.c_str() );
      ASSERT_EQ( expected, actual );
    }
};

const char* const SocketReaderTests::STREAM_TERMINATOR = "\n\n";

TEST_F( SocketReaderTests, ReadsCorrectValues )  
{
  testWithNBytes( 0 );
  testWithNBytes( 1 );
  testWithNBytes( 2 );
  testWithNBytes( 3 );
  testWithNBytes( 254 );
  testWithNBytes( 255 );
  testWithNBytes( 256 );
  testWithNBytes( 257 );
  testWithNBytes( 258 );
  testWithNBytes( 1000 * 1000 );
}

TEST_F( SocketReaderTests, ThrowsExceptionOnErrorRead )  
{
  MockSocketReadApi socketApi;
  socketApi.returnErrorOnRead_ = true;
  ASSERT_THROW( setAndGet( socketApi, "" ), int );
}

TEST_F( SocketReaderTests, ReadsOnSocketItReceives )
{
  MockSocketReadApi socketApi;
  socketApi.sourceBuffer_ = " end";

  SocketReader reader( socketApi );

  reader.readToEnd( 88, "end" );
  ASSERT_EQ( 88, socketApi.socketReadOn_ );
}

