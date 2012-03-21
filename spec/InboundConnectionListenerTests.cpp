#include "gtest/gtest.h"
#include "mocks/MockSocket.h"
#include "InboundConnectionListener.h"

class InboundConnectionListenerTester
  : public ::testing::Test
{
  private:
    MockSocket* socket_;
    InboundConnectionListener listener_;

  public:
    InboundConnectionListenerTester()
      : socket_( new MockSocket() )
      , listener_( socket_ )
    { }
};


TEST_F( InboundConnectionListenerTester, CreatesASocket )
{
  MockSocket* socket = new MockSocket();
  InboundConnectionListener listener( socket );
  EXPECT_TRUE( socket->socketsCreated_ == 1 );
}

TEST_F( InboundConnectionListenerTester, ThrowsExceptionOnErrorSocket ) 
{
  MockSocket* socket = new MockSocket();
  socket->throwExceptionOnSocket_ = true;
  ASSERT_THROW( InboundConnectionListener listener( socket ), int );
}

TEST_F( InboundConnectionListenerTester, BindsToTheSocketFDItReceives ) 
{
  MockSocket* socket = new MockSocket();
  InboundConnectionListener listener( socket );
  EXPECT_TRUE( socket->boundTo_ == socket->socketFD_ );
}

//TODO: Test error returns on:
//      - bind( ... )
//      - accept( ... )

//TODO: Test proper parameters get sent to:
//      - bind()
//      - accept()
//
//TODO: Test if socket gets deleted in destructor
//
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
