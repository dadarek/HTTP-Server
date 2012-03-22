#include "gtest/gtest.h"
#include "mocks/MockSocketApi.h"
#include "InboundConnectionListener.h"

class InboundConnectionListenerTester
  : public ::testing::Test
{
  protected:
    const int PORT_TO_BIND_TO;

    struct MockSocketApiReturnValues returnValues_;
    struct MockSocketApiInputValues inputValues_;
    struct MockSocketApiFlags flags_;

    MockSocketApi socketApi_;

    InboundConnectionListener* createListener()
    {
      return new InboundConnectionListener( &socketApi_, PORT_TO_BIND_TO ); 
    }

    void createAndDeleteListener()
    {
      delete createListener();
    }

  public:
    InboundConnectionListenerTester()
      : PORT_TO_BIND_TO( 8090 )
      , returnValues_( 85, 0, 7777 )
      , socketApi_( returnValues_, inputValues_, flags_ )
    { }
};


TEST_F( InboundConnectionListenerTester, CreatesASocket )
{
  createAndDeleteListener();
  ASSERT_TRUE( flags_.socketCalled );
}

TEST_F( InboundConnectionListenerTester, ThrowsExceptionOnErrorSocket ) 
{
  flags_.socketShouldError = true;
  ASSERT_THROW( createAndDeleteListener(), int );
}

TEST_F( InboundConnectionListenerTester, ClosesFDOnBindException ) 
{
  flags_.bindShouldError = true;
  try
  {
    createAndDeleteListener();
  }
  catch( int )
  { }
  
  EXPECT_EQ( returnValues_.socket, inputValues_.close );
}

TEST_F( InboundConnectionListenerTester, BindsToSocketFDItReceives ) 
{
  createAndDeleteListener();
  EXPECT_EQ( returnValues_.socket, inputValues_.bindFD );
}

TEST_F( InboundConnectionListenerTester, BindsToPortSpecifiedInConstructor ) 
{
  createAndDeleteListener();
  EXPECT_EQ( PORT_TO_BIND_TO, inputValues_.bindPort );
}

TEST_F( InboundConnectionListenerTester, ThrowsExceptionOnErrorBind )  
{
  flags_.bindShouldError = true;
  ASSERT_THROW( createAndDeleteListener(), int );
}

TEST_F( InboundConnectionListenerTester, DestructorClosesFD )  
{
  {
    createAndDeleteListener();
  }
  EXPECT_EQ( returnValues_.socket, inputValues_.close );
}

TEST_F( InboundConnectionListenerTester, ListensToSocketFDItReceives )  
{
  createAndDeleteListener();
  EXPECT_EQ( returnValues_.socket, inputValues_.listen );
}

TEST_F( InboundConnectionListenerTester, AcceptsConnectionsOnSocketFDItReceives )  
{
  InboundConnectionListener* listener = createListener();
  listener->nextConnection();

  EXPECT_EQ( returnValues_.socket, inputValues_.accept );
  delete listener;
}

TEST_F( InboundConnectionListenerTester, PassesInCorrectSocketFDToAccept )  
{
  InboundConnectionListener* listener = createListener();
  listener->nextConnection();

  EXPECT_EQ( returnValues_.socket, inputValues_.accept );
  delete listener;
}

TEST_F( InboundConnectionListenerTester, ThrowsExceptionWhenAcceptFails )  
{
  InboundConnectionListener* listener = createListener();
  flags_.acceptShouldError = true;

  ASSERT_THROW( listener->nextConnection(), int );
  delete listener;
}

TEST_F( InboundConnectionListenerTester, NextConnectionReturnsCorrectFD )  
{
  InboundConnectionListener* listener = createListener();
  int actual = listener->nextConnection(); 

  ASSERT_EQ( returnValues_.accept, actual );
  delete listener;
}

//TODO: Merge common headers together
//
//TODO: Create good exceptions Exceptions better names
//
//TODO: Use -Wreorder in gcc
//
//TODO: Do explicit destructors (virtual and non-virtual)
//      implicitly call the base destructor?
//
//TODO: Give better names to test functions (i.e. ThrowsExceptionWhenBindReturnsError
//
