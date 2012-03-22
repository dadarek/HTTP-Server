#include "gtest/gtest.h"
#include "SocketReader.h"
#include "mocks/MockSocketReadApi.h"

class SocketReaderTests
  : public ::testing::Test
{
  protected:
    MockSocketReadApi socketApi_;
    SocketReader reader_;

  public:
    SocketReaderTests() 
      : reader_( &socketApi_ )
    { }

   std::string setBufferAndReadToEnd( std::string stringToTest )
   {
     int length = stringToTest.length() + 1;
     const char* buffer = stringToTest.c_str();

     socketApi_.readBuffer_[0] = buffer;
     socketApi_.readReturns_[0] = length;
     socketApi_.howMuchToCopy_[0] = length;

     return reader_.readToEnd( 5 );
   } 
};

TEST_F( SocketReaderTests, ReadsEmptyStream )  
{
  std::string expected = "";
  std::string actual = setBufferAndReadToEnd( expected );
  ASSERT_EQ( expected, actual );
}

TEST_F( SocketReaderTests, ReadsShortStream )  
{
  std::string expected = "Hello there ...";
  std::string actual = setBufferAndReadToEnd( expected );
  ASSERT_EQ( expected, actual );
}
/*
TEST( SocketReaderTests, ReadsALongStream)  
{
  std::string expected = std::string( 1000, '.' );
  std::string actual = SocketReaderTests::setBufferAndReadToEnd( expected );
  ASSERT_EQ( expected, actual );
}
*/
//TODO: Throw exception when read returns -1
//TODO: Throw exception when read returns -1
//
//TODO: make sure input socket is valid
//
