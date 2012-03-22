#include "gtest/gtest.h"
#include "mocks/MockSocketApi.h"
#include "EchoRequestHandler.h"

class EchoRequestHandlerTester
  : public ::testing::Test
{
  protected:
    MockSocketApiReturnValues returnValues_;
    MockSocketApiInputValues inputValues_;
    MockSocketApiFlags flags_;

    MockSocketApi socketApi_;

  public:
    EchoRequestHandlerTester()
      : returnValues_( 2939, 0, 2020 )
      , socketApi_( returnValues_, inputValues_, flags_ )
    { }
};

TEST_F( EchoRequestHandlerTester, Compiles )
{
  EchoRequestHandler handler( &socketApi_ ); 
}


