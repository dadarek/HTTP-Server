#include "gtest/gtest.h"
#include "HttpConnectionHandler.h"

class HttpConnectionHandlerTester
  : public ::testing::Test
{
  public:
    HttpConnectionHandlerTester()
    { }
};

TEST_F( HttpConnectionHandlerTester, Compiles )
{
  HttpConnectionHandler handler( ); 
}


