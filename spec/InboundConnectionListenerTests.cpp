#include "gtest/gtest.h"
#include "mocks/MockSocket.h"
#include "InboundConnectionListener.h"

class InboundConnectionListenerTester
  : public ::testing::Test
{
  protected:
    const int PORT_TO_LISTEN_ON = 9080;

    struct MockSocketReturnValues returnValues_ = { 85, 0, 7777 };
    struct MockSocketInputValues inputValues_ = { -1, -1, -1, -1, -1 };
    struct MockSocketFlags flags_ = { false, false, false, false };

    MockSocket* socket_;
    InboundConnectionListener listener_;

  public:
    InboundConnectionListenerTester()
      : socket_( new MockSocket( returnValues_, inputValues_, flags_ ) )
      , listener_( socket_, PORT_TO_LISTEN_ON )
    { }
};


TEST_F( InboundConnectionListenerTester, CreatesASocket )
{
  ASSERT_TRUE( flags_.socketCalled );
}

TEST_F( InboundConnectionListenerTester, ThrowsExceptionOnErrorSocket ) 
{
  MockSocket* socket = new MockSocket( returnValues_, inputValues_, flags_ );
  flags_.socketShouldError = true;
  ASSERT_THROW( InboundConnectionListener listener( socket, 0 ), int );
}

TEST_F( InboundConnectionListenerTester, ClosesFDOnBindException ) 
{
  MockSocket* socket = new MockSocket( returnValues_, inputValues_, flags_ );
  flags_.bindShouldError = true;
  try
  {
    InboundConnectionListener listener( socket, 0 );
  }
  catch( int )
  { }
  
  EXPECT_EQ( returnValues_.socket, inputValues_.close );
}

TEST_F( InboundConnectionListenerTester, BindsToSocketFDItReceives ) 
{
  EXPECT_EQ( returnValues_.socket, inputValues_.bindFD );
}

TEST_F( InboundConnectionListenerTester, BindsToPortSpecifiedInConstructor ) 
{
  EXPECT_EQ( PORT_TO_LISTEN_ON, inputValues_.bindPort );
}

TEST_F( InboundConnectionListenerTester, ThrowsExceptionOnErrorBind )  
{
  MockSocket* socket = new MockSocket( returnValues_, inputValues_, flags_ );
  flags_.bindShouldError = true;
  ASSERT_THROW( InboundConnectionListener listener( socket, 0 ), int );
}

TEST_F( InboundConnectionListenerTester, DestructorClosesFD )  
{
  {
    MockSocket* socket = new MockSocket( returnValues_, inputValues_, flags_ );
    InboundConnectionListener listener( socket, 0 );
  }
  EXPECT_EQ( returnValues_.socket, inputValues_.close );
}

TEST_F( InboundConnectionListenerTester, ListensToSocketFDItReceives )  
{
  EXPECT_EQ( returnValues_.socket, inputValues_.listen );
}

TEST_F( InboundConnectionListenerTester, AcceptsConnectionsOnSocketFDItReceives )  
{
  listener_.nextConnection();
  EXPECT_EQ( returnValues_.socket, inputValues_.accept );
}

TEST_F( InboundConnectionListenerTester, PassesInCorrectSocketFDToAccept )  
{
  listener_.nextConnection();
  EXPECT_EQ( returnValues_.socket, inputValues_.accept );
}

TEST_F( InboundConnectionListenerTester, ThrowsExceptionWhenAcceptFails )  
{
  flags_.acceptShouldError = true;
  ASSERT_THROW( listener_.nextConnection(), int );
}

TEST_F( InboundConnectionListenerTester, NextConnectionReturnsCorrectFD )  
{
  int actual = listener_.nextConnection(); 
  ASSERT_EQ( returnValues_.accept, actual );
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
//TODO: Get rid of ALL warnings
//
//TODO: Maybe don't do all this setup in the constructor?
//      It may make it easier to test and refactor tests.
//
//TODO: Create helper function for MockSocket
//
//TODO: There is a problem with sharing the structs among 2 instances
//      of Listener (some tests create an extra instance).  Both 
//      instances modify the struct values - that can get buggy.
//
