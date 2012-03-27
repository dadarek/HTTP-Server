#include "gtest/gtest.h"
#include "HttpConnectionHandler.h"
#include "MockSocketReader.h"
#include "MockHttpRequestHandlerFactory.h"

class HttpConnectionHandlerTester
  : public ::testing::Test
{
  public:
    HttpConnectionHandlerTester()
    { }
};

TEST_F( HttpConnectionHandlerTester, Compiles )
{
  MockSocketReader socketReader;
  MockHttpRequestHandlerFactory factory;

  HttpConnectionHandler handler( socketReader, factory ); 
}

