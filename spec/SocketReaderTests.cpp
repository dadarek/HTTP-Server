#include "gtest/gtest.h"
#include "SocketReader.h"
#include "mocks/MockSocketReadApi.h"

class SocketReaderTests
{
  public:
   static std::string readToEnd( std::string stringToTest )
   {
     int length = stringToTest.length() + 1;
     const char* buffer = stringToTest.c_str();

     MockSocketReadApi socketApi;
      
     SocketReader reader( &socketApi );

     socketApi.readBuffer_[0] = buffer;
     socketApi.readReturns_[0] = length;
     socketApi.howMuchToCopy_[0] = length;

     return reader.readToEnd( 5 );
   } 
};

TEST( SocketReaderTests, ReadsEmptyStream )  
{
  std::string expected = "";
  std::string actual = SocketReaderTests::readToEnd( expected );
  ASSERT_EQ( expected, actual );
}

TEST( SocketReaderTests, ReadsShortStream )  
{
  std::string expected = "Hello there ...";
  std::string actual = SocketReaderTests::readToEnd( expected );
  ASSERT_EQ( expected, actual );
}
/*
TEST( SocketReaderTests, ReadsALongStream)  
{
  std::string expected = std::string( 1000, '.' );
  std::string actual = SocketReaderTests::readToEnd( expected );
  ASSERT_EQ( expected, actual );
}
*/
//TODO: Throw exception when read returns -1
//TODO: Throw exception when read returns -1
//
//TODO: make sure input socket is valid
//
