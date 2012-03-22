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

    MockSocket* socket_;
    InboundConnectionListener listener_;

  public:
    InboundConnectionListenerTester()
      : socket_( new MockSocket( SOCKET_RETURN_VALUE, ACCEPT_RETURN_VALUE ) )
      , listener_( socket_, PORT_TO_LISTEN_ON )
    { }
};


TEST_F( InboundConnectionListenerTester, CreatesASocket )
{
  EXPECT_EQ( 1, socket_->socketsCreated_ );
}

TEST_F( InboundConnectionListenerTester, ThrowsExceptionOnErrorSocket ) 
{
  socket_->returnErrorOnSocket_ = true;
  ASSERT_THROW( InboundConnectionListener listener( socket_, 0 ), int );
}

TEST_F( InboundConnectionListenerTester, ClosesFDOnBindException ) 
{
  socket_->returnErrorOnBind_ = true;
  try
  {
    InboundConnectionListener listener( socket_, 0 );
  }
  catch( int )
  { }
  
  EXPECT_EQ( SOCKET_RETURN_VALUE, socket_->socketClosed_ );
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
  
  EXPECT_EQ( SOCKET_RETURN_VALUE, socket_->socketClosed_ );
}

TEST_F( InboundConnectionListenerTester, BindsToSocketFDItReceives ) 
{
  EXPECT_EQ( SOCKET_RETURN_VALUE, socket_->boundTo_ );
}

TEST_F( InboundConnectionListenerTester, BindsToPortSpecifiedInConstructor ) 
{
  EXPECT_EQ( PORT_TO_LISTEN_ON, socket_->boundToPort_ );
}


TEST_F( InboundConnectionListenerTester, ThrowsExceptionOnErrorBind )  
{
  socket_->returnErrorOnBind_ = true;
  ASSERT_THROW( InboundConnectionListener listener( socket_, 0 ), int );
}

TEST_F( InboundConnectionListenerTester, DeletesInjectedSocket )
{
  bool destructorCalled = false;
  {
    MockSocket* socket = new MockSocket( SOCKET_RETURN_VALUE, ACCEPT_RETURN_VALUE );
    socket->destructorCalled_ = &destructorCalled;
    InboundConnectionListener listener( socket, 0 );
  }
  EXPECT_TRUE( destructorCalled );
}

TEST_F( InboundConnectionListenerTester, ListensToSocketFDItReceives )  
{
  EXPECT_EQ( SOCKET_RETURN_VALUE, socket_->listeningTo_ );
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
//TODO: Make sure socket is destroyed on Ctor exception
//
//TODO: make all names common (i.e. accpetReturnValue, SocketReturnValue 
//
