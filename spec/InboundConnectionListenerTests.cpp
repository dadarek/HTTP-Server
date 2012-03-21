#include "gtest/gtest.h"
#include "mocks/MockSocket.h"
#include "InboundConnectionListener.h"

class InboundConnectionListenerTester
  : public ::testing::Test
{
  protected:
    int portToListenOn_;
    MockSocket* socket_;
    InboundConnectionListener listener_;

  public:
    InboundConnectionListenerTester()
      : portToListenOn_( 9080 )
      , socket_( new MockSocket() )
      , listener_( socket_, portToListenOn_ )
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
  
  EXPECT_EQ( socket_->socketFD_, socket_->socketClosed_ );
}

TEST_F( InboundConnectionListenerTester, BindsToSocketFDItReceives ) 
{
  EXPECT_EQ( socket_->socketFD_, socket_->boundTo_ );
}

TEST_F( InboundConnectionListenerTester, BindsToPortSpecifiedInConstructor ) 
{
  EXPECT_EQ( portToListenOn_, socket_->boundToPort_ );
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
    MockSocket* socket = new MockSocket();
    socket->destructorCalled_ = &destructorCalled;
    InboundConnectionListener listener( socket, 0 );
  }
  EXPECT_TRUE( destructorCalled );
}

TEST_F( InboundConnectionListenerTester, ListensToSocketFDItReceives )  
{
  EXPECT_EQ( socket_->socketFD_, socket_->listeningTo_ );
}

TEST_F( InboundConnectionListenerTester, AcceptsConnectionsOnSocketFDItReceives )  
{
  listener_.nextConnection();
  EXPECT_EQ( socket_->socketFD_, socket_->socketFDPassedIntoAccept_ );
}

//TODO: Test error returns on:
//      - accept( ... )

//TODO: Test if socket was created but bind or accept
//      threw error, that socket was closed.
//
//TODO: Merge common headers together
//
//TODO: Create good exceptions Exceptions better names
//
//TODO: Use -Wreorder in gcc
//
//TODO: Do explicit destructors (virtual and non-virtual)
//      implicitly call the base destructor?
//
//TODO: Use EXPECT_EQ
//
