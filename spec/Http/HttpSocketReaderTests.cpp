#include "gtest/gtest.h"
#include "HttpSocketReader.h"
#include "SocketReadException.h"
#include "MockSocketReadApi.h"

class HttpSocketReaderTests
  : public ::testing::Test
{
  protected:
    static const char* const STREAM_TERMINATOR;

    MockSocketReadApi socketApi_;
    HttpSocketReader reader_;

    HttpSocketReaderTests()
      : socketApi_()
      , reader_( socketApi_ )
    { }

    std::string read( const char* input )
    {
      socketApi_.sourceBuffer_ = input;
      std::string result = reader_.readToEnd( -1 );

      return result;
    }
    void testWithNBytes( int numberOfBytes )
    {
      std::string expected( numberOfBytes, '.' );
      
      std::string input = expected + STREAM_TERMINATOR + "Some Extra Stuff"; 
      std::string actual = read( input.c_str() );
      ASSERT_EQ( expected, actual );
    }
};

const char* const HttpSocketReaderTests::STREAM_TERMINATOR = "\r\n\r\n";

TEST_F( HttpSocketReaderTests, readsEmpty )  
{
  testWithNBytes( 0 );
}

TEST_F( HttpSocketReaderTests, reads1Byte )
{
  testWithNBytes( 1 );
}

TEST_F( HttpSocketReaderTests, reads2Bytes )
{
  testWithNBytes( 2 );
}

TEST_F( HttpSocketReaderTests, reads255Bytes )
{
  testWithNBytes( 255 );
}

TEST_F( HttpSocketReaderTests, reads256Bytes )
{
  testWithNBytes( 256 );
}

TEST_F( HttpSocketReaderTests, reads257Bytes )
{
  testWithNBytes( 257 );
}

TEST_F( HttpSocketReaderTests, readsALotOfBytes )
{
  testWithNBytes( 1000 * 1000 );
}

TEST_F( HttpSocketReaderTests, ThrowsExceptionOnErrorRead )  
{
  socketApi_.returnErrorOnRead_ = true;
  ASSERT_THROW( reader_.readToEnd( 0 ), SocketReadException );
}

TEST_F( HttpSocketReaderTests, ReadsOnSocketItReceives )
{
  socketApi_.sourceBuffer_ = STREAM_TERMINATOR;
  reader_.readToEnd( 88 );
  ASSERT_EQ( 88, socketApi_.socketReadOn_ );
}

