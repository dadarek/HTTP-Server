#include "gtest/gtest.h"
#include "SocketReader.h"
#include "mocks/MockSocketReadApi.h"

class SocketReaderTests
  : public ::testing::Test
{
  protected:
    std::string setAndGet( const char* input )
    {
      MockSocketReadApi socketApi;
      SocketReader reader( &socketApi );

      socketApi.sourceBuffer_ = input;
      std::string result = reader.readToEnd( -1 );

      return result;
    }
};

TEST_F( SocketReaderTests, ReadsEmptySocket )  
{
  std::string actual = setAndGet( "" );
  ASSERT_EQ( "", actual );
}

TEST_F( SocketReaderTests, ReadsSocketWith1Byte )  
{
  std::string actual = setAndGet( "x" );
  ASSERT_EQ( "x", actual );
}

TEST_F( SocketReaderTests, ReadsSocketWithManyBytes )  
{
  std::string expected = std::string( 1000 * 1000, '.' );
  std::string actual = setAndGet( expected.c_str() );
  ASSERT_EQ( expected, actual );
}


//TODO: Throw exception when read returns -1
//TODO: Throw exception when read returns -1
//
//TODO: make sure input socket is valid
//
//

