#include "gtest/gtest.h"
#include "mocks/MockSocket.h"
#include "InboundConnectionListener.h"

class InboundConnectionListenerTester
  : public ::testing::Test
{
  protected:
    const int SOCKET_RETURN_VALUE = 85;
    const int ACCEPT_RETURN_VALUE = 7777;
    const int PORT_TO_LISTEN_ON = 9080;

    struct MockSocketReturnValues returnValues_ = { 85, 7777 };
    struct MockSocketInputValues inputValues_ = { -1, -1, -1, -1 };
    struct MockSocketFlags flags_ = { false };

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
  EXPECT_EQ( 1, socket_->socketsCreated_ );
}

TEST_F( InboundConnectionListenerTester, ThrowsExceptionOnErrorSocket ) 
{
  MockSocket* socket = new MockSocket( returnValues_, inputValues_, flags_ );
  socket->returnErrorOnSocket_ = true;
  ASSERT_THROW( InboundConnectionListener listener( socket, 0 ), int );
}

TEST_F( InboundConnectionListenerTester, ClosesFDOnBindException ) 
{
  MockSocket* socket = new MockSocket( returnValues_, inputValues_, flags_ );
  socket->returnErrorOnBind_ = true;
  try
  {
    InboundConnectionListener listener( socket, 0 );
  }
  catch( int )
  { }
  
  EXPECT_EQ( returnValues_.socket, inputValues_.close );
}

TEST_F( InboundConnectionListenerTester, ClosesFDOnAcceptException ) 
{
  socket_->returnErrorOnAccept_ = true;
  try
  {
    listener_.nextConnection();
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
  socket->returnErrorOnBind_ = true;
  ASSERT_THROW( InboundConnectionListener listener( socket, 0 ), int );
}

TEST_F( InboundConnectionListenerTester, DeletesInjectedSocket )
{
  {
    MockSocket* socket = new MockSocket( returnValues_, inputValues_, flags_ );
    InboundConnectionListener listener( socket, 0 );
  }
  EXPECT_TRUE( flags_.destructorCalled );
}

TEST_F( InboundConnectionListenerTester, DeletesInjectedSocketOnSocketError )
{
  {
    MockSocket* socket = new MockSocket( returnValues_, inputValues_, flags_ );
    socket->returnErrorOnSocket_ = true;
    try
    {
      InboundConnectionListener listener( socket, 0 );
    }
    catch( int )
    { }
  }
  EXPECT_TRUE( flags_.destructorCalled );
}

TEST_F( InboundConnectionListenerTester, DeletesInjectedSocketOnBindError )
{
  {
    MockSocket* socket = new MockSocket( returnValues_, inputValues_, flags_ );
    socket->returnErrorOnBind_ = true;
    try
    {
      InboundConnectionListener listener( socket, 0 );
    }
    catch( int )
    { }
  }
  EXPECT_TRUE( flags_.destructorCalled );
}

TEST_F( InboundConnectionListenerTester, ListensToSocketFDItReceives )  
{
  EXPECT_EQ( returnValues_.socket, inputValues_.listen );
}

TEST_F( InboundConnectionListenerTester, AcceptsConnectionsOnSocketFDItReceives )  
{
  listener_.nextConnection();
  EXPECT_EQ( SOCKET_RETURN_VALUE, socket_->socketFDPassedIntoAccept_ );
}

TEST_F( InboundConnectionListenerTester, PassesInCorrectSocketFDToAccept )  
{
  listener_.nextConnection();
  EXPECT_EQ( SOCKET_RETURN_VALUE, socket_->socketFDPassedIntoAccept_ );
}

TEST_F( InboundConnectionListenerTester, ThrowsExceptionWhenAcceptFails )  
{
  socket_->returnErrorOnAccept_ = true;
  ASSERT_THROW( listener_.nextConnection(), int );
}

TEST_F( InboundConnectionListenerTester, nextConnectionReturnsCorrectFD )  
{
  int actual = listener_.nextConnection(); 
  ASSERT_EQ( ACCEPT_RETURN_VALUE, actual );
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
//TODO: Give better names (i.e. ThrowsExceptionWhenBindReturnsError
//
//TODO: make all names common (i.e. accpetReturnValue, SocketReturnValue 
//
//TODO: Get rid of ALL warnings
//
//TODO: Maybe don't do all this setup in the constructor?
//      It may make it easier to test and refactor tests.
//
//TODO: Create helper function for MockSocket
