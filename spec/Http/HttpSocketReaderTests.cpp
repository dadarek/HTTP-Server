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
};

const char* const HttpSocketReaderTests::STREAM_TERMINATOR = "\r\n\r\n";

TEST_F( HttpSocketReaderTests, readsEmpty )  
{
  std::string headers( "HEADERS GO HERE" );
  
  std::string input = headers + STREAM_TERMINATOR + "Some Extra Stuff"; 
  socketApi_.sourceBuffer_ = input.c_str();

  std::string actual = reader_.readToEnd( -1 );
  ASSERT_EQ( headers, actual );
};

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

TEST_F( HttpSocketReaderTests, ReadsBodyIfPresent )
{
  std::string input = "Content-Length: 5";
  input += STREAM_TERMINATOR;
  input += "12345";

  socketApi_.sourceBuffer_ = input.c_str();
  std::string result = reader_.readToEnd( -1 );

  ASSERT_EQ( input, result );
}
