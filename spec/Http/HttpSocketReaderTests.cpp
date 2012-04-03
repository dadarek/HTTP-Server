#include "gtest/gtest.h"
#include "HttpSocketReader.h"
#include "SocketReadException.h"
#include "MockSocketReadApi.h"

class HttpSocketReaderTests
  : public ::testing::Test
{
  protected:
    MockSocketReadApi socketApi_;
    HttpSocketReader reader_;

    HttpSocketReaderTests()
      : socketApi_()
      , reader_( socketApi_ )
    { }
};


TEST_F( HttpSocketReaderTests, readsSomeHeaders )
{
  std::string headers( "HEADERS" );
  socketApi_.sourceBuffer_ = headers.c_str();

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
  socketApi_.sourceBuffer_ = "";
  reader_.readToEnd( 88 );
  ASSERT_EQ( 88, socketApi_.socketReadOn_ );
}

TEST_F( HttpSocketReaderTests, ReadsBodyIfPresent )
{
  std::string input = "Content-Length: 5";
  input += "\r\n\r\n";
  input += "12345";

  socketApi_.sourceBuffer_ = input.c_str();
  std::string result = reader_.readToEnd( -1 );

  ASSERT_EQ( input, result );
}
