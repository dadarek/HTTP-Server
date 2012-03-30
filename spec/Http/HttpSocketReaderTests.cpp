#include "gtest/gtest.h"
#include "HttpSocketReader.h"
#include "SocketReadException.h"
#include "MockSocketReadApi.h"

class HttpSocketReaderTests
  : public ::testing::Test
{
  protected:
    static const char* const STREAM_TERMINATOR;

    std::string setAndGet( MockSocketReadApi& socketApi, const char* input )
    {
      HttpSocketReader reader( socketApi );

      socketApi.sourceBuffer_ = input;
      std::string result = reader.readToEnd( -1 );

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

const char* const HttpSocketReaderTests::STREAM_TERMINATOR = "\r\n\r\n";

TEST_F( HttpSocketReaderTests, ReadsCorrectValues )  
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

TEST_F( HttpSocketReaderTests, ThrowsExceptionOnErrorRead )  
{
  MockSocketReadApi socketApi;
  socketApi.returnErrorOnRead_ = true;
  ASSERT_THROW( setAndGet( socketApi, "" ), SocketReadException );
}

TEST_F( HttpSocketReaderTests, ReadsOnSocketItReceives )
{
  MockSocketReadApi socketApi;
  socketApi.sourceBuffer_ = STREAM_TERMINATOR;

  HttpSocketReader reader( socketApi );

  reader.readToEnd( 88 );
  ASSERT_EQ( 88, socketApi.socketReadOn_ );
}

