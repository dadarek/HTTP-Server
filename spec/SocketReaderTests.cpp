#include "gtest/gtest.h"
#include "SocketReader.h"
#include "mocks/MockSocketApi.h"

class SocketReaderTests
{
  public:
   static std::string readToEnd( std::string stringToTest )
   {
     int length = stringToTest.length() + 1;
     const char* buffer = stringToTest.c_str();

     MockSocketApiReturnValues returnValues_;
     MockSocketApiInputValues inputValues_;
     MockSocketApiFlags flags_;

     MockSocketApi socketApi( returnValues_, inputValues_, flags_ );
      
     SocketReader reader( &socketApi );

     returnValues_.readBuffer[0] = buffer;
     returnValues_.readReturns[0] = length;
     returnValues_.howMuchToCopy[0] = length;

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
