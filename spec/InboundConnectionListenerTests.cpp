#include "gtest/gtest.h"
#include "mocks/MockSocket.h"
#include "InboundConnectionListener.h"

class InboundConnectionListenerTester
  : public ::testing::Test
{
  protected:
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
  EXPECT_TRUE( socket_->socketsCreated_ == 1 );
}

TEST_F( InboundConnectionListenerTester, ThrowsExceptionOnErrorSocket ) 
{
  socket_->throwExceptionOnSocket_ = true;
  ASSERT_THROW( InboundConnectionListener listener( socket_ ), int );
}

TEST_F( InboundConnectionListenerTester, BindsToTheSocketFDItReceives ) 
{
  EXPECT_TRUE( socket_->boundTo_ == socket_->socketFD_ );
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
